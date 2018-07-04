#include"drv_uart.h"
#include"md_rs485.h"
#include"md_debug.h"
#include"md_usb.h"
#include"md_ir.h"
#include"config.h"

void drv_uart_init(void)
{
    UartMode Mode;

    // 端口参数配置
    Mode.Baud     = UartBaud9600;
    Mode.DataBit  = DATA_8;
    Mode.Parity   = PARITY_NONE;
    Mode.Sequence = LSB;
    Mode.StopBit  = STOP_1;

    // UART1: USB 转串口
    COM1_TX_OUT;
    COM1_RX_IN;
    iPPSInput(IN_FN_PPS_U1RX, COM1_IN_PIN_PPS);
    iPPSOutput(COM1_OUT_PIN_PPS, OUT_FN_PPS_U1TX);
    Uart1Config(&Mode, IrqServerDefaultRS, md_usb_data_recv);

    // UART2: RS485
    COM2_TX_OUT;
    COM2_RX_IN;
    iPPSInput(IN_FN_PPS_U2RX, COM2_IN_PIN_PPS);
    iPPSOutput(COM2_OUT_PIN_PPS, OUT_FN_PPS_U2TX);
    Uart2Config(&Mode, IrqServerDefaultRS, md_rs485_data_recv);

    // UART4: IR
    COM4_TX_OUT;
    COM4_RX_IN;
    iPPSInput(IN_FN_PPS_U4RX, COM4_IN_PIN_PPS);
    iPPSOutput(COM4_OUT_PIN_PPS, OUT_FN_PPS_U4TX);
    Uart4Config(&Mode, IrqServerDefaultRS, md_ir_data_recv);

    // UART3: DEBUG
    Mode.Baud = UartBaud128000;
    COM3_TX_OUT;
    COM3_RX_IN;
    iPPSInput(IN_FN_PPS_U3RX, COM3_IN_PIN_PPS);
    iPPSOutput(COM3_OUT_PIN_PPS, OUT_FN_PPS_U3TX);
    Uart3Config(&Mode, IrqServerDefaultRS, md_debug_data_recv);
}
