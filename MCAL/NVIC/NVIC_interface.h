/**************************************************/
/*Author     :Sherif Emad*/
/*Data         :25/4/2022 */
/*Version      :V01*/
/*******************************************/

#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H

void MNVIC_voidInit(void);
void MNVIC_voidSetPriorty(s8 copy_s8IntNumber, u8 copy_u8GroupPriority, u8 copy_u8SubPriority);
void MNVIC_voidEnableInterrput(u8 copy_u8IntNumber);
void MNVIC_voidDisableInterrput(u8 copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(u8 copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag(u8 copy_u8IntNumber);

typedef enum{
	EXTI0=6,
	EXTI1=7,
	EXTI2=8,
	EXTI3=9,
	EXTI4=10,
}INTERRPUT_NO;



//TODO understand why we did this?
#define MNVIC_GROUP_4_SUB_0 0x05FA0300
#define MNVIC_GROUP_3_SUB_1 0x05FA4300
#define MNVIC_GROUP_2_SUB_2 0x05FA0500
#define MNVIC_GROUP_1_SUB_3 0x05FA0600
#define MNVIC_GROUP_0_SUB_4 0x05FA0700

#endif // !_NVIC_INTERFACE_H
