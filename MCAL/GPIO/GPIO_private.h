/**
 * @file GPIO_private.h
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief ALl registers for this driver are defined here and Also some private stuff that user won't need to use 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS 0x40010800
#define GPIOB_BASE_ADDRESS 0x40010C00
#define GPIOC_BASE_ADDRESS 0x40011000

/*Register addresses for PORTA*/
#define GPIOA_CRL *((volatile u32*)(GPIOA_BASE_ADDRESS+0x00))
#define GPIOA_CRH *((volatile u32*)(GPIOA_BASE_ADDRESS+0x04))
#define GPIOA_IDR *((volatile u32*)(GPIOA_BASE_ADDRESS+0x08))
#define GPIOA_ODR *((volatile u32*)(GPIOA_BASE_ADDRESS+0x0C))
#define GPIOA_BSR *((volatile u32*)(GPIOA_BASE_ADDRESS+0x10))
#define GPIOA_BRR *((volatile u32*)(GPIOA_BASE_ADDRESS+0x14))
#define GPIOA_LCK *((volatile u32*)(GPIOA_BASE_ADDRESS+0x18))

/*Register addresses for PORTB*/
#define GPIOB_CRL *((volatile u32*)(GPIOB_BASE_ADDRESS+0x00))
#define GPIOB_CRH *((volatile u32*)(GPIOB_BASE_ADDRESS+0x04))
#define GPIOB_IDR *((volatile u32*)(GPIOB_BASE_ADDRESS+0x08))
#define GPIOB_ODR *((volatile u32*)(GPIOB_BASE_ADDRESS+0x0C))
#define GPIOB_BSR *((volatile u32*)(GPIOB_BASE_ADDRESS+0x10))
#define GPIOB_BRR *((volatile u32*)(GPIOB_BASE_ADDRESS+0x14))
#define GPIOB_LCK *((volatile u32*)(GPIOB_BASE_ADDRESS+0x18))

/*Register addresses for PORTC*/
#define GPIOC_CRL *((volatile u32*)(GPIOC_BASE_ADDRESS+0x00))
#define GPIOC_CRH *((volatile u32*)(GPIOC_BASE_ADDRESS+0x04))
#define GPIOC_IDR *((volatile u32*)(GPIOC_BASE_ADDRESS+0x08))
#define GPIOC_ODR *((volatile u32*)(GPIOC_BASE_ADDRESS+0x0C))
#define GPIOC_BSR *((volatile u32*)(GPIOC_BASE_ADDRESS+0x10))
#define GPIOC_BRR *((volatile u32*)(GPIOC_BASE_ADDRESS+0x14))
#define GPIOC_LCK *((volatile u32*)(GPIOC_BASE_ADDRESS+0x18))


#endif // !_DIO_PRIVATE_H