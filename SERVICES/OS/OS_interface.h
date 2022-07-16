/*
 * OS_interface.h
 *
 *  Created on: Nov 26, 2021
 *      Author: DELL
 */

#ifndef OS_OS_INTERFACE_H_
#define OS_OS_INTERFACE_H_

void OS_vidStartScheluler(void);

void OS_vidCreateTask(u16 periodicity, u8 TaskID,u16 initaildelay, void (*fptr)(void));


#endif /* OS_OS_INTERFACE_H_ */
