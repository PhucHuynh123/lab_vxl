/*
 * button_reading.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */
#include "main.h"
#include "button_reading.h"
#include "global.h"


#define NUMBER_OF_BUTTONS 3
#define DURATION 300


int KeyReg0[NUMBER_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[NUMBER_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[NUMBER_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[NUMBER_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int TimeOutForKeyPress[NUMBER_OF_BUTTONS] =  {300,300,300};

int button_flag[NUMBER_OF_BUTTONS]={0,0,0};
int button_flag_pressed_3s[NUMBER_OF_BUTTONS]={0,0,0};


void subKeyProcess(int index){
	//TOD
	button_flag[index] = 1;
}



void getKeyInput(){
	for(int i=0; i<NUMBER_OF_BUTTONS; i++){
		  KeyReg2[i] = KeyReg1[i];
		  KeyReg1[i] = KeyReg0[i];
		  if(i==0) KeyReg0[i] = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
		  if(i==1) KeyReg0[i] = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
		  if(i==2) KeyReg0[i] = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
		  if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
		    if (KeyReg2[i] != KeyReg3[i]){
		      KeyReg3[i] = KeyReg2[i];
		      if (KeyReg3[i] == PRESSED_STATE){
		        TimeOutForKeyPress[i] = 300;
		        subKeyProcess(i);
		      }
		      else {
		    	  button_flag_pressed_3s[i]=0;
		      }
		    }else{
		       TimeOutForKeyPress[i] --;
		        if (TimeOutForKeyPress[i] == 0){
		          if(KeyReg3[i] == PRESSED_STATE){
		        	  button_flag_pressed_3s[i]=1;
		        	  KeyReg3[i] = NORMAL_STATE;
		          }
		          else button_flag_pressed_3s[i] = 0;
		        	   TimeOutForKeyPress[i]=300;
		        }
		    }
		  }
	}
}
