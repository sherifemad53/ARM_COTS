/**************************************************/
/*  Author       :Sherif Emad                     */
/*  Data         :25/4/2022                       */
/*  Version      :V01                             */
/**************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit()
{
#define SCB_BASE_ADDRESS 0xE000ED00
#define SCB_AIRCR *((volatile u32 *)(SCB_BASE_ADDRESS + 0x0C))
  SCB_AIRCR = NIVC_GROUP_SUB;
}

void MNVIC_voidSetPriorty(s8 copy_s8IntNumber, u8 copy_u8GroupPriority, u8 copy_u8SubPriority)
{
  u8 Local_u8Proirity = copy_u8SubPriority | copy_u8GroupPriority << (NIVC_GROUP_SUB - MNVIC_GROUP_4_SUB_0) / 256;

  if (copy_s8IntNumber >= 0 && copy_s8IntNumber <= 59)
  {
    NVIC_IPR[copy_s8IntNumber] = Local_u8Proirity << 4;
  }
}

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

// TODO: wrong function as i understand
//  void MNVIC_voidSetPriorty(s8 copy_s8IntNumber, u8 copy_u8GroupPriority, u8 copy_u8SubPriority, u32 copy_u32Group)
//  {
//    u8 Local_u8Proirity = copy_u8SubPriority | copy_u8GroupPriority << (copy_u32Group - MNVIC_GROUP_4_SUB_0) / 256;

//   if (copy_s8IntNumber >= 0 && copy_s8IntNumber <= 59)
//   {
//     NVIC_IPR[copy_s8IntNumber] = Local_u8Proirity << 4;
//   }
//   SCB_AIRCR = copy_u32Group;
// }
