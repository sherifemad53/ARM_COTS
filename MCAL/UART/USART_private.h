/**
 * @file USART_private.h
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _USART_PRIAVTE_H
#define _USART_PRIAVTE_H

typedef struct USART_private
{
  volatile u32 SR;
  volatile u32 DR;
  volatile u32 BRR;
  volatile u32 CR1;
  volatile u32 CR2;
  volatile u32 CR3;
  volatile u32 GTPR;  
}MUSART_t;


#define USART1_BASS_ADDRESS 0x40013800
#define USART2_BASS_ADDRESS 0x40004400
#define USART3_BASS_ADDRESS 0x40004800


#define MUSART1 ((volatile MUSART_t*) USART1_BASS_ADDRESS)
#define MUSART2 ((volatile MUSART_t*) USART2_BASS_ADDRESS)
#define MUSART3 ((volatile MUSART_t*) USART3_BASS_ADDRESS)

#endif // !_USART_PRIAVTE_H