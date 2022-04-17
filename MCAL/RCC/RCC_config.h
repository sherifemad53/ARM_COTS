/******************************************************************************************************/
/*
 * Author :Sherif Emad
 * Version:1.0
 * Date:24/3/2022
 */

#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H
/* Options:
 RCC_HSE_CRYSTAL
 RCC_HSE_RC
 RCC_HSI
 RCC_PLL
 */

#define RCC_CLOCK_TYPE RCC_HSE_CRYSTAL

/*Options:RCC_PLL_IN_HSI_DIV_2
 RCC_PLL_IN_HSE_DIV_2
RCC_PLL_IN_HSE
 * */
/*Note: Select value only if you have PLL_type selected as clock source*/
#if RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_INPUT RCC_PLL_IN_HSI_DIV_2
#endif

/*Options 2 to 16*/
/*RCC_PLLMUL_X2 = 0,
	RCC_PLLMUL_X3
	RCC_PLLMUL_X4
	RCC_PLLMUL_X5
	RCC_PLLMUL_X6
	RCC_PLLMUL_X7
	RCC_PLLMUL_X8
	RCC_PLLMUL_X9
	RCC_PLLMUL_X10
	RCC_PLLMUL_X11
	RCC_PLLMUL_X12
	RCC_PLLMUL_X13
	RCC_PLLMUL_X14
	RCC_PLLMUL_X15
	RCC_PLLMUL_X16
	*/

/*Note: Select value only if you have PLL_type selected as clock source*/
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLLMUL_VAL RCC_PLLMUL_X9
#endif


#define RCC_MCO_MODE_SELECTION RCC_MCO_MODE_SYSCLK

#endif
