
#include "main.h"
#include "input_reading.h"
#include "global.h"


int KeyReg0[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int KeyReg3[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};


int button_flag[3] = {0,0,0};
int TimeOutForKeyPress[3] = {500,50,500};

void subKeyProcess(int index){
	//TODO
	button_flag[index] = 1;
}

void getKeyInput(){
	for(int i = 0;i<3;i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		if(i == 0){
			KeyReg0[i] = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
		}
		else if(i == 1){
			KeyReg0[i] = HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin);
		}
		else if (i == 2){
			KeyReg0[i] = HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin);
		}
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg2[i] != KeyReg3[i]){
			  KeyReg3[i] = KeyReg2[i];
			  if (KeyReg3[i] == PRESSED_STATE){
				  if(i == 1){
					  TimeOutForKeyPress[i] = 50;
				  }
				  subKeyProcess(i);
			  }
			}
			else{
				 if (i == 1) TimeOutForKeyPress[i]--;
				 if (i == 1 && TimeOutForKeyPress[i] == 0){
					 KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}
