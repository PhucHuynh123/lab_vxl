/*
 * scheduler.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Admin
 */

#include "scheduler.h"

void SCH_Init(void){
	unsigned char i;
	for(i=0;i<SCH_MAX_TASKS;i++){
		SCH_Delete_Task_Init(i);
	}
}

void SCH_Add_Task ( void (*pFunction)() ,uint32_t DELAY, uint32_t PERIOD){
	DELAY=DELAY/TICK;
	PERIOD=PERIOD/TICK;
	int index1, index2;
	//find position empty
	for(index1=0;index1<SCH_MAX_TASKS;index1++){
		if(SCH_tasks_G[index1].pTask==0) break;
	}
	//array: empty
	if(index1==0){
		SCH_tasks_G[index1].pTask=pFunction;
		SCH_tasks_G[index1].Delay=DELAY;
		SCH_tasks_G[index1].Period=PERIOD;
		SCH_tasks_G[index1].RunMe=0;
		return;
	}
	//array: full
	else if(index1==SCH_MAX_TASKS) return;
	else{
		for(int i=0;i<=index1;i++){
			//compare DELAY and Delay of each task in array
			if(DELAY>=SCH_tasks_G[i].Delay&&SCH_tasks_G[i].pTask) DELAY-=SCH_tasks_G[i].Delay;
			else{
				index2=i;
				SCH_tasks_G[i].Delay-=DELAY;
				break;
			}
			index2=i;
		}
		// add task
		for(int i=index1;i>index2;i--){
			SCH_tasks_G[i]=SCH_tasks_G[i-1];
		}
		SCH_tasks_G[index2].pTask=pFunction;
		SCH_tasks_G[index2].Delay=DELAY;
		SCH_tasks_G[index2].Period=PERIOD;
		SCH_tasks_G[index2].RunMe=0;
	}
}

void SCH_Update(void){
	if(SCH_tasks_G[0].pTask){
		if(SCH_tasks_G[0].Delay==0){
			SCH_tasks_G[0].RunMe+=1;
		}else{
			SCH_tasks_G[0].Delay-=1;
		}
	}
}

void SCH_Dispatch_Tasks(void){
	unsigned char Index;
	sTask temp;
	for(Index=0; Index< SCH_MAX_TASKS;Index++){
		if(SCH_tasks_G[Index].RunMe>0){
			(*SCH_tasks_G[Index].pTask)();
			SCH_tasks_G[Index].RunMe-=1;
			temp=SCH_tasks_G[Index];
			SCH_Delete_Task(Index);
			if(temp.Period){
				SCH_Add_Task(temp.pTask, temp.Period*TICK, temp.Period*TICK);
			}
		}
	}
}

void SCH_Delete_Task_Init(const uint32_t TASK_INDEX){
	SCH_tasks_G[TASK_INDEX].pTask=0x0000;
	SCH_tasks_G[TASK_INDEX].Delay=0;
	SCH_tasks_G[TASK_INDEX].Period=0;
	SCH_tasks_G[TASK_INDEX].RunMe=0;
}

void SCH_Delete_Task(const uint32_t TASK_INDEX){
	for(int i=TASK_INDEX;i<SCH_MAX_TASKS-1;i++){
		SCH_tasks_G[i]=SCH_tasks_G[i+1];
	}
	SCH_tasks_G[SCH_MAX_TASKS-1].pTask=0x0000;
	SCH_tasks_G[SCH_MAX_TASKS-1].Delay=0;
	SCH_tasks_G[SCH_MAX_TASKS-1].Period=0;
	SCH_tasks_G[SCH_MAX_TASKS-1].RunMe=0;
}
