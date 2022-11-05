/*
 * fsm_simple_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */
#include "fsm_simple_buttons.h"
#include "global.h"
#include "button_reading.h"
#include "led_display.h"
#include "timer.h"

enum State {INIT, MODE, RESET_0, DEC, INC, INC_1S , DEC_1S };
enum State  currentState = INIT;
enum State  nextState = INIT;




void fsm_simple_buttons_run(){
	currentState = nextState;
	switch(currentState){
	    case INIT:
	        count_down();
	        if(button_flag[0] == 1 || button_flag[1] == 1 || button_flag[2] == 1){
				nextState = MODE;
				setTimer2(10000);
			}
		case MODE:
			/*IF ALL 3 BUTTON ARE NOT PRESSED FOR 10 SECOND */
		    if(button_flag[0] == 1 || button_flag[1] == 1 || button_flag[2] == 1){
				setTimer2(10000);
			}
			if(timer2_flag){
			    nextState = INIT;
			}
			if(button_flag[0]== 1){
				button_flag[0] = 0;
				nextState = RESET_0;
			}
			if(button_flag_pressed_3s[1] == 1){
				counter++;
				if(counter > 9) {
					counter = 0;
				}
				display7SEG(counter);
				nextState = INC_1S;
				setTimer1(1000);
			}
			if(button_flag_pressed_3s[2] == 1){
				counter--;
				if(counter < 0) {
					counter = 9;
				}
				display7SEG(counter);
				nextState = DEC_1S;
				setTimer1(1000);
			}
			if(button_flag[1] == 1 ){
				button_flag[1] = 0;
				nextState = INC;
			}
			if(button_flag[2] == 1 ){
				button_flag[2] = 0;
				nextState = DEC;
			}
	    	break;
		case RESET_0: /*SET COUNTER = 0*/
			counter = 0;
			display7SEG(counter);
			if(button_flag[0]== 0){
				nextState = MODE;
			}
			break;
		case INC: /*INCREASE COUNTER*/
	    	counter++;
	    	if(counter > 9){
	    		counter = 0;
	    	}
	    	display7SEG(counter);
	    	if (button_flag[1] == 0){
	    		nextState = MODE;
	    	}
			break;
		case INC_1S: /*THE COUNNTER INCREASES BY ONE UNIT EVERY SECOND*/
			if(timer1_flag==1){
				setTimer1(1000);
				counter++;
				if(counter > 9) {
					counter = 0;
				}
				display7SEG(counter);
			}
			if(button_flag_pressed_3s[1] == 0){
				nextState = MODE;
			}
			break;
		case DEC: /*DECREASE COUNTER*/
			counter--;
	    	if(counter < 0){
	    		counter = 9;
	    	}
	    	display7SEG(counter);
	    	if(button_flag[2] == 0){
	    		nextState= MODE;
	    	}
	    	break;
		case DEC_1S: /*THE COUNNTER DECREASES BY ONE UNIT EVERY SECOND*/
			if(timer1_flag==1){
				setTimer1(1000);
				counter--;
				if(counter < 0) {
					counter = 9;
				}
				display7SEG(counter);
			}
			if(button_flag_pressed_3s[2] == 0){
				nextState = MODE;
			}
			break;
		default:
			break;
	}
}



