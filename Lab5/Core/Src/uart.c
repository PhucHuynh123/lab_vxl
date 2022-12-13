/*
 * uart.c
 *
 *  Created on: Dec 1, 2022
 *      Author: Admin
 */
#include "uart.h"
#include <stdio.h>
#include <string.h>

ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;

enum communicateState{RST_WAIT, RST_OK, ADC_SEND};

enum communicateState commState = RST_WAIT;

int ADC_value = 0;

char str[20];
char out[30];

void uart_communication_fsm(){
	switch(commState){
	case RST_WAIT:
		if(status() == 1){
			command_done = 0;
/*		HAL_UART_Transmit(&huart2, (void*)out, sprintf(out, "\r\nYour command is: %s \r\n", getCommand()), 1000);*/
			if(strcmp(getCommand(),"RST") == 0){ /*compare string "RST"*/
				ADC_value = HAL_ADC_GetValue(&hadc1);
				commState = ADC_SEND;
				setTimer1(3000);
			}
		}
		break;
	case ADC_SEND:
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n!ADC = %d#", ADC_value),1000);
		commState = RST_OK;
		break;
	case RST_OK:
		if(status() == 1){
			command_done = 0;
/*		HAL_UART_Transmit(&huart2, (void*)out, sprintf(out, "\r\nYour command is: %s \r\n", getCommand()), 1000);*/
				if(strcmp(getCommand(),"OK") == 0){ /*compare string "OK"*/
					commState = RST_WAIT;
					setTimer1(3000);
				}
			clearCommand();
		}
		if(timer1_flag==1){
			commState = ADC_SEND;
			setTimer1(3000);
		}
		break;
	default:
		break;
	}
}
