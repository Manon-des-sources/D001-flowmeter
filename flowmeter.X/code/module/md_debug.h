/* 
 * File:   md_debug.h
 * Author: Administrator
 *
 * Created on May 29, 2018, 2:50 PM
 */

#ifndef MD_DEBUG_H
#define	MD_DEBUG_H

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
}T_DEBUG_DATA, *pT_DEBUG_DATA;


#define md_debug_ctl__addr(buf)        (buf)
#define md_debug_ctl__pwrite(phead)    (phead)
#define md_debug_ctl__pread(pread)     (pread)


void md_debug_data_recv(uint8_t data);
void md_debug_check_data(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MD_DEBUG_H */
