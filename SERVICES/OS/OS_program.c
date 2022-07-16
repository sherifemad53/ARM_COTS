/*
 * OS_program.c
 *
 *  Created on: Nov 26, 2021
 *      Author: DELL
 */

#include "../lib/STD_TYPES.h"
#include "../lib/BIT_MATH.h"

#include "../TIMERS/TIMERS_interface.h"
#include "../GIE/GIE_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

static Task_t OS_TaskQueue[NO_OF_TASKS]; //= { { NULL } };

void Scheduler(void)
{
	// static u16 tickcount = 0;
	for (int i = 0; i < NO_OF_TASKS; i++)
	{
		//		if (tickcount % OS_TaskQueue[i].periodicity
		//				/*&& */) {
		//			OS_TaskQueue[i].TaskFptr();
		//		}
		if (OS_TaskQueue[i].state == READY)
		{
			if (OS_TaskQueue[i].initialdelay == 0)
			{
				OS_TaskQueue[i].initialdelay = OS_TaskQueue[i].periodicity;
				OS_TaskQueue[i].TaskFptr();
			}
			else
			{
				OS_TaskQueue[i].initialdelay--;
			}
		}
	}
}

void OS_vidStartScheluler(void)
{
  //todo implement here SYSTICK TIMER SETINTERVALPERIODIC with the required tick time
	while (1)
	{
	}
}

void OS_vidCreateTask(u16 periodicity, u8 TaskID, u16 initaildelay,
											void (*TaskFptr)(void))
{
	OS_TaskQueue[TaskID].periodicity = periodicity;
	OS_TaskQueue[TaskID].TaskFptr = TaskFptr;
	OS_TaskQueue[TaskID].state = READY;
	OS_TaskQueue[TaskID].initialdelay = initaildelay;
}
