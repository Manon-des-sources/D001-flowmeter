/* 
 * File:   imath.h
 * Author: Administrator
 *
 * Created on June 1, 2018, 11:03 AM
 */

#ifndef IMATH_H
#define	IMATH_H

#ifdef	__cplusplus
extern "C" {
#endif


#include"config.h"


typedef struct 
{
    uint8_t *dest;  // 目标缓冲区
    uint8_t *cycle; // 循环缓冲区
    uint16_t len;   // 拷贝的数据长度
    uint16_t start; // 从循环缓冲区的这个位置开始复制数据
    uint16_t dmax;  // 目标缓冲区的大小
    uint16_t cmax;  // 循环缓冲区的大小
}T_MEMCPY_FROM_CYCLE, *pT_MEMCPY_FROM_CYCLE;
uint16_t memcpy_from_cycle(pT_MEMCPY_FROM_CYCLE copy);
uint16_t memcpy_to_cycle(pT_MEMCPY_FROM_CYCLE copy);

#ifdef	__cplusplus
}
#endif

#endif	/* IMATH_H */
