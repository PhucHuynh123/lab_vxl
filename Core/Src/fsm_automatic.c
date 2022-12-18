/*
 * fsm_automatic.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Admin
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(mode){
	case INIT:
		setValueLocalModeNormal();
		setTimeLed();
		mode=NORMAL;
		setTimer3(1000);
		break;
	case NORMAL:
		normal_mode();

		if(button_flag[3]==1){
			button_flag[3]=0;
			time_wait1=1;
		}
		if(time_wait1-2==time_pedestrian){
			time_wait1=0;
			PWM = 0;
			clearPedestrian();
		}
		if(button_flag[0]==1){
			clearPedestrian();
			time_wait1=0;
			button_flag[0]=0;
			clear_all_traffic_led=0;
			mode=RED;
			setTimer3(1000);
		}
		if(button_flag[1]==1||button_flag[2]==1){
			button_flag[1]=0;
			button_flag[2]=0;
		}
		break;
	case RED:
		red_mode();
		if(time_wait==10){
			mode=INIT;
		}
		if(button_flag[0]==1){
			button_flag[0]=0;
			clear_all_traffic_led=0;
			time_wait = 0;
			mode=GREEN;
			setTimer3(1000);
		}
		if(button_flag[3]==1){
			button_flag[3]=0;
		}
		break;
	case GREEN:
		green_mode();
		if(time_wait==10){
			mode=INIT;
		}
		if(button_flag[0]==1){
			clearPedestrian();
			time_wait1=0;
			button_flag[0]=0;
			clear_all_traffic_led=0;
			mode=YELLOW;
			time_wait = 0;
			setTimer3(1000);
		}
		if(button_flag[3]==1){
			button_flag[3]=0;
		}
		break;
	case YELLOW:
		yellow_mode();
		if(time_wait==10){
			mode=INIT;
		}
		if(button_flag[0]==1){
			clearPedestrian();
			time_wait1=0;
			button_flag[0]=0;
			mode=INIT;
		}
		if(button_flag[3]==1){
			button_flag[3]=0;
		}
		break;
	default:
		break;
	}
}
