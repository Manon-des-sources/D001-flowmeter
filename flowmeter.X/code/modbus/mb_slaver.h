/* 
 * File:   mb_slaver.h
 * Author: Administrator
 *
 * Created on June 1, 2018, 10:18 AM
 */

#ifndef MB_SLAVER_H
#define	MB_SLAVER_H

#ifdef	__cplusplus
extern "C" {
#endif



#include"config.h"
#include"mb_slaver.h"


#define MB_SLAVER_NUM   (4)    // 支持10个从机

// modbus从机信息
typedef struct 
{
    uint8_t  addr;        // 从机地址
    void_pfun_puint8 ack; // 从机回应主机
    void_pfun_puint8_puint8 frame; // 从机分析数据帧
}T_MODBUS_SLAVER_INFO, *pT_MODBUS_SLAVER_INFO;

// modbus从机回应
typedef struct 
{
    uint8_t  addr;      // 从机地址
    uint8_t  funcode;   // 从机回应的指令码(错误码 >= 0x80)
    uint16_t datalen;   // 从机回应的数据字节数
    uint8_t *data;      // 从机回应的数据
    void_pfun_void ack; // 从机回应函数
}T_MODBUS_SLAVER_ACK, *pT_MODBUS_SLAVER_ACK;


uint16_t mb_make_crc16(uint16_t count, uint8_t *pdata);

void mb_slaver_init(void);
void mb_slaver_check_frame(void);
uint8_t mb_slaver_frame_fun_append(pT_MODBUS_SLAVER_INFO flowmeter_info);
void mb_slaver_response(pT_MODBUS_SLAVER_ACK mb_slaver);



#ifdef	__cplusplus
}
#endif

#endif	/* MB_SLAVER_H */
