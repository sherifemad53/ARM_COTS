/**
 * @file USART_interface.h
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _USART_INTERFACE_H
#define _USART_INTERFACE_H

void MUSART1_voidInit(void);
void MUSART1_voidTransit(u8 Copy_u8Arr[]);
u8 MUSART1_u8Recevice();

#endif // !_USART_INTERFACE_H