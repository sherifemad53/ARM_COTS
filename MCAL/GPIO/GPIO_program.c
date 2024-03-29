/**
 * @file GPIO_program.c
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief This is GPIO Driver implemention for ARM_CORTEX_M3 *STM32F38T6*
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
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

/**
 * @brief This function set pin direction input or output
 * 
 * @param copy_u8PORT 
 * @param copy_u8PIN 
 * @param copy_u8Mode 
 */

void MGPIO_voidSETPinDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode)
{
  switch (copy_u8PORT)
  {
  case GPIOA:
    if (copy_u8PIN < 8)
    {
      GPIOA_CRL &= ~((0b1111) << (copy_u8PIN * 4));
      GPIOA_CRL |= (copy_u8Mode << (copy_u8PIN * 4));
    }
    else if (copy_u8PIN > 8 && copy_u8PIN <= 15)
    {
      copy_u8PIN = copy_u8PIN - 8;
      GPIOA_CRH &= ~((0b1111) << (copy_u8PIN * 4));
      GPIOA_CRH |= (copy_u8Mode << (copy_u8PIN * 4));
    }
    break;
  case GPIOB:
    if (copy_u8PIN < 8)
    {
      GPIOB_CRL &= ~((0b1111) << (copy_u8PIN * 4));
      GPIOB_CRL |= (copy_u8Mode << (copy_u8PIN * 4));
    }
    else if (copy_u8PIN > 8 && copy_u8PIN <= 15)
    {
      copy_u8PIN = copy_u8PIN - 8;
      GPIOB_CRH &= ~((0b1111) << (copy_u8PIN * 4));
      GPIOB_CRH |= (copy_u8Mode << (copy_u8PIN * 4));
    }
    break;
  case GPIOC:
    if (copy_u8PIN < 3)
    {
      GPIOC_CRL &= ~((0b1111) << (copy_u8PIN * 4));
      GPIOC_CRL |= (copy_u8Mode << (copy_u8PIN * 4));
    }
    break;
  }
}
/**
 * @brief This function put high or low on the pin configured to be output
 * @see MGPIO_voidSETPinDirection() for info about pin configuration
 * @param copy_u8PORT 
 * @param copy_u8PIN 
 * @param copy_u8Value 
 */
void MGPIO_voidSETPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value)
{
  switch (copy_u8PORT)
  {
  case GPIOA:
    if (copy_u8Value == GPIO_HIGH)
    {
      SET_BIT(GPIOA_ODR, copy_u8PIN);
    }
    else
    {
      CLR_BIT(GPIOA_ODR, copy_u8PIN);
    }
    break;
  case GPIOB:
    if (copy_u8Value == GPIO_HIGH)
    {
      SET_BIT(GPIOB_ODR, copy_u8PIN);
    }
    else
    {
      CLR_BIT(GPIOB_ODR, copy_u8PIN);
    }
    break;
  case GPIOC:
    if (copy_u8Value == GPIO_HIGH)
    {
      SET_BIT(GPIOB_ODR, copy_u8PIN);
    }
    else
    {
      CLR_BIT(GPIOB_ODR, copy_u8PIN);
    }
    break;
  }
}

void MGPIO_voidTogglePin(u8 copy_u8PORT, u8 copy_u8PIN)
{
  switch (copy_u8PORT)
  {
  case GPIOA:
    TOGGLE_BIT(GPIOA_ODR, copy_u8PIN);
    break;
  case GPIOB:
    TOGGLE_BIT(GPIOB_ODR, copy_u8PIN);
    break;
  case GPIOC:
    TOGGLE_BIT(GPIOB_ODR, copy_u8PIN);
    break;
  }
}

u8 MGPIO_u8GetPinValue(u8 copy_u8PORT, u8 copy_u8PIN)
{
  u8 LOC_u8Result = 0;
  switch (copy_u8PORT)
  {
  case GPIOA:
    LOC_u8Result = GET_BIT(GPIOA_IDR, copy_u8PIN);
    break;
  case GPIOB:
    LOC_u8Result = GET_BIT(GPIOB_IDR, copy_u8PIN);
    break;
  case GPIOC:
    LOC_u8Result = GET_BIT(GPIOC_IDR, copy_u8PIN);
    break;
  }
  return LOC_u8Result;
}
