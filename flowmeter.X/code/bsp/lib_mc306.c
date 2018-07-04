/*
                                                    ****************************
                                                            lib_rs004
                                                    ****************************

?µ?÷:       ??¼þ?µ?÷

                TRISx:0���,1����/AD        TRISBbits.TRISB8
                ANSx:0���ֶ˿�,1ģ��˿�    ANSBbits.ANSB8
                ODCx:0�������,1��©���    ODCBbits.ODB8
                PORTx:�˿ڵ�ƽ              PORTBbits.RB8
                //LATBx:��д�˿ڵ�ƽ�����    LATBbits.LATB9

                2.4V-5.5V
                High-speedOCO(fiH)
                8MHz

?è?ó:       ¶??²¼þ»ò?ä?ü?í¼þµ??è?ó
°æ±¾:       v0.0.0
°æ?¨:       ?þ????????±í¹?·?????¹«?¾¡¡°æ?¨?ù??£¬(c)2000-2050
??¸?¼??¼:   --------------------------------------------------------------------
            ????:           ¸º?ð??:     ¹¤?÷:           °æ±¾:
            XXXX-XX-XX      XXXX    ´´½¨/??¸?/?ö¼?/???´ v0.0.0
********************************************************************************
*/

#define     _lib_rs004_C_
#include    "lib_mc306.h"

static unsigned short Random;
void IrqServerDefaultRS(unsigned char Data){ ; }
void IrqServerDefault(void){ ; }

IRQServerFT IRQServerCN0 = IrqServerDefault;
IRQServerFT IRQServerCN1 = IrqServerDefault; 
IRQServerFT IRQServerCN2 = IrqServerDefault; 
IRQServerFT IRQServerCN3 = IrqServerDefault; 
IRQServerFT IRQServerCN4 = IrqServerDefault; 
IRQServerFT IRQServerCN5 = IrqServerDefault; 
IRQServerFT IRQServerCN6 = IrqServerDefault; 
IRQServerFT IRQServerCN7 = IrqServerDefault; 
IRQServerFT IRQServerCN8 = IrqServerDefault; 
IRQServerFT IRQServerCN9 = IrqServerDefault; 
IRQServerFT IRQServerCN10 = IrqServerDefault;
IRQServerFT IRQServerCN11 = IrqServerDefault;
IRQServerFT IRQServerCN12 = IrqServerDefault;
IRQServerFT IRQServerCN13 = IrqServerDefault;
IRQServerFT IRQServerCN14 = IrqServerDefault;
IRQServerFT IRQServerCN26 = IrqServerDefault;
IRQServerFT IRQServerCN27 = IrqServerDefault;
IRQServerFT IRQServerCN63 = IrqServerDefault;
IRQServerFT IRQServerCN64 = IrqServerDefault;

IRQServerFT IRQServerINT0 = IrqServerDefault;
IRQServerFT IRQServerINT1 = IrqServerDefault;
IRQServerFT IRQServerINT2 = IrqServerDefault;
IRQServerFT IRQServerINT3 = IrqServerDefault;
IRQServerFT IRQServerINT4 = IrqServerDefault;

void __attribute__((interrupt, no_auto_psv)) _CNInterrupt(void)
{
    InputChange_Clear_Intr_Status_Bit;
    //if ((CNEN1bits.CN9IE == 1) && (PORTGbits.RG7 == 0))
    //    IRQServerCN9();
    //if ((CNEN1bits.CN10IE == 1) && (PORTGbits.RG8 == 0))
    //    IRQServerCN10();
    //if ((CNEN2bits.CN26IE == 1) && (PORTBbits.RB8 == 0))
    //    IRQServerCN26();
    Random++;
}
void __attribute__((interrupt, no_auto_psv)) _INT0Interrupt(void)
{
    Int0_Clear_Intr_Status_Bit;
    IRQServerINT0();
    Random++;
}

void __attribute__ ((interrupt,no_auto_psv)) _INT1Interrupt(void)
{
    Int1_Clear_Intr_Status_Bit;
    IRQServerINT1();
    Random++;
}

void __attribute__ ((interrupt,no_auto_psv)) _INT2Interrupt(void)
{
    Int2_Clear_Intr_Status_Bit;
    IRQServerINT2();
    Random++;
}

void __attribute__ ((interrupt,no_auto_psv)) _INT3Interrupt(void)
{
    Int3_Clear_Intr_Status_Bit;
    IRQServerINT3();
    Random++;
}

void __attribute__ ((interrupt,no_auto_psv)) _INT4Interrupt(void)
{
    Int4_Clear_Intr_Status_Bit;
    IRQServerINT4();
    Random++;
}


//Config: RISING_EDGE_INT/FALLING_EDGE_INT
void INT0Config(unsigned char Config, IRQServerFT Fuc)
{

}

void INT1Config(unsigned char Config, IRQServerFT Fuc)
{

}

void INT2Config(unsigned char Config, IRQServerFT Fuc)
{

}

void INT3Config(unsigned char Config, IRQServerFT Fuc)
{

}

void INT4Config(unsigned char Config, IRQServerFT Fuc)
{

}

void INT5Config(unsigned char Config, IRQServerFT Fuc)
{

}

void INT6Config(unsigned char Config, IRQServerFT Fuc)
{

}

void INT7Config(unsigned char Config, IRQServerFT Fuc)
{

}

/**************************************************************************/

IRQServerRecvDataFT IRQServerUart1Receive = IrqServerDefaultRS;
IRQServerRecvDataFT IRQServerUart2Receive = IrqServerDefaultRS;
IRQServerRecvDataFT IRQServerUart3Receive = IrqServerDefaultRS;
IRQServerRecvDataFT IRQServerUart4Receive = IrqServerDefaultRS;

void set_IRQServerUart2Receive(IRQServerRecvDataFT fun)
{
    IRQServerUart2Receive = fun;
}

void __attribute__ ((interrupt,no_auto_psv)) _U1RXInterrupt(void)
{
    unsigned char rx_data;
    U1RX_Clear_Intr_Status_Bit;
    while(!DataRdyUART1());
    rx_data = U1RXREG;
    IRQServerUart1Receive(rx_data);
    Random += rx_data;
}

void __attribute__ ((interrupt,no_auto_psv)) _U2RXInterrupt(void)
{
    unsigned char rx_data;
    U2RX_Clear_Intr_Status_Bit;
    while(!DataRdyUART2());
    rx_data = U2RXREG;
    IRQServerUart2Receive(rx_data);
    Random += rx_data;
}

void __attribute__ ((interrupt,no_auto_psv)) _U3RXInterrupt(void)
{
    unsigned char rx_data;
    U3RX_Clear_Intr_Status_Bit;
    while(!DataRdyUART3());
    rx_data = U3RXREG;
    IRQServerUart3Receive(rx_data);
    Random += rx_data;
}

void __attribute__ ((interrupt,no_auto_psv)) _U4RXInterrupt(void)
{
    unsigned char rx_data;
    U4RX_Clear_Intr_Status_Bit;
    while(!DataRdyUART4());
    rx_data = U4RXREG;
    IRQServerUart4Receive(rx_data);
    Random += rx_data;
}

#define SUBBAUD
#ifdef SUBBAUD
unsigned int GetBaud(UartBaud Baud)
{
    unsigned long ubrg = 0;

    ubrg =  ((unsigned long) DEF_MAIN_CLK) >> 5;
    switch(Baud)
    {
    case UartBaud1200:
        ubrg = (ubrg / 1200) - 1;
        break;
    case UartBaud2400:
        ubrg = (ubrg / 2400) - 1;
        break;
    case UartBaud4800:
        ubrg = (ubrg / 4800) - 1;
        break;
    case UartBaud9600:
        ubrg = (ubrg / 9600) - 1;
        break;
    case UartBaud19200:
        ubrg = (ubrg / 19200) - 1;
        break;
    case UartBaud38400:
        ubrg = (ubrg / 38400) - 1;
        break;
    case UartBaud115200:
        ubrg = (ubrg / 115200) -1 ;
        break;
    case UartBaud128000:
        ubrg = (ubrg / 115200) -1 ;
        break;
    case UartBaud62500:
        ubrg = (ubrg / 62500) - 1;
        break;
    default:
        break;
    }
    return (unsigned int)ubrg;
}
#endif
void Uart1Config(pUartMode Mode, IRQServerSendDataFT SendFun, IRQServerRecvDataFT RecvFun)
{
    unsigned int config1=0;
    unsigned int config2=0;
    unsigned int ubrg=0;
    config1 |= UART_EN;
    //�??�??�??
    if((Mode->Parity == PARITY_NONE)&&(Mode->DataBit == DATA_8))
    {
        config1 |= UART_NO_PAR_8BIT;
    }
    else if((Mode->Parity == PARITY_ODD)&&(Mode->DataBit == DATA_8))
    {
        config1 |= UART_ODD_PAR_8BIT;
    }
    else if((Mode->Parity == PARITY_EVEN)&&(Mode->DataBit == DATA_8))
    {
        config1 |= UART_EVEN_PAR_8BIT;
    }
    else if((Mode->Parity == PARITY_NONE)&&(Mode->DataBit == DATA_9))
    {
        config1 |= UART_NO_PAR_9BIT;
    }

    //???�??
    if(Mode->StopBit == STOP_1)
    {
        config1 |= UART_1STOPBIT;
    }
    else if(Mode->StopBit == STOP_2)
    {
        config1 |= UART_2STOPBITS;
    }

    config2 |= UART_TX_ENABLE;

#ifdef SUBBAUD
    ubrg = GetBaud(Mode->Baud);
#else
    switch(Mode->Baud)
    {
    case UartBaud1200:
        ubrg = ((DEF_MAIN_CLK/2)/(16*1200))-1;
        break;
    case UartBaud2400:
        ubrg = ((DEF_MAIN_CLK/2)/(16*2400))-1;
        break;
    case UartBaud4800:
        ubrg = ((DEF_MAIN_CLK/2)/(16*4800))-1;
        break;
    case UartBaud9600:
        ubrg = ((DEF_MAIN_CLK/2)/(16*9600))-1;
        break;
    case UartBaud19200:
        ubrg = ((DEF_MAIN_CLK/2)/(16*19200))-1;
        break;
    case UartBaud38400:
        ubrg = ((DEF_MAIN_CLK/2)/(16*38400))-1;
        break;
    case UartBaud115200:
        ubrg = ((DEF_MAIN_CLK/2)/(16*115200))-1;
        break;
    default:
        break;
    }
#endif
    CloseUART1();
    ConfigIntUART1( UART_RX_INT_EN | UART_RX_INT_PR3);
    OpenUART1(config1 , config2, ubrg);

    IRQServerUart1Receive = RecvFun;
}

void Uart2Config(pUartMode Mode, IRQServerSendDataFT SendFun, IRQServerRecvDataFT RecvFun)
{
   unsigned int config1=0; 
    unsigned int config2=0;
    unsigned int ubrg=0;
    config1 |= UART_EN;
    //�??�??�??
    if((Mode->Parity == PARITY_NONE)&&(Mode->DataBit == DATA_8))
    {
        config1 |= UART_NO_PAR_8BIT;
    }
    else if((Mode->Parity == PARITY_ODD)&&(Mode->DataBit == DATA_8))
    {
        config1 |= UART_ODD_PAR_8BIT;
    }
    else if((Mode->Parity == PARITY_EVEN)&&(Mode->DataBit == DATA_8))
    {
        config1 |= UART_EVEN_PAR_8BIT;
    }
    else if((Mode->Parity == PARITY_NONE)&&(Mode->DataBit == DATA_9))
    {
        config1 |= UART_NO_PAR_9BIT;
    }

    //???�??
    if(Mode->StopBit == STOP_1)
    {
        config1 |= UART_1STOPBIT;
    }
    else if(Mode->StopBit == STOP_2)
    {
        config1 |= UART_2STOPBITS;
    }
    config2 |= UART_TX_ENABLE;
#ifdef SUBBAUD
    ubrg = GetBaud(Mode->Baud);
#else
    switch(Mode->Baud)
    {
    case UartBaud1200:
        ubrg = ((DEF_MAIN_CLK/2)/(16*1200))-1;
        break;
    case UartBaud2400:
        ubrg = ((DEF_MAIN_CLK/2)/(16*2400))-1;
        break;
    case UartBaud4800:
        ubrg = ((DEF_MAIN_CLK/2)/(16*4800))-1;
        break;
    case UartBaud9600:
        ubrg = ((DEF_MAIN_CLK/2)/(16*9600))-1;
        break;
    case UartBaud19200:
        ubrg = ((DEF_MAIN_CLK/2)/(16*19200))-1;
        break;
    case UartBaud38400:
        ubrg = ((DEF_MAIN_CLK/2)/(16*38400))-1;
        break;
    case UartBaud115200:
        ubrg = ((DEF_MAIN_CLK/2)/(16*115200))-1;
        break;
    default:
        break;
    }
#endif
    CloseUART2();
    ConfigIntUART2( UART_RX_INT_EN | UART_RX_INT_PR3);
    OpenUART2(config1 , config2, ubrg);
    IRQServerUart2Receive = RecvFun;
}

void Uart3Config(pUartMode Mode, IRQServerSendDataFT SendFun, IRQServerRecvDataFT RecvFun)
{
   unsigned int config1=0; 
    unsigned int config2=0;
    unsigned int ubrg=0;
    config1 |= UART_EN;
    //�??�??�??
    if((Mode->Parity == PARITY_NONE)&&(Mode->DataBit == DATA_8))
    {
        config1 |= UART_NO_PAR_8BIT;
    }
    else if((Mode->Parity == PARITY_ODD)&&(Mode->DataBit == DATA_8))
    {
        config1 |= UART_ODD_PAR_8BIT;
    }
    else if((Mode->Parity == PARITY_EVEN)&&(Mode->DataBit == DATA_8))
    {
        config1 |= UART_EVEN_PAR_8BIT;
    }
    else if((Mode->Parity == PARITY_NONE)&&(Mode->DataBit == DATA_9))
    {
        config1 |= UART_NO_PAR_9BIT;
    }

    //???�??
    if(Mode->StopBit == STOP_1)
    {
        config1 |= UART_1STOPBIT;
    }
    else if(Mode->StopBit == STOP_2)
    {
        config1 |= UART_2STOPBITS;
    }
    config2 |= UART_TX_ENABLE;

#ifdef SUBBAUD
    ubrg = GetBaud(Mode->Baud);
#else
    switch(Mode->Baud)
    {
    case UartBaud1200:
        ubrg = ((DEF_MAIN_CLK/2)/(16*1200))-1;
        break;
    case UartBaud2400:
        ubrg = ((DEF_MAIN_CLK/2)/(16*2400))-1;
        break;
    case UartBaud4800:
        ubrg = ((DEF_MAIN_CLK/2)/(16*4800))-1;
        break;
    case UartBaud9600:
        ubrg = ((DEF_MAIN_CLK/2)/(16*9600))-1;
        break;
    case UartBaud19200:
        ubrg = ((DEF_MAIN_CLK/2)/(16*19200))-1;
        break;
    case UartBaud38400:
        ubrg = ((DEF_MAIN_CLK/2)/(16*38400))-1;
        break;
    case UartBaud115200:
        ubrg = ((DEF_MAIN_CLK/2)/(16*115200))-1;
        break;
    default:
        break;
    }
#endif
    CloseUART3();
    ConfigIntUART3( UART_RX_INT_EN | UART_RX_INT_PR3);
    OpenUART3(config1 , config2, ubrg);
    IRQServerUart3Receive = RecvFun;
}

void Uart4Config(pUartMode Mode, IRQServerSendDataFT SendFun, IRQServerRecvDataFT RecvFun)
{
   unsigned int config1=0; 
    unsigned int config2=0;
    unsigned int ubrg=0;
    config1 |= UART_EN;
    //�??�??�??
    if((Mode->Parity == PARITY_NONE)&&(Mode->DataBit == DATA_8))
    {
        config1 |= UART_NO_PAR_8BIT;
    }
    else if((Mode->Parity == PARITY_ODD)&&(Mode->DataBit == DATA_8))
    {
        config1 |= UART_ODD_PAR_8BIT;
    }
    else if((Mode->Parity == PARITY_EVEN)&&(Mode->DataBit == DATA_8))
    {
        config1 |= UART_EVEN_PAR_8BIT;
    }
    else if((Mode->Parity == PARITY_NONE)&&(Mode->DataBit == DATA_9))
    {
        config1 |= UART_NO_PAR_9BIT;
    }

    //???�??
    if(Mode->StopBit == STOP_1)
    {
        config1 |= UART_1STOPBIT;
    }
    else if(Mode->StopBit == STOP_2)
    {
        config1 |= UART_2STOPBITS;
    }
    config2 |= UART_TX_ENABLE;
#ifdef SUBBAUD
    ubrg = GetBaud(Mode->Baud);
#else
    switch(Mode->Baud)
    {
    case UartBaud1200:
        ubrg = ((DEF_MAIN_CLK/2)/(16*1200))-1;
        break;
    case UartBaud2400:
        ubrg = ((DEF_MAIN_CLK/2)/(16*2400))-1;
        break;
    case UartBaud4800:
        ubrg = ((DEF_MAIN_CLK/2)/(16*4800))-1;
        break;
    case UartBaud9600:
        ubrg = ((DEF_MAIN_CLK/2)/(16*9600))-1;
        break;
    case UartBaud19200:
        ubrg = ((DEF_MAIN_CLK/2)/(16*19200))-1;
        break;
    case UartBaud38400:
        ubrg = ((DEF_MAIN_CLK/2)/(16*38400))-1;
        break;
    case UartBaud115200:
        ubrg = ((DEF_MAIN_CLK/2)/(16*115200))-1;
        break;
    default:
        break;
    }
#endif
    CloseUART4();
    ConfigIntUART4( UART_RX_INT_EN | UART_RX_INT_PR3);
    OpenUART4(config1 , config2, ubrg);
    IRQServerUart4Receive = RecvFun;
}

void Uart1SendEnable(void)
{
    EnableIntU1TX;
}

void Uart1SendDisable(void)
{
   DisableIntU1TX;
}

void Uart1ReceiveEnable(void)
{
   EnableIntU1RX; 
}

void Uart1ReceiveDisable(void)
{
   DisableIntU1RX;
}

void Uart2SendEnable(void)
{
   EnableIntU2TX;
}

void Uart2SendDisable(void)
{
   DisableIntU2TX;
}

void Uart2ReceiveEnable(void)
{
    EnableIntU2RX;
}

void Uart2ReceiveDisable(void)
{
    DisableIntU2RX;
}

void Uart3SendEnable(void)
{
    EnableIntU3TX;
}

void Uart3SendDisable(void)
{
   DisableIntU3TX;
}

void Uart3ReceiveEnable(void)
{
   EnableIntU3RX;
}

void Uart3ReceiveDisable(void)
{
   DisableIntU3RX;
}
void Uart4SendEnable(void)
{
   EnableIntU4TX;
}

void Uart4SendDisable(void)
{
   DisableIntU4TX;
}

void Uart4ReceiveEnable(void)
{
   EnableIntU4RX;
}

void Uart4ReceiveDisable(void)
{
   DisableIntU4RX;
}

// USB
int Uart1SendData(unsigned char*pSendBuf,unsigned int Len)
{ 
   while (Len!=0) {
      while(BusyUART1());
      WriteUART1(*pSendBuf++);
      Len--;
   }
   return 1;
}
// RS485
int Uart2SendData(unsigned char*pSendBuf,unsigned int Len)
{
   while (Len!=0) {
      while(BusyUART2());
      WriteUART2(*pSendBuf++);
      Len--;
   }
   return 1;
}
// DEGUG
int Uart3SendData(unsigned char*pSendBuf,unsigned int Len)
{
   while (Len!=0) {
      while(BusyUART3());
      WriteUART3(*pSendBuf++);
      Len--;
   }
   return 1;
}
// IR 
int Uart4SendData(unsigned char*pSendBuf,unsigned int Len)
{
   while (Len!=0) {
      while(BusyUART4());
      WriteUART4(*pSendBuf++);
      Len--;
   }
   return 1;
}



/*
*******************************************************
*******************************************************
*******************************************************
*******************************************************
?¯??
*/
void MCU_SleepEnter(void)
{
    Nop();
    Nop();
    Sleep();    //{__asm__ volatile ("pwrsav #0");}
    Nop();
    Nop();
}
//308??´?¹¦??
void MCU_IntEn(void)
{

}
//308??´?¹¦??
void MCU_IntDis(void)
{

}
/*
*******************************************************

*/
void MCU_Reset(void)
{
    Nop();
    Nop();
    asm volatile("RESET");
    Nop();
    Nop();
    Nop();
}
/*
*******************************************************
 ?µ?÷:¿´??¹·?è??
*/
void MCU_DogCfg(void)
{
    //_WDTPS3 = 1;
//    EnableWDT(WDT_ENABLE);//WDT_DISABLE
}
void MCU_DogReset(void)
{
    ClrWdt();
}
/*
*******************************************************
?µ?÷:  
*/
void MCUPllCfg(void)
{
    int Idx;

#if 1
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 0;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB3 = 0;
    TRISBbits.TRISB4 = 0;
    TRISBbits.TRISB5 = 0;
    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB7 = 0;
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 0;
    TRISBbits.TRISB10 = 0;
    TRISBbits.TRISB11 = 0;
    TRISBbits.TRISB12 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB15 = 0;

    PORTBbits.RB0 = 0;
    PORTBbits.RB1  = 0;
    PORTBbits.RB2  = 0;
    PORTBbits.RB3  = 0;
    PORTBbits.RB4  = 0;
    PORTBbits.RB5  = 0;
    PORTBbits.RB6  = 0;
    PORTBbits.RB7  = 0;
    PORTBbits.RB8  = 0;
    PORTBbits.RB9  = 0;
    PORTBbits.RB10= 0;
    PORTBbits.RB11= 0;
    PORTBbits.RB12= 0;
    PORTBbits.RB13= 0;
    PORTBbits.RB14= 0;
    PORTBbits.RB15= 0;

    TRISCbits.TRISC12  = 0;
    TRISCbits.TRISC15  = 0;

    PORTCbits.RC12= 0;
    PORTCbits.RC13= 0;
    PORTCbits.RC14= 0;
    PORTCbits.RC15= 0;

    TRISDbits.TRISD0  = 0;
    TRISDbits.TRISD1  = 0;
    TRISDbits.TRISD2  = 0;
    TRISDbits.TRISD3  = 0;
    TRISDbits.TRISD4  = 0;
    TRISDbits.TRISD5  = 0;
    TRISDbits.TRISD6  = 0;
    TRISDbits.TRISD7  = 0;
    TRISDbits.TRISD8  = 0;
    TRISDbits.TRISD9  = 0;
    TRISDbits.TRISD10  = 0;
    TRISDbits.TRISD11  = 0;

    PORTDbits.RD0  = 0;
    PORTDbits.RD1  = 0;
    PORTDbits.RD2  = 0;
    PORTDbits.RD3  = 0;
    PORTDbits.RD4  = 0;
    PORTDbits.RD5  = 0;
    PORTDbits.RD6  = 0;
    PORTDbits.RD7  = 0;
    PORTDbits.RD8  = 0;
    PORTDbits.RD9  = 0;
    PORTDbits.RD10= 0;
    PORTDbits.RD11= 0;

    TRISEbits.TRISE0  = 0;
    TRISEbits.TRISE1  = 0;
    TRISEbits.TRISE2  = 0;
    TRISEbits.TRISE3  = 0;
    TRISEbits.TRISE4  = 0;
    TRISEbits.TRISE5  = 0;
    TRISEbits.TRISE6  = 0;
    TRISEbits.TRISE7  = 0;

    PORTEbits.RE0  = 0;
    PORTEbits.RE1  = 0;
    PORTEbits.RE2  = 0;
    PORTEbits.RE3  = 0;
    PORTEbits.RE4  = 0;
    PORTEbits.RE5  = 0;
    PORTEbits.RE6  = 0;
    PORTEbits.RE7  = 0;

    TRISFbits.TRISF0    = 0;
    TRISFbits.TRISF1    = 0;
    TRISFbits.TRISF2    = 0;
    TRISFbits.TRISF3    = 0;
    TRISFbits.TRISF4    = 0;
    TRISFbits.TRISF5    = 0;
    TRISFbits.TRISF6    = 0;

    PORTFbits.RF0  = 0;
    PORTFbits.RF1  = 0;
    PORTFbits.RF2  = 0;
    PORTFbits.RF3  = 0;
    PORTFbits.RF4  = 0;
    PORTFbits.RF5  = 0;
    PORTFbits.RF6  = 0;

    TRISGbits.TRISG2   = 0;
    TRISGbits.TRISG3   = 0;
    TRISGbits.TRISG6   = 0;
    TRISGbits.TRISG7   = 0;
    TRISGbits.TRISG8   = 0;
    TRISGbits.TRISG9   = 0;

    PORTGbits.RG2  = 0;
    PORTGbits.RG3  = 0;
    PORTGbits.RG6  = 0;
    PORTGbits.RG7  = 0;
    PORTGbits.RG8  = 0;
    PORTGbits.RG9  = 0;
#endif

    OSCCONbits.COSC = 0;    // ��ǰ���� = ����RC����(FRC)��Ĭ��2����Ϊ4MHz
    OSCCONbits.NOSC = 0;    // ������   = ����RC����(FRC)
    _OSWEN  = 0;            // ���л���NOSCָ��������
    _SOSCEN = 0;            // ��ʹ��32 kHz��������
    _POSCEN = 0;            // ������������ģʽ�ڼ䱻��ֹ

    _NSTDIS = 1;            // ��ֹ�ж�Ƕ��
    _RETEN  = 1;            // ����ģʽ�����ñ���ģʽ
    
    for(Idx = 0; Idx < 2000; Idx++) {}
}
/*
*******************************************************
#ifdef NEW_CBB_BOARD1
?µ?÷:  ?º¾§:    0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  COM0,COM1,COM2,COM3
             MCU:    48 27 04 05 06 07 26 25 24 23 22  21  20  16  15  14  13  28  47  12  18  COM0,COM1,CPM2,COM3

#else
?µ?÷:  ?º¾§:    0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  COM0,COM1,COM2,COM3
             MCU:    48 27 04 05 06 07 26 25 24 23 22  21  20  17  16  15  14  13  28  47  12  COM0,COM1,CPM2,COM3
#endif
*/
void MCU_LcdCfg(void)   //æ¶²æ?�¶å�??�§�??�å�??
{
    //LCDSEx
    {//¶?¿??ä??
        _SE48 = 1;
        _SE27 = 1;
        _SE04 = 1;
        _SE05 = 1;
        _SE06 = 1;
        _SE07 = 1;
        _SE26 = 1;
        _SE25 = 1;
        _SE24 = 1;
        _SE23 = 1;
        _SE22 = 1;
        _SE21 = 1;
        _SE20 = 1;
#ifdef NEW_CBB_BOARD1
        _SE18 = 1;
#else
        _SE17 = 1;
#endif
        _SE16 = 1;
        _SE15 = 1;
        _SE14 = 1;
        _SE13 = 1;
        _SE28 = 1;
        _SE47 = 1;
        _SE12 = 1;
    }
    LCDCONbits.LCDSIDL = 0;//LCD driver continues to operate in CPU Idle mode
    LCDCONbits.SLPEN = 0;//LCD driver module is enabled in Sleep mode
    LCDCONbits.CS = 1;//Clock Source Select bits:SOSC-------------------
    LCDCONbits.LMUX = 0x03;//1/4 MUX (COM<3:0>)

    //LCDREGbits.CPEN = 0;
    //LCDREGbits.BIAS = 5;
    //LCDREGbits.MODE13 = 1;
    //LCDREGbits.CKSEL = 0;

    //?ä??¼?´æ?÷
    LCDPSbits.WFT = 0;
    LCDPSbits.BIASMD = 0;
    LCDPSbits.LP = 3;//LCDԤ��Ƶ��

    LCDREFbits.LCDIRE = 1;
    LCDREFbits.LCDCST = 0;//¶?±?¶?
    LCDREFbits.LRLAP = 0;//¹¦º?µ?¼¶
    LCDREFbits.LRLBP = 1;//¹¦º?µ?¼¶
    LCDREFbits.LRLAT = 0;
    LCDREFbits.VLCD1PE = 0;
    LCDREFbits.VLCD2PE = 0;
    LCDREFbits.VLCD3PE = 0;
}
void MCU_LcdOpen(void)
{
    LCDCONbits.LCDEN = 1;
}
void MCU_LcdClose(void)
{
    LCDCONbits.LCDEN = 0;
}
void MCU_LcdAllSet(void)
{
    int Idx;
    for (Idx = 0; Idx <= 20; Idx++)
    {
        MCU_LcdWriteReg(Idx, 0xff);
    }
}
void MCU_LcdAllClr(void)
{
    int Idx;
    for (Idx = 0; Idx <= 20; Idx++)
    {
        MCU_LcdWriteReg(Idx, 0);
    }
}
void MCU_LcdWriteReg(unsigned char Seg, unsigned char Reg)
{
    switch (Seg)
    {
#ifdef NEW_CBB_BOARD1
    case  0: _S48C0 = (Reg >> 0); _S48C1 = (Reg >> 1); _S48C2 = (Reg >> 2); _S48C3 = (Reg >> 3); break;
    case  1: _S27C0 = (Reg >> 0); _S27C1 = (Reg >> 1); _S27C2 = (Reg >> 2); _S27C3 = (Reg >> 3); break;
    case  2: _S04C0 = (Reg >> 0); _S04C1 = (Reg >> 1); _S04C2 = (Reg >> 2); _S04C3 = (Reg >> 3); break;
    case  3: _S05C0 = (Reg >> 0); _S05C1 = (Reg >> 1); _S05C2 = (Reg >> 2); _S05C3 = (Reg >> 3); break;
    case  4: _S06C0 = (Reg >> 0); _S06C1 = (Reg >> 1); _S06C2 = (Reg >> 2); _S06C3 = (Reg >> 3); break;
    case  5: _S07C0 = (Reg >> 0); _S07C1 = (Reg >> 1); _S07C2 = (Reg >> 2); _S07C3 = (Reg >> 3); break;
    case  6: _S26C0 = (Reg >> 0); _S26C1 = (Reg >> 1); _S26C2 = (Reg >> 2); _S26C3 = (Reg >> 3); break;
    case  7: _S25C0 = (Reg >> 0); _S25C1 = (Reg >> 1); _S25C2 = (Reg >> 2); _S25C3 = (Reg >> 3); break;
    case  8: _S24C0 = (Reg >> 0); _S24C1 = (Reg >> 1); _S24C2 = (Reg >> 2); _S24C3 = (Reg >> 3); break;
    case  9: _S23C0 = (Reg >> 0); _S23C1 = (Reg >> 1); _S23C2 = (Reg >> 2); _S23C3 = (Reg >> 3); break;
    case 10: _S22C0 = (Reg >> 0); _S22C1 = (Reg >> 1); _S22C2 = (Reg >> 2); _S22C3 = (Reg >> 3); break;
    case 11: _S21C0 = (Reg >> 0); _S21C1 = (Reg >> 1); _S21C2 = (Reg >> 2); _S21C3 = (Reg >> 3); break;
    case 12: _S20C0 = (Reg >> 0); _S20C1 = (Reg >> 1); _S20C2 = (Reg >> 2); _S20C3 = (Reg >> 3); break;
    case 13: _S16C0 = (Reg >> 0); _S16C1 = (Reg >> 1); _S16C2 = (Reg >> 2); _S16C3 = (Reg >> 3); break;
    case 14: _S15C0 = (Reg >> 0); _S15C1 = (Reg >> 1); _S15C2 = (Reg >> 2); _S15C3 = (Reg >> 3); break;
    case 15: _S14C0 = (Reg >> 0); _S14C1 = (Reg >> 1); _S14C2 = (Reg >> 2); _S14C3 = (Reg >> 3); break;
    case 16: _S13C0 = (Reg >> 0); _S13C1 = (Reg >> 1); _S13C2 = (Reg >> 2); _S13C3 = (Reg >> 3); break;
    case 17: _S28C0 = (Reg >> 0); _S28C1 = (Reg >> 1); _S28C2 = (Reg >> 2); _S28C3 = (Reg >> 3); break;
    case 18: _S47C0 = (Reg >> 0); _S47C1 = (Reg >> 1); _S47C2 = (Reg >> 2); _S47C3 = (Reg >> 3); break;
    case 19: _S12C0 = (Reg >> 0); _S12C1 = (Reg >> 1); _S12C2 = (Reg >> 2); _S12C3 = (Reg >> 3); break;
    case 20: _S18C0 = (Reg >> 0); _S18C1 = (Reg >> 1); _S18C2 = (Reg >> 2); _S18C3 = (Reg >> 3); break;
#else
    case  0: _S48C0 = (Reg >> 0); _S48C1 = (Reg >> 1); _S48C2 = (Reg >> 2); _S48C3 = (Reg >> 3); break;
    case  1: _S27C0 = (Reg >> 0); _S27C1 = (Reg >> 1); _S27C2 = (Reg >> 2); _S27C3 = (Reg >> 3); break;
    case  2: _S04C0 = (Reg >> 0); _S04C1 = (Reg >> 1); _S04C2 = (Reg >> 2); _S04C3 = (Reg >> 3); break;
    case  3: _S05C0 = (Reg >> 0); _S05C1 = (Reg >> 1); _S05C2 = (Reg >> 2); _S05C3 = (Reg >> 3); break;
    case  4: _S06C0 = (Reg >> 0); _S06C1 = (Reg >> 1); _S06C2 = (Reg >> 2); _S06C3 = (Reg >> 3); break;
    case  5: _S07C0 = (Reg >> 0); _S07C1 = (Reg >> 1); _S07C2 = (Reg >> 2); _S07C3 = (Reg >> 3); break;
    case  6: _S26C0 = (Reg >> 0); _S26C1 = (Reg >> 1); _S26C2 = (Reg >> 2); _S26C3 = (Reg >> 3); break;
    case  7: _S25C0 = (Reg >> 0); _S25C1 = (Reg >> 1); _S25C2 = (Reg >> 2); _S25C3 = (Reg >> 3); break;
    case  8: _S24C0 = (Reg >> 0); _S24C1 = (Reg >> 1); _S24C2 = (Reg >> 2); _S24C3 = (Reg >> 3); break;
    case  9: _S23C0 = (Reg >> 0); _S23C1 = (Reg >> 1); _S23C2 = (Reg >> 2); _S23C3 = (Reg >> 3); break;
    case 10: _S22C0 = (Reg >> 0); _S22C1 = (Reg >> 1); _S22C2 = (Reg >> 2); _S22C3 = (Reg >> 3); break;
    case 11: _S21C0 = (Reg >> 0); _S21C1 = (Reg >> 1); _S21C2 = (Reg >> 2); _S21C3 = (Reg >> 3); break;
    case 12: _S20C0 = (Reg >> 0); _S20C1 = (Reg >> 1); _S20C2 = (Reg >> 2); _S20C3 = (Reg >> 3); break;
    case 13: _S17C0 = (Reg >> 0); _S17C1 = (Reg >> 1); _S17C2 = (Reg >> 2); _S17C3 = (Reg >> 3); break;
    case 14: _S16C0 = (Reg >> 0); _S16C1 = (Reg >> 1); _S16C2 = (Reg >> 2); _S16C3 = (Reg >> 3); break;
    case 15: _S15C0 = (Reg >> 0); _S15C1 = (Reg >> 1); _S15C2 = (Reg >> 2); _S15C3 = (Reg >> 3); break;
    case 16: _S14C0 = (Reg >> 0); _S14C1 = (Reg >> 1); _S14C2 = (Reg >> 2); _S14C3 = (Reg >> 3); break;
    case 17: _S13C0 = (Reg >> 0); _S13C1 = (Reg >> 1); _S13C2 = (Reg >> 2); _S13C3 = (Reg >> 3); break;
    case 18: _S28C0 = (Reg >> 0); _S28C1 = (Reg >> 1); _S28C2 = (Reg >> 2); _S28C3 = (Reg >> 3); break;
    case 19: _S47C0 = (Reg >> 0); _S47C1 = (Reg >> 1); _S47C2 = (Reg >> 2); _S47C3 = (Reg >> 3); break;
    case 20: _S12C0 = (Reg >> 0); _S12C1 = (Reg >> 1); _S12C2 = (Reg >> 2); _S12C3 = (Reg >> 3); break;
#endif
    }
}
unsigned char MCU_LcdReadReg(unsigned char Seg)
{
    switch (Seg)
    {
#ifdef NEW_CBB_BOARD1
    case 0:  return _S48C0 | (_S48C1 << 1) | (_S48C2 << 2) | (_S48C3 << 3);
    case 1:  return _S27C0 | (_S27C1 << 1) | (_S27C2 << 2) | (_S27C3 << 3);
    case 2:  return _S04C0 | (_S04C1 << 1) | (_S04C2 << 2) | (_S04C3 << 3);
    case 3:  return _S05C0 | (_S05C1 << 1) | (_S05C2 << 2) | (_S05C3 << 3);
    case 4:  return _S06C0 | (_S06C1 << 1) | (_S06C2 << 2) | (_S06C3 << 3);
    case 5:  return _S07C0 | (_S07C1 << 1) | (_S07C2 << 2) | (_S07C3 << 3);
    case 6:  return _S26C0 | (_S26C1 << 1) | (_S26C2 << 2) | (_S26C3 << 3);
    case 7:  return _S25C0 | (_S25C1 << 1) | (_S25C2 << 2) | (_S25C3 << 3);
    case 8:  return _S24C0 | (_S24C1 << 1) | (_S24C2 << 2) | (_S24C3 << 3);
    case 9:  return _S23C0 | (_S23C1 << 1) | (_S23C2 << 2) | (_S23C3 << 3);
    case 10: return _S22C0 | (_S22C1 << 1) | (_S22C2 << 2) | (_S22C3 << 3);
    case 11: return _S21C0 | (_S21C1 << 1) | (_S21C2 << 2) | (_S21C3 << 3);
    case 12: return _S20C0 | (_S20C1 << 1) | (_S20C2 << 2) | (_S20C3 << 3);
    case 13: return _S16C0 | (_S16C1 << 1) | (_S16C2 << 2) | (_S16C3 << 3);
    case 14: return _S15C0 | (_S15C1 << 1) | (_S15C2 << 2) | (_S15C3 << 3);
    case 15: return _S14C0 | (_S14C1 << 1) | (_S14C2 << 2) | (_S14C3 << 3);
    case 16: return _S13C0 | (_S13C1 << 1) | (_S13C2 << 2) | (_S13C3 << 3);
    case 17: return _S28C0 | (_S28C1 << 1) | (_S28C2 << 2) | (_S28C3 << 3);
    case 18: return _S47C0 | (_S47C1 << 1) | (_S47C2 << 2) | (_S47C3 << 3);
    case 19: return _S12C0 | (_S12C1 << 1) | (_S12C2 << 2) | (_S12C3 << 3);
    case 20: return _S18C0 | (_S18C1 << 1) | (_S18C2 << 2) | (_S18C3 << 3);
    default:       return 1;
#else
    case 0:  return _S48C0 | (_S48C1 << 1) | (_S48C2 << 2) | (_S48C3 << 3);
    case 1:  return _S27C0 | (_S27C1 << 1) | (_S27C2 << 2) | (_S27C3 << 3);
    case 2:  return _S04C0 | (_S04C1 << 1) | (_S04C2 << 2) | (_S04C3 << 3);
    case 3:  return _S05C0 | (_S05C1 << 1) | (_S05C2 << 2) | (_S05C3 << 3);
    case 4:  return _S06C0 | (_S06C1 << 1) | (_S06C2 << 2) | (_S06C3 << 3);
    case 5:  return _S07C0 | (_S07C1 << 1) | (_S07C2 << 2) | (_S07C3 << 3);
    case 6:  return _S26C0 | (_S26C1 << 1) | (_S26C2 << 2) | (_S26C3 << 3);
    case 7:  return _S25C0 | (_S25C1 << 1) | (_S25C2 << 2) | (_S25C3 << 3);
    case 8:  return _S24C0 | (_S24C1 << 1) | (_S24C2 << 2) | (_S24C3 << 3);
    case 9:  return _S23C0 | (_S23C1 << 1) | (_S23C2 << 2) | (_S23C3 << 3);
    case 10: return _S22C0 | (_S22C1 << 1) | (_S22C2 << 2) | (_S22C3 << 3);
    case 11: return _S21C0 | (_S21C1 << 1) | (_S21C2 << 2) | (_S21C3 << 3);
    case 12: return _S20C0 | (_S20C1 << 1) | (_S20C2 << 2) | (_S20C3 << 3);
    case 13: return _S17C0 | (_S17C1 << 1) | (_S17C2 << 2) | (_S17C3 << 3);
    case 14: return _S16C0 | (_S16C1 << 1) | (_S16C2 << 2) | (_S16C3 << 3);
    case 15: return _S15C0 | (_S15C1 << 1) | (_S15C2 << 2) | (_S15C3 << 3);
    case 16: return _S14C0 | (_S14C1 << 1) | (_S14C2 << 2) | (_S14C3 << 3);
    case 17: return _S13C0 | (_S13C1 << 1) | (_S13C2 << 2) | (_S13C3 << 3);
    case 18: return _S28C0 | (_S28C1 << 1) | (_S28C2 << 2) | (_S28C3 << 3);
    case 19: return _S47C0 | (_S47C1 << 1) | (_S47C2 << 2) | (_S47C3 << 3);
    case 20: return _S12C0 | (_S12C1 << 1) | (_S12C2 << 2) | (_S12C3 << 3);
    default:       return 1;
#endif
    }
}
/*
*******************************************************
*/
#define ServerIntervalNum   1
IRQServerFT IRQServerTM1[ServerIntervalNum] = { IrqServerDefault };//, IrqServerDefault, IrqServerDefault };//
IRQServerFT IRQServerTM2[ServerIntervalNum] = { IrqServerDefault };//, IrqServerDefault, IrqServerDefault };//
IRQServerFT IRQServerTM3[ServerIntervalNum] = { IrqServerDefault };//, IrqServerDefault, IrqServerDefault };//
IRQServerFT IRQServerTM4[ServerIntervalNum] = { IrqServerDefault };//, IrqServerDefault, IrqServerDefault };//
IRQServerFT IRQServerTM5[ServerIntervalNum] = { IrqServerDefault };//, IrqServerDefault, IrqServerDefault };//

unsigned char Onesec = 0;
unsigned char sec = 0;
unsigned char min = 0;
void __attribute__((interrupt,auto_psv)) _T1Interrupt(void)
{
    unsigned char i;
    T1_Clear_Intr_Status_Bit;
    for (i = 0; i < ServerIntervalNum; i++)
        IRQServerTM1[i]();
    Random++;
}

void __attribute__((interrupt,auto_psv)) _T2Interrupt(void)
{
    unsigned char i;
    T2_Clear_Intr_Status_Bit;
    for (i = 0; i < ServerIntervalNum; i++)
        IRQServerTM2[i]();
    Random++;
}

void __attribute__((interrupt,auto_psv)) _T3Interrupt(void)
{
    unsigned char i;
    T3_Clear_Intr_Status_Bit;
    for (i = 0; i < ServerIntervalNum; i++)
        IRQServerTM3[i]();
    Random++;
}

void __attribute__((interrupt,auto_psv)) _T4Interrupt(void)
{
    unsigned char i;
    T4_Clear_Intr_Status_Bit;
    for (i = 0; i < ServerIntervalNum; i++)
        IRQServerTM4[i]();
    Random++;
}

void __attribute__((interrupt,auto_psv)) _T5Interrupt(void)
{
    unsigned char i;
    T5_Clear_Intr_Status_Bit;
    for (i = 0; i < ServerIntervalNum; i++)
        IRQServerTM5[i]();
    Random++;
}

//?¹??FRC?ñµ´?÷,¶¨?±?÷?¹??64·??µ
#define TIME_SP_CNT_MS1     (62)
#define TIME_SP_CNT_MS10    (610)
#define TIME_SP_CNT_MS20    (610*2)
#define TIME_SP_CNT_MS50    (610*5)
#define TIME_SP_CNT_MS100   (610*10)
#define TIME_SP_CNT_MS500   (610*50)
#define TIME_SP_CNT_MS1000  (800*100U)
#define TIME_SP_CNT_MS2000  (610*200U)
void MCU_TimerCfg(PortNumET TimeNo, TimeSpET Sp, IRQServerFT TimeServer)
{
    unsigned int i;
    unsigned int Space;
    switch(Sp)
    {
        case TimeSpMs1   : Space = TIME_SP_CNT_MS1;    break;
        case TimeSpMs10  : Space = TIME_SP_CNT_MS10;   break;
        case TimeSpMs20  : Space = TIME_SP_CNT_MS20;   break;
        case TimeSpMs50  : Space = TIME_SP_CNT_MS50;   break;
        case TimeSpMs100 : Space = TIME_SP_CNT_MS100;  break;
        case TimeSpMs500 : Space = TIME_SP_CNT_MS500;  break;
        case TimeSpMs1000: Space = TIME_SP_CNT_MS1000; break;
        case TimeSpMs2000: Space = TIME_SP_CNT_MS2000; break;
    }
    switch (TimeNo)
    {
        case PortVmNum1:
            for (i = 0; i < ServerIntervalNum; i++)
            {
                if (IRQServerTM1[i] == IrqServerDefault)
                {
                    IRQServerTM1[i] = TimeServer;
                    break;
                }
            }
            switch (Sp)
            {
                case TimeSpMs1   : Space = 2;    break;
                case TimeSpMs10  : Space = 41;   break;
                case TimeSpMs20  : Space = 82;   break;
                case TimeSpMs50  : Space = 205;  break;
                case TimeSpMs100 : Space = 310;  break;
                case TimeSpMs500 : Space = 2048; break;
                case TimeSpMs1000: Space = 3068; break;
                case TimeSpMs2000: Space = 4072; break;
            }
            ConfigIntTimer1(T1_INT_PRIOR_1 + T1_INT_OFF);
            OpenTimer1(T1_OFF | T1_IDLE_STOP | T1_CLK_SOSC | T1_SOURCE_EXT | T1_PS_1_8, Space);
            break;
        case PortVmNum2:
            for (i = 0; i < ServerIntervalNum; i++)
            {
                if (IRQServerTM2[i] == IrqServerDefault)
                {
                    IRQServerTM2[i] = TimeServer;
                    break;
                }
            }
            ConfigIntTimer2(T2_INT_PRIOR_1 + T2_INT_OFF);
            OpenTimer2(T2_OFF | T2_IDLE_STOP | T2_PS_1_64 | T2_SOURCE_INT, Space);//TSYNC=0;TCS=1;
            break;
        case PortVmNum3:
            for (i = 0; i < ServerIntervalNum; i++)
            {
                if (IRQServerTM3[i] == IrqServerDefault)
                {
                    IRQServerTM3[i] = TimeServer;
                    break;
                }
            }
            ConfigIntTimer3(T3_INT_PRIOR_1 + T3_INT_OFF);
            OpenTimer3(T3_OFF | T3_IDLE_STOP | T3_GATE_OFF | T3_PS_1_64 | T3_SOURCE_INT, Space);
            break;
        case PortVmNum4:
            for (i = 0; i < ServerIntervalNum; i++)
            {
                if (IRQServerTM4[i] == IrqServerDefault)
                {
                    IRQServerTM4[i] = TimeServer;
                    break;
                }
            }
            ConfigIntTimer4(T4_INT_PRIOR_1 + T4_INT_OFF);
            OpenTimer4(T4_OFF | T4_IDLE_STOP | T4_GATE_OFF | T4_PS_1_64 | T4_32BIT_MODE_OFF | T4_SOURCE_INT, Space);
            break;
        case PortVmNum5:
            for (i = 0; i < ServerIntervalNum; i++)
            {
                if (IRQServerTM5[i] == IrqServerDefault)
                {
                    IRQServerTM5[i] = TimeServer;
                    break;
                }
            }
            ConfigIntTimer5(T5_INT_PRIOR_1 + T5_INT_OFF);
            OpenTimer5(T5_OFF | T5_IDLE_STOP | T5_GATE_OFF | T5_PS_1_64 | T5_SOURCE_INT, Space);
            break;
        default:
            break;
    }
}
void MCU_TimerStart(PortNumET TimeNo)
{
    switch (TimeNo)
    {
    case PortVmNum1:
        T1CONbits.TON = 1;
        EnableIntT1;
        break;
    case PortVmNum2:
        T2CONbits.TON = 1;
        EnableIntT2;
        break;
    case PortVmNum3:
        T3CONbits.TON = 1;
        EnableIntT3;
        break;
    case PortVmNum4:
        T4CONbits.TON = 1;
        EnableIntT4;
        break;
    case PortVmNum5:
        T5CONbits.TON = 1;
        EnableIntT5;
        break;
    default:
        break;
    }
}
void MCU_TimerStop(PortNumET TimeNo)
{
    switch (TimeNo)
    {
    case PortVmNum1:
        CloseTimer1();
        DisableIntT1;
        break;
    case PortVmNum2:
        CloseTimer2();
        DisableIntT2;
        break;
    case PortVmNum3:
        CloseTimer3();
        DisableIntT3;
        break;
    case PortVmNum4:
        CloseTimer4();
        DisableIntT4;
        break;
    case PortVmNum5:
        CloseTimer5();
        DisableIntT5;
        break;
    default:
        break;
    }
}
/*
*******************************************************�??
�??    ???     AD???

*/
unsigned short AdcRefVolt = 3300;//ADC�ɼ���׼,��λmV
unsigned char ADChangeBit = 8;
unsigned char ADCStaIsBusy = FALSE;
unsigned int ADCResult; //�?????�??�?DC�??
void __MCU_ADCCfg(PortNumET ADCNum, ADCModeST Mode)   //
{
    UINT channel = 0, config1 = 0, config2 = 0, config3 = 0, config4 = 0, config5 = 0;
    UINT configctmu_low = 0, configctmu_high = 0, configscan_low = 0, config_high = 0;

    CloseADC10();

    /*set adc channel*/
    ANCFGbits.VBGEN = 0; //??VBG
    switch (ADCNum)
    {
    case PortVmNum0:
        channel = ADC_CH0_POS_SAMPLEA_AN0;
        configscan_low = ADC_SCAN_AN0;
        ANSBbits.ANSB0 = 1;//����Ϊģ��
        TRISBbits.TRISB0 = 1;//����Ϊ����
        break;
    case PortVmNum1:
        channel = ADC_CH0_POS_SAMPLEA_AN1;
        configscan_low = ADC_SCAN_AN1;
        ANSBbits.ANSB1 = 1;//����Ϊģ��
        TRISBbits.TRISB1 = 1;//����Ϊ����
        break;
    case PortVmNum2:
        channel = ADC_CH0_POS_SAMPLEA_AN2;
        configscan_low = ADC_SCAN_AN2;
        ANSBbits.ANSB2 = 1;//����Ϊģ��
        TRISBbits.TRISB2 = 1;//����Ϊ����
        break;
    case PortVmNum3:
        channel = ADC_CH0_POS_SAMPLEA_AN3;
        configscan_low = ADC_SCAN_AN3;
        ANSBbits.ANSB3 = 1;//����Ϊģ��
        TRISBbits.TRISB3 = 1;//����Ϊ����
        break;
    case PortVmNum4:
        channel = ADC_CH0_POS_SAMPLEA_AN4;
        configscan_low = ADC_SCAN_AN4;
        ANSBbits.ANSB4 = 1;//����Ϊģ��
        TRISBbits.TRISB4 = 1;//����Ϊ����
        break;
    case PortVmNum5:
        channel = ADC_CH0_POS_SAMPLEA_AN5;
        configscan_low = ADC_SCAN_AN5;
        ANSBbits.ANSB5 = 1;//����Ϊģ��
        TRISBbits.TRISB5 = 1;//����Ϊ����
        break;
    case PortVmNum6:
        channel = ADC_CH0_POS_SAMPLEA_AN6;
        configscan_low = ADC_SCAN_AN6;
        ANSBbits.ANSB6 = 1;//����Ϊģ��
        TRISBbits.TRISB6 = 1;//����Ϊ����
        break;
    case PortVmNum7:
        channel = ADC_CH0_POS_SAMPLEA_AN7;
        configscan_low = ADC_SCAN_AN7;
        ANSBbits.ANSB7 = 1;//����Ϊģ��
        TRISBbits.TRISB7 = 1;//����Ϊ����
        break;
    case PortVmNum8:
        channel = ADC_CH0_POS_SAMPLEA_AN8;
        configscan_low = ADC_SCAN_AN8;
        ANSBbits.ANSB8 = 1;//����Ϊģ��
        TRISBbits.TRISB8 = 1;//����Ϊ����
        break;
    case PortVmNum9:
        channel = ADC_CH0_POS_SAMPLEA_AN9;
        configscan_low = ADC_SCAN_AN9;
        ANSBbits.ANSB9 = 1;//����Ϊģ��
        TRISBbits.TRISB9 = 1;//����Ϊ����
        break;
    case PortVmNum10:
        channel = ADC_CH0_POS_SAMPLEA_AN10;
        configscan_low = ADC_SCAN_AN10;
        ANSBbits.ANSB10 = 1;//����Ϊģ��
        TRISBbits.TRISB10 = 1;//����Ϊ����
        break;
    case PortVmNum11:
        channel = ADC_CH0_POS_SAMPLEA_AN11;
        configscan_low = ADC_SCAN_AN11;
        ANSBbits.ANSB11 = 1;//����Ϊģ��
        TRISBbits.TRISB11 = 1;//����Ϊ����
        break;
    case PortVmNum12:
        channel = ADC_CH0_POS_SAMPLEA_AN12;
        configscan_low = ADC_SCAN_AN12;
        ANSBbits.ANSB12 = 1;//����Ϊģ��
        TRISBbits.TRISB12 = 1;//����Ϊ����
        break;
    case PortVmNum13:
        channel = ADC_CH0_POS_SAMPLEA_AN13;
        configscan_low = ADC_SCAN_AN13;
        ANSBbits.ANSB13 = 1;//����Ϊģ��
        TRISBbits.TRISB13 = 1;//����Ϊ����
        break;
    case PortVmNum14:
        channel = ADC_CH0_POS_SAMPLEA_AN14;
        configscan_low = ADC_SCAN_AN14;
        ANSBbits.ANSB14 = 1;//����Ϊģ��
        TRISBbits.TRISB14 = 1;//����Ϊ����
        break;
    case PortVmNum15:
        channel = ADC_CH0_POS_SAMPLEA_AN15;
        configscan_low = ADC_SCAN_AN15;
        ANSBbits.ANSB15= 1;//����Ϊģ��
        TRISBbits.TRISB15 = 1;//����Ϊ����
        break;
    case PortVmNum25:
        channel = ADC_CH0_POS_SAMPLEA_VBG;
        //configscan_low = ADC_SCAN_VBG;
        ANCFGbits.VBGEN = 1; //??VBG
        break;
    default:
        return;
        break;
    }
    SetChanADC10(channel);

    /*Configure adc*/
   config1 = ADC_MODULE_OFF | ADC_CLK_AUTO |ADC_AUTO_SAMPLING_ON ;
   if (Mode.ADCModeResolution == 1)
   {
       config1 |= ADC_10BIT_MODE;
       ADChangeBit = 10;
   }
   else if (Mode.ADCModeResolution == 2)
   {
       config1 |= ADC_12BIT_MODE;
       ADChangeBit = 12;
   }
   else if (Mode.ADCModeResolution == 0)
   {
       config1 |= ADC_10BIT_MODE;
       ADChangeBit = 8;
   }
   
   config2 = ADC_INTR_EACH_CONV;
   config3 = ADC_EXT_SAMP_OFF | ADC_SAMPLE_TIME_31 | ADC_CONV_CLK_31Tcy;
   config5 = ADC_LOW_POWER_DISABLE | ADC_CTMU_DISABLE;

   if (ADCNum >= PortVmNum25)
       config5 |= ADC_BG_ENABLE;

    OpenADC10(config1, config2, config3, config4, config5,
        configctmu_low, configctmu_high, configscan_low, config_high);

    if (ADCNum >= PortVmNum25)
        AD1CON5bits.BGREQ = 1;
}
unsigned int __MCU_ADCRead(void);
void MCU_ADCCfg(PortNumET ADCNum, ADCModeST Mode)   //
{
    static char ADCCntMax = 4;
    static char ADCCnt = 4;
    static char InitAdcChk = 0;
    char Idx = 0;
    ADCCnt++;
    if (InitAdcChk == 0)
    {
        char Jdx = 0;
        InitAdcChk = 1;
        for (Jdx = 0; Jdx < 30; Jdx++)
        {
            unsigned int Ret = 0, Temp;
            unsigned short RefTemp;
            ADCModeST ADCMode;
            ADCCnt = 0;
            ADCMode.ADCModeResolution = 1;
            __MCU_ADCCfg(PortVmNum25, ADCMode);
            MCU_ADCStart(0);
            __MCU_ADCRead();
            for (Idx = 0; Idx < 2; Idx++)
            {
                Temp = __MCU_ADCRead();
                if (Temp == 0)
                    break;
                Ret += Temp;
            }
            if (Idx == 2)
                Ret >>= 1;
            RefTemp = (unsigned short)(((unsigned long long)1024)*((unsigned long long)1200) / ((unsigned long long)Ret));
            if ((RefTemp <= 3400) && (RefTemp >= 1700))
            {
                AdcRefVolt += RefTemp;
                AdcRefVolt >>= 1;
            }
            if (AdcRefVolt >= 3250)
                ADCCntMax = 100;
            else
                ADCCntMax = 1;
            MCU_ADCStop(0);
        }
    }
    else
    {
        if (ADCCnt >= ADCCntMax)
        {
            unsigned int Ret = 0, Temp;
            unsigned short RefTemp;
            ADCModeST ADCMode;
            ADCCnt = 0;
            ADCMode.ADCModeResolution = 1;
            __MCU_ADCCfg(PortVmNum25, ADCMode);
            MCU_ADCStart(0);
            __MCU_ADCRead();
            for (Idx = 0; Idx < 2; Idx++)
            {
                Temp = __MCU_ADCRead();
                if (Temp == 0)
                    break;
                Ret += Temp;
            }
            if (Idx == 2)
                Ret >>= 1;
            RefTemp = (unsigned short)(((unsigned long long)1024)*((unsigned long long)1200) / ((unsigned long long)Ret));
            if ((RefTemp <= 3400) && (RefTemp >= 1700))
            {
                AdcRefVolt += RefTemp;
                AdcRefVolt >>= 1;
            }
            if (AdcRefVolt >= 3250)
                ADCCntMax = 100;
            else
                ADCCntMax = 1;
            MCU_ADCStop(0);
        }
    }
    __MCU_ADCCfg(ADCNum, Mode);
}
void MCU_ADCStart(PortNumET ADCNum)
{
    ADCStaIsBusy = TRUE;
    EnableADC1;
}
void MCU_ADCStop(PortNumET ADCNum)
{
    ADCStaIsBusy = FALSE;
    CloseADC10();
}
unsigned int __MCU_ADCRead(void)
{
    unsigned short OverCnt = 0;

    ConvertADC10();
    while (ADCStaIsBusy == TRUE)/*wait till conversion complete*/
    {
        if (BusySampADC1 == FALSE)
        {
            ADCResult = ReadADC10(0);//ADC1BUF0;
            break;
        }
        OverCnt++;
        if (OverCnt >= 20000)
            return 0;
    }
    if (ADChangeBit == 8)
        ADCResult = ADCResult >> 2;
    Random += ADCResult;
    return ADCResult;
}
unsigned int MCU_ADCRead(void)
{
    char Idx;
    unsigned int Ret = 0, Temp;
    __MCU_ADCRead();
    for (Idx = 0; Idx < 2; Idx++)
    {
        Temp = __MCU_ADCRead();
        if (Temp == 0)
            return 0;
        Ret += Temp;
    }
    return Ret >>= 1;
}
rtccTimeDate RtccTimeDate, RtccTimeDateVal;
int RTCCfg(void)                //è¿??��??��?RUE/FALSE
{
    RtccInitClock(); //turn on clock source
//    mRtccSetIntPriority(4);//set interrupt priority to 4
//    mRtccSetInt(1);//set interrupt
    RtccWrOn(); //enable RTCC peripheral
    mRtccOn();
    return 0;
}
int RTCReadTime(RTC_T* Rtc)     //è¿??��??��?RUE/FALSE
{
    RtccReadTimeDate(&RtccTimeDateVal);
    Rtc->Year = RtccTimeDateVal.f.year;
    Rtc->Mon = RtccTimeDateVal.f.mon;
    Rtc->Day = RtccTimeDateVal.f.mday;
    Rtc->Hour = RtccTimeDateVal.f.hour;
    Rtc->Min = RtccTimeDateVal.f.min;
    Rtc->Sec = RtccTimeDateVal.f.sec;
    Rtc->Week = RtccTimeDateVal.f.wday;
    if (RCON2bits.VBPOR == 1)
        return FALSE;
    return TRUE;
}
int RTCWriteTime(RTC_T* Rtc)    //è¿??��??��?RUE/FALSE
{
    int Time_Input_out_of_range ;
//    RtccReadTimeDate(&RtccTimeDateVal);
    RtccTimeDateVal.f.year = Rtc->Year;
    RtccTimeDateVal.f.mon = Rtc->Mon;
    RtccTimeDateVal.f.mday = Rtc->Day;
    RtccTimeDateVal.f.hour = Rtc->Hour;
    RtccTimeDateVal.f.min = Rtc->Min;
    RtccTimeDateVal.f.sec = Rtc->Sec;
    RtccTimeDateVal.f.wday = Rtc->Week;
    Time_Input_out_of_range = RtccWriteTimeDate(&RtccTimeDateVal, TRUE);
    RCON2bits.VBPOR = 0;
    return Time_Input_out_of_range;
}
void DelayUs(unsigned int Us)
{
    while (Us--)
    {
        Nop();  //4M:for( char i = 0; i < 2; i++ );
        //8M:NOP();
    }
}
void DelayMs(unsigned int Ms)
{
    int i;
    while (Ms)
    {
        for (i = 0; i < 800; i++)  //4M:400.8M:800
            ;
        Ms--;
    }
}
void CBB_NOP(void)
{
    Nop();
}
unsigned short GetRandom(void)
{
    return Random;
}
