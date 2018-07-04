#include"task_manager.h"
#include"Drv_print.h"
#include"md_led.h"

T_TASK task_queue[TASK_NUM_MAX]; // 任务队列

void task_start(void)
{
    MCU_TimerCfg(PortVmNum2, TimeSpMs1, task_update);
    MCU_TimerStart(PortVmNum2);
}

void task_init(void)
{
    uint8_t index = 0;
    for(index = 0; index < _countof(task_queue); index++)
    {
        task_delete(index);
    }
}

// ==========================================================================================================
//      添加任务到任务队列
// 
// 参数：
//      delay   任务延时计数
//      period  任务运行间隔(period = 0的单次任务只执行一次)
//      task    任务函数名
//      init    任务的初始化函数-(任务不再放到sys_init()里面去初始化)
// 
// 返回值：
//      index   任务号，>= _countof(task_queue) == SYS_TASK_MAX的任务号是无效的任务号
// 
// ==========================================================================================================
bool task_add(const uint16_t delay, const uint16_t period, const void_pfun_void task, const void_pfun_void init)
{
    bool FIN = FALSE;
    uint8_t index = 0;

    if(task == NULL) { return FIN; }

    for(index = 0; index < _countof(task_queue); index++)
    {
        if(task_queue[index].task == NULL) { break; }
    }
    if(index < _countof(task_queue))
    {
        task_queue[index].id     = index;
        task_queue[index].run    = (delay == 0) ? 1      : 0;
        task_queue[index].delay  = (delay == 0) ? period : delay;
        task_queue[index].period = period;
        task_queue[index].task   = task;
        // 必须在任务设置完毕后才初始化
        // 因为初始化里面可能需要用到task_index(),这涉及到task_queue[index].task、task_queue[index].id
        if(init != NULL)
        {
            init();
        }
        FIN = TRUE;
    }
    if(FIN == FALSE) { Warning(("warning; task %d add fail\r\n", index)); }
    return FIN;
}
// 添加单次运行的任务
bool task_add_OneTime(const uint16_t delay, const void_pfun_void task, const void_pfun_void init)
{
    return task_add(delay, period_OneTime(0), task, init);
}

// ==========================================================================================================
// 删除任务队列中的任务
// 
// ==========================================================================================================
void task_delete(const uint8_t index)
{
    if(index < _countof(task_queue))
    {
        if(task_queue[index].task != NULL)
        {
            task_queue[index].id     = 0;
            task_queue[index].run    = 0;
            task_queue[index].delay  = 0;
            task_queue[index].period = 0;
            task_queue[index].task   = NULL;
        }
    }
}

// ==========================================================================================================
//      任务调度函数
// 
// 说明：
// (1). 运行任务队列中 所有 已经就绪的任务
// (2). .run > 1表示该任务之前有被延迟 >1个调度时刻
// 
// (3). 新时刻到来会立即打断调度函数：
//      在运行过程中会被刷新任务状态的ISR(TIMER0_COMP_vect)打断，但由于任务是在每次时刻到来时被执行
//      所以每次打断的时刻、都是刚才任务被执行的时刻结束、而新时刻到来的时刻
//      此时、只要刚才的任务没超过或接近1ms，那么在这个时刻到来前、该任务早就执行完毕了
//      所以、此时打断并不影响刚才的任务，也不会出现刚才的任务执行完毕后、被加载在其后面执行的情况
// 
// (2). 单次任务：
//      将.period初始化为0，该函数就只会被执行1次、执行完毕后会立即被删除
//      sys_task_add(0, n, X, Xi)在初始化结束X后，X会立即被执行、或者在下一个时刻被执行：
//      1、如果任务队列中、当前任务前面还有空余位置，任务X就会被放在当前任务之前，那么任务X会在下一个时刻被执行
//      2、如果任务队列中、当前任务前面没有空余位置，任务X就会被放在当前任务之后，那么任务X会在当前任务所在时刻被执行
//      由于任务X及其初始化函数Xi都会增加执行时间，所以必须考虑新任务不会导致当前任务超时
//      一般：
//      -->只执行一次的任务、尽量放到启动任务队列之前去执行，不放到任务队列中
//      -->只执行一次的任务、尽量做得短小，其初始化一般为空
//      可以不用支持单次运行的任务，这里保留
// 
// (3). 每个任务都需要在退出任务前、解锁自己锁定的事件等资源
// 
// ==========================================================================================================
void task_dispatch(void)
{
    uint8_t  index = 0;

    for(index = 0; index < _countof(task_queue); index++)
    {
        if(task_queue[index].run > 0)
        {
            task_queue[index].task();
            if(task_queue[index].run > 1)
            {
                // 该任务曾经被延迟
            }
            task_queue[index].run = 0;
            if(task_queue[index].period == 0)
            {
                task_delete(index);  // 删除单次任务
            }
        }
    }
}

// ==========================================================================================================
//      系统定时器(Timer0)中断(中断周期=1ms)
// 
// (1). 刷新任务状态
// (2). sys_task_add中将.delay初始化为0，意味着第1次进入 任务调度函数、就会执行这个任务
// (3). 抢占式任务将直接在中断中执行，所以要求尽量短小
// 
// ==========================================================================================================
void task_update(void)
{
    uint8_t index = 0;

    for(index = 0; index < _countof(task_queue); index++)
    {
        if(task_queue[index].task != NULL)
        {
            if(task_queue[index].delay > 0) { task_queue[index].delay--; }

            if(task_queue[index].delay == 0) // 任务就绪检查
            {
                if(task_queue[index].run < TASK_RUN_MAX) { task_queue[index].run++; }
                // 单次运行的任务将会被删除、这里保证它在被删除前不再重新计数(也就不会被再次执行)
                if(task_queue[index].period > 0)
                {
                    task_queue[index].delay = task_queue[index].period;
                }
            }
        }
    }
}

// ==========================================================================================================
// 获取一个任务的任务号
// 
// 参数：
//      task    任务函数名
// 
// 返回值：
//      index   任务号，>=SYS_TASK_MAX的任务号是无效的任务号
// 
// ==========================================================================================================
uint8_t task_index(const void_pfun_void task)
{
    uint8_t index = _countof(task_queue);

    if(task != NULL)
    {
        for(index = 0; index < _countof(task_queue); index++)
        {
            if(task_queue[index].task == task)   // 指针可能需要转换为(uint16_t)来进行比较
            {
                index = task_queue[index].id;
                break;
            }
        }
    }
    return index;
}

// 判断任务是否已经存在
bool task_exist(const void_pfun_void task)
{
    if(task_index(task) < _countof(task_queue))
        return TRUE;
    return FALSE;
}
