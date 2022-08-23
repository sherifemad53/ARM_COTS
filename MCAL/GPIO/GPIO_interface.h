/**
 * @file GPIO_interface.h
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

#define GPIO_LOW 0
#define GPIO_HIGH 1

//Used in MGPIO_voidSetPinValue Function to Set pin to PULLUP or PULLDOWN 
//After configuring it as INPUT_PIN
#define GPIO_PULLDOWN 0
#define GPIO_PULLUP 1
/**
 * @brief 
 * 
 */

#define GPIOA 0
#define GPIOB 1
#define GPIOC 2

/**
 * @brief 
 * 
 * @param 
 */
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8
#define PIN9 9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15

#define OUTPUT_SPEED_10MHZ_PUSHPULL 0b0001
#define OUTPUT_SPEED_10MHZ_OPENDRAIN 0b0101
#define OUTPUT_SPEED_10MHZ_ALTFUNCTION_PUSHPULL 0b1001
#define OUTPUT_SPEED_10MHZ_ALTFUNCTION_OPENDRAIN 0b1101

#define OUTPUT_SPEED_2MHZ_PUSHPULL 0b0010
#define OUTPUT_SPEED_2MHZ_OPENDRAIN 0b0110
#define OUTPUT_SPEED_2MHZ_ALTFUNCTION_PUSHPULL 0b1010
#define OUTPUT_SPEED_2MHZ_ALTFUNCTION_OPENDRAIN 0b1110

#define OUTPUT_SPEED_50MHZ_PUSHPULL 0b0011
#define OUTPUT_SPEED_50MHZ_OPENDRAIN 0b0111
#define OUTPUT_SPEED_50MHZ_ALTFUNCTION_PUSHPULL 0b1011
#define OUTPUT_SPEED_50MHZ_ALTFUNCTION_OPENDRAIN 0b1111

#define INPUT_ANALOG 0b0000
#define INPUT_FLOATING 0b0100
#define INPUT_PULLDOWN_PULLUP 0b1000


void MGPIO_voidSETPinDirection(u8 copy_u8PORT,u8 copy_u8PIN,u8 copy_u8Direction);
void MGPIO_voidSETPinValue(u8 copy_u8PORT,u8 copy_u8PIN,u8 copy_u8Value);
void MGPIO_voidTogglePin(u8 copy_u8PORT, u8 copy_u8PIN);
u8 MGPIO_u8GetPinValue(u8 copy_u8PORT,u8 copy_u8PIN);

#endif // !_DIO_INTERFACE_H