/***************************************************************************/
/* Name:Sherif Emad Saad                                                   */
/* Version:v1                                                              */
/* Date:14/7/2022                                                         */
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMATRIX.h"

void LEDMATRIX_voidInit()
{
  /*Init rows pins as output*/
  MGPIO_voidSETPinDirection(LEDMATRIX_ROW0_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(LEDMATRIX_ROW1_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(LEDMATRIX_ROW2_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(LEDMATRIX_ROW3_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(LEDMATRIX_ROW4_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(LEDMATRIX_ROW5_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(LEDMATRIX_ROW6_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(LEDMATRIX_ROW7_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);

  /*Init columns pins as output*/
  MGPIO_voidSETPinDirection(LEDMATRIX_COLUMN0_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(LEDMATRIX_COLUMN1_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(LEDMATRIX_COLUMN2_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(LEDMATRIX_COLUMN3_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(LEDMATRIX_COLUMN4_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(LEDMATRIX_COLUMN5_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(LEDMATRIX_COLUMN6_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
  MGPIO_voidSETPinDirection(LEDMATRIX_COLUMN7_PIN, OUTPUT_SPEED_2MHZ_PUSHPULL);
}


static void SetRowValue(u8 Copy_u8Value)
{
  u8 Local_u8Temp;
  Local_u8Temp = GET_BIT(Copy_u8Value, 0);
  MGPIO_voidSETPinValue(LEDMATRIX_ROW0_PIN, Local_u8Temp);

  Local_u8Temp = GET_BIT(Copy_u8Value, 1);
  MGPIO_voidSETPinValue(LEDMATRIX_ROW1_PIN, Local_u8Temp);

  Local_u8Temp = GET_BIT(Copy_u8Value, 2);
  MGPIO_voidSETPinValue(LEDMATRIX_ROW2_PIN, Local_u8Temp);
  
  Local_u8Temp = GET_BIT(Copy_u8Value, 3);
  MGPIO_voidSETPinValue(LEDMATRIX_ROW3_PIN, Local_u8Temp);
  
  Local_u8Temp = GET_BIT(Copy_u8Value, 4);
  MGPIO_voidSETPinValue(LEDMATRIX_ROW4_PIN, Local_u8Temp);
  
  Local_u8Temp = GET_BIT(Copy_u8Value, 5);
  MGPIO_voidSETPinValue(LEDMATRIX_ROW5_PIN, Local_u8Temp);
  
  Local_u8Temp = GET_BIT(Copy_u8Value, 6);
  MGPIO_voidSETPinValue(LEDMATRIX_ROW6_PIN, Local_u8Temp);
  
  Local_u8Temp = GET_BIT(Copy_u8Value, 7);
  MGPIO_voidSETPinValue(LEDMATRIX_ROW7_PIN, Local_u8Temp);

}

static void DisableColumns(void){

  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN0_PIN, GPIO_HIGH);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN1_PIN, GPIO_HIGH);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN2_PIN, GPIO_HIGH);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN3_PIN, GPIO_HIGH);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN4_PIN, GPIO_HIGH);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN5_PIN, GPIO_HIGH);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN6_PIN, GPIO_HIGH);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN7_PIN, GPIO_HIGH);
}


void LEDMATRIX_voidDisplay(u8 *Copy_u8ARR)
{
  // enable column 0
  DisableColumns();
  SetRowValue(Copy_u8ARR[0]);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN0_PIN, GPIO_LOW);
  MSTK_voidSetBusyWait(2500);

  // enable column 1
  DisableColumns();
  SetRowValue(Copy_u8ARR[1]);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN1_PIN, GPIO_LOW);
  MSTK_voidSetBusyWait(2500);
 
  // enable column 2
  DisableColumns();
  SetRowValue(Copy_u8ARR[2]);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN2_PIN, GPIO_LOW);
  MSTK_voidSetBusyWait(2500);
 
  // enable column 3
  DisableColumns();
  SetRowValue(Copy_u8ARR[3]);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN3_PIN, GPIO_LOW);
  MSTK_voidSetBusyWait(2500);
 
  // enable column 4
  DisableColumns();
  SetRowValue(Copy_u8ARR[4]);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN4_PIN, GPIO_LOW);
  MSTK_voidSetBusyWait(2500);
 
  // enable column 5
  DisableColumns();
  SetRowValue(Copy_u8ARR[5]);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN5_PIN, GPIO_LOW);
  MSTK_voidSetBusyWait(2500);
 
  // enable column 6
  DisableColumns();
  SetRowValue(Copy_u8ARR[6]);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN6_PIN, GPIO_LOW);
  MSTK_voidSetBusyWait(2500);
  
  // enable column 7
  DisableColumns();
  SetRowValue(Copy_u8ARR[7]);
  MGPIO_voidSETPinValue(LEDMATRIX_COLUMN7_PIN, GPIO_LOW);
  MSTK_voidSetBusyWait(2500);
}


