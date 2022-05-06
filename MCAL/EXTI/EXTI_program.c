/***************************************************************************/
/* Name:Sherif Emad Saad                                                   */
/* Version:v1                                                              */
/* Date:27/4/2022                                                          */
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void MEXTI_voidInit(u8 copy_u8Line, u8 copy_u8SignalLatch)
{
  switch (copy_u8SignalLatch)
  {
  case EXTI_RISING:
    SET_BIT(EXTI->EXTI_RTSR, copy_u8Line);
    break;
  case EXTI_FALLING:
    SET_BIT(EXTI->EXTI_FTSR, copy_u8Line);
    break;
  case EXTI_ONCHANGE:
    SET_BIT(EXTI->EXTI_RTSR, copy_u8Line);
    SET_BIT(EXTI->EXTI_FTSR, copy_u8Line);
    break;
  }
}

void MEXTI_voidEnableEXTI(u8 copy_u8Line)
{
  SET_BIT(EXTI->EXTI_IMR, copy_u8Line);
}

void MEXTI_voidDisableEXTI(u8 copy_u8Line)
{
  CLR_BIT(EXTI->EXTI_IMR, copy_u8Line);
}

void MEXTI_voidSoftwareTriggerEXTI(u8 copy_u8Line)
{
  //TODO: Why used this line not the one below ?? 
  SET_BIT(EXTI->EXTI_SWIER, copy_u8Line);
  //SET_BIT(EXTI->EXTI_SWIER, SET_BIT(EXTI->EXTI_IMR, copy_u8Line));
}
