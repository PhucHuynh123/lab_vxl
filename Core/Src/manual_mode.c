/*
 * manual_mode.c
 *
 *  Created on: Dec 6, 2022
 *      Author: Admin
 */
#include "manual_mode.h"


UART_HandleTypeDef huart2;

//status yellow
void yellowBlinking(){
	//turn off all led
	if(clear_all_traffic_led==0){
		clear_led();
	}
	//blinking led-yellow
	if(clear_all_traffic_led==1){
		yellow1Control();
		yellow2Control();

	}
	clear_all_traffic_led = 1 - clear_all_traffic_led;
}

//increase the timer of led-yellow when press button 2(button_flag[1]=1)
void increaseTimeYellow(){
	if(button_flag[1]==1){
		time_wait=0;
		button_flag[1]=0;
		time_yellow++;
		if(time_yellow>99) time_yellow=1;
		change_time_yellow=1;
	}
}
//decrease the timer of led-yellow when press button 3(button_flag[2]=1)
void decreaseTimeYellow(){
	if(button_flag[2]==1){
		time_wait=0;
		button_flag[2]=0;
		time_yellow--;
		if(time_yellow<0) time_yellow=99;
		change_time_yellow=1;
	}
}


void yellow_mode(){
	decreaseTimeYellow();
	increaseTimeYellow();
	if(timer_flag1==1){
		setTimer1(500);
		yellowBlinking();
	}
	if(timer_flag2==1){
		sprintf(str,"!7SEG:%d#\r\n",time_yellow);
		HAL_UART_Transmit_IT(&huart2,(void*)str,9);
		counter=0;
		setTimer2(1000);
		time_wait++;
	}
}

//status red
void redBlinking(){
	//turn off all led
	if(clear_all_traffic_led==0){
		clear_led();
	}
	//blinking led-red
	if(clear_all_traffic_led==1){
		red1Control();
		red2Control();
	}
	clear_all_traffic_led = 1 - clear_all_traffic_led;
}

//increase the timer of led-red when press button 2(button_flag[1]=1)
void increaseTimeRed(){
	if(button_flag[1]==1){
		time_wait=0;
		button_flag[1]=0;
		time_red++;
		if(time_red>99) time_red=1;
		change_time_red=1;
	}
}
//decrease the timer of led-red when press button 3(button_flag[2]=1)
void decreaseTimeRed(){
	if(button_flag[2]==1){
		time_wait=0;
		button_flag[2]=0;
		time_red--;
		if(time_red<0) time_red=99;
		change_time_red=1;
	}
}


void red_mode(){
	decreaseTimeRed();
	increaseTimeRed();
//	redPedestrianControl();
	if(timer_flag1==1){
		setTimer1(500);
		redBlinking();
	}
	if(timer_flag2==1){
		sprintf(str,"!7SEG:%d#\r\n",time_red);
		HAL_UART_Transmit_IT(&huart2,(void*)str,9);
		counter=0;
		setTimer2(1000);
		time_wait++;
	}
}

//status green

void greenBlinking(){
	//turn off all led
	if(clear_all_traffic_led==0){
		clear_led();
	}
	//blinking led-green
	if(clear_all_traffic_led==1){
		green1Control();
		green2Control();
	}
	clear_all_traffic_led = 1 - clear_all_traffic_led;
}

//increase the timer of led-green when press button 2(button_flag[1]=1)
void increaseTimeGreen(){
	if(button_flag[1]==1){
		time_wait=0;
		button_flag[1]=0;
		time_green++;
		if(time_green>99) time_green=1;
		change_time_green=1;
	}
}

//decrease the timer of led-green when press button 3(button_flag[2]=1)
void decreaseTimeGreen(){
	if(button_flag[2]==1){
		time_wait=0;
		button_flag[2]=0;
		time_green--;
		if(time_green<0) time_green=99;
		change_time_green=1;
	}
}

void green_mode(){
	increaseTimeGreen();
	decreaseTimeGreen();
//	redPedestrianControl();
	if(timer_flag1==1){
		setTimer1(500);
		greenBlinking();
	}
	if(timer_flag2==1){
		sprintf(str,"!7SEG:%d#\r\n",time_green);
		HAL_UART_Transmit_IT(&huart2,(void*)str,9);
		counter=0;
		setTimer2(1000);
		time_wait++;
	}
}

void setTimeLed(){
	if(change_time_red==1&&change_time_green==0&&change_time_yellow==0){
		if(time_red-time_yellow<0) time_red=time_yellow+time_green;
		if(time_red-time_yellow>=0) time_green=time_red-time_yellow;
	}
	if(change_time_red==0&&change_time_green==1&&change_time_yellow==0){
		time_red=time_green+time_yellow;
	}
	if(change_time_red==0&&change_time_green==0&&change_time_yellow==1){
		time_red=time_green+time_yellow;
	}
	time_red=time_green+time_yellow;
	change_time_green=0;
	change_time_red=0;
	change_time_yellow=0;
}

