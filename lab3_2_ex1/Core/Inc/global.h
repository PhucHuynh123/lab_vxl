

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


#define INIT1 1
#define AUTO_RED1 2
#define AUTO_GREEN1 3
#define AUTO_YELLOW1 4

#define INIT2 1
#define AUTO_GREEN2 2
#define AUTO_YELLOW2 3
#define AUTO_RED2 4


#define INIT3 1
#define SEG_1 2
#define SEG_2 3


#define MODE1 1
#define MODE2 2
#define MODE3 3
#define MODE4 4



/*value for led7seg*/
extern int time_red ;
extern int time_amber ;
extern int time_green;

/*Temp value for traffic light used for increase or decrease*/
extern int bufferRed;
extern int bufferAmber;
extern int bufferGreen;


/*Counter*/
extern int timer0_counter;
extern int timer1_counter;
extern int timer2_counter;
extern int timer3_counter;
extern int timer4_counter;
extern int timer5_counter;
extern int timer6_counter;


/*state variable*/
extern int status1;
extern int status2;
extern int status3;
extern int status4;
extern int status4_1;
extern int status4_2;
extern int status5;


extern int State;



extern int count_flag;
extern int state_led_7seg1;
extern int state_led_7seg2;
#endif /* INC_GLOBAL_H_ */