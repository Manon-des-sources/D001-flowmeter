/* 
 * File:   config.h
 * Author: Administrator
 *
 * Created on May 29, 2018, 1:31 PM
 * 
 * 代码分类：
 * -------------------------
 * task：
 *     上告
 * -------------------------
 * API：
 *    打印、显示
 * -------------------------
 * 定时任务(软件中断)：
 *    阀门处理、IR数据分析、GPRS数据分析
 * -------------------------
 * 异步中断任务(硬件中断)：
 *     串口中断
 * -------------------------
 * 系统组件：
 *     事件队列
 * 
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif


#include<stdint.h>
#include<string.h>
#include"p24FJ64GA306.h"
#include"lib_public.h"
#include"bsp_mc306.h"
#include"lib_mc306.h"
#include"PPS.h"


#ifndef _countof
#define _countof(x) (sizeof(x) / sizeof((x)[0]))
#endif

typedef float float32_t;


typedef void (*void_pfun_void)(void);
typedef void (*void_pfun_puint8)(uint8_t *);
typedef void (*void_pfun_puint8_puint8)(uint8_t *, uint8_t *);



// 一些功能开关
#define __DEBUG_WARNING__   (1)  // 警告信息


#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */
