#ifndef __LIB_RS004_H__
#define __LIB_RS004_H__
#define USE_AND_OR
#include    <p24Fxxxx.h>
#include    <timer.h>
#include    <uart.h>
#include    <PPS.h>
#include    <ports.h>
#include    <rtcc.h>
#include    <adc.h>
#include "lib_public.h"
#define NEW_CBB_BOARD1

#define CLR_BIT(d,bit)      ((d) &= (~(bit)))
#define SET_BIT(d,bit)      ((d) |= (bit))

#define DEF_MAIN_CLK       8000000

typedef	enum PortNumE 
{
    PortVmNum0,
    PortVmNum1,
    PortVmNum2,
    PortVmNum3,
    PortVmNum4,
    PortVmNum5,
    PortVmNum6,
    PortVmNum7,
    PortVmNum8,
    PortVmNum9,
    PortVmNum10,
    PortVmNum11,
    PortVmNum12,
    PortVmNum13,
    PortVmNum14,
    PortVmNum15,
    PortVmNum16,
    PortVmNum17,
    PortVmNum18,
    PortVmNum19,
    PortVmNum20,
    PortVmNum21,
    PortVmNum22,
    PortVmNum23,
    PortVmNum24,
    PortVmNum25,
    PortVmNum26,
    PortVmNum27,
    PortVmNum28,
    PortVmNum29
}PortNumET;



typedef	enum TimeSpE
{
    TimeSpMs1,
    TimeSpMs10,
    TimeSpMs20,
    TimeSpMs50,
    TimeSpMs100,
    TimeSpMs500,
    TimeSpMs1000,
    TimeSpMs2000
}TimeSpET;

void IrqServerDefaultRS(unsigned char Data);
void set_IRQServerUart2Receive(IRQServerRecvDataFT fun);

void INT0Config(unsigned char Config, IRQServerFT Fuc);
void INT1Config(unsigned char Config, IRQServerFT Fuc);
void INT2Config(unsigned char Config, IRQServerFT Fuc);
void INT3Config(unsigned char Config, IRQServerFT Fuc);
void INT4Config(unsigned char Config, IRQServerFT Fuc);
void INT5Config(unsigned char Config, IRQServerFT Fuc);
void INT6Config(unsigned char Config, IRQServerFT Fuc);
void INT7Config(unsigned char Config, IRQServerFT Fuc);


/***********************************************************************************************************************
***********************************************************************************************************************/

//�??�????��
void INT0Config(unsigned char Config, IRQServerFT Fuc);
void INT1Config(unsigned char Config, IRQServerFT Fuc);
void INT2Config(unsigned char Config, IRQServerFT Fuc);
void INT3Config(unsigned char Config, IRQServerFT Fuc);
void INT4Config(unsigned char Config, IRQServerFT Fuc);
void INT5Config(unsigned char Config, IRQServerFT Fuc);
void INT6Config(unsigned char Config, IRQServerFT Fuc);
void INT7Config(unsigned char Config, IRQServerFT Fuc);
//串�???��
void Uart0Config(pUartMode Mode, IRQServerSendDataFT SendFun, IRQServerRecvDataFT RecvFun);
void Uart1Config(pUartMode Mode, IRQServerSendDataFT SendFun, IRQServerRecvDataFT RecvFun);
void Uart2Config(pUartMode Mode, IRQServerSendDataFT SendFun, IRQServerRecvDataFT RecvFun);
void Uart3Config(pUartMode Mode, IRQServerSendDataFT SendFun, IRQServerRecvDataFT RecvFun);
void Uart4Config(pUartMode Mode, IRQServerSendDataFT SendFun, IRQServerRecvDataFT RecvFun);
//串�?使�??��?
void Uart1SendEnable(void);
void Uart1SendDisable(void);
void Uart1ReceiveEnable(void);
void Uart1ReceiveDisable(void);
void Uart2SendEnable(void);
void Uart2SendDisable(void);
void Uart2ReceiveEnable(void);
void Uart2ReceiveDisable(void);
void Uart3SendEnable(void);
void Uart3SendDisable(void);
void Uart3ReceiveEnable(void);
void Uart3ReceiveDisable(void);
void Uart0SendEnable(void);
void Uart4SendEnable(void);
void Uart4SendDisable(void);
void Uart4ReceiveEnable(void);
void Uart4ReceiveDisable(void);
int Uart1SendData(unsigned char*pSendBuf, unsigned int Len);
int Uart2SendData(unsigned char*pSendBuf, unsigned int Len);
int Uart3SendData(unsigned char*pSendBuf, unsigned int Len);
int Uart4SendData(unsigned char*pSendBuf, unsigned int Len);
//MCU?��?
void MCU_SleepEnter(void);
//MCU�???��?
void MCU_IntEn(void);
void MCU_IntDis(void);
void MCU_DogCfg(void);              //???�??
void MCU_DogReset(void);            //???
void MCUPllCfg(void);
void MCU_LcdCfg(void);   //液�????�??
void MCU_LcdOpen(void);  //???液�?
void MCU_LcdClose(void); //?��?液�?
void MCU_LcdMemSet(unsigned char Reg);
void MCU_LcdAllSet(void); //?��?液�?
void MCU_LcdAllClr(void); //?��?液�?
void MCU_LcdWriteReg(unsigned char Seg, unsigned char Reg);
unsigned char MCU_LcdReadReg(unsigned char Seg);
//�???��?�??
void MCU_TimerCfg(PortNumET TimeNo, TimeSpET Sp, IRQServerFT TimeServer);
void MCU_TimerStart(PortNumET TimeNo);
void MCU_TimerStop(PortNumET TimeNo);
//ADC?��?
void MCU_ADCCfg(PortNumET ADCNum, ADCModeST Mode);   //
void MCU_ADCStart(PortNumET ADCNum);
void MCU_ADCStop(PortNumET ADCNum);
unsigned int MCU_ADCRead(void);
//�???��??��?
int RTCCfg(void);                //�??TRUE/FALSE
int RTCReadTime(RTC_T* Rtc);     //�??TRUE/FALSE
int RTCWriteTime(RTC_T* Rtc);    //�??TRUE/FALSE



#endif

