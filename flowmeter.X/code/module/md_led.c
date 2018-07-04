#include"md_led.h"

// ==========================================================================================================
// 测试点3
// ==========================================================================================================
void md_pot3_init(void)
{
    TRISFbits.TRISF4 = 0;
    PORTFbits.RF4    = 0;
}

void md_pot3_toggle(void)
{
    PORTFbits.RF4 ^= 1;
}

void md_pot3_set(void)
{
    PORTFbits.RF4 = 1;
}

void md_pot3_clr(void)
{
    PORTFbits.RF4 = 0;
}

// ==========================================================================================================
// 测试点2
// ==========================================================================================================
void md_pot2_init(void)
{
    TRISFbits.TRISF5 = 0;
    PORTFbits.RF5    = 0;
}

void md_pot2_toggle(void)
{
    PORTFbits.RF5 ^= 1;
}

void md_pot2_set(void)
{
    PORTFbits.RF5 = 1;
}

void md_pot2_clr(void)
{
    PORTFbits.RF5 = 0;
}

// ==========================================================================================================
// 测试点1
// ==========================================================================================================
void md_pot1_init(void)
{
    TRISFbits.TRISF1 = 0;
    PORTFbits.RF1    = 0;
}

void md_pot1_toggle(void)
{
    PORTFbits.RF1 ^= 1;
}

void md_pot1_set(void)
{
    PORTFbits.RF1 = 1;
}

void md_pot1_clr(void)
{
    PORTFbits.RF1 = 0;
}

// ==========================================================================================================
// LED2
// ==========================================================================================================
void md_led_toggle(void)
{
    PORTBbits.RB15 ^= 1;
}

void md_led_init(void)
{
    ANSBbits.ANSB15   = 0;
    TRISBbits.TRISB15 = 0;
    PORTBbits.RB15    = 0;
}
