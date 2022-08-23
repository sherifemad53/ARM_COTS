/**
 * @file IRRECIVER.c
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"

#include "IRRECIVER.h"

volatile u8 u8Startflag = 0;
volatile u32 u32FrameData[50] = { 0 };
volatile u8 u8EdgeCounter = 0;

u8 IRREC_u8GetPressedButton(void){
	//todo get also address
	//todo repeat code
	//check for starting bit if valid in this type of protocol
  volatile u8 Local_u8PressedButton = 0;
	
  if (u32FrameData[0] > 10000 && u32FrameData[0] < 14000) {
		//sets and clear data bits in u8PressedButon to get the value of pressedbutton
		for (u8 i = 0; i < 8; i++) {
			if (u32FrameData[17 + i] >= 2000 && u32FrameData[17 + i] <= 2300) {
				SET_BIT(Local_u8PressedButton, i);
			} else {
				CLR_BIT(Local_u8PressedButton, i);
			}
		}
	}

	u8Startflag = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter = 0;
  return Local_u8PressedButton;
}


void voidTakeAction(void) {

}

void voidReadFrame(void) {
	if (u8Startflag == 0) {
		MSTK_voidSetIntervelSingle(1000000, voidTakeAction);
		u8Startflag = 1;
	} else {
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapesdTime();
		MSTK_voidSetIntervelSingle(1000000, voidTakeAction);
		u8EdgeCounter++;
	}
}