/* 
 * File:   mb_master.h
 * Author: Administrator
 *
 * Created on June 1, 2018, 10:17 AM
 */

#ifndef MB_MASTER_H
#define	MB_MASTER_H

#ifdef	__cplusplus
extern "C" {
#endif


#include"config.h"


// 本工程支持的modbus指令
typedef enum 
{
    E_MODBUS_CODE_READ_DIGITAL_OUTPUT = 0x01,
    E_MODBUS_CODE_READ_DIGITAL_INPUT  = 0x02,
    E_MODBUS_CODE_READ_HOLD_REGISTER  = 0x03,
    E_MODBUS_CODE_READ_INPUT_REGISTER = 0x04,
    E_MODBUS_CODE_FORCE_SINGLE_DIGITAL_OUTPUT = 0x05,
    E_MODBUS_CODE_PRESET_SINGLE_HOLD_REGISTER = 0x06,
    E_MODBUS_CODE_FORCE_MULTI_DIGITAL_OUTPUT  = 0x0F,
    E_MODBUS_CODE_PRESET_MULTI_HOLD_REGISTER  = 0x10,
    E_MODBUS_CODE_UNKNOWN
}E_MODBUS_FUNCTION_CODE;

// modbus主机协议帧
typedef struct 
{
    uint8_t addr;
    uint8_t funcode;
    uint8_t reg_addr[2];
    uint8_t reg_num[2];
    uint8_t CRC16_[2];
}T_MODBUS_MASTER_FRAME, *pT_MODBUS_MASTER_FRAME;



#ifdef	__cplusplus
}
#endif

#endif	/* MB_MASTER_H */
