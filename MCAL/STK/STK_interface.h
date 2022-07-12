/**************************************************/
/*  Author       :Sherif Emad                     */
/*  Data         :5/6/2022                       */
/*  Version      :V01                             */
/**************************************************/

#ifndef _STK_INTERFACE_H
#define _STK_INTERFACE_H

void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSetIntervelSingle(u32 Copy_u32Ticks, void (*Copy_fptr)(void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_fptr)(void));
void MSTK_voidStopInterval(void);
u32 MSTK_u32GetElapesdTime(void);
u32 MSTK_u32GetRemainingTime(void);

#endif // !_STK_INTERFACE_H