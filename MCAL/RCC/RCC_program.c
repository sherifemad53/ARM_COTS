#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void) {
#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	RCC_CR = 0x00010000;/*Enable HSE with no bypass*/
	RCC_CFGR =0x00000001;
#elif 	RCC_CLOCK_TYPE == RCC_HSE_RC
	RCC_CR=0x00050000;/*Enable HSE with  bypass*/
	RCC_CFGR =0x00000001;
#elif	RCC_CLOCK_TYPE == RCC_HSI
	RCC_CR=0x00000081;/*Enable HSI  + 0 trimming*/
	RCC_CFGR =0x00000000;
#elif RCC_CLOCK_TYPE == RCC_PLL
	#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	//todo RCC_PLLMUL MASK
	#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
	#endif
#else
#error("You choose wrong Clock type in RCC_config.h")
#endif

}

void RCC_voidEnableClock(uint8_t Copy_uint8BusId, uint8_t Copy_uint8PerId) {
	if (Copy_uint8PerId <= 31) {
		switch (Copy_uint8PerId) {
		case RCC_AHB:
			SET_BIT(RCC_AHBENR, Copy_uint8PerId);
			break;
		case RCC_APB1:
			SET_BIT(RCC_APB1ENR, Copy_uint8PerId);
			break;
		case RCC_APB2:
			SET_BIT(RCC_APB2ENR, Copy_uint8PerId);
			break;
//			default:
//				break;
		}
	} else {
		/*Return error*/
	}
}

void RCC_voidDisableClock(uint8_t Copy_uint8BusId, uint8_t Copy_uint8PerId) {
	if (Copy_uint8PerId <= 31) {
		switch (Copy_uint8PerId) {
		case RCC_AHB:
			CLR_BIT(RCC_AHBENR, Copy_uint8PerId);
			break;
		case RCC_APB1:
			CLR_BIT(RCC_APB1ENR, Copy_uint8PerId);
			break;
		case RCC_APB2:
			CLR_BIT(RCC_APB2ENR, Copy_uint8PerId);
			break;
//			default:
//				break;
		}
	} else {
		/*Return error*/
	}
}
