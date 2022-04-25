/**************************************************/
/*Author     :Sherif Emad*/
/*Data         :25/4/2022 */
/*Version      :V01*/
/*******************************************/

#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS 0xE000E100

#define NVIC_ISER0 *((u32 *)(NVIC_BASE_ADDRESS + 0x00))/*Enable extrenal interrput from 0-31*/
#define NVIC_ISER1 *((u32 *)(NVIC_BASE_ADDRESS + 0x04))/*Enable extrenal interrput from 32-63*/

#define NVIC_ICER0 *((u32 *)(NVIC_BASE_ADDRESS + 0x80))/*Disable extrenal interrput from 0-31*/
#define NVIC_ICER1 *((u32 *)(NVIC_BASE_ADDRESS + 0x84))/*Disable extrenal interrput from 32-59*/

#define NVIC_ISPR0 *((u32 *)(NVIC_BASE_ADDRESS + 0x100))/*Enable pending flag for extrenal interrput from 32-59*/
#define NVIC_ISPR1 *((u32 *)(NVIC_BASE_ADDRESS + 0x104))/*Enable pending flag for interrput from 32-59*/

#define NVIC_ICPR0 *((u32 *)(NVIC_BASE_ADDRESS + 0x180))/*Disable pending flag for external interrput from 32-59*/
#define NVIC_ICPR1 *((u32 *)(NVIC_BASE_ADDRESS + 0x184))/*Disable pending flag for extrenal interrput from 32-59*/

#define NVIC_IABR0 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x200))/*Read active flag for external interrput from 32-59*/
#define NVIC_IABR1 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x204))/*Read active flag for extrenal interrput from 32-59*/

#define NVIC_IPR0 *((u32 *)(NVIC_BASE_ADDRESS + 0x300))/*Set priorty for extrenal interrput*/
 



#endif // !_NVIC_PRIVATE_H