/*
 * fsm_traffic.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Admin
 */

#include "fsm_traffic.h"


/**/

//status of traffic light
int state_led=0;
//the time of status of traffic light
int counter_second=-1;
//countdown the time of led_red
int counter_red = 0;
//countdown the time of led_green
int counter_green=0;
//countdown the time of led_yellow
int counter_yellow=0;
//turn on or turn off 4 led7segment
int status_led7segment=0;
//count the time of led_green or led_yellow
int counter_second1=0;

UART_HandleTypeDef huart2;



void clear_led(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, 0);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin,0);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 0);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin,0);
}


void red1Control(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, 1);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin,0);
}

void green1Control(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, 0);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin,1);
}

void yellow1Control(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, 1);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin,1);
}



void red2Control(){
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 1);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin,0);
}


void green2Control(){
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 0);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin,1);
}

void yellow2Control(){
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 1);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin,1);
}


void redPedestrianControl(){
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, 1);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, 0);
}

void greenPedestrianControl(){
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, 0);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, 1);
}


void clearPedestrian(){
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, 0);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, 0);
}




void fsm_automatic(){
	  if(state_led==0){
			  counter_second++;
			  if(counter_second < time_green){
				  //trang thai 1: led_red_1,led_green_2: bat
				  //			led_yellow_1,led_green_1,led_red_2,led_yellow_2:tat
				 red1Control();
				 green2Control();
				 if(time_wait1){
//					  if (time_wait >= time_pedestrian - 4){
//						  PWM += 20;
//						  if(PWM > 500){
//							  PWM = 0;
//						  }
//					  }
					 PWM=0;
					 greenPedestrianControl();
					 time_wait1++;
				 }
			  }
			  if(counter_second>=time_green){
				  //trang thai 2: led_red_1,led_yellow_2: bat
				  //			led_yellow_1,led_green_1,led_red_2,led_green_2:tat
				  red1Control();
				  yellow2Control();
				  if(time_wait1){
					  PWM+=20;
					  greenPedestrianControl();
					  time_wait1++;
				  }
			  }
			  if(counter_second == time_red){
				  // set lai gia tri cua state_led va counter_second
				  state_led=1;
				  counter_second=-1;
			  }
		  }
		  if(state_led==1){
			  counter_second++;
			  if(counter_second<time_green){
				  //trang thai 1: led_red_2,led_green_1: bat
				  //			led_yellow_1,led_green_2,led_red_1,led_yellow_2:tat
				  red2Control();
				  green1Control();
					 if(time_wait1){
						 PWM=0;
//						  if (time_wait>=time_pedestrian-4){
//							  PWM += 20;
//							  if(PWM > 500){
//								  PWM = 0;
//							  }
//						  }
						 redPedestrianControl();
						 time_wait1++;
					 }
			  }
			  if(counter_second>=time_green){
				  //trang thai 2: led_red_2,led_yellow_1: bat
				  //			led_yellow_2,led_green_1,led_red_1,led_green_2:tat
				  red2Control();
				  yellow1Control();
					 if(time_wait1){
						 PWM=0;
//						  if (time_wait>=time_pedestrian-4){
//							  PWM += 20;
//							  if(PWM > 500){
//								  PWM = 0;
//							  }
//						  }
						 redPedestrianControl();
						 time_wait1++;
					 }
			  }
			  if(counter_second==time_red-1){
				  //set lại gia tri cua state_led va counter_second
				  state_led=0;
				  counter_second=-1;
			  }
		  }
}


void setValueLocalModeNormal(){
	//status of traffic light
	state_led=0;
	//the time of status of traffic light
	counter_second=-1;
	//countdown the time of led_red
	counter_red=0;
	//countdown the time of led_green
	counter_green=0;
	//countdown the time of led_yellow
	counter_yellow=0;
	//count the time of led_green or led_yellow
	counter_second1 = 0;
	//set value of time_wait
	time_wait=0;
}




void display_counter(){
	if(counter<time_red){
		sprintf(str,"!7SEG:%d#\r\n",time_red-counter);
		HAL_UART_Transmit_IT(&huart2,(void*)str,9);
	}
	if(counter>=time_red&&counter<(time_red+time_green)){
		sprintf(str,"!7SEG:%d#\r\n",time_green+time_red-counter);
		HAL_UART_Transmit_IT(&huart2,(void*)str,9);
	}
	if(counter>=(time_red+time_green)&&counter<(time_green+time_red+time_yellow)){
		sprintf(str,"!7SEG:%d#\r\n",time_green+time_red+time_yellow-counter);
		HAL_UART_Transmit_IT(&huart2,(void*)str,9);
	}
	counter++;
	if(counter==(time_green+time_red+time_yellow)){
		counter=0;
	}
}

void normal_mode(){
	if(timer_flag1==1){
		display_counter();
		setTimer1(1000);
		fsm_automatic();
	}
}


/*void fsm_automatic_run(){
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
		break;
	default:
		break;
	}
}*/





