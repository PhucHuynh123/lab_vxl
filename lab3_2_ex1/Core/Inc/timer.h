

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer_flag0;
extern int timer_flag1;
extern int timer_flag2;
extern int timer_flag3;
extern int timer_flag4;
extern int timer_flag5;
extern int timer_flag6;


void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);
void setTimer6(int duration);

void timer_run();
#endif /* INC_TIMER_H_ */