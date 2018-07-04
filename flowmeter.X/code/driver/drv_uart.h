/* 
 * File:   drv_uart.h
 * Author: Administrator
 *
 * Created on May 29, 2018, 2:31 PM
 */

#ifndef DRV_UART_H
#define	DRV_UART_H

#ifdef	__cplusplus
extern "C" {
#endif



#include"config.h"


// 数据buffer管理
typedef struct
{
    // 数据存取
    uint8_t *data;
    uint8_t  write;
    uint8_t  read;
}T_UART_DATA, *pT_UART_DATA;

void drv_uart_init(void);
void md_debug_check_data(void);


#ifdef	__cplusplus
}
#endif

#endif	/* DRV_UART_H */
