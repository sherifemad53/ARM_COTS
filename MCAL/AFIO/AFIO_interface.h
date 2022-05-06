/***************************************************************************/
/* Name:Sherif Emad Saad                                                   */
/* Version:v1                                                              */
/* Date:1/5/2022                                                          */
/***************************************************************************/

#ifndef _AFIO_INTERFACE_H
#define _AFIO_INTERFACE_H

#define AFIO_PORTA 0b0000
#define AFIO_PORTB 0b0001
#define AFIO_PORTC 0b0010

// #define AFIO_PORTD 0b0011
// #define AFIO_PORTE 0b0100
// #define AFIO_PORTF 0b0101
// #define AFIO_PORTG 0b0110

//Note: EXTI line defined in EXTI_interface.h file
void MAFIO_voidSetEXTICongif(u8 copy_u8EXTILine,u8 copy_u8SelectedPort);



#endif // !_AFIO_INTERFACE_H