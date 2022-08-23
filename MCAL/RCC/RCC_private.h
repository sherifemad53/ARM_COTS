/**
 * @file RCC_private.h
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-22
 *
 * @copyright Copyright (c) 2022
 *
 */

// Note: Three cases to use volatile keyword in variables or register definetion
//  1- variable changed by ISR
//  2- variable changed by Hardware like READONLY registers
//  3- Multitasking (OS RTOS) Two tasks while(check x){} while(1){change x}

#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H

// /*CLOCK TYPES*/
// #define RCC_HSE_CRYSTAL 0
// #define RCC_HSE_RC 1
// #define RCC_HSI 2
// #define RCC_PLL 3

// /*PLL Options*/
// #define RCC_PLL_IN_HSI_DIV_2 0
// #define RCC_PLL_IN_HSE_DIV_2 2
// #define RCC_PLL_IN_HSE 2

#define RCC_CR_HSION (u32)(1<<0)
#define RCC_CR_HSEON (u32)(1<<16)
#define RCC_CR_PLLON (u32)(1<<24)

#define RCC_CFGR_MCO_HSI (u32)(4 << 24)
#define RCC_CFGR_MCO_HSE (u32)(5 << 24)
#define RCC_CFGR_MCO_SYSCLK (u32)(6 << 24)
#define RCC_CFGR_MCO_PLL_DIV2 (u32)(7 << 24)

#define RCC_CFGR_PLLSRC_HSI (u32)(0 << 16)
#define RCC_CFGR_PLLSRC_HSE (u32)(1 << 16)

#define RCC_CFGR_PLLXTPRE_HSE (u32)(0 << 17) 
#define RCC_CFGR_PLLXTPRE_HSE_Div2 (u32)(1 << 17) 

#define RCC_CFGR_SWS_HSI (u32)(0 << 2)
#define RCC_CFGR_SWS_HSE (u32)(1 << 2)
#define RCC_CFGR_SWS_PLL (u32)(2 << 2)

#define RCC_CFGR_SW_HSI (u32)(0 << 0)
#define RCC_CFGR_SW_HSE (u32)(1 << 0)
#define RCC_CFGR_SW_PLL (u32)(2 << 0)



#define RCC_CFGR_PLLMULL2 (u32)(0 << 18)
#define RCC_CFGR_PLLMULL3 (u32)(1 << 18)
#define RCC_CFGR_PLLMULL4 (u32)(2 << 18)
#define RCC_CFGR_PLLMULL5 (u32)(3 << 18)
#define RCC_CFGR_PLLMULL6 (u32)(4 << 18)
#define RCC_CFGR_PLLMULL7 (u32)(5 << 18)
#define RCC_CFGR_PLLMULL8 (u32)(6 << 18)
#define RCC_CFGR_PLLMULL9 (u32)(7 << 18)
#define RCC_CFGR_PLLMULL10 (u32)(8 << 18)
#define RCC_CFGR_PLLMULL11 (u32)(9 << 18)
#define RCC_CFGR_PLLMULL12 (u32)(10 << 18)
#define RCC_CFGR_PLLMULL13 (u32)(11 << 18)
#define RCC_CFGR_PLLMULL14 (u32)(12 << 18)
#define RCC_CFGR_PLLMULL15 (u32)(13 << 18)
#define RCC_CFGR_PLLMULL16 (u32)(14 << 18)

#define RCC_BASEADDRESS 0x40021000

typedef struct
{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2STR;
	volatile u32 APB1STR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
} RCC_t;

#define RCC ((volatile RCC_t *)RCC_BASEADDRESS)

// #define RCC_CR *((volatile u32*)0x40021000)
// #define RCC_CFGR *((volatile u32*)0x40021004)
// #define RCC_CIR *((volatile u32*)0x40021008)
// #define RCC_APB2RSTR *((volatile u32*)0x4002100C)
// #define RCC_APB1RSTR *((volatile u32*)0x40021010)
// #define RCC_AHBENR *((volatile u32*)0x40021014)
// #define RCC_APB2ENR *((volatile u32*)0x40021018)
// #define RCC_APB1ENR *((volatile u32*)0x4002101C)
// #define RCC_BDCR *((volatile u32*)0x40021020)
// #define RCC_CSR *((volatile u32*)0x400210024)

#endif
