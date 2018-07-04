/* 
 * File:   drv_timer.h
 * Author: Administrator
 *
 * Created on May 29, 2018, 2:53 PM
 */

#ifndef DRV_TIMER_H
#define	DRV_TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif


#include"config.h"


typedef enum
{
    TIMER1 = 0,
    TIMER2 = 1,
    TIMER3 = 2,
    TIMER_LEN_1MS    = 0,
    TIMER_LEN_100MS  = 1,
    TIMER_LEN_1000MS = 2
}E_TIMER_SET;

void drv_timer_init(void);


#ifdef	__cplusplus
}
#endif

#endif	/* DRV_TIMER_H */
