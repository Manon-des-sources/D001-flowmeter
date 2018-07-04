/* 
 * File:   system.h
 * Author: Administrator
 *
 * Created on May 29, 2018, 1:39 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif


#include"config.h"


void delay_us(uint32_t us);
void delay_ms(uint32_t ms);
void sys_init(void);
uint16_t sram_addr_overflow_check(const uint16_t addr);


#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

