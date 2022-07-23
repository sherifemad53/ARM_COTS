/***************************************************************************/
/* Name:Sherif Emad Saad                                                   */
/* Version:v1                                                              */
/* Date:20/7/2022                                                          */
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "DAC_interface.h"
#include "DAC_config.h"
#include "DAC_private.h"

// todo 1- output on dac words (hello help hungry water) using dac,lm386 and remote to choose between them using 4 buttons on remote

// todo 2- frequency change the song output by using remote 4 buttons to change the frequency

u8 *GLOBAL_u8ARR;
u16 GLOBAL_u16ARRSIZE = 0;
void MDAC_voidInit(void)
{
  MGPIO_voidSETPinDirection(MDAC_PIN0_BIT0, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(MDAC_PIN0_BIT1, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(MDAC_PIN0_BIT2, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(MDAC_PIN0_BIT3, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(MDAC_PIN0_BIT4, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(MDAC_PIN0_BIT5, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(MDAC_PIN0_BIT6, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(MDAC_PIN0_BIT7, OUTPUT_SPEED_2MHZ_PUSHPULL);
#if MDAC_BITS > 8
  MGPIO_voidSETPinDirection(MDAC_PIN0_BIT8, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(MDAC_PIN0_BIT9, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(MDAC_PIN0_BIT10, OUTPUT_SPEED_2MHZ_PUSHPULL);
#endif
}

void MDAC_voidFrequencyChanger(void)
{
}

void MDAC_voidPlaySound(u8 *Copy_u8ARR, u16 Copy_u16Size)
{
  GLOBAL_u8ARR = Copy_u8ARR;
  GLOBAL_u16ARRSIZE = Copy_u16Size;
  MSTK_voidSetIntervalPeriodic(2500, Playsound);
}

volatile u16 i = 0;
void Playsound(void)
{
  for (i = 0; i < GLOBAL_u16ARRSIZE; i++)
  {
    outputsound(GLOBAL_u8ARR[i]);
  }
}

static void outputsound(u8 Copy_u8Value)
{
  u8 Local_u8Temp;
  Local_u8Temp = GET_BIT(Copy_u8Value, 0);
  MGPIO_voidSETPinValue(MDAC_PIN0_BIT0, Local_u8Temp);

  Local_u8Temp = GET_BIT(Copy_u8Value, 1);
  MGPIO_voidSETPinValue(MDAC_PIN0_BIT1, Local_u8Temp);

  Local_u8Temp = GET_BIT(Copy_u8Value, 2);
  MGPIO_voidSETPinValue(MDAC_PIN0_BIT2, Local_u8Temp);

  Local_u8Temp = GET_BIT(Copy_u8Value, 3);
  MGPIO_voidSETPinValue(MDAC_PIN0_BIT3, Local_u8Temp);

  Local_u8Temp = GET_BIT(Copy_u8Value, 4);
  MGPIO_voidSETPinValue(MDAC_PIN0_BIT4, Local_u8Temp);

  Local_u8Temp = GET_BIT(Copy_u8Value, 5);
  MGPIO_voidSETPinValue(MDAC_PIN0_BIT5, Local_u8Temp);

  Local_u8Temp = GET_BIT(Copy_u8Value, 6);
  MGPIO_voidSETPinValue(MDAC_PIN0_BIT6, Local_u8Temp);

  Local_u8Temp = GET_BIT(Copy_u8Value, 7);
  MGPIO_voidSETPinValue(MDAC_PIN0_BIT7, Local_u8Temp);
#if MDAC_BITS > 8
#endif
}