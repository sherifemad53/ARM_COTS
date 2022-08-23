/**
 * @file USART_program.c
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

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"

void MUSART1_voidInit(void)
{
  // MRCC_voidInitSysClock();
  MRCC_voidEnableClock(RCC_APB2_IOPAEN);
  MRCC_voidEnableClock(RCC_APB2, RCC_APB2_USART1EN);
  // Setting TX1 as output ALTFUNCTION
  MGPIO_voidSETPinDirection(GPIOA, PIN9, OUTPUT_SPEED_50MHZ_ALTFUNCTION_PUSHPULL);
  // Setting RX1 as Floating Input
  MGPIO_voidSETPinDirection(GPIOA, PIN10, INPUT_FLOATING);

  // todo change 8MHz to fclk
  f32 Local_f32BaudRateDiv = 8000000 / (16 * USART1_BUADRATE);

  u16 MANTISA = (u16)Local_f32BaudRateDiv;
  u16 FRACTION = (u16)((Local_f32BaudRateDiv - MANTISA) * 16);

  // MUSART1->BRR = (MANTISA << 4) | FRACTION;

  MUSART1->BRR = 0x45;

  SET_BIT(MUSART1->CR1, 3); // transmitter enable
  SET_BIT(MUSART1->CR1, 2); // reciver enable

  SET_BIT(MUSART1->CR1, 13); // enable USART1 driver
}

void MUSART1_voidTransit(u8 Copy_u8Arr[])
{
  u8 Local_u8Counter=0;
  while (Copy_u8Arr[Local_u8Counter] != '\0')
  {
    MUSART1->DR = Copy_u8Arr[Local_u8Counter];
    while (GET_BIT(MUSART1->SR, 6) != 1)
      ;
    Local_u8Counter++;
  }
}

u8 MUSART1_u8Recevice()
{
  u8 Local_u8Temp;
  u16 timeout = 0;

  while (GET_BIT(MUSART1->SR, 5) == 0)
  {
    //Note: important to use Timeout in polling function incase error occurs it doesn't frezze the microcontroller
    timeout++;
    if (timeout == 10000)
    {
      Local_u8Temp = 255;
      break;
    }
  }
  if (Local_u8Temp == 0)
  {
    Local_u8Temp = MUSART1->DR;
  }
  return Local_u8Temp;
}
