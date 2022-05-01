/***************************************************************************/
/* Name:Sherif Emad Saad                                                   */
/* Version:v1                                                              */
/* Date:27/4/2022                                                          */

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


typedef struct EXTI_t
{
  volatile u32 EXTI_IMR;
  volatile u32 EXTI_EMR;
  volatile u32 EXTI_RTSR;
  volatile u32 EXTI_FTSR;
  volatile u32 EXTI_SWIER;
  volatile u32 EXTI_PR;
} EXTI_t;

#define EXTI ((volatile EXTI_t*) 0x40010400)


#define RISING 0
#define FALLING 0
#define ONCHANGE 0

#endif // !EXTI_PRIVATE_H