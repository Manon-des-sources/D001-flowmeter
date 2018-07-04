#ifndef __LIB_PUBLIC_H__
#define __LIB_PUBLIC_H__

#include <PPS.h>

typedef void(*IRQServerRecvDataFT)(unsigned char Data);
typedef void(*IRQServerSendDataFT)(unsigned char Data);
typedef void(*IRQServerFT)(void);

typedef struct
{
    unsigned char	Year;	//BCD年份
    unsigned char	Mon;	//BCD
    unsigned char	Day;	//BCD
    unsigned char	Hour;	//BCD
    unsigned char	Min;	//BCD
    unsigned char	Sec;	//BCD
    unsigned char	Week;	//BCD
}RTC_T;

// ���ò�����
typedef enum
{
    UartBaud1200 = 0,
    UartBaud2400,
    UartBaud4800,
    UartBaud9600,
    UartBaud19200,
    UartBaud38400,
    UartBaud57600,
    UartBaud62500,
    UartBaud115200,
    UartBaud128000
}UartBaud;

// ���ڻ�������
typedef struct
{
    UartBaud      Baud;           // ������
    unsigned char Parity   : 2;   // 0=8bit����ģʽ+��У�顢1=8bit����ģʽ+��У�顢2=8bit����ģʽ+żУ�顢3=9bit����ģʽ+��У��
    unsigned char StopBit  : 1;   // 0=1��ֹͣλ��1=����ֹͣλ
    unsigned char DataBit  : 2;   // 0:7��1:8��; 2:9?
    unsigned char Sequence : 1;   // 0=LSB��1=MSB
    unsigned char reserved : 2;
}UartMode, *pUartMode;

typedef struct ADCModeS
{
    unsigned char ADCModeOpt : 2;//0:����//1:����
    unsigned char ADCModeResolution : 2;//0:8bit//1:10bit//2:12bit
    unsigned char ADCModeVREFU : 2;//0:VDD//1:�ڲ���׼//2:�ⲿ����׼
    unsigned char ADCModeVREFD : 2;//0:VSS//1:�ⲿ����׼
}ADCModeST;

typedef struct
{
    unsigned char ADCModeConversionMode;   //????,0:??,1:??
    unsigned char ADCModeChannel;          //????,0:????,1:????
    unsigned char ADCModeConversionBit;    //??????,8:8?,10:10?;12:12?
    unsigned char ADCRef;                  //????????,0:??1.45V,1:VDD
}ADC_InitTypeDef;

typedef enum
{
    // У��
    PARITY_NONE = 0,
    PARITY_ODD  = 1,
    PARITY_EVEN = 2,
    // ֹͣλ
    STOP_NONE = 0,
    STOP_1    = 1,
    STOP_2    = 2,
    // ���ݳ���
    DATA_7    = 0,
    DATA_8    = 1,
    DATA_9    = 2,
    // �ȷ��͸�λ���ǵ�λ
    LSB       = 0,
    MSB       = 1
}UartParam;

// PIC24FJ64GA306֧��4������
typedef enum
{
    COM1 = 0,
    COM2 = 1,
    COM3 = 2,
    COM4 = 3
} USART_TypeDef;

#define BIT0             0x01 /*Port Bit 0*/
#define BIT1             0x02 /*Port Bit 1*/
#define BIT2             0x04 /*Port Bit 2*/
#define BIT3             0x08 /*Port Bit 3*/
#define BIT4             0x10 /*Port Bit 4*/
#define BIT5             0x20 /*Port Bit 5*/
#define BIT6             0x40 /*Port Bit 6*/
#define BIT7             0x80 /*Port Bit 7*/

#define    DISABLE   0
#define    ENABLE    1

#ifndef BOOL
    #ifndef FALSE
        #define FALSE           0
        #define TRUE            1
    #endif
#endif

#ifndef bool
typedef unsigned char       bool;
#endif

 //����
// �����ذ�--(USB)
#define  COM1_TX_IN        (TRISDbits.TRISD11 = 1, ANSDbits.ANSD11 = 0,  ODCDbits.ODD11 = 0 )
#define  COM1_TX_OUT       (TRISDbits.TRISD11 = 0, ANSDbits.ANSD11 = 0,  ODCDbits.ODD11 = 0 )
#define  COM1_RX_IN        (TRISDbits.TRISD0  = 1, /* ANSDbits.ANSD0  = 0,*/  ODCDbits.ODD0  = 0 )
#define  COM1_OUT_PIN_PPS  OUT_PIN_PPS_RP12
#define  COM1_IN_PIN_PPS   IN_PIN_PPS_RP11

// �������԰�--(485)
#define  COM2_TX_IN        (TRISBbits.TRISB7 = 1, ANSBbits.ANSB7 = 0,  ODCBbits.ODB7 = 0 )
#define  COM2_TX_OUT       (TRISBbits.TRISB7 = 0, ANSBbits.ANSB7 = 0,  ODCBbits.ODB7 = 0 )
#define  COM2_RX_IN        (TRISBbits.TRISB6 = 1, ANSBbits.ANSB6 = 0,  ODCBbits.ODB6 = 0 )
#define  COM2_RX_OUT       (TRISBbits.TRISB6 = 0, ANSBbits.ANSB6 = 0,  ODCBbits.ODB6 = 0 )
#define  COM2_OUT_PIN_PPS  OUT_PIN_PPS_RP7
#define  COM2_IN_PIN_PPS   IN_PIN_PPS_RP6

// ������Ϣ--(���Կ�)
#define  COM3_TX_OUT        (TRISGbits.TRISG7 = 0,  ANSGbits.ANSG7 = 0,  ODCGbits.ODG7 = 0 )
#define  COM3_RX_IN         (TRISGbits.TRISG8 = 1,  ANSGbits.ANSG8 = 0,  ODCGbits.ODG8 = 0 )
#define  COM3_OUT_PIN_PPS   OUT_PIN_PPS_RP26
#define  COM3_IN_PIN_PPS    IN_PIN_PPS_RP19

//IR
#define  COM4_TX_OUT       (TRISDbits.TRISD2 = 0, /*ANSDbits.ANSD2 = 0,*/  ODCDbits.ODD2 = 0 )
#define  COM4_RX_IN        (TRISDbits.TRISD1 = 1, /*ANSDbits.ANSD1 = 0,*/  ODCDbits.ODD1 = 0 )
#define  COM4_OUT_PIN_PPS  OUT_PIN_PPS_RP23
#define  COM4_IN_PIN_PPS   IN_PIN_PPS_RP24

//void RegOneSecIRQFun(IRQServerFT CallBack);
#endif
