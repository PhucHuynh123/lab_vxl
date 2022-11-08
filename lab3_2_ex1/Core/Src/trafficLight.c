
#include "input_processing.h"
#include "trafficLight.h"
#include "led_display.h"
#include "global.h"
#include "main.h"
#include "timer.h"

void red1Control(){
	HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 0);
	HAL_GPIO_WritePin(amber1_GPIO_Port, amber1_Pin, 1);
	HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, 1);
}
void red2Control(){
	HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 0);
	HAL_GPIO_WritePin(amber2_GPIO_Port, amber2_Pin, 1);
	HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, 1);
}
void amber1Control(){
	HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 1);
	HAL_GPIO_WritePin(amber1_GPIO_Port, amber1_Pin, 0);
	HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, 1);
}
void amber2Control(){
	HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 1);
	HAL_GPIO_WritePin(amber2_GPIO_Port, amber2_Pin, 0);
	HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, 1);
}
void green1Control(){
	HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 1);
	HAL_GPIO_WritePin(amber1_GPIO_Port, amber1_Pin, 1);
	HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, 0);
}
void green2Control(){

	HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 1);
	HAL_GPIO_WritePin(amber2_GPIO_Port, amber2_Pin, 1);
	HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, 0);
}


void fsm_automatic_1(){
	switch(status1){
		case INIT1:
			status1 = AUTO_RED1;
			red1Control();
			setTimer0(time_red*1000);
			break;
		case AUTO_RED1:
			if(timer_flag0 == 1){
				status1 = AUTO_GREEN1;
				green1Control();
				setTimer0(time_green*1000);
			}
			break;
		case AUTO_GREEN1:
			if(timer_flag0 == 1){
				status1 = AUTO_YELLOW1;
				amber1Control();
				setTimer0(time_amber*1000);
			}
			break;
		case AUTO_YELLOW1:
			if(timer_flag0 == 1){
				status1 = INIT1;
                red1Control();
                setTimer0(time_red*1000);
			}
			break;
		default:
			break;
	}
}

void fsm_automatic_2(){
	switch(status2){
		case INIT2:
			status2 = AUTO_GREEN2;
			green2Control();
			setTimer1(time_green*1000);
			break;
		case AUTO_GREEN2:
			if(timer_flag1 == 1){
				status2 = AUTO_YELLOW2;
				amber2Control();
				setTimer1(time_amber*1000);
			}
			break;
		case AUTO_YELLOW2:
			if(timer_flag1 == 1){
				status2 = AUTO_RED2;
                red2Control();
                setTimer1(time_red*1000);
			}
			break;
		case AUTO_RED2:
			if(timer_flag1== 1){
				status2 = INIT2;
				green2Control();
				setTimer1(time_green*1000);
			}
			break;
		default:
			break;
	}
}

