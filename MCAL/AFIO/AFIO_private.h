/***************************************************************************/
/* Name:Sherif Emad Saad                                                   */
/* Version:v1                                                              */
/* Date:1/5/2022                                                          */
/***************************************************************************/

#ifndef _AFIO_PRIVATE_H
#define _AFIO_PRIVATE_H

typedef struct 
{
  volatile u32 AFIO_EVCR;
  volatile u32 AFIO_MAPR;
  volatile u32 AFIO_EXTICR[4];
  volatile u32 AFIO_MAPR2;
}AFIO_t;

#define AFIO_BASS_ADDRESS 0x40010000

#define AFIO ((volatile AFIO_t*)AFIO_BASS_ADDRESS)


#endif // !_AFIO_PRIVATE_H