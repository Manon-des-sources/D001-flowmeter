#include    "bsp_mc306.h"
#include    "lib_mc306.h"
/*
 *         iPPSInput(IN_FN_PPS_INT1|IN_PIN_PPS_RP16);
        ConfigINT1(FALLING_EDGE_INT |INT_ENABLE|INT_PRI_0);//XXXX;
*/
#if 1
//24FJ128GA306������
_CONFIG4  (0xFE3F);
#ifdef EXT_TIMER_CLOCK
_CONFIG3  (0xFF7F);
#else
_CONFIG3  (0xFFFF);
#endif
_CONFIG2  (0xFA1E);//0xFA1E
_CONFIG1  (0x399F);//0x399F;
#else
//24FJ64GA306������
int CONFIG4 __attribute__((space(prog), address(0xABF8))) = 0xFE3F;
#ifdef EXT_TIMER_CLOCK
int CONFIG3 __attribute__((space(prog), address(0xABFA))) = 0xFF7F;
#else
int CONFIG3 __attribute__((space(prog), address(0xABFA))) = 0xFFFF;
#endif
int CONFIG2 __attribute__((space(prog), address(0xABFC))) = 0xFA1E;//0xFA1E
int CONFIG1 __attribute__((space(prog), address(0xABFE))) = 0x399F;
#endif

extern void IrqServerDefaultRS(unsigned char Data);
extern void IrqServerDefault(void);
//#define USER_CN_IRQ
//RF4
void IM_m2m_Set_MotorSleep_GPIO(unsigned char fun)//���
{
    TRISFbits.TRISF4 = 0;
    ODCFbits.ODF4 = 0;
    if (fun == 1)
    {
        LATFbits.LATF4 = 1;
    }
    else
    {
        LATFbits.LATF4 = 0;
    }
}
//RF5
void IM_m2m_Set_MotorOpen_GPIO(unsigned char fun)//���
{
    TRISFbits.TRISF5 = 0;
    ODCFbits.ODF5 = 0;
    if (fun == 1)
    {
        LATFbits.LATF5 = 1;
    }
    else
    {
        LATFbits.LATF5 = 0;
    }
}
//RF2
void IM_m2m_Set_MotorClose_GPIO(unsigned char fun)//���
{
    TRISFbits.TRISF2 = 0;
    ODCFbits.ODF2 = 0;
    if (fun == 1)
    {
        LATFbits.LATF2 = 1;
    }
    else
    {
        LATFbits.LATF2 = 0;
    }
}
#ifdef NEW_CBB_BOARD1
//RE4
#else
//RB12
#endif
void BspBeepOn(void)//���
{
#ifdef NEW_CBB_BOARD1
    TRISEbits.TRISE4 = 0;
    ANSEbits.ANSE4 = 0;
    ODCEbits.ODE4 = 0;
    LATEbits.LATE4 = 1;
#else
    TRISBbits.TRISB12 = 0;
    ANSBbits.ANSB12 = 0;
    ODCBbits.ODB12 = 0;
    LATBbits.LATB12 = 1;
#endif
}
void BspBeepOff(void)//���
{
#ifdef NEW_CBB_BOARD1
    TRISEbits.TRISE4 = 0;
    ANSEbits.ANSE4 = 0;
    ODCEbits.ODE4 = 0;
    LATEbits.LATE4 = 0;
#else
    TRISBbits.TRISB12 = 0;
    ANSBbits.ANSB12 = 0;
    ODCBbits.ODB12 = 0;
    LATBbits.LATB12 = 0;
#endif
}
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//�޺��޺��޺��޺��޺��޺��޺��޺��޺��޺��޺��޺��޺��޺��޺��޺��޺��޺�
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------
//Һ��Һ��Һ��Һ��Һ��Һ��Һ��Һ��Һ��
//------------------------------------
//����Һ����ʾ
void LcdOn(void)//���
{
    MCU_LcdOpen();
}
//�ر�Һ����ʾ
void LcdOff(void)//���
{
    MCU_LcdClose();
}
//��ײ�Һ����ʾ�Ĵ�����д����ֵ
//x���Ĵ�����ַ
//reg���Ĵ���ֵ
void LcdWriteReg(unsigned char x, unsigned char reg)//���
{
    MCU_LcdWriteReg(x, reg);
}
//��ȡ�Ĵ�����ַ�е�ֵ
unsigned char LcdReadReg(unsigned char x)//���
{
    return MCU_LcdReadReg(x);
}
//Һ���ײ��ʼ��
void LcdInit(void)//���
{
    {   //���Ӳ������Ӧ�˿�����ΪҺ����
 
    }
    MCU_LcdCfg();
}
//------------------------------------
//����������������������������
//------------------------------------
//�жϻص�����
//
#ifdef USER_CN_IRQ
extern IRQServerFT IRQServerCN9;
extern IRQServerFT IRQServerCN10;
#else
extern IRQServerFT IRQServerINT2;
extern IRQServerFT IRQServerINT3;
#endif
//HALLA:RG8/CN10
//HALLB:RG7/CN9
void HallAInt(void);
void HallBInt(void);
//��ȡ����io��״̬
unsigned char GpioHallARead(void)//���
{
    return (PORTGbits.RG8);//XXXX
}
unsigned char GpioHallBRead(void)//���
{
    return (PORTGbits.RG7);//XXXX
}
//�ı��жϴ�������
//0�������أ�1���½���
void HallASetInt(unsigned char c,void(*p)(void))//���
{
    TRISGbits.TRISG8 = 1;
    ANSGbits.ANSG8 = 0;
    ODCGbits.ODG8 = 0;
#ifdef USER_CN_IRQ
    InputChange_Clear_Intr_Status_Bit;
    ConfigIntCN(INT_ENABLE | INT_PRI_4);//XXXX;
    CNEN1bits.CN10IE = 1;
    IRQServerCN10 = p;
#else
    RPINR1bits.INT2R = 19;//rp19;
    ConfigINT2(FALLING_EDGE_INT | INT_ENABLE | INT_PRI_3);
    IRQServerINT2 = p;//rp19
#endif
}
void HallBSetInt(unsigned char c,void(*p)(void))//���
{
    TRISGbits.TRISG7 = 1;
    ANSGbits.ANSG7 = 0;
    ODCGbits.ODG7 = 0;
#ifdef USER_CN_IRQ
    InputChange_Clear_Intr_Status_Bit;
    ConfigIntCN(INT_ENABLE | INT_PRI_4);//XXXX;
    CNEN1bits.CN9IE = 1;
    IRQServerCN9 = p;
#else
    RPINR1bits.INT3R = 26;//rp26;
    ConfigINT3(FALLING_EDGE_INT | INT_ENABLE | INT_PRI_3);
    IRQServerINT3 = p;//rp26
#endif
}
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//�����κ����κ����κ����κ����κ����κ����κ����κ����κ����κ����κ�����
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------
//CPU��CPU��CPU��CPU��CPU��CPU��CPU��
//------------------------------------
/*
*/
/*void CardSdaInput(void);        //SDA�ţ�IO����Ϊ����
void CardSdaOutput(void);       //SDA�ţ�IO����Ϊ���
void CardSdaSet(void);          //SDA�ţ�IO������ߵ�ƽ
void CardSdaReset(void);        //SDA�ţ�IO������͵�ƽ
unsigned char CardSdaRead(void);//SDA�ţ���IO�ڵ�ƽ
void CardRstSet(void);          //RST�ţ�IO������ߵ�ƽ
void CardRstReset(void);        //RST�ţ�IO������͵�ƽ */
//CLK���ϵ���Ϊ�����Ҫ�����Ƶ����500HZ���� 
//NOP;

//------------------------------------
//1608��1608��1608��1608��1608��1608��
//------------------------------------
/*
 * RST:RB7
 * CHK:RB8;CN26
 * SDA:RB10
 * SCL:RB9
 * ERR:RB6
 * POW:RB11
*/
#ifdef USER_CN_IRQ
extern IRQServerFT IRQServerCN26;
#else
extern IRQServerFT IRQServerINT1;
#endif
//�忨�ж� 0�������أ�1���½���
void CardIntConfig(unsigned char c,void(*p)(void))//CHK//���
{
    TRISBbits.TRISB8 = 1;
    ANSBbits.ANSB8 = 0;
    ODCBbits.ODB8 = 0;
#ifdef USER_CN_IRQ
    InputChange_Clear_Intr_Status_Bit;
    ConfigIntCN(INT_ENABLE | INT_PRI_4);//XXXX;
    CNEN2bits.CN26IE = 1;
    IRQServerCN26 = p;
#else
    RPINR0bits.INT1R = 8;//RP8;
    ConfigINT1(FALLING_EDGE_INT | INT_ENABLE | INT_PRI_3);
    IRQServerINT1 = p;
#endif
}
unsigned char CardBslRead(void)//���
{
    if (PORTBbits.RB8)//XXXX
        return 1;
    else
        return 0;
}
void CardSclOutput(void)//���
{
    TRISBbits.TRISB9 = 0;
    ANSBbits.ANSB9 = 0;
    ODCBbits.ODB9 = 0;
}
void CardSclSet(void)//���
{
    LATBbits.LATB9 = 1;
}
void CardSclClr(void)
{
    LATBbits.LATB9 = 0;
}
void CardRstOutput(void)//���
{
    TRISBbits.TRISB7 = 0;
    ANSBbits.ANSB7 = 0;
    ODCBbits.ODB7 = 0;
}
void CardRstSet(void)//���
{
    LATBbits.LATB7 = 1;
}
void CardRstClr(void)//���
{
    LATBbits.LATB7 = 0;
}
void CardSdaSet(void)//���
{
    LATBbits.LATB10 = 1;
}
void CardSdaClr(void)//���
{
    LATBbits.LATB10 = 0;
}
void CardSdaOutput(void)//���
{
    TRISBbits.TRISB10 = 0;
    ANSBbits.ANSB10 = 0;
    ODCBbits.ODB10 = 0;
}
void CardSdaInput(void)//���
{
    TRISBbits.TRISB10 = 1;
    ANSBbits.ANSB10 = 0;
    ODCBbits.ODB10 = 0;
}
unsigned char CardSdaRead(void)//���
{
    if (PORTBbits.RB10)//XXXX
        return 1;
    else
        return 0;
}
void CardPowerCheckInput(void)//���
{
    TRISBbits.TRISB6 = 1;
    ANSBbits.ANSB6 = 0;
    ODCBbits.ODB6 = 0;
}
unsigned char CardPowerCheckRead(void)//���
{
    if (PORTBbits.RB6)//XXXX
        return 1;
    else
        return 0;
}
void CardPowerContrlOutput(void)//���
{
    TRISBbits.TRISB11 = 0;
    ANSBbits.ANSB11 = 0;
    ODCBbits.ODB11 = 0;
}
void CardPowerContrlSet(void)//���
{
    LATBbits.LATB11 = 1;
}
void CardPowerContrlClr(void)//���
{
    LATBbits.LATB11 = 0;
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//������������������������������������������������������������������������
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------
//nand flash nand flash nand flash
//------------------------------------
//�����/��
#define FLASH_CS(a)
//�����/��
#define FLASH_WP(a)
//�����/��
#define FLASH_MOSI(a)
//�����/��
#define FLASH_CLK(a)
//�����/��
#define FLASH_POWER(a)
//����
#define FLASH_MISO()

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//��ع?��ع?��ع?��ع?��ع?��ع?��ع?��ع?��ع?��ع?��ع?��ع?
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------
//ADCADCADCADCADCADCADCADCADCADCADCADC
//------------------------------------
//RB13
void IO_VBB_CHK_EN_DIR_OUT(void)
{
    TRISBbits.TRISB13 = 0;
    ANSBbits.ANSB13 = 0;
    ODCBbits.ODB13 = 0;
}
void IO_VBB_CHK_EN_1(void)
{
    LATBbits.LATB13 = 1;
}
void IO_VBB_CHK_EN_0(void)
{
    LATBbits.LATB13 = 0;
}
/**
* @declare ADC��ʼ��
*
* @author Administrator (2014-11-03)
*
* @requirements
*
* @param ADC_InitStruct ADC������Ϣ
*/
//GATE:AN15;RB15
//SYS:AN14;RB14
void OA_ADC_Init(ADC_InitTypeDef* ADC_InitStruct)//���
{
    ADCModeST ADCMode;
    ADCMode.ADCModeOpt = ADC_InitStruct->ADCModeConversionMode;
    if (ADC_InitStruct->ADCModeConversionBit == 8)
        ADCMode.ADCModeResolution = 0;
    else if (ADC_InitStruct->ADCModeConversionBit == 10)
        ADCMode.ADCModeResolution = 1;
    else 
        ADCMode.ADCModeResolution = 2;

    if (ADC_InitStruct->ADCModeChannel == 1)//����
    {
        MCU_ADCCfg(PortVmNum15, ADCMode);
    }
    else//ϵͳ
    {
        MCU_ADCCfg(PortVmNum14, ADCMode);
    }
}
/**
* @declare ʹ�ܻ���ʧ��ָ����ADC
*
* @author Administrator (2014-11-03)
*
* @requirements
*
* @param NewState ����ADCx����״̬
*/
void OA_ADC_CMD(unsigned char NewState)//���
{
    if (NewState == DISABLE)
        MCU_ADCStop(0);
    else
        MCU_ADCStart(0);
}
/**
* @declare �������һ��ADCx��ת�����
*
* @author Administrator (2014-11-03)
*
* @requirements
*
* @return unsigned short 16λģʽADC���ؽṹ
*/
unsigned short OA_ADC_GetConversionValue(void)//���
{
    return MCU_ADCRead();
}
/**
* @declare ��ȡADCת��״̬
*
* @author Administrator (2014-11-03)
*
* @requirements
*
*
* @return unsigned char ת����ɷ���0;����ת���з���1
*/
unsigned char OA_ADC_GetConversionState(void)//���
{
    if (BusySampADC1 == FALSE)
        return 0;
    else
        return 1;
}
/**
* @declare ����ADCת��ͨ��
*
* @author ZYX (2014/11/6)
*
* requirements
*
* @param channel ADCת��ͨ��:0
*/
typedef enum
{
    ADCCHANNELVOLT = 0,
    ADCCHANNELCUR,
}ADCChannelET;

void OA_ADC_SetConversionChannel(unsigned char channel)//���
{
    if (channel == 1)//����
    {
        ANSBbits.ANSB15= 1;//����Ϊģ��
        TRISBbits.TRISB15 = 1;//����Ϊ����
        SetChanADC10(ADC_CH0_POS_SAMPLEA_AN15);
    }
    else//ϵͳ
    {
        ANSBbits.ANSB14 = 1;//����Ϊģ��
        TRISBbits.TRISB14 = 1;//����Ϊ����
        SetChanADC10(ADC_CH0_POS_SAMPLEA_AN14);
    }
}

//
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//115 115 115 115 115 115 115 115 115 115 115 115 115 115 115 115 115 115 
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//prt:0��ʾEEPROM/RTC8025Tģ���;1��ʾICCARDģ���
//EEPROM/8025
//POW:RE5
//SDA:RE6
//SCL:RG6
//I2C��Դ�������   
void IM_IICPWR_OUT(unsigned char prt) //prt,0:1��ģ���,1:2��ģ���//���
{
    if (prt)
    {

    }
    else
    {
        TRISEbits.TRISE5 = 0;
        ANSEbits.ANSE5 = 0;
        ODCEbits.ODE5 = 0;
    }
}
//I2C��Դ��������
void IM_IICPWR_UP(unsigned char prt) //prt,0:1��ģ���,1:2��ģ���
{
    if (prt)
    {

    }
    else
    {

    }
}
//I2C��Դ��������
void IM_IICPWR_DOWN(unsigned char prt) //prt,0:1��ģ���,1:2��ģ���
{
    if (prt)
    {
    }
    else
    {
    }
}
//I2C��Դ�����
void IM_IICPWR_ON(unsigned char prt) //prt,0:1��ģ���,1:2��ģ���
{
    if (prt)
    {

    }
    else
    {
        LATEbits.LATE5 = 0;
    }
}
//I2C��Դ�����
void IM_IICPWR_OFF(unsigned char prt) //prt,0:1��ģ���,1:2��ģ���
{
    if (prt)
    {

    }
    else
    {
        LATEbits.LATE5 = 1;
    }
}    
//prt,0:1��ģ���,1:2��ģ���
void IM_IICSCL_OUT(unsigned char prt)
{
    if (prt)
    {

    }
    else
    {
        TRISGbits.TRISG6 = 0;
        ANSGbits.ANSG6 = 0;
        ODCGbits.ODG6 = 0;
    }
}
//prt,0:1��ģ���,1:2��ģ���
void IM_IICSCL_IN(unsigned char prt)
{
    if (prt)
    {

    }
    else
    {
        TRISGbits.TRISG6 = 1;
        ANSGbits.ANSG6 = 0;
        ODCGbits.ODG6 = 0;
    }
}
//prt,0:1��ģ���,1:2��ģ���
void IM_IICSCL_UP(unsigned char prt)
{
    if (prt)
    {

    }
    else
    {

    }
}
// prt,0:1��ģ���,1:2��ģ���
void IM_IICSCL_DOWN(unsigned char prt)
{
    if (prt)
    {
    }
    else
    {
    }
}
// prt,0:1��ģ���,1:2��ģ���
void IM_IICSCL_SET(unsigned char prt)
{
    if (prt)
    {

    }
    else
    {
        LATGbits.LATG6 = 1;
    }
}
// prt,0:1��ģ���,1:2��ģ���
void IM_IICSCL_CLR(unsigned char prt)
{
    if (prt)
    {

    }
    else
    {
        LATGbits.LATG6 = 0;
    }
}
// prt,0:1��ģ���,1:2��ģ���
void IM_IICSDA_OUT(unsigned char prt)
{
    if (prt)
    {

    }
    else
    {
        TRISEbits.TRISE6 = 0;
        ANSEbits.ANSE6 = 0;
        ODCEbits.ODE6 = 0;
    }
}
//prt,0:1��ģ���,1:2��ģ���
void IM_IICSDA_IN(unsigned char prt)
{
    if (prt)
    {

    }
    else
    {
        TRISEbits.TRISE6 = 1;
        ANSEbits.ANSE6 = 0;
        ODCEbits.ODE6 = 0;
    }
}
//prt,0:1��ģ���,1:2��ģ���
void IM_IICSDA_UP(unsigned char prt)
{
    if (prt)
    {

    }
    else
    {

    }
}
// prt,0:1��ģ���,1:2��ģ���
void IM_IICSDA_DOWN(unsigned char prt)
{
    if (prt)
    {
    }
    else
    {
    }
}
// prt,0:1��ģ���,1:2��ģ���
void IM_IICSDA_SET(unsigned char prt)
{
    if (prt)
    {

    }
    else
    {
        LATEbits.LATE6 = 1;
    }
}
// prt,0:1��ģ���,1:2��ģ���
void IM_IICSDA_CLR(unsigned char prt)
{
    if (prt)
    {

    }
    else
    {
        LATEbits.LATE6 = 0;
    }
}
// prt,0:1��ģ���,1:2��ģ���
unsigned char IM_IICSDA_STU(unsigned char prt)
{
    if (prt)
    {
        return 1;//XXXX;
    }
    else
    {
        return (PORTEbits.RE6);//XXXX
    }
}
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//������������������������������������������������������������������������
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//typedef void (*ISR_FUNC_PTR)(void);
//type: 0 ��ʱ��       1ms
//type: 1 ��Ƶʱ��     100ms
//len: 0 1ms
//len: 1 100ms
//len: 2 1000ms
void User_TimerCfg(unsigned char type, unsigned char len, IRQServerFT CallBack)
{
    if(type == 0)
    {
        MCU_TimerCfg(PortVmNum2, len, CallBack);//MCU_TimerCfg(PortVmNum8, TimeSpMs100, CallBack);
    }
    else if(type == 1)
    {
        MCU_TimerCfg(PortVmNum1, len, CallBack);
    }
    else if(type == 2)
    {
        MCU_TimerCfg(PortVmNum3, len, CallBack);
    }
}
//type: 0 ��ʱ��
//type: 1 ��Ƶʱ��
void User_TimerStart(unsigned char type)
{
    if (type == 0)
        MCU_TimerStart(PortVmNum2);//MCU_TimerStart(PortVmNum8);
    else
        MCU_TimerStart(PortVmNum1);
}
//type: 0 ��ʱ��
//type: 1 ��Ƶʱ��
void User_TimerStop(unsigned char type)
{
    if (type == 0)
        MCU_TimerStop(PortVmNum2);//MCU_TimerStop(PortVmNum8);
    else
        MCU_TimerStop(PortVmNum1);
}
//extern IRQServerFT IRQServerTM1[3];
//void RegOneSecIRQFun(IRQServerFT TimeServer)
//{
//    int i;
//    for (i = 0; i < 3; i++)
//    {
//        if (IRQServerTM1[i] == IrqServerDefault)
//        {
//            IRQServerTM1[i] = TimeServer;
//            break;
//        }
//    }
//}
void UnusedPinIint(void)
{
    //M_POW
    TRISFbits.TRISF6 = 0;
    ODCFbits.ODF6 = 0;
    LATFbits.LATF6 = 0;
    //M_DETECT1
    TRISCbits.TRISC15 = 0;
    ODCCbits.ODC15 = 0;
    LATCbits.LATC15 = 0;
    //M_DETECT2
    TRISCbits.TRISC12 = 0;
    ODCCbits.ODC12 = 0;
    LATCbits.LATC12 = 0;
    //ESAM_POW   �ߵ�ƽ�ϵ�
    TRISEbits.TRISE7 = 0;
    ANSEbits.ANSE7 = 0;
    ODCEbits.ODE7 = 0;
    LATEbits.LATE7 = 1;
    //ESAM_RST
    TRISGbits.TRISG9 = 0;
    ANSGbits.ANSG9 = 0;
    ODCGbits.ODG9 = 0;
    LATGbits.LATG9 = 0;
}


