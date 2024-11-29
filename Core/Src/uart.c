/*
 * uart.c
 *
 *  Created on: Nov 9, 2024
 *      Author: DELL
 */

#include "uart.h"

uint8_t uartChar = 0;
uint8_t uartBuffer[UART_SIZE];
uint8_t uartIndex = 0;
unsigned char uartFlag = 0;
char uartMessage[100];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART1) {
		uartBuffer[uartIndex] = uartChar;
		uartFlag = 1;
		HAL_UART_Transmit(&huart1, &uartChar, 1, 50);
		HAL_UART_Receive_IT(&huart1, &uartChar, 1);
	}
}

void uartRead(void) {
	if (uartFlag == 1) {
		uartFlag = 0;
		SCH_AddTask(commandParser, 0, 0);
	}
}

void uartSend(void) {
	HAL_UART_Transmit(&huart1, (void*)uartMessage, sprintf(uartMessage, "\r\n!ADC=%ld#\r\n", sensorValue), 100);
}
