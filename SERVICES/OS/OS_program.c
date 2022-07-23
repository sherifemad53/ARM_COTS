/**************************************************/
/*  Author       :Sherif Emad                     */
/*  Data         :17/7/2022                       */
/*  Version      :V02                             */
/**************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

static Task_t OS_TaskQueue[NO_OF_TASKS] = {{NULL}};

void Scheduler(void)
{
	// static u16 tickcount = 0;
	for (u8 i = 0; i < NO_OF_TASKS; i++)
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

void OS_voidStartScheluler(void)
{
	// todo implement here SYSTICK TIMER SETINTERVALPERIODIC with the required tick time
	while (1)
	{
	}
}

void OS_voidCreateTask(u16 periodicity, u8 TaskID, u16 initaildelay,
											void (*TaskFptr)(void))
{
	OS_TaskQueue[TaskID].periodicity = periodicity;
	OS_TaskQueue[TaskID].TaskFptr = TaskFptr;
	OS_TaskQueue[TaskID].state = READY;
	OS_TaskQueue[TaskID].initialdelay = initaildelay;
}

// todo change state to suspend
void OS_voidEndTask(Task_t *task)
{
	task->state = SUSPENDED;
}


//todo change task to resume
void OS_voidResumeTask(Task_t *task)
{
	task->state = READY;
}