/* 
 * File:   task_manager.h
 * Author: Administrator
 *
 * Created on May 30, 2018, 2:21 PM
 */

#ifndef TASK_MANAGER_H
#define	TASK_MANAGER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include"config.h"

#define TASK_NUM_MAX       (7)
#define TASK_RUN_MAX       (5)  // 1个任务的就绪状态的最大值

#define period(t)          (t)
#define delay(t)           (t)
#define period_OneTime(t)  (period(0))   // period = 0的单次任务只执行一次
#define delay_OneTime(t)   (delay(t))

typedef struct 
{
    uint8_t  id;     // 任务号：该任务在任务队列中的位置
    uint8_t  run;    // 任务状态：(0)=准备中、(>0)=就绪、(>1)=任务曾经被延迟
    uint16_t delay;  // 任务延时计数
    uint16_t period; // 任务运行间隔
    void_pfun_void task; // 任务函数
}T_TASK, *pT_TASK;




void task_init(void);
void task_start(void);
void task_update(void);
void task_dispatch(void);
void task_delete(const uint8_t index);
bool task_add(const uint16_t delay, const uint16_t period, const void_pfun_void task, const void_pfun_void init);
bool task_add_OneTime(const uint16_t delay, const void_pfun_void task, const void_pfun_void init);
bool task_exist(const void_pfun_void task);
uint8_t task_index(const void_pfun_void task);


#ifdef	__cplusplus
}
#endif

#endif	/* TASK_MANAGER_H */
