/*
 * OS_private.h
 *
 *  Created on: Nov 26, 2021
 *      Author: DELL
 */

#ifndef OS_OS_PRIVATE_H_
#define OS_OS_PRIVATE_H_

typedef enum{
	RUNNING,
	WAITING,
	SUSPENDED,
	READY
}TASKState_t;

typedef struct{
	u16 periodicity;
	u16 initialdelay;
	TASKState_t state;
	void (*TaskFptr)(void);
}Task_t;


#endif /* OS_OS_PRIVATE_H_ */
