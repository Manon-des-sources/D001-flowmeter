/* 
 * File:   md_rs485.h
 * Author: Administrator
 *
 * Created on May 29, 2018, 2:45 PM
 */

#ifndef MD_RS485_H
#define	MD_RS485_H

#ifdef	__cplusplus
extern "C" {
#endif


#include"config.h"


typedef struct 
{
    uint8_t  *buf;  // 指向用户的数据buf
    uint8_t   busy; // 用户自己的数据buf正在使用中
    uint16_t  len;  // 指向传给用户的数据长度
    uint16_t *plen; // plen = &len、用来传递len的地址
    uint16_t  size; // 用户数据buf的大小
}T_RS485_USER, *pT_RS485_USER;

// 数据buffer管理
typedef struct
{
    // 数据存取
    uint8_t *data;
    uint8_t  write;
    uint8_t  read;
    // 数据接收完毕检测
    uint8_t  store;
    uint8_t  rev_end;
    // 需要数据的用户
    T_RS485_USER user[4];  // 最多支持4个用户
}T_RS485_DATA, *pT_RS485_DATA;




void md_rs485_init(void);
void md_rs485_data_recv(uint8_t data);

bool md_rs485_user_append(pT_RS485_USER user);
bool md_rs485_user_del(pT_RS485_USER user);
bool md_rs485_set_user_busy(pT_RS485_USER user, bool busy_status);

void md_rs485_detect_data(void);

void md_rs485_send_frame(uint8_t *buf, uint16_t len);


#ifdef	__cplusplus
}
#endif

#endif	/* MD_RS485_H */
