/* 
 * File:   md_led.h
 * Author: Administrator
 *
 * Created on May 29, 2018, 2:13 PM
 */

#ifndef MD_LED_H
#define	MD_LED_H

#ifdef	__cplusplus
extern "C" {
#endif



#include"config.h"

void md_pot3_init(void);
void md_pot3_toggle(void);
void md_pot3_set(void);
void md_pot3_clr(void);
void md_pot3_init(void);

void md_pot2_toggle(void);
void md_pot2_set(void);
void md_pot2_clr(void);
void md_pot2_init(void);

void md_pot1_toggle(void);
void md_pot1_set(void);
void md_pot1_clr(void);
void md_pot1_init(void);

void md_led_toggle(void);
void md_led_init(void);



#ifdef	__cplusplus
}
#endif

#endif	/* MD_LED_H */
