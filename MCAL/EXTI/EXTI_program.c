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

static void (*EXTI_CallBack[16])(void) = {NULL};

void MEXTI_voidInit()
{
}

void MEXTI_voidSetSignalLatch(u8 copy_u8Line, u8 Copy_u8EXTISenseMode)
{
  switch (Copy_u8EXTISenseMode)
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
  SET_BIT(EXTI->EXTI_IMR, copy_u8Line);
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
  // TODO: Why used this line not the one below ??
  SET_BIT(EXTI->EXTI_SWIER, copy_u8Line);
  // SET_BIT(EXTI->EXTI_SWIER, SET_BIT(EXTI->EXTI_IMR, copy_u8Line));
}

void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*Copy_fptr)(void))
{
  if (Copy_u8EXTILine < 16)
  {
    if (Copy_fptr == NULL)
    {
    }

    else
    {
      EXTI_CallBack[Copy_u8EXTILine] = Copy_fptr;
    }
  }
}

void EXTI0_IRQHandler(void)
{
  EXTI_CallBack[0]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE0);
}
void EXTI1_IRQHandler(void)
{
  EXTI_CallBack[1]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE1);
}
void EXTI2_IRQHandler(void)
{
  EXTI_CallBack[2]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE2);
}
void EXTI3_IRQHandler(void)
{
  EXTI_CallBack[3]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE3);
}
void EXTI4_IRQHandler(void)
{
  EXTI_CallBack[4]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE4);
}
void EXTI5_IRQHandler(void)
{
  EXTI_CallBack[5]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE5);
}
void EXTI6_IRQHandler(void)
{
  EXTI_CallBack[6]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE6);
}
void EXTI7_IRQHandler(void)
{
  EXTI_CallBack[7]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE7);
}
void EXTI8_IRQHandler(void)
{
  EXTI_CallBack[8]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE8);
}

void EXTI9_IRQHandler(void)
{
  EXTI_CallBack[9]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE9);
}
void EXTI10_IRQHandler(void)
{
  EXTI_CallBack[10]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE10);
}
void EXTI11_IRQHandler(void)
{
  EXTI_CallBack[11]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE11);
}
void EXTI12_IRQHandler(void)
{
  EXTI_CallBack[12]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE12);
}
void EXTI13_IRQHandler(void)
{
  EXTI_CallBack[13]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE13);
}
void EXTI14_IRQHandler(void)
{
  EXTI_CallBack[14]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE14);
}
void EXTI15_IRQHandler(void)
{
  EXTI_CallBack[15]();
  // to clear pending flag
  SET_BIT(EXTI->EXTI_PR, EXTI_LINE15);
}
