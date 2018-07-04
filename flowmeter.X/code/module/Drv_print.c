// ==========================================================================================================
// 本文定义了print函数、是printf函数的简化版
// 使用UART输出
//
// -------------------
// 待改进：
// 1、buf超了可以报警
// 2、完整版printf、并可选择是否使用完整版
//
// ==========================================================================================================
#include "Drv_print.h"
#include"system.h"

typedef struct
{
    uint8_t data[160];  // 两行(屏幕一行80)
    uint8_t pwrite;
    uint8_t pread;
}T_PRINT_CTRL, *pT_PRINT_CTRL;

static uint8_t data_part[10] = {0};  // 用于存放拆分后的32位十进制数
T_PRINT_CTRL print_buf;

void DEBUG_DataProcess(uint8_t data)
{
    print_buf.data[print_buf.pwrite++] = data;
    if(print_buf.pwrite >= sizeof(print_buf.data)) { print_buf.pwrite = 0; }
}

// 数据发送
void print_send_frame(uint8_t *buf, uint16_t len)
{
    Uart3SendData(buf, len);
}

// ==========================================================================================================
// print_buffer_data() 拆分unsigned int型整数数据的每一位到数据buffer
//
// 参数：data       整数数据
//
// ==========================================================================================================
void print_buffer_udata(uint32_t data)
{
    uint8_t  index = 0;

    do
    {
        data_part[index] = data % 10;
        data -= data_part[index];  // 负数在这里越减越大、导致出不了这个循环，所以上面要将其转化为正数
        data /= 10;
        index++;
    }while(0 != data);

    do
    {
        index--;
        DEBUG_DataProcess(data_part[index] + '0');
    }while(0 < index);
}

// ==========================================================================================================
// print_buffer_data() 拆分int型整数数据的每一位到数据buffer
//
// 参数：data       整数数据
//
// ==========================================================================================================
void print_buffer_data(int32_t data)
{
    uint32_t temp  = data;

    if(0 > data)
    {
        temp = -data;
        DEBUG_DataProcess('-');
    }
    print_buffer_udata(temp);
}

// ==========================================================================================================
// print_buffer_char() 组织字符数据到数据buffer
//
// 参数：data       字符数据
//
// ==========================================================================================================
void print_buffer_char(char data)
{
    DEBUG_DataProcess(data);
}

// ==========================================================================================================
// print_buffer_string() 组织字符串到数据buffer
//
// 参数：data       字符串地址
//
// ==========================================================================================================
void print_buffer_string(char *data)
{
    while('\0' != *data)
    {
        DEBUG_DataProcess((uint8_t)*data);
        data++;
    }
}

// ==========================================================================================================
// print_buffer_hex() 组织数据以十六进制格式解析到数据buffer
//
// 参数：data       数据
//
// ==========================================================================================================
void print_buffer_hex(uint32_t data)
{
    uint8_t index = 0;
    uint8_t temp;

    do
    {
        temp = (data & 0x0F);
        temp = (temp > 9) ? (temp + 'a' - 10) : (temp + '0');
        data_part[index] = temp;
        data >>= 4;  // 必须是正数、才能保证这个循环能够退出(负数右移时最高位补1)
        index++;
    }while(0 != data);

    // 自动补齐2位数字或4位数字
    if((index == 1) || (index == 3))
    {
        data_part[index] = '0';
        index++;
    }

    do
    {
        index--;
        DEBUG_DataProcess(data_part[index]);
    }while(0 < index);
}

// 为了避免print()里面的default处理va_arg(ap, int)时的报警提示
static void dumy(int data)
{
    ;
}

// ==========================================================================================================
// print()
//
// 参数：fmt        格式控制字符串
//
// 说明：
// (1). 支持格式：%c    char  字符
//                %s    char *字符串
//                %d    16位signed int
//                %l    32位signed long int
//                %u    16位unsigned int
//                %U    32位unsigned long int
//                %x    16位int的十六进制格式(负数会保留符号位)
//                %X    32位long int的十六进制格式
// (2). 空格不能在%和d/./x之间，错误举例：print("a = % d\n",a);
// (3). 不要在中断中或抢占式任务中使用这个print函数，因为它是不可重入的，会修改全局的buffer
//
//  测试与使用范例：
//  print("ab145 = %s\r\n", "ab145");
//  print("sys start [V1.2]\r\n");
//  print("1 = %d, -2 = %d, a = %c\r\n", 1, -2, 'a');
//  print("655360 = %l, \r\n", 655360);
//  print("0x4567 = 0x%x\r\n", 0x4567);
//  print("0x01234567 = 0x%X\r\n", 0x01234567);
//  print("15671 = %u\r\n", 15671);
//  print("11234567 = %U\r\n", 11234567);
//
// ==========================================================================================================
void print(const char fmt[], ...)
{
    bool     transfer = FALSE;
    uint8_t *format   = (uint8_t *)fmt;
    uint16_t addr     = 0;
    va_list  ap       = NULL;

    va_start(ap, fmt);

    while('\0' != *format)
    {
        transfer = TRUE;

        if('%' == *format)
        {
            format++;
            switch(*format)
            {
                case 'c':print_buffer_char((char)va_arg(ap, int));
                         break;
                case 's':addr = sram_addr_overflow_check(va_arg(ap, int));
                         print_buffer_string((char *)addr);
                         break;
                case 'd':print_buffer_data(va_arg(ap, int));
                         break;
                case 'l':print_buffer_data(va_arg(ap, long));
                         break;
                case 'u':print_buffer_udata((uint32_t)(va_arg(ap, int)) & 0x0000FFFF);  // 去掉符号位(负数int转化为无符号long的时候、高16位全是符号位FFFF)
                         break;
                case 'U':print_buffer_udata(va_arg(ap, long));
                         break;
                case 'x':print_buffer_hex(va_arg(ap, int));  // 保留高16位正好可以看到符号位
                         break;
                case 'X':print_buffer_hex(va_arg(ap, long));
                         break;
                default: dumy(va_arg(ap, int));  // 跳过这个参数、它的格式设置不对，结果就是这个参数的具体值没有被存下来
                         print_buffer_char(*format);
                         break;
            }
        }
        else
        {
            print_buffer_char(*format);
        }
        format++;
    }
    va_end(ap);

    // 触发数据发送(如果发送器正在发送，这个触发并不会影响正在发送的操作)
    if(TRUE == transfer)
    {
        print_send_frame(print_buf.data, print_buf.pwrite - print_buf.pread);
        print_buf.pwrite = 0;
        print_buf.pread  = 0;
    }
}
