/*
 * uart.h
 *
 *  Created on: Dec 1, 2022
 *      Author: Admin
 */

#ifndef INC_UART_H_
#define INC_UART_H_
#include "main.h"
#include "timer.h"
#include "command.h"
#include <stdio.h>
#include <string.h>

extern uint8_t buffer_flag;
extern uint8_t temp ;

extern int ADC_value;

void uart_communication_fsm();

#endif /* INC_UART_H_ */
