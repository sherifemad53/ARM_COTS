/***************************************************************************/
/* Name:Sherif Emad Saad                                                   */
/* Version:v1                                                              */
/* Date:1/5/2022                                                          */
/***************************************************************************/

#ifndef _DMA_PRIVATE_H
#define _DMA_PRIVATE_H

#define SIZE_8_BITS 1 
#define SIZE_16_BITS 2 
#define SIZE_32_BITS 3

#define READ_FROM_PERIPHERAL 0
#define READ_FROM_MEMORY 1

typedef struct 
{
  volatile u32 CCR;
  volatile u32 CNDTR;
  volatile u32 CPAR;
  volatile u32 CMAR;
  volatile u32 RESERVED;
}DMA_CHANNEL;


typedef struct DMA_private
{
  volatile u32 ISR;
  volatile u32 IFCR;
  DMA_CHANNEL CHANNEL[7];
}MDMA_t;

#define DMA_BASEADDRESS  0x40020000 

#define MDMA ((volatile MDMA_t*) DMA_BASEADDRESS)

#endif // !_DMA_PRIVATE_H