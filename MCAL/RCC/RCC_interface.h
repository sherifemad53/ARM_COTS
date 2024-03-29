/**
 * @file RCC_interface.h
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief Function and Definitons that the user will need
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 * @note Still needs to implement the algorithm for maxing the Fcpu (72Mhz)
 * @warning RCC configured for 8MHZ only
 */


#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

#define RCC_AHB 0
#define RCC_APB1 1
#define RCC_APB2 2

typedef enum {
	RCC_AHB_DMA1EN = 0,
	RCC_AHB_DMA2EN = 1,
	RCC_AHB_SPAMEN = 2,
	RCC_AHB_FLITFEN = 4,
	RCC_AHB_CRCEN = 6,
	RCC_AHB_FSMCEN = 8,
	RCC_AHB_SDIOEN = 10,
} RCC_AHB_PERIPHERALS;

typedef enum {
	RCC_APB2_AFIOEN = 0,
	RCC_APB2_IOPAEN = 2,
	RCC_APB2_IOPBEN = 3,
	RCC_APB2_IOPCEN = 4,
	RCC_APB2_IOPDEN = 5,
	RCC_APB2_IOPEEN = 6,
	RCC_APB2_IOPFEN = 7,
	RCC_APB2_IOPGEN = 8,
	RCC_APB2_ADC1EN = 9,
	RCC_APB2_ADC2EN = 10,
	RCC_APB2_TIM1EN = 11,
	RCC_APB2_SPE1EN = 12,
	RCC_APB2_TIM8EN = 13,
	RCC_APB2_USART1EN = 14,
	RCC_APB2_ADC3EN = 15,
	RCC_APB2_TIM9EN = 19,
	RCC_APB2_TIM10EN = 20,
	RCC_APB2_TIM11EN = 21,
} RCC_APB2_PERIPHERALS;

typedef enum {
	RCC_APB1_TIM2EN = 0,
	RCC_APB1_TIM3EN = 1,
	RCC_APB1_TIM4EN = 2,
	RCC_APB1_TIM5EN = 3,
	RCC_APB1_TIM6EN = 4,
	RCC_APB1_TIM7EN = 5,
	RCC_APB1_TIM12EN = 6,
	RCC_APB1_TIM13EN = 7,
	RCC_APB1_TIM14EN = 8,
	RCC_APB1_WWDGEN = 11,
	RCC_APB1_SPI2EN = 14,
	RCC_APB1_SPI3EN = 15,
	RCC_APB1_USART2EN = 17,
	RCC_APB1_USART3EN = 18,
	RCC_APB1_USART4EN = 19,
	RCC_APB1_USART5EN = 20,
	RCC_APB1_I2C1EN = 21,
	RCC_APB1_I2C2EN = 22,
	RCC_APB1_USBEN = 23,
	RCC_APB1_CANEN = 25,
	RCC_APB1_BKPEN = 27,
	RCC_APB1_PWREN = 28,
	RCC_APB1_DACEN = 29,
} RCC_APB1_PERIPHERALS;


void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(uint8 Copy_uint8BusId, uint8 Copy_uint8PerId);
void MRCC_voidDisableClock(uint8 Copy_uint8BusId, uint8 Copy_uint8PerId);

#endif
