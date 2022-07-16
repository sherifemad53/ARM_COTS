/**************************************************/
/*  Author       :Sherif Emad                     */
/*  Data         :5/6/2022                       */
/*  Version      :V01                             */
/**************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

// TODO Assigment 200ms led ping pong animation

// Note: Deffirance between synchrounos function and Asynchrounos function
//  1- synchrounos function means it must finish before all it code before returning like while loop , etc. as it doesn't set value and return
//  2- while asynchrounos is the opposite of synchrounos it sets value and gets out of the function

void (*GLOBAL_voidCallBack)(void);
volatile u8SetInterval = 0;

void MSTK_voidInit() {
#if STK_CLKSOURCE == CLK_SOURCE_AHB
	SET_BIT(MSTK->CTRL, 2);
#elif STK_CLKSOURCE == CLK_SOURCE_AHB_DIV_8
	CLR_BIT(STK_CTRL, 2);
#endif
}

// TODO: To delay 1ms need 1000us so 1000 count

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks) {
	MSTK->VAL = 0;
	MSTK->LOAD = Copy_u32Ticks;
//   SET_BIT(MSTK->CTRL, STK_ENABLE_BIT);
	MSTK->CTRL |= 0x01;
	while (GET_BIT(MSTK->CTRL, STK_COUNTFLAG_BIT) != 1)
		;
//   SET_BIT(MSTK->CTRL, STK_ENABLE_BIT);
	MSTK->CTRL = 0x00;
	MSTK->LOAD = 0;
	MSTK->VAL = 0;
}

void MSTK_voidSetIntervelSingle(u32 Copy_u32Ticks, void (*Copy_fptr)(void)) {
	MSTK->VAL = 0;
	MSTK->LOAD = Copy_u32Ticks;
	u8SetInterval = SINGLE;
	GLOBAL_voidCallBack = Copy_fptr;
//  SET_BIT(MSTK->CTRL, STK_TICKINTEN_BIT);
//  SET_BIT(MSTK->CTRL, STK_ENABLE_BIT);
	MSTK->CTRL |= 0x03;
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_fptr)(void)) {
	MSTK->VAL = 0;

	MSTK->LOAD = Copy_u32Ticks;
	GLOBAL_voidCallBack = Copy_fptr;
	u8SetInterval = PERIODIC;
//  SET_BIT(MSTK->CTRL, STK_TICKINTEN_BIT);
//  SET_BIT(MSTK->CTRL, STK_ENABLE_BIT);
	MSTK->CTRL |= 0x03;
}

void MSTK_voidStopInterval() {
	MSTK->CTRL = 0x00;
//  CLR_BIT(MSTK->CTRL, STK_TICKINTEN_BIT);
//  SET_BIT(MSTK->CTRL, STK_ENABLE_BIT);
	MSTK->LOAD = 0;
	MSTK->VAL = 0;
}

u32 MSTK_u32GetElapesdTime(void) {
	return MSTK->VAL;
}
u32 MSTK_u32GetRemainingTime(void) {
	return MSTK->LOAD - MSTK->VAL;
}

void SysTick_Handler(void) {
	u8 Local_u8Temp;
	GLOBAL_voidCallBack();
	if (u8SetInterval == SINGLE) {
		MSTK_voidStopInterval();
	}

	Local_u8Temp = GET_BIT(MSTK->CTRL, STK_COUNTFLAG_BIT);
}

// u32 MSTK_u32GetCounter()
// {
//   return counter;
// }

// void MSTK_voidDelay(u32 copy_u32MilliSecond)
// {
//   u32 local_u32Tickstart = STK_u32GetCounter();
//   while ((STK_u32GetCounter() - local_u32Tickstart) < copy_u32MilliSecond)
//     ;
// }

// void MSTK_voidLoadOvfTime(u32 copy_u32OvfValue)
// {
//   if (copy_u32OvfValue < 0xffffff)
//   {
//     STK_LOAD = copy_u32OvfValue;
//   }
// }
