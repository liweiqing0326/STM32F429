#ifndef __CMD_H
#define __CMD_H

#include "stm32f4xx_hal.h"

void CMD_CheckCmd(char *ptr);

extern char pos_pin[10];
extern char neg_pin[127];

#endif

