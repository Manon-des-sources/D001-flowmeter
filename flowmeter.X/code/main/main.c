#include"system.h"
#include"config.h"
#include"Drv_print.h"
#include"task_manager.h"
#include"flowmeters.h"
#include"mb_slaver.h"
#include"md_debug.h"
#include"md_rs485.h"
#include"md_led.h"

int main(void)
{
    sys_init();

    task_init();
    task_add(delay(0), period(1000), md_led_toggle, md_led_init);
    // 这些任务可以放到一个循环队列里面去
    task_add(delay(1), period(10), md_debug_check_data,  NULL);
    task_add(delay(2), period(10), md_rs485_detect_data, md_rs485_init);
    task_add(delay(3), period(10), mb_slaver_check_frame,mb_slaver_init);
    task_add(delay(4), period(10), flowmeter_update,     flowmeter_init);
    task_start();
    
    while(1)
    {
        task_dispatch();
    }
    return 0;
}
