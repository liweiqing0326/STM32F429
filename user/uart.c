#include "stm32f4xx_hal.h"
#include <stdarg.h>
#include <stdio.h>
#include "usart.h"
#include "com.h"
#include "uart.h"


#ifdef GNUC

#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch,FILE *f)
#endif

PUTCHAR_PROTOTYPE {
    HAL_UART_Transmit(&huart1, (uint8_t*) &ch, 1, 1000);
    return ch;
}



