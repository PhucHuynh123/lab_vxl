/*
 * button_reading.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */
#include"main.h"

#ifndef INC_BUTTON_READING_H_
#define INC_BUTTON_READING_H_

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button_flag_pressed_3s[3];
extern int button_flag[3];

void getKeyInput();
void subKeyProcess(int);


#endif /* INC_BUTTON_READING_H_ */