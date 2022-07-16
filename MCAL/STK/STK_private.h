/**************************************************/
/*  Author       :Sherif Emad                     */
/*  Data         :5/6/2022                       */
/*  Version      :V01                             */
/**************************************************/

#ifndef _STK_PRIAVTE_H
#define _STK_PRIAVTE_H

#define SINGLE 0
#define PERIODIC 1
typedef struct STK_private
{
  volatile u32 CTRL;
  volatile u32 LOAD;
  volatile u32 VAL;
  volatile u32 CALIB;
}MSTK_t;


#define STK_BASS_ADDRESS 0xE000E010
#define MSTK ((volatile MSTK_t*) STK_BASS_ADDRESS)

#define CLK_SOURCE_AHB 0
#define CLK_SOURCE_AHB_DIV_8 1

#define STK_TICKINTEN_BIT 1
#define STK_ENABLE_BIT 0
#define STK_COUNTFLAG_BIT 16


// #define STK_CTRL *((volatile u32 *)STK_BASS_ADDRESS + 0x00)
// #define STK_LOAD *((volatile u32 *)STK_BASS_ADDRESS + 0x04)
// #define STK_VAL *((volatile u32 *)STK_BASS_ADDRESS + 0x08)
// #define STK_CALIB *((volatile u32 *)STK_BASS_ADDRESS + 0x0C)

#endif // !_STK_PRIAVTE_H