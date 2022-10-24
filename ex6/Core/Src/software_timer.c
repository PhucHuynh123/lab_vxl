/*
 * software_timer.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Admin
 */
#include "software_timer.h"

int timer1_counter = 0;
int timer1_flag = 0;
int TIME_CYCLE = 10;


void setTimer1(int duration){
	timer1_counter = duration / 10;
	timer1_flag = 0;
}


void timerRun(){
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter <= 0){
			timer1_flag = 1;
		}
	}
}

