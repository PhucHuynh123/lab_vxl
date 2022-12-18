/*
 * button.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Admin
 */
#include "button.h"

#define DURATION 100

int KeyReg0[NUMBER_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[NUMBER_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[NUMBER_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[NUMBER_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int TimeOutForKeyPress[NUMBER_OF_BUTTONS] =  {100,100,100,100};
int button_flag[NUMBER_OF_BUTTONS]={0,0,0,0};
int button_flag_press_1s[NUMBER_OF_BUTTONS]={0,0,0,0};

void subKeyProcess(int index){
	//TOD
	button_flag[index] = 1;
}


void getKeyInput(){
	for(int i=0;i<NUMBER_OF_BUTTONS;i++){
		  KeyReg2[i] = KeyReg1[i];
		  KeyReg1[i] = KeyReg0[i];
		  if(i==0) KeyReg0[i] = HAL_GPIO_ReadPin(A1_GPIO_Port, A1_Pin);
		  if(i==1) KeyReg0[i] = HAL_GPIO_ReadPin(A2_GPIO_Port, A2_Pin);
		  if(i==2) KeyReg0[i] = HAL_GPIO_ReadPin(A3_GPIO_Port, A3_Pin);
		  if(i==3) KeyReg0[i] = HAL_GPIO_ReadPin(A0_GPIO_Port, A0_Pin);
		  if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
		    if (KeyReg2[i] != KeyReg3[i]){
		      KeyReg3[i] = KeyReg2[i];

		      if (KeyReg3[i] == PRESSED_STATE){
		        TimeOutForKeyPress[i] = 100;
		        subKeyProcess(i);
		      }
		      else button_flag_press_1s[i]=0;

		    }else{
		       TimeOutForKeyPress[i] --;
		        if (TimeOutForKeyPress[i] == 0){
		          if(KeyReg3[i] == PRESSED_STATE){
		        	  button_flag_press_1s[i]=1;
		          }
		          else button_flag_press_1s[i]=0;
		        	  TimeOutForKeyPress[i]=100;
		        }
		    }
		  }
	}
}

