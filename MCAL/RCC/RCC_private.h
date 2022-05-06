/******************************************************************************************************/
/*
 * Author :Sherif Emad
 * Version:1.0
 * Date:24/3/2022
 */

#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H

/*CLOCK TYPES*/
#define RCC_HSE_CRYSTAL 0
#define RCC_HSE_RC 1
#define RCC_HSI 2
#define RCC_PLL 3

/*PLL Options*/
#define RCC_PLL_IN_HSI_DIV_2 0
#define RCC_PLL_IN_HSE_DIV_2 2
#define RCC_PLL_IN_HSE 2


//#define RCC_SYSCLK_MODE_HSE 1
//#define RCC_SYSCLK_MODE_PLL 2

#define RCC_MCO_MODE_SYSCLK 0
#define RCC_MCO_MODE_HSI 1
#define RCC_MCO_MODE_HSE 2
#define RCC_MCO_MODE_PLL 3


enum{
	RCC_PLLMUL_X2 = 0,
	RCC_PLLMUL_X3 = 1,
	RCC_PLLMUL_X4 = 2,
	RCC_PLLMUL_X5 = 3,
	RCC_PLLMUL_X6 = 4,
	RCC_PLLMUL_X7 = 5,
	RCC_PLLMUL_X8 = 6,
	RCC_PLLMUL_X9 = 7,
	RCC_PLLMUL_X10 = 8,
	RCC_PLLMUL_X11 = 9,
	RCC_PLLMUL_X12 = 10,
	RCC_PLLMUL_X13 = 11,
	RCC_PLLMUL_X14 = 12,
	RCC_PLLMUL_X15 = 13,
	RCC_PLLMUL_X16 = 14,
};


#define RCC_CR *((u32*)0x40021000)
#define RCC_CFGR *((u32*)0x40021004)
#define RCC_CIR *((u32*)0x40021008)
#define RCC_APB2RSTR *((u32*)0x4002100C)
#define RCC_APB1RSTR *((u32*)0x40021010)
#define RCC_AHBENR *((u32*)0x40021014)
#define RCC_APB2ENR *((u32*)0x40021018)
#define RCC_APB1ENR *((u32*)0x4002101C)
#define RCC_BDCR *((u32*)0x40021020)
#define RCC_CSR *((u32*)0x400210024)

#endif
