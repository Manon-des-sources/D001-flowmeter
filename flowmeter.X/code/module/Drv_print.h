// ==========================================================================================================
// 本文定义了print函数、是printf函数的简化版
// 使用UART输出
//
// -------------------
//
// ==========================================================================================================

#ifndef DRV_PRINT_H
#define	DRV_PRINT_H

#ifdef	__cplusplus
extern "C" {
#endif


#include"config.h"
#include<stdarg.h>  // 包含可变参数函数需要的几个宏


void print(const char fmt[], ...);



#if __DEBUG_WARNING__
    #define Warning(msg)  print msg
#else
    #define Warning(msg)
#endif



#ifdef	__cplusplus
}
#endif

#endif	/* DRV_PRINT_H */
