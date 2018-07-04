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
// ==========================================================================================================
#ifndef SYS_EVENT_H
#define SYS_EVENT_H



#include"config.h"


typedef enum 
{
    EVENT_SYS,
    EVENT_KEY,
    EVENT_IR_RECIEVE,
    EVENT_IR_SEND,
    EVENT_RTC,
    EVENT_DIGITAL_FORMAT,// 数据进制格式、范围：[2,16]进制
    EVENT_SEG_UPDATE,    // 参数为32bit的事件(必须至少有一个、避免数组sys_event_int32[]的元素个数为0)
    EVENT_RS485,
    EVENT_MAX
}EVENT;

bool sys_event_post(uint8_t type);
bool sys_event_peek(uint8_t type);


#endif	// #ifndef SYS_EVENT_H
