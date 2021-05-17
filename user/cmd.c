#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cmd.h"
#include "uart.h"
#include "main.h"

char pos_pin[10];
char neg_pin[127];


void CMD_Help(void) {
    printf("help\r\n");

    printf("*_*\r\n");
}

void CMD_CheckCmd(char *ptr) {
    if (strcmp(ptr, "help\r\n") == 0) {
        CMD_Help();
    } else if (strstr(ptr, "Modbus_test") != NULL) {

    } else {
        printf("command is error,please input 'help' cmd*_*\r\n");
    }
}

