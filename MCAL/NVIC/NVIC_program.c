/**************************************************/
/*Author     :Sherif Emad*/
/*Data         :25/4/2022 */
/*Version      :V01*/
/*******************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidEnableInterrput(u8 copy_u8IntNumber)
{

  if (copy_u8IntNumber >= 0 && copy_u8IntNumber < 31)
  {
    // Note this register writing 0 on it has no effect
    // SET_BIT(NVIC_ISER0, copy_u8IntNumber);
    NVIC_ISER0 = (1 << copy_u8IntNumber);
  }
  else if (copy_u8IntNumber >= 32 && copy_u8IntNumber <= 59)
  {
    copy_u8IntNumber -= 32;
    // Note this register writing 0 on it has no effect
    // SET_BIT(NVIC_ISER0, copy_u8IntNumber);
    NVIC_ISER1 = (1 << copy_u8IntNumber);
  }
  else
  {
  }
}

void MNVIC_voidDisableInterrput(u8 copy_u8IntNumber)
{

  if (copy_u8IntNumber >= 0 && copy_u8IntNumber < 31)
  {
    // Note this register writing 0 on it has no effect
    NVIC_ICER0 = (1 << copy_u8IntNumber);
  }
  else if (copy_u8IntNumber >= 32 && copy_u8IntNumber <= 59)
  {
    copy_u8IntNumber -= 32;
    // Note this register writing 0 on it has no effect
    NVIC_ICER1 = (1 << copy_u8IntNumber);
  }
  else
  {
  }
}

void MNVIC_voidSetPendingFlag(u8 copy_u8IntNumber)
{

  if (copy_u8IntNumber >= 0 && copy_u8IntNumber < 31)
  {
    // Note this register writing 0 on it has no effect
    NVIC_ISPR0 = (1 << copy_u8IntNumber);
  }
  else if (copy_u8IntNumber >= 32 && copy_u8IntNumber <= 59)
  {
    copy_u8IntNumber -= 32;
    // Note this register writing 0 on it has no effect
    NVIC_ISPR1 = (1 << copy_u8IntNumber);
  }
  else
  {
  }
}

void MNVIC_voidClearPendingFlag(u8 copy_u8IntNumber)
{

  if (copy_u8IntNumber >= 0 && copy_u8IntNumber < 31)
  {
    // Note this register writing 0 on it has no effect
    NVIC_ICPR0 = (1 << copy_u8IntNumber);
  }
  else if (copy_u8IntNumber >= 32 && copy_u8IntNumber <= 59)
  {
    copy_u8IntNumber -= 32;
    // Note this register writing 0 on it has no effect
    NVIC_ICPR1 = (1 << copy_u8IntNumber);
  }
  else
  {
  }
}

u8 MNVIC_u8GetActiveFlag(u8 copy_u8IntNumber)
{
  u8 loc_u8Result = 0;
  if (copy_u8IntNumber >= 0 && copy_u8IntNumber < 31)
  {
    loc_u8Result = GET_BIT(NVIC_IABR0, copy_u8IntNumber);
  }
  else if (copy_u8IntNumber >= 32 && copy_u8IntNumber <= 59)
  {
    copy_u8IntNumber -= 32;
    loc_u8Result = GET_BIT(NVIC_IABR0, copy_u8IntNumber);
  }
  else
  {
  }
  return loc_u8Result;
}

void MNVIC_voidSetPriorty(u8 copy_u8IntNumber,u8 copy_u8PriortyNumber){
  if(copy_u8IntNumber>=0 && copy_u8IntNumber <=59){
    
  }
}