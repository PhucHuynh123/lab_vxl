
#include "main.h"
#include "led_display.h"
#include "trafficLight.h"
#include"timer.h"
#include "global.h"

void clear_led(){
	HAL_GPIO_WritePin(amber1_GPIO_Port, amber1_Pin, 1);
	HAL_GPIO_WritePin(amber2_GPIO_Port, amber2_Pin, 1);
	HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, 1);
	HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, 1);
	HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 1);
	HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 1);
}
void state_7seg1(int a ,int b , int c , int d , int e ,int f, int g){
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2,a);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3,b);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4,c);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,d);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6,e);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7,f);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8,g);
 }
void display7SEG1(int num){
	 if (num == 0){
		state_7seg1(0,0,0,0,0,0,1);
	 }
	 else if (num == 1){
		 state_7seg1(1,0,0,1,1,1,1);
	 }
	 else if (num == 2){
		 state_7seg1(0,0,1,0,0,1,0);
	 }
	 else if (num == 3){
		 state_7seg1(0,0,0,0,1,1,0);
	 }
	 else if (num == 4){
		 state_7seg1(1,0,0,1,1,0,0);
	 }
	 else if (num == 5){
		 state_7seg1(0,1,0,0,1,0,0);
	 }
	 else if (num == 6){
		 state_7seg1(0,1,0,0,0,0,0);
	 }
	 else if(num == 7){
		 state_7seg1(0,0,0,1,1,1,1);
	 }
	 else if (num == 8){
		 state_7seg1(0,0,0,0,0,0,0);
	 }
	 else if(num == 9){
		 state_7seg1(0,0,0,0,1,0,0);
	 }
	 else if(num >= 10){
		 state_7seg1(0,0,0,0,0,0,1);
	 }
}

void state_7seg2(int a ,int b , int c , int d , int e ,int f, int g){
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9,a);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10,b);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11,c);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12,d);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,e);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14,f);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15,g);
 }
void display7SEG2(int num){
	 if (num == 0){
		state_7seg2(0,0,0,0,0,0,1);
	 }
	 if (num == 1){
		 state_7seg2(1,0,0,1,1,1,1);
	 }
	 if (num == 2){
		 state_7seg2(0,0,1,0,0,1,0);
	 }
	 if (num == 3){
		 state_7seg2(0,0,0,0,1,1,0);
	 }
	 if (num == 4){
		 state_7seg2(1,0,0,1,1,0,0);
	 }
	 if (num == 5){
		 state_7seg2(0,1,0,0,1,0,0);
	 }
	 if (num == 6){
		 state_7seg2(0,1,0,0,0,0,0);
	 }
	 if(num == 7){
		 state_7seg2(0,0,0,1,1,1,1);
	 }
	 if (num == 8){
		 state_7seg2(0,0,0,0,0,0,0);
	 }
	 if(num == 9){
		 state_7seg2(0,0,0,0,1,0,0);
	 }
	 if(num >= 10){
		 state_7seg2(0,0,0,0,0,0,1);
	 }
}


int count_7seg1;
int count_7seg2;
void display_two_7SEG(){
	switch(status3){
		case INIT3:
			status3 = SEG_1;

			count_7seg1 = time_red;
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,  0);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,  1);
			display7SEG1(count_7seg1/10);

			count_7seg2 = time_green;
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,  0);
		    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,  1);
			display7SEG2(count_7seg2/10);

			setTimer2(500);
			break;
		case SEG_1:
			/*TH for led 7SEG1*/
			if (status1 == AUTO_GREEN1 && count_7seg1 == 0){
				count_7seg1 = time_green;
			}
			else if (status1 == AUTO_YELLOW1 && count_7seg1 == 0){
				count_7seg1 = time_amber;
			}
			else if (status1 == AUTO_RED1 && count_7seg1 == 0){
				count_7seg1 = time_red;
			}
			/*TH for led 7SEG2*/
			if (status2 == AUTO_GREEN2 && count_7seg2 == 0){
				count_7seg2 = time_green;
			}
			else if (status2 == AUTO_YELLOW2 && count_7seg2 == 0){
				count_7seg2 = time_amber;
			}
			else if (status2 == AUTO_RED2 && count_7seg2 == 0){
				count_7seg2 = time_red;
			}

			if(timer_flag2 == 1){
				status3 = SEG_2;
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,  1);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,  0);
				display7SEG1((count_7seg1 - (count_7seg1/10)*10));

				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,  1);
			    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,  0);
				display7SEG2((count_7seg2 - (count_7seg2/10)*10));
				setTimer2(500);
			}
			break;

		case SEG_2:
			if(timer_flag2 == 1){
				count_7seg1--;
				status3 = SEG_1;
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,  0);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,  1);
				display7SEG1(count_7seg1/10);

				count_7seg2--;
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,  0);
			    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,  1);
				display7SEG2(count_7seg2/10);

				setTimer2(500);
			}
			break;
		default:
			break;
	}
}


void blink_led_red(){
	switch(status4){
		case 1:
			clear_led();
			status4 = 2;
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 0);
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin,0);
		    setTimer4(500);
		    break;
		case 2:
			if(timer_flag4 == 1){
				status4 = 3;
				HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
				HAL_GPIO_TogglePin(red2_GPIO_Port, red2_Pin);
				setTimer4(500);
			}
			break;
		case 3:
			if(timer_flag4 == 1){
				status4 = 2;
				HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
				HAL_GPIO_TogglePin(red2_GPIO_Port, red2_Pin);
				setTimer4(500);
			}
			break;
		default:
			break;
	}
}


void blink_led_amber(){
	switch(status4_1){
		case 1:
			clear_led();
			status4_1 = 2;
			HAL_GPIO_WritePin(amber1_GPIO_Port, amber1_Pin, 0);
			HAL_GPIO_WritePin(amber2_GPIO_Port, amber2_Pin,0);
		    setTimer4(500);
		    break;
		case 2:
			if(timer_flag4 == 1){
				status4_1 = 3;
				HAL_GPIO_TogglePin(amber1_GPIO_Port, amber1_Pin);
				HAL_GPIO_TogglePin(amber2_GPIO_Port, amber2_Pin);
				setTimer4(500);
			}
			break;
		case 3:
			if(timer_flag4 == 1){
				status4_1 = 2;
				HAL_GPIO_TogglePin(amber1_GPIO_Port,amber1_Pin);
				HAL_GPIO_TogglePin(amber2_GPIO_Port, amber2_Pin);
				setTimer4(500);
			}
			break;
		default:
			break;
	}
}

void blink_led_green(){
	switch(status4_2){
		case 1:
			clear_led();
			status4_2 = 2;
			HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin,0);
			HAL_GPIO_WritePin(green2_GPIO_Port,green2_Pin,0);
		    setTimer4(500);
		    break;
		case 2:
			if(timer_flag4 == 1){
				status4_2 = 3;
				HAL_GPIO_TogglePin(green1_GPIO_Port, green1_Pin);
				HAL_GPIO_TogglePin(green2_GPIO_Port, green2_Pin);
				setTimer4(500);
			}
			break;
		case 3:
			if(timer_flag4 == 1){
				status4_2 = 2;
				HAL_GPIO_TogglePin(green1_GPIO_Port, green1_Pin);
				HAL_GPIO_TogglePin(green2_GPIO_Port, green2_Pin);
				setTimer4(500);
			}
			break;
		default:
			break;
	}
}


void update_two_7SEG(int num){
	switch(status5){
		case 1:
			status5 = 2;

			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,  0);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,  1);
			display7SEG1((int)num/10);

			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,  0);
		    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,  1);
			display7SEG2((int)num/10);

			setTimer5(100);
			break;
		case 2:

			if(timer_flag5 == 1){
				status5 = 3;
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,  1);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,  0);
				display7SEG1(num%10);

				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,  1);
			    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,  0);
				display7SEG2(num%10);
				setTimer5(100);
			}
			break;

		case 3:
			if(timer_flag5 == 1){
				status5 = 2;
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,  0);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,  1);
				display7SEG1((int)num/10);

				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,  0);
			    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,  1);
				display7SEG2((int)num/10);

				setTimer5(100);
			}
			break;
		default:
			break;
	}
}

