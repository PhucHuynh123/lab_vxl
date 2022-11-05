/*
 * led_display.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */
#include "led_display.h"
#include "main.h"
#include "global.h"
#include "timer.h"

void state_7seg(int a ,int b , int c , int d , int e ,int f, int g){
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0,a);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1,b);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2,c);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3,d);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4,e);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,f);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6,g);
}

void display7SEG(int num){
	 if (num == 0){
		state_7seg(0,0,0,0,0,0,1);
	 }
	 else if (num == 1){
		 state_7seg(1,0,0,1,1,1,1);
	 }
	 else if (num == 2){
		 state_7seg(0,0,1,0,0,1,0);
	 }
	 else if (num == 3){
		 state_7seg(0,0,0,0,1,1,0);
	 }
	 else if (num == 4){
		 state_7seg(1,0,0,1,1,0,0);
	 }
	 else if (num == 5){
		 state_7seg(0,1,0,0,1,0,0);
	 }
	 else if (num == 6){
		 state_7seg(0,1,0,0,0,0,0);
	 }
	 else if(num == 7){
		 state_7seg(0,0,0,1,1,1,1);
	 }
	 else if (num == 8){
		 state_7seg(0,0,0,0,0,0,0);
	 }
	 else if(num == 9){
		 state_7seg(0,0,0,0,1,0,0);
	 }
	 else if(num >= 10){
		 state_7seg(0,0,0,0,0,0,1);
	 }
}

/*FUNTION COUNT_DOWN*/
int status1 = 1;
void count_down(){
	switch(status1){
		case 1:
			display7SEG(counter);
			counter--;
			if(counter <= 0){
				counter = 0;
			}
			status1 = 2;
			setTimer0(1000);
			break;
		case 2:
			if(timer0_flag == 1){
				timer0_flag = 0;
				display7SEG(counter);
				setTimer0(1000);
				status1	 = 1;
			}
			break;
		default:
			break;

	}
}


/*LED BLINK FUNTION*/

int status2 = 0;
void blink_led(){
	switch(status2){
		case 0:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 0);
			status2 = 1;
			setTimer3(1000);
			break;
		case 1:
			if(timer3_flag == 1){
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				setTimer3(1000);
				status2	 = 2;
			}
			break;
		case 2:
			if(timer3_flag == 1){
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				setTimer3(1000);
				status2	 = 2;
			}
			break;
		default:
			break;

	}
}
