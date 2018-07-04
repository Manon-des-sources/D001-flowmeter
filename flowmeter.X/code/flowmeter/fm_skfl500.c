#include"fm_skfl500.h"

// 这里的地址顺序必须与T_SKFL500_DATA里面的数据顺序一致
static uint8_t fm_skfl500_hold_reg[] = 
{
    E_SKFL500_REG_Qf,
    E_SKFL500_REG_dumy01,
    E_SKFL500_REG_Vog,
    E_SKFL500_REG_dumy02,
    E_SKFL500_REG_Sos,
    E_SKFL500_REG_Qb,
    E_SKFL500_REG_dumy03,
    E_SKFL500_REG_C,
    E_SKFL500_REG_Pf,
    E_SKFL500_REG_Tf,
    E_SKFL500_REG_Vf,
    E_SKFL500_REG_dumy04,
    E_SKFL500_REG_Vf_err,
    E_SKFL500_REG_dumy05,
    E_SKFL500_REG_Vb
};
static uint8_t fm_skfl500_buf[sizeof(T_SKFL500_DATA)] = { 0 };
static pT_SKFL500_DATA pfm_skfl500_data = (pT_SKFL500_DATA)fm_skfl500_buf;

T_MODBUS_SLAVER_ACK fm_skfl500_ack_frame;

// 流量计数据更新
void fm_skfl500_update(void)
{
    pfm_skfl500_data->Vb += 40;
    pfm_skfl500_data->Vf += 42;
}
void fm_skfl500_init(void)
{
    T_MODBUS_SLAVER_INFO flowmeter_info;

    pfm_skfl500_data->Vb = 1025467;
    pfm_skfl500_data->Vf = 1025491;
    pfm_skfl500_data->Qb = 240.2;
    pfm_skfl500_data->Qf = 242.4;
    pfm_skfl500_data->Pf = 101.6;
    pfm_skfl500_data->Tf = 25.4;

    fm_skfl500_ack_frame.addr = SKFL500_ADDR;

    flowmeter_info.addr  = SKFL500_ADDR;
    flowmeter_info.ack   = fm_skfl500_ack;
    flowmeter_info.frame = fm_skfl500_check_frame;
    mb_slaver_frame_fun_append(&flowmeter_info);
}

// 流量计RS485通信
void fm_skfl500_check_frame(uint8_t *recv_buf, uint8_t *data)
{
    uint8_t  i;
    uint8_t  reg_index;
    uint8_t  ret_remain;
    uint16_t reg_addr = (recv_buf[2] << 8) + recv_buf[3];
    uint16_t reg_num  = (recv_buf[4] << 8) + recv_buf[5];

    fm_skfl500_ack_frame.funcode = recv_buf[1];
    for(reg_index = 0; reg_index < _countof(fm_skfl500_hold_reg); reg_index++)
    {
        if(reg_addr == fm_skfl500_hold_reg[reg_index]) { break; }
    }
    if(reg_index < _countof(fm_skfl500_hold_reg))
    {
        ret_remain = _countof(fm_skfl500_hold_reg) - reg_index;
        if(reg_num <= ret_remain)
        {
            // 每个寄存器地址对应2字节
            fm_skfl500_ack_frame.datalen = reg_num * 4;
            // 读出寄存器
            for(i = 0; i < (reg_num * 4); i++)
                data[i] = fm_skfl500_buf[(reg_index * 4) + i];
        }
        else
        {
            // 需要读取的寄存器数量超了
            fm_skfl500_ack_frame.funcode |= 0x80;
            data[0] = 1;
            fm_skfl500_ack_frame.datalen = 1;
        }
    }
    else
    {
        // 寄存器地址不存在
        fm_skfl500_ack_frame.funcode |= 0x80;
        data[0] = 2;
        fm_skfl500_ack_frame.datalen = 1;
    }
}
void fm_skfl500_ack(uint8_t *data)
{
    fm_skfl500_ack_frame.data = data;
    fm_skfl500_ack_frame.ack  = NULL;  // 不使用自定义的回应函数、使用标准Modbus模块的回应函数
    mb_slaver_response(&fm_skfl500_ack_frame);
}
