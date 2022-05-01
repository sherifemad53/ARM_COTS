/**************************************************/
/*Author     :Sherif Emad*/
/*Data         :25/4/2022 */
/*Version      :V01*/
/*******************************************/

#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H

void MNVIC_voidEnableInterrput(u8 copy_u8IntNumber);
void MNVIC_voidDisableInterrput(u8 copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(u8 copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag(u8 copy_u8IntNumber);

//TODO understand why we didi this?
#define GROUP3 0x05FA0300
#define GROUP4 0x05FA4300
#define GROUP5 0x05FA0500
#define GROUP6 0x05FA0600
#define GROUP7 0x05FA0700

#endif // !_NVIC_INTERFACE_H
