#include"drv_timer.h"
#include"md_led.h"
#include"task_manager.h"


// 100ms定时中断
void drv_timer1_callback(void)
{
    md_pot1_toggle();
}

void drv_timer_init(void)
{
    MCU_TimerCfg(PortVmNum1, TimeSpMs100, drv_timer1_callback);
    MCU_TimerStart(PortVmNum1);
}
