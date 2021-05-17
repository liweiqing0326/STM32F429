#ifndef __COM_H
#define __COM_H

#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <string.h>

#define COMBUFSIZE		  	512
#define RCVTIMEOUT      	10 //ms

extern uint8_t data[512];

typedef struct {
    uint8_t rcv[COMBUFSIZE];
    uint8_t num;
    uint32_t timeStamp ;
} COM_DEF;

extern COM_DEF hcom1;


void COM_init(UART_HandleTypeDef *huart, COM_DEF *hcom);

void COM_RCV(UART_HandleTypeDef *huart, COM_DEF *hcom);

char *COM_Check(COM_DEF *hcom);

#endif
