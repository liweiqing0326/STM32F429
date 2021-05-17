#include "stm32f4xx_hal.h"
#include "usart.h"
#include "com.h"
#include "cmd.h"
#include <string.h>
#include <stdio.h>

COM_DEF hcom1;


/**
  * @brief  COM口初始化
  * @param  huart:串口号
  *			    hcom:COM号
  * @retval 无
  */
void COM_init(UART_HandleTypeDef *huart, COM_DEF *hcom) {
    /* Enable the UART Parity Error Interrupt */
    __HAL_UART_ENABLE_IT(huart, UART_IT_PE);
    /* Enable the UART Error Interrupt: (Frame error, noise error, overrun error) */
    __HAL_UART_ENABLE_IT(huart, UART_IT_ERR);
    /* Enable the UART Data Register not empty Interrupt */
    __HAL_UART_ENABLE_IT(huart, UART_IT_RXNE);

    memset(hcom->rcv, 0, 512);
    hcom->num = 0;
}

/**
  * @brief  获取COM数据
  * @param  huart:串口号
  *			    hcom:COM号
  * @retval 无
  */
void COM_RCV(UART_HandleTypeDef *huart, COM_DEF *hcom) {
    hcom->rcv[hcom->num++] = (uint8_t) (huart->Instance->DR & 0x00FF);
    hcom->timeStamp = HAL_GetTick();
}

/**
  * @brief  解析COM数据
  * @param  hcom:COM号
  * @retval 解析的字符串
  */
char* COM_Check(COM_DEF *hcom) {
    char *pStr = NULL;
    uint8_t data[COMBUFSIZE];
    if (hcom->num > 0) {  
        if ((uint32_t) (HAL_GetTick() - hcom->timeStamp) > RCVTIMEOUT) {
            if (strstr((char*) hcom->rcv, "\r\n") != NULL) {
                memcpy(data, hcom->rcv, COMBUFSIZE);
                pStr = (char*) data;
                hcom->num = 0;
                memset(hcom->rcv, 0, COMBUFSIZE);
									CMD_CheckCmd(pStr);
            } else {
                hcom->num = 0;
                memset(hcom->rcv, 0, COMBUFSIZE);
                return NULL;
            }
        }
    }
    return pStr;
}
