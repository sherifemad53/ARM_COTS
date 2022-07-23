/***************************************************************************/
/* Name:Sherif Emad Saad                                                   */
/* Version:v1                                                              */
/* Date:23/7/2022                                                          */
/***************************************************************************/

#ifndef _STP_H
#define _STP_H

#include "STD_TYPES.h" 

/* Please wire pair (PORT , PIN) EX: (GPIOA,PIN0)*/
//Note: PIN2 GPIOB not on board also PIN3,PIN4 don't use

#define STP_OUTENABLE_PIN GPIOA,PIN0
#define STP_DATAIN_PIN GPIOA,PIN1
#define STP_SHIFTCLOCK_PIN GPIOA,PIN2
#define STP_LATCH_PIN GPIOA,PIN3

void HSTP_voidInit(void);
void HSTP_voidShiftOut(u8 Copy_u8DataIn, u8 Copy_u8NumberOfShiftedBits);
void HSTP_voidSendSynchronus(u8 Copy_u8DataIn);

#endif // !_STP_H