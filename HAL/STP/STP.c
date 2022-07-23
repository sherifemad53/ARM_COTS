/***************************************************************************/
/* Name:Sherif Emad Saad                                                   */
/* Version:v1                                                              */
/* Date:23/7/2022                                                         */
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

// Serial to Parallel communication
#include "STP.h"

void HSTP_voidInit(void)
{
  MRCC_voidInitSysClock();
  // todo if he selected GPIOB or GPIOC not a how to handle that
  MRCC_voidEnableClock(RCC_APB1, RCC_APB2_IOPAEN);

  MGPIO_voidSETPinDirection(STP_DATAIN_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(STP_OUTENABLE_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(STP_SHIFTCLOCK_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  // MGPIO_voidSETPinDirection(STP_DATAIN_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);

  MSTK_voidInit();
}

void HSTP_voidShiftOut(u8 Copy_u8DataIn, u8 Copy_u8NumberOfShiftedBits)
{

  for (s8 Local_s8Counter = 7; Local_s8Counter >= 0; Local_s8Counter--)
  {
    if (GET_BIT(Copy_u8DataIn, Local_s8Counter) == 1)
    {
      MGPIO_voidSETPinValue(STP_DATAIN_PIN, GPIO_HIGH);
    }
    else
    {
      MGPIO_voidSETPinValue(STP_DATAIN_PIN, GPIO_LOW);
    }
    MGPIO_voidSETPinValue(STP_SHIFTCLOCK_PIN, GPIO_HIGH);
    MSTK_voidSetBusyWait(1);
    MGPIO_voidSETPinValue(STP_SHIFTCLOCK_PIN, GPIO_LOW);
    MSTK_voidSetBusyWait(1);
  }
  MGPIO_voidSETPinValue(STP_LATCH_PIN, GPIO_HIGH);
  MSTK_voidSetBusyWait(1);
  MGPIO_voidSETPinValue(STP_LATCH_PIN, GPIO_LOW);
  MSTK_voidSetBusyWait(1);
}

void HSTP_voidSendSynchronus(u8 Copy_u8DataIn)
{

  for (s8 Local_s8Counter = 7; Local_s8Counter >= 0; Local_s8Counter--)
  {
    if (GET_BIT(Copy_u8DataIn, Local_s8Counter) == 1)
    {
      MGPIO_voidSETPinValue(STP_DATAIN_PIN, GPIO_HIGH);
    }
    else
    {
      MGPIO_voidSETPinValue(STP_DATAIN_PIN, GPIO_LOW);
    }
    MGPIO_voidSETPinValue(STP_SHIFTCLOCK_PIN, GPIO_HIGH);
    MSTK_voidSetBusyWait(1);
    MGPIO_voidSETPinValue(STP_SHIFTCLOCK_PIN, GPIO_LOW);
    MSTK_voidSetBusyWait(1);
  }
  MGPIO_voidSETPinValue(STP_LATCH_PIN, GPIO_HIGH);
  MSTK_voidSetBusyWait(1);
  MGPIO_voidSETPinValue(STP_LATCH_PIN, GPIO_LOW);
  MSTK_voidSetBusyWait(1);
}