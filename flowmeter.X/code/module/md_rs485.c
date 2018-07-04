#include"md_rs485.h"
#include"drv_uart.h"
#include"Drv_print.h"
#include"task_manager.h"
#include"sys_event.h"
#include"imath.h"

#define RS485_BUF_SIZE  (256)
uint8_t md_rs485_buf[RS485_BUF_SIZE];
T_RS485_DATA md_rs485_ctl;

void md_rs485_init(void)
{
    uint8_t index;
    md_rs485_ctl.data  = md_rs485_buf;
    md_rs485_ctl.write = 0;
    md_rs485_ctl.read  = 0;
    md_rs485_ctl.store   = 0;
    md_rs485_ctl.rev_end = 0xFF;
    for(index = 0; index < _countof(md_rs485_ctl.user); index++)
    {
        md_rs485_ctl.user[index].buf  = NULL;
        md_rs485_ctl.user[index].busy = FALSE;
        md_rs485_ctl.user[index].plen = NULL;
        md_rs485_ctl.user[index].size = 0;
    }
}

// 这个忙标志不适用于抢占式任务
bool md_rs485_set_user_busy(pT_RS485_USER user, bool busy_status)
{
    uint8_t index;
    for(index = 0; index < _countof(md_rs485_ctl.user); index++)
    {
        if(md_rs485_ctl.user[index].buf == user->buf)
        {
            md_rs485_ctl.user[index].busy = busy_status;
        }
        return TRUE;
    }
    return FALSE;
}

static void md_rs485_reset_recv(void)
{
    md_rs485_ctl.read  = 0;
    md_rs485_ctl.write = 0;
    md_rs485_ctl.store   = 0;
    md_rs485_ctl.rev_end = 0xFF;
}

void md_rs485_data_recv(uint8_t data)
{
    // sizeof(md_rs485_ctl.data) == 256,而.write为uint8_t类型, 它加1溢出后正好为0(255 + 1 == 0)
    // 所以这里不需要检测.write++溢出
    #if RS485_BUF_SIZE > 256
        #error("RS485_BUF_SIZE > 255");
    #endif
    md_rs485_ctl.data[md_rs485_ctl.write++] = data;
}



// 需要使用RS485接口数据的用户在这里注册
bool md_rs485_user_append(pT_RS485_USER user)
{
    uint8_t index;
    for(index = 0; index < _countof(md_rs485_ctl.user); index++)
    {
        if(md_rs485_ctl.user[index].buf == NULL)
        {
            md_rs485_ctl.user[index].buf  = user->buf;
            md_rs485_ctl.user[index].busy = user->busy;
            md_rs485_ctl.user[index].plen = user->plen;
            md_rs485_ctl.user[index].size = user->size;
            return TRUE;
        }
    }
    return FALSE;
}

bool md_rs485_user_del(pT_RS485_USER user)
{
    uint8_t index;
    for(index = 0; index < _countof(md_rs485_ctl.user); index++)
    {
        if(md_rs485_ctl.user[index].buf == user->buf)
        {
            md_rs485_ctl.user[index].buf = NULL;
            return TRUE;
        }
    }
    return FALSE;
}

// 每10ms运行1次
void md_rs485_detect_data(void)
{
    uint8_t index;
    uint8_t users_busy = FALSE;
    T_MEMCPY_FROM_CYCLE copy;
    if(md_rs485_ctl.write != md_rs485_ctl.store)
    {
        md_rs485_ctl.store = md_rs485_ctl.write;
        md_rs485_ctl.rev_end = 0;
    }
    else
    {
        // 连续10ms没有数据过来、就认为一帧数据接收完毕
        if(md_rs485_ctl.rev_end < 2)
        {
            md_rs485_ctl.rev_end++;
            if(md_rs485_ctl.rev_end > 1)
            {
                copy.cycle = md_rs485_buf;
                copy.cmax  = sizeof(md_rs485_buf);
                // 数据接收完毕后、拷贝给需要的用户、并通知他们有数据到了
                for(index = 0; index < _countof(md_rs485_ctl.user); index++)
                {
                    if(md_rs485_ctl.user[index].busy == TRUE)
                    {
                        users_busy = TRUE;
                        continue;
                    }
                    if(md_rs485_ctl.user[index].buf != NULL)
                    {
                        copy.dest  = md_rs485_ctl.user[index].buf;
                        copy.dmax  = md_rs485_ctl.user[index].size;
                        copy.len   = md_rs485_ctl.write - md_rs485_ctl.read;
                        copy.start = md_rs485_ctl.read;
                        memcpy_from_cycle(&copy);
                       *md_rs485_ctl.user[index].plen = copy.len;
                    }
                }
                // 所有客户都拿到数据之后、就可以重置接收缓存了
                if(users_busy == FALSE)
                {
                    md_rs485_reset_recv();
                }
            }
        }
    }
}




// 数据发送
void md_rs485_send_frame(uint8_t *buf, uint16_t len)
{
    Uart2SendData(buf, len);
}
