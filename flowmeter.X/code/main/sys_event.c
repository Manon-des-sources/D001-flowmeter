// ==========================================================================================================
// Copyright (c) 2016 ChenChen <codingmanon@163.com>
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and 
// associated documentation files (the "Software"), to deal in the Software without restriction, including 
// without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
// sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject 
// to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in 
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
// BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// 
// ---------------------------
// 本文定义了事件管理模块
// 
// 说明：
// (1).本文将事件(event)所带的参数称为消息(message)，以区分事件本身和事件的参数
//
// ---------------------------------------------------
// 这种简单的锁定、对实时任务会访问事件队列的情况无效
// 那时、需使用资源管理器与资源请求队列
// 
//    需要加锁的部分：
// 1、任务间通信的事件队列
// 2、多个任务共同使用的RAM块
// 3、多个任务共同使用的端口/硬件接口
// 
//    更安全的锁定机制-资源管理器与资源请求队列(32bit的队列.list，支持32个任务使用该资源)：
// 0、任务A访问资源S前，先做：if(ALLOWED | (.list | (1 << PRIORITY_S_A)))
//    ALLOWED一般为0、表示允许使用
// 1、任务A访问资源S前，先做：.list | (1 << PRIORITY_S_A)，设置任务A的使用请求标志
//    其中PRIORITY_S_A有用户分配，表示使用优先级
// 2、资源队列从.list的bit0开始检查、bit0对应优先级最高的请求
//    然后通知
// 
// ---------------------------
// 包含：
// 
// ==========================================================================================================
#include"sys_event.h"


static uint8_t sys_event_temp = 0;

bool sys_event_post(uint8_t type)
{
    sys_event_temp = type;
    return TRUE;
}

bool sys_event_peek(uint8_t type)
{
    bool FIN = FALSE;
    if(sys_event_temp == type)
    {
        FIN = TRUE;
    }
    sys_event_temp = EVENT_MAX;
    return FIN;
}
