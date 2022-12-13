/*
 * command.h
 *
 *  Created on: Dec 1, 2022
 *      Author: Admin
 */

#ifndef INC_COMMAND_H_
#define INC_COMMAND_H_

#include "main.h"
#include "timer.h"
#include <stdio.h>
#include <string.h>

extern unsigned char command_index;
extern unsigned char command_done;

void command_parser_fsm();
char* getCommand();
void clearCommand();
unsigned char status();

#endif /* INC_COMMAND_H_ */
