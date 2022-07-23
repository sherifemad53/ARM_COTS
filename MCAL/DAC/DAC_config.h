/***************************************************************************/
/* Name:Sherif Emad Saad                                                   */
/* Version:v1                                                              */
/* Date:1/5/2022                                                          */
/***************************************************************************/

/*Warning you need to initualize the clock and config the systick to tick every 1us*/


#ifndef _DAC_CONFIG_H
#define _DAC_CONFIG_H

/* enter the port and pin like that PORT,PIN like: GPIO,PIN0 */
// Note: by default it is connected to GPIO starting From PIN0

#define MDAC_BITS 8

#define MDAC_PIN0_BIT0 GPIOA, PIN0
#define MDAC_PIN0_BIT1 GPIOA, PIN1
#define MDAC_PIN0_BIT2 GPIOA, PIN2
#define MDAC_PIN0_BIT3 GPIOA, PIN3
#define MDAC_PIN0_BIT4 GPIOA, PIN4
#define MDAC_PIN0_BIT5 GPIOA, PIN5
#define MDAC_PIN0_BIT6 GPIOA, PIN6
#define MDAC_PIN0_BIT7 GPIOA, PIN7

#if MDAC_BITS > 8
#if MDAC_BITS == 9
#define MDAC_PIN0_BIT8 GPIOA, PIN8
#endif
#if MDAC_BITS == 10
#define MDAC_PIN0_BIT8 GPIOA, PIN8
#define MDAC_PIN0_BIT0 GPIOA, PIN9
#endif

#endif

#endif // !_DAC_CONFIG_H