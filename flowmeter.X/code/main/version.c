#include"version.h"
#include"Drv_print.h"


static unsigned char sys_version[] = {1, 0, 2}; // 版本 = v1.0.2

void print_version_info(void)
{
    print("\r\n");
    print("* ========================== *\r\n");
    print("*   version [v%d.%d.%d]         *\r\n", sys_version[0], sys_version[1], sys_version[2]);
    print("*                            *\r\n");
    print("*   %s | %s   *\r\n", __DATE__, __TIME__);
    print("* ========================== *\r\n");
    print("\r\n");
}
