#include"imath.h"



// 从环形缓冲区复制数据
uint16_t memcpy_from_cycle(pT_MEMCPY_FROM_CYCLE copy)
{
    uint16_t i;
    for(i = 0; (i < copy->len) && (i < copy->dmax); i++)
    {
        // 循环缓冲区下标溢出时需要归0
        if((copy->start + i) >= copy->cmax)
        {
            copy->start = 0;
        }
        copy->dest[i] = copy->cycle[copy->start + i];
    }
    return i;
}
// 复制数据到环形缓冲区
uint16_t memcpy_to_cycle(pT_MEMCPY_FROM_CYCLE copy)
{
    uint16_t i;
    for(i = 0; i < copy->len; i++)
    {
        if((copy->start + i) >= copy->cmax)
        {
            copy->start = 0;
        }
        copy->cycle[copy->start + i] = copy->dest[i];
    }
    return i;
}


// 本工程的Microchip浮点数和IEEE754浮点数是一样的
// =================================================================
// Microchip浮点数和IEEE754浮点数互相转换
// ------------------------------------
// 资料来源：help里面搜索mchptoieee()函数
// ------------------------------------
// 验证数据：45.67(IEEE754) = 0x4236AE14
// =================================================================
//                  | eb        | f0        | f1        | f2
// -----------------------------------------------------------------
// IEEE-754 32-bit  | seee eeee | exxx xxxx | xxxx xxxx | xxxx xxxx 
// -----------------------------------------------------------------
// Microchip 32-bit | eeee eeee | sxxx xxxx | xxxx xxxx | xxxx xxxx
// -----------------------------------------------------------------
//                  | s=sign bit    e=exponent    x=significand 
// =================================================================
// 
// IEEE754 float --> Microchip float
float32_t IEEE754_to_MCPH_LittleEndian(uint32_t data)
{
    uint8_t s;
    union float32_int32
    {
        float32_t f32;
        uint32_t  i32;
        uint16_t  i16[2];
        uint8_t   i8[4];
    } float_int;
    float_int.i32 = data;
    s = float_int.i8[3] & 0x80;
    float_int.i16[1] <<= 1;
    float_int.i8[3]  >>= 1;
    float_int.i8[3]   |= s;
    return float_int.f32;
}
// 
// Microchip float --> IEEE754 float
uint32_t MCPH_to_IEEE754_LittleEndian(float32_t data)
{
    uint8_t s;
    union float32_int32
    {
        float32_t f32;
        uint32_t  i32;
        uint16_t  i16[2];
        uint8_t   i8[4];
    } float_int;
    float_int.f32 = data;
    s = float_int.i8[2] & 0x80;
    float_int.i8[2]  <<= 1;
    float_int.i16[1] >>= 1;
    float_int.i8[3]   |= s;
    return float_int.i32;
}
