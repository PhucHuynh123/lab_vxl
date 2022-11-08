
#include "main.h"
#include "input_reading.h"
#include "input_processing.h"
#include "trafficLight.h"
#include "global.h"
#include "timer.h"



 void fsm_for_input_processing (){
 	switch (State){
 		case MODE1:
 			fsm_automatic_1();
 			fsm_automatic_2();
 			display_two_7SEG();
 			if(button_flag[0] == 1 ){
 				button_flag[0] = 0;
 				setTimer6(10000);
 				State = MODE2;
 			}
 			break;
 		case MODE2:
 			if(button_flag[0] == 1 || button_flag[1] == 1 || button_flag[2] == 1 ){
 				setTimer6(10000);
 			}
 			if (timer_flag6 == 1){
 				status1 = 1;
 				status2 = 1;
 				status3 = 1;
 				status4 = 1;
 				status4_1 = 1;
 				status4_2 = 1;
 				State = MODE1;
 			}
 			blink_led_red();
 			if(button_flag[1] == 1){
 				button_flag[1] = 0;
 				bufferRed++;
 				if(bufferRed > 99){
 					bufferRed = 1;
 				}
 			}
 			update_two_7SEG(bufferRed);
 			if(button_flag[2] == 1){
 				button_flag[2] = 0;
 				time_red = bufferRed;
 			}
 			if (button_flag[0]){
 				button_flag[0] = 0;
 				State = MODE3;
 				setTimer6(10000);
 			}
 			break;
 		case MODE3:
			if(button_flag[0] == 1 || button_flag[1] == 1 || button_flag[2] == 1 ){
 				setTimer6(10000);
 			}
 			if (timer_flag6 == 1){
 				status1 = 1;
 				status2 = 1;
 				status3 = 1;
 				status4 = 1;
 				status4_1 = 1;
 				status4_2 = 1;
 				State = MODE1;
 			}
 			blink_led_amber();
 			if(button_flag[1] == 1){
 				button_flag[1] = 0;
 				bufferAmber++;
 				if(bufferAmber > 99){
 					bufferAmber = 1;
 				}
 			}
 			if(button_flag[2] == 1){
 				button_flag[2] = 0;
 				time_amber = bufferAmber;
 			}
 			update_two_7SEG(bufferAmber);
 			if (button_flag[0]){
 					button_flag[0] = 0;
 					setTimer6(10000);
 					State = MODE4;
 			}
 			break;
 		case MODE4:
			if(button_flag[0] == 1 || button_flag[1] == 1 || button_flag[2] == 1 ){
 				setTimer6(10000);
 			}
 			if (timer_flag6 == 1){
 				status1 = 1;
 				status2 = 1;
 				status3 = 1;
 				status4 = 1;
 				status4_1 = 1;
 				status4_2 = 1;
 				State = MODE1;
 			}
 			blink_led_green();
 			if(button_flag[1] == 1){
 				button_flag[1] = 0;
 				bufferGreen++;
 				if(bufferGreen > 99){
 					bufferGreen = 1;
 				}
 			}
 			update_two_7SEG(bufferGreen);
 			if(button_flag[2] == 1){
 				button_flag[2] = 0;
 				time_green = bufferGreen;
 			}
 			if(button_flag[0]){
 				button_flag[0] = 0;
 				State = MODE1;
 				status1 = 1;
 				status2 = 1;
 				status3 = 1;
 				status4 = 1;
 				status4_1 = 1;
 				status4_2 = 1;
 			}
 			break;
 		default:
 			break;
 	}
 }

