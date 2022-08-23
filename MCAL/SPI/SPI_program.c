/**
 * @file SPI_program.c
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void MSPI_voidInit(void)
{
#if SPI_MODE == MASTER_MODE
  MSPI1->CR1 = 0x0347;

#elif SPI_MODE == SLAVE_MODE
#endif
}

u8 MSPI_u8SendReceviceSync(u8 Copy_u8SendDaTa)
{

  MGPIO_voidSETPinValue(MSPI_SLAVE_PIN, GPIO_HIGH);

  MSPI1->DR = Copy_u8SendDaTa;

  while (GET_BIT(MSPI1->SR, 7) == 1)
    ;

  MGPIO_voidSETPinValue(MSPI_SLAVE_PIN, GPIO_HIGH);

  return (MSPI1->DR);
}

void MSPI_voidSendReceviceAsync(u8 Copy_u8SendDaTa, void (*Copy_Fptr)(u8))
{

  // todo this function
  MGPIO_voidSETPinValue(MSPI_SLAVE_PIN, GPIO_HIGH);

  MSPI1->DR = Copy_u8SendDaTa;

  while (GET_BIT(MSPI1->SR, 7) == 1)
    ;

  MGPIO_voidSETPinValue(MSPI_SLAVE_PIN, GPIO_HIGH);

  return (MSPI1->DR);
}
