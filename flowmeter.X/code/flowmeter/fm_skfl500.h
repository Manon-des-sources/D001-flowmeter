/* 
 * File:   fm_skfl500.h
 * Author: Administrator
 *
 * Created on June 1, 2018, 10:09 AM
 */

#ifndef FM_SKFL500_H
#define	FM_SKFL500_H

#ifdef	__cplusplus
extern "C" {
#endif


#include"config.h"
#include"mb_master.h"
#include"mb_slaver.h"


// 保持寄存器地址表：
// Addr  | Size |  Type   |         Value               | Unit
// ---------------------------------------------------------------
//  7002 |  2   | FLOAT32 | Flow rate actual Qf 工况瞬时 | m³/h
//  7004 |  2   | FLOAT32 | Gas velocity VOG    气体流速 | m/s
//  7006 |  2   | FLOAT32 | Speed of sound SOS  声速声速 | m/s
// ---------------------------------------------------------------
//  5026 |  2   | FLOAT32 | Flow rate base Qb   标况瞬时 | Sm³/h
//  5028 |  2   | FLOAT32 | Conversion factor   转换系数 | C
//  5033 |  2   | FLOAT32 | Compressibility     压缩因子 | Z
//  5035 |  2   | FLOAT32 | 标准参比条件下压缩因子        | Zn
//  5037 |  2   | FLOAT32 | 工作条件下的压缩因子          | Zf
//  5136 |  2   | FLOAT32 | Pressure Pf         压力     | bar(a)
//  5224 |  2   | FLOAT32 | Temperature Tf      温度     | ℃
//  ---------------------------------------------------------------
//  4102 |  2   | UINT32  | Counter Vf 工况总累          |
//  4104 |  2   | UINT32  | Counter Vf err错误工况总累   |
//  4106 |  2   | UINT32  | Counter Vb 标况总累          |
//  4108 |  2   | UINT32  | Counter Vb err错误标况总累   |
//  4110 |  2   | UINT32  | Counter Vb total标况总累计   |
// 
// 流量计数据
// 根据FL500 Modbus地址表、有15个寄存器、每个寄存器2字节
// 但由于有些地址不连续、所以需要填充几个寄存器让它们连续
typedef struct 
{
    float32_t Qf;  // 工况流量 @ 7002
    float32_t dumy01;
    float32_t Vog; // 气体流速 @ 7004
    float32_t dumy02;
    float32_t Sos; // 声速     @ 7006
    float32_t Qb;  // 标况流量 @ 5026
    float32_t dumy03;
    float32_t C;   // 转换系数 @ 5028 
    float32_t Pf;  // 压力     @ 5136
    float32_t Tf;  // 温度     @ 5224
    uint32_t  Vf;  // 工况总量  @ 4102
    uint32_t  dumy04;
    uint32_t  Vf_err;// 错误工况总累 @ 4104
    uint32_t  dumy05;
    uint32_t  Vb;  // 标况总量  @ 4106
}T_SKFL500_DATA, *pT_SKFL500_DATA;

// 流量计保持寄存器的地址
// 这里的地址顺序必须与T_SKFL500_DATA里面的数据顺序一致
// 用结构体将这个地址表和上面的数据结构绑定在一起
typedef enum 
{
    E_SKFL500_REG_Qf      = 2 - 1,
    E_SKFL500_REG_dumy01  = 3 - 1,
    E_SKFL500_REG_Vog     = 4 - 1,
    E_SKFL500_REG_dumy02  = 5 - 1,
    E_SKFL500_REG_Sos     = 6 - 1,
    E_SKFL500_REG_Qb      = 26 - 1,
    E_SKFL500_REG_dumy03  = 27 - 1,
    E_SKFL500_REG_C       = 28  - 1,
    E_SKFL500_REG_Pf      = 136 - 1,
    E_SKFL500_REG_Tf      = 224 - 1,
    E_SKFL500_REG_Vf      = 102 - 1,
    E_SKFL500_REG_dumy04  = 103 - 1,
    E_SKFL500_REG_Vf_err  = 104 - 1,
    E_SKFL500_REG_dumy05  = 105 - 1,
    E_SKFL500_REG_Vb      = 106 - 1
}E_SKFL500_HOLD_REGISTER_ADDR;

typedef enum 
{
    SKFL500_ADDR = 0x01  // 从机地址
}E_SKFL500_ADDR;


void fm_skfl500_update(void);
void fm_skfl500_init(void);

void fm_skfl500_check_frame(uint8_t *buf, uint8_t *data);
void fm_skfl500_ack(uint8_t *data);


#ifdef	__cplusplus
}
#endif

#endif	/* FM_SKFL500_H */
