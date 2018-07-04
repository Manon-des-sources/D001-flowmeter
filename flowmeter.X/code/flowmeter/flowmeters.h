/* 
 * File:   flowmeters.h
 * Author: Administrator
 *
 * Created on June 1, 2018, 10:09 AM
 */

#ifndef FLOWMETERS_H
#define	FLOWMETERS_H

#ifdef	__cplusplus
extern "C" {
#endif


#include"fm_skfl500.h"


void flowmeter_init(void);
void flowmeter_update(void);


#ifdef	__cplusplus
}
#endif

#endif	/* FLOWMETERS_H */

