/*
 * fsm_traffic.h
 *
 *  Created on: Dec 4, 2022
 *      Author: Admin
 */

#ifndef INC_FSM_TRAFFIC_H_
#define INC_FSM_TRAFFIC_H_

#include "main.h"
#include "global.h"
#include "button.h"
#include "timer.h"
#include <stdio.h>
#include <string.h>
#include "manual_mode.h"

/*clear all led */
void clear_led();

void red1Control();
void red2Control();

void yellow1Control();
void yellow2Control();

void green1Control();
void green2Control();


void fsm_automatic();

void setValueLocalModeNormal();
void normal_mode();
void clearPedestrian();

#endif /* INC_FSM_TRAFFIC_H_ */
