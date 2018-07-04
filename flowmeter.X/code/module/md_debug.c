#include"md_debug.h"
#include"drv_uart.h"
#include"Drv_print.h"
#include"task_manager.h"


uint8_t md_debug_buf[256];
T_DEBUG_DATA md_debug_ctl = {
                            md_debug_ctl__addr(md_debug_buf), 
                            md_debug_ctl__pwrite(0), 
                            md_debug_ctl__pread(0) 
                           };

void md_debug_data_recv(uint8_t data)
{
    md_debug_ctl.data[md_debug_ctl.write++] = data;
    // uint8_t write超过sizeof(md_debug_buf)(=255)时会自动清0、这里无需处理
//    if(md_debug_ctl.write >= sizeof(md_debug_buf)) { md_debug_ctl.write = 0; }
}

// 分析数据帧
void md_debug_check_frame(void)
{
    print("debug got data\r\n");
    if((md_debug_ctl.data[0] == 0x09) && (md_debug_ctl.data[1] == 0x90))
        print("debug frame ok!\r\n");
    else
        print("debug frame crushed!\r\n");
    md_debug_ctl.read = md_debug_ctl.write = 0;
}

// 每10ms检查1次是否有数据过来
void md_debug_check_data(void)
{
    if(md_debug_ctl.write > (md_debug_ctl.read + 5))
    {
        // 50ms后运行一次、用以分析数据
        if(task_exist(md_debug_check_frame) == FALSE)
            task_add(delay_OneTime(50), period_OneTime(0), md_debug_check_frame, NULL);
    }
}
