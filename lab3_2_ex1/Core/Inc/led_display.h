
#include "main.h"
#include"global.h"
#include "trafficLight.h"

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

void display7SEG1(int num);
void display7SEG2(int num);

void clear_led();
void display_two_7SEG();
void blink_led_red();
void blink_led_green();
void blink_led_amber();
void update_two_7SEG(int);
#endif /* INC_LED_DISPLAY_H_ */