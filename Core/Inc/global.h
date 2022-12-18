/*
 * global.h
 *
 *  Created on: Dec 6, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

extern int mode;
extern int change_time_red;
extern int change_time_green;
extern int change_time_yellow;
//time of led red
extern int time_red;
//time of led green
extern int time_green;
//time of led yellow
extern int time_yellow;
extern int clear_all_traffic_led;
//control buzzer
extern int PWM;
//time no buttons press
extern int time_wait;
//control pedestrian traffic
extern int time_wait1;
//counter time: pedestrian traffic turn on
extern int time_pedestrian;
extern char str[30] ;
extern int counter;

extern int counter_second;

#define INIT 0
#define NORMAL 1
#define RED 2
#define GREEN 3
#define YELLOW 4


#endif /* INC_GLOBAL_H_ */
