/*
 * timer.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Admin
 */
#include "timer.h"
int timer_flag0 = 0;
int timer_flag1 = 0;
int timer_flag2 = 0;
int timer_flag3 = 0;
int timer_flag4 = 0;
int timer_flag5 = 0;
int timer_flag6 = 0;


int timer0_counter = 0;
int timer1_counter = 0;
int timer2_counter = 0;
int timer3_counter = 0;
int timer4_counter = 0;
int timer5_counter = 0;
int timer6_counter = 0;

const int TIMER_CYCLE = 10;

void setTimer0(int duration){
	 timer0_counter = duration / TIMER_CYCLE ;
	 timer_flag0 = 0;
}
void setTimer1(int duration){
	 timer1_counter = duration/ TIMER_CYCLE ;
	 timer_flag1 = 0;
}
void setTimer2(int duration){
	timer2_counter = duration/TIMER_CYCLE;
	timer_flag2 = 0;
}
void setTimer3(int duration){
	 timer3_counter = duration / TIMER_CYCLE ;
	 timer_flag3 = 0;
}
void setTimer4(int duration){
	 timer4_counter = duration/ TIMER_CYCLE ;
	 timer_flag4 = 0;
}
void setTimer5(int duration){
	timer5_counter = duration/TIMER_CYCLE;
	timer_flag5 = 0;
}
void setTimer6(int duration){
	timer6_counter = duration/TIMER_CYCLE;
	timer_flag6 = 0;
}
void timer_run() {
	 if( timer0_counter > 0) {
		 timer0_counter--;
		 if( timer0_counter == 0) timer_flag0 = 1;
	 }

	 if( timer1_counter > 0) {
		 timer1_counter--;
		 if( timer1_counter == 0) timer_flag1 = 1;
	 }
	 if(timer2_counter>0){
		 timer2_counter--;
		 if(timer2_counter == 0) timer_flag2 = 1;
	 }
	 if( timer3_counter > 0) {
		 timer3_counter--;
		 if( timer3_counter == 0) timer_flag3 = 1;
	 }

	 if( timer4_counter > 0) {
		 timer4_counter--;
		 if( timer4_counter == 0) timer_flag4 = 1;
	 }
	 if(timer5_counter>0){
		 timer5_counter--;
		 if(timer5_counter == 0) timer_flag5 = 1;
	 }
	 if(timer6_counter>0){
		 timer6_counter--;
		 if(timer6_counter == 0) timer_flag6 = 1;
	 }

 }

