/***************************************************************************/
/* Name:Sherif Emad Saad                                                   */
/* Version:v1                                                              */
/* Date:27/4/2022                                                          */

#ifndef SCB_PRIVATE_H
#define SCB_PRIVATE_H

#define SCB_BASE_ADDRESS 0xE000ED00
#define SCB_AIRCR *((volatile u32 *)(SCB_BASE_ADDRESS + 0x0C))

#endif // !SCB_PRIVATE_H