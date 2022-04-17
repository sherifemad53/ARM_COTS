/******************************************************************************************************/
/*
 * Author :Sherif Emad
 * Version:1.0
 * Date:28/3/2022
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

/* 
  todo fast Setpin vlaue function
  NOTE: by using BSRR and BRR ,without using | & logic 
  todo LOCKPIN FUCTION
*/

void MGPIO_voidSETPinDirection(uint8 copy_uint8PORT, uint8 copy_uint8PIN, uint8 copy_uint8Mode)
{
  switch (copy_uint8PORT)
  {
  case GPIOA:
    if (copy_uint8PIN < 8)
    {
      GPIOA_CRL &= ~((0b1111) << (copy_uint8PIN * 4));
      GPIOA_CRL |= (copy_uint8Mode << (copy_uint8PIN * 4));
    }
    else if (copy_uint8PIN > 8 && copy_uint8PIN <= 15)
    {
      copy_uint8PIN = copy_uint8PIN - 8;
      GPIOA_CRH &= ~((0b1111) << (copy_uint8PIN * 4));
      GPIOA_CRH |= (copy_uint8Mode << (copy_uint8PIN * 4));
    }
    break;
  case GPIOB:
    if (copy_uint8PIN < 8)
    {
      GPIOB_CRL &= ~((0b1111) << (copy_uint8PIN * 4));
      GPIOB_CRL |= (copy_uint8Mode << (copy_uint8PIN * 4));
    }
    else if (copy_uint8PIN > 8 && copy_uint8PIN <= 15)
    {
      copy_uint8PIN = copy_uint8PIN - 8;
      GPIOB_CRH &= ~((0b1111) << (copy_uint8PIN * 4));
      GPIOB_CRH |= (copy_uint8Mode << (copy_uint8PIN * 4));
    }
    break;
  case GPIOC:
    if (copy_uint8PIN < 3)
    {
      GPIOC_CRL &= ~((0b1111) << (copy_uint8PIN * 4));
      GPIOC_CRL |= (copy_uint8Mode << (copy_uint8PIN * 4));
    }
    break;
  }
}

void MGPIO_voidSETPinValue(uint8 copy_uint8PORT, uint8 copy_uint8PIN, uint8 copy_uint8Value)
{
  switch (copy_uint8PORT)
  {
  case GPIOA:
    if (copy_uint8Value == GPIO_HIGH)
    {
      SET_BIT(GPIOA_ODR, copy_uint8PIN);
    }
    else
    {
      CLR_BIT(GPIOA_ODR, copy_uint8PIN);
    }
    break;
  case GPIOB:
    if (copy_uint8Value == GPIO_HIGH)
    {
      SET_BIT(GPIOB_ODR, copy_uint8PIN);
    }
    else
    {
      CLR_BIT(GPIOB_ODR, copy_uint8PIN);
    }
    break;
  case GPIOC:
    if (copy_uint8Value == GPIO_HIGH)
    {
      SET_BIT(GPIOB_ODR, copy_uint8PIN);
    }
    else
    {
      CLR_BIT(GPIOB_ODR, copy_uint8PIN);
    }
    break;
  }
}

uint8 MGPIO_uint8GetPinValue(uint8 copy_uint8PORT, uint8 copy_uint8PIN)
{
  uint8 LOC_uint8Result = 0;
  switch (copy_uint8PORT)
  {
  case GPIOA:
    LOC_uint8Result = GET_BIT(GPIOA_IDR, copy_uint8PIN);
    break;
  case GPIOB:
    LOC_uint8Result = GET_BIT(GPIOB_IDR, copy_uint8PIN);
    break;
  case GPIOC:
    LOC_uint8Result = GET_BIT(GPIOC_IDR, copy_uint8PIN);
    break;
  }
  return LOC_uint8Result;
}
