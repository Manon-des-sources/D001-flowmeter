#include"system.h"
#include"version.h"
#include"drv_uart.h"
#include"drv_timer.h"
#include"Drv_print.h"
#include"task_manager.h"
#include"md_led.h"

void osc_init(void)
{
    // 时钟配置
    OSCCONbits.COSC = 0;    // 当前振荡器 = 快速RC振动器(FRC)、外设默认1分频为8MHz、CPU默认2分配为4MHz
    OSCCONbits.NOSC = 0;    // 新振荡器   = 快速RC振动器(FRC)
    _OSWEN  = 0;            // 不切换到NOSC指定的新振荡器
    _SOSCEN = 0;            // 不使用32 kHz辅助振荡器
    _POSCEN = 0;            // 主振荡器在休眠模式期间被禁止
    // 其他
    _NSTDIS = 1;            // 禁止中断嵌套
    _RETEN  = 1;            // 休眠模式下启用保护模式(向内核提供1.2V稳压电源)
}

void delay_us(uint32_t us)
{
    while (us--)
    {
        Nop();//8M
        //for( char i = 0; i < 2; i++ );//4M
    }
}

void delay_ms(uint32_t ms)
{
    int i;
    while (ms--)
    {
        for (i = 0; i < 800; i++){}  //4M:400,8M:800
    }
}

void sys_init(void)
{
    // 时钟
    osc_init();
    delay_ms(250);  // 上电后、Flash芯片需要100ms以上才能准备好
    // 外围模块
    md_pot1_init();
    md_pot2_init();
    md_pot3_init();
    drv_timer_init();
    drv_uart_init();
    delay_ms(25);  // 必须等UART初始化OK之后才可以使用print等串口
    print_version_info();
}

// ==========================================================================================================
// sram_addr_overflow_check()
//
// 参数：addr       地址
//
// 说明：
// (1). 有些寄存器读出数据之后就会被清0或者引发其他隐患，所以print()的%s等地方想要进行地址检查，保证地址在RAM范围内
// (2). 地址越界、就赋予RAMSTART(iom16.h)
//
// ==========================================================================================================
uint8_t err_overflow_addr[] = "\r\nerr_overflow_addr\r\n";
uint16_t sram_addr_overflow_check(const uint16_t addr)
{
#if 0
    uint16_t Fin = addr;

    if((addr < RAMSTART) || (RAMEND < addr))
    {
        Fin = (uint16_t)err_overflow_addr;
    }
    return Fin;
#else
    return addr;
#endif
}
