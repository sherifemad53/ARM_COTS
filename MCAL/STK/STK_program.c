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

static volatile u32 counter = 0;

void MSTK_voidInit()
{
#if STK_CLKSOURCE == CLK_SOURCE_AHB
  SET_BIT(STK_CTRL, 2);
#elif STK_CLKSOURCE == CLK_SOURCE_AHB_DIV_8
  CLR_BIT(STK_CTRL, 2);
#endif
#if STK_TICKINTEN == ENABLE
  SET_BIT(STK_CTRL, 1);
#endif
#if STK_ENABLE == ENABLE
  SET_BIT(STK_CTRL, 0);
#endif
}

// TODO: To delay 1ms need 1000us so 1000 count
void SysTick_Handler()
{
  counter++;
}

u32 MSTK_u32GetCounter()
{
  return counter;
}

void MSTK_voidDelay(u32 copy_u32MilliSecond)
{
  u32 local_u32Tickstart = STK_u32GetCounter();
  while ((STK_u32GetCounter() - local_u32Tickstart) < copy_u32MilliSecond)
    ;
}

void MSTK_voidLoadOvfTime(u32 copy_u32OvfValue)
{
  if (copy_u32OvfValue < 0xffffff)
  {
    STK_LOAD = copy_u32OvfValue;
  }
}