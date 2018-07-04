#include"mb_slaver.h"
#include"fm_skfl500.h"
#include"md_rs485.h"
#include"sys_event.h"


T_MODBUS_SLAVER_INFO mb_slaver_info[MB_SLAVER_NUM] = { {0xFF, NULL, NULL} };
// 用于接收从机的寄存器数据
uint8_t mb_slaver_buf[192] = { 0 };
// 需要向RS485要数据、就注册成为它的数据用户
T_RS485_USER mbSlaver;

// 返回已经注册进来的从机的序号
uint8_t mb_slaver_get_addr_index(uint8_t addr)
{
    uint8_t index;
    for(index = 0; index < _countof(mb_slaver_info); index++)
    {
        if(addr == mb_slaver_info[index].addr) { break; }
    }
    return index;
}
// 添加从机
uint8_t mb_slaver_frame_fun_append(pT_MODBUS_SLAVER_INFO pflowmeter_info)
{
    uint8_t index;
    for(index = 0; index < _countof(mb_slaver_info); index++)
    {
        if(mb_slaver_info[index].addr == 0xFF)
        {
            mb_slaver_info[index].addr  = pflowmeter_info->addr;
            mb_slaver_info[index].ack   = pflowmeter_info->ack;
            mb_slaver_info[index].frame = pflowmeter_info->frame;
            return TRUE;
        }
    }
    return FALSE;
}

void mb_slaver_init(void)
{
    uint8_t index;
    for(index = 0; index < _countof(mb_slaver_info); index++)
    {
        mb_slaver_info[index].addr   = 0xFF;
        mb_slaver_info[index].ack    = NULL;
        mb_slaver_info[index].frame  = NULL;
    }
    mbSlaver.buf  = mb_slaver_buf;
    mbSlaver.busy = FALSE;
    mbSlaver.len  = 0;
    mbSlaver.plen = &mbSlaver.len;
    mbSlaver.size = sizeof(mb_slaver_buf);
    md_rs485_user_append(&mbSlaver);
}

// 每10ms运行1次
void mb_slaver_check_frame(void)
{
    uint8_t  index;

    if(mbSlaver.len == 0) { return; }

    md_rs485_set_user_busy(&mbSlaver, TRUE);  // 这里使用数据过程中不会被rs485数据拷贝打断、所以可以不必设置忙标志
    index = mb_slaver_get_addr_index(mb_slaver_buf[0]);
    if(index < _countof(mb_slaver_info))
    {
        mb_slaver_info[index].frame(mb_slaver_buf, mb_slaver_buf);
        mb_slaver_info[index].ack(mb_slaver_buf);
    }
    md_rs485_set_user_busy(&mbSlaver, FALSE);
    mbSlaver.len = 0;
}

// 回应主机
void mb_slaver_response(pT_MODBUS_SLAVER_ACK pmb_slaver)
{
    uint16_t len;
    uint16_t CRC16;
    // 特殊协议的回复
    if(pmb_slaver->ack != NULL)
        return pmb_slaver->ack();

    // 标准Modbus协议的回复
    mb_slaver_buf[0] = pmb_slaver->addr;
    mb_slaver_buf[1] = pmb_slaver->funcode;
    mb_slaver_buf[2] = pmb_slaver->datalen >> 8;
    mb_slaver_buf[3] = pmb_slaver->datalen;
    len = pmb_slaver->datalen;
    while(pmb_slaver->datalen)
    {
        mb_slaver_buf[4 + pmb_slaver->datalen - 1] = pmb_slaver->data[pmb_slaver->datalen - 1];
        pmb_slaver->datalen--;
    }
    len += 4;
    CRC16 = mb_make_crc16(len, mb_slaver_buf);
    mb_slaver_buf[len + 0] = CRC16;
    mb_slaver_buf[len + 1] = CRC16 >> 8;
    // 数据发送
    md_rs485_send_frame(mb_slaver_buf, len + 2);
}
