/**
 * @file DMA_program.c
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"

void MDMA_voidChannelInit(void)
{

#if CHANNEL1 == ENABLE
  #if CHANNEL1_MEMTOMEM == ENABLE
  #else
  #endif

  /*
    CHANNEL1_PRIORITY Options:
            VERY_HIGH,HIGH,MEDIUM,LOW
  */
  #if CHANNEL1_PRIORITY == VERY_HIGH
  //todo set the priority
  #elif CHANNEL1_PRIORITY == HIGH
  #elif CHANNEL1_PRIORITY == MEDIUM
  #else 
  #endif

  /*
    CHANNEL1_MEMSIZE Options:
            SIZE_8_BITS,SIZE_16_BITS,SIZE_32_BITS
  */
  #if CHANNEL1_MEMSIZE == SIZE_8_BITS
  //todo set the priority
  #elif CHANNEL1_MEMSIZE == SIZE_16_BITS
  #elif CHANNEL1_MEMSIZE == SIZE_32_BITS
  #else 
  #endif

  /*
    CHANNEL1_PERSIZE Options:
            SIZE_8_BITS,SIZE_16_BITS,SIZE_32_BITS
  */
  #if CHANNEL1_PERSIZE == SIZE_8_BITS
  //todo set PERIPHERAL size
  #elif CHANNEL1_PERSIZE == SIZE_16_BITS
  #elif CHANNEL1_PERSIZE == SIZE_32_BITS
  #else 
  #endif

  /*
  MEMORY_INCREMENT_MODE Options:
                                ENABLE,DISABLE
  */
  #if MEMORY_INCREMENT_MODE == ENABLE
  #else
  #endif

  /*
  PERIPHERAL_INCREMENT_MODE Options:
                                ENABLE,DISABLE
  */
  #if PERIPHERAL_INCREMENT_MODE == ENABLE
  #else
  #endif

  /*
  CIRCULAR_MODE Options:
                        ENABLE,DISABLE
  */
  #if CIRCULAR_MODE == ENABLE
  #else
  #endif

  /*
  DATA_TRANSFER_DIRECTION Options:
                        READ_FROM_PERIPHERAL,READ_FROM_MEMORY
  */
  #if DATA_TRANSFER_DIRECTION == READ_FROM_PERIPHERAL
  #elif DATA_TRANSFER_DIRECTION == READ_FROM_MEMORY
  #endif

  //TRANSFER COMPLETE INTERRUPT FOR CHANNEL1
  #if CHANNEL1_INTERRUPT_TRANSFER_COMPLETE == ENABLE
  //todo enable interrupt
  #endif

  //TRANSFER ERROR INTERRUPT FOR CHANNEL1
  #if CHANNEL1_INTERRUPT_TRANSFER_ERROR == ENABLE
  #endif

  //HALF TRANSFER COMPLETE INTERRUPT FOR CHANNEL1
  #if CHANNEL1_INTERRUPT_TRANSFER_HALFCOMPLETE == ENABLE
  #endif
#endif
}

void MDMA_voidChannelStart(u8 Copy_u8ChannelID,u32 *Copy_Pu32SourceAddress, u32 *Copy_Pu32DestinationAddress, u16 Copy_u16BlockSize)
{

  //Note: make sure that channel disble
  CLR_BIT(MDMA->CHANNEL[Copy_u8ChannelID].CCR, 0);
  MDMA->CHANNEL[Copy_u8ChannelID].CPAR = Copy_Pu32SourceAddress;
  MDMA->CHANNEL[Copy_u8ChannelID].CMAR = Copy_Pu32DestinationAddress;
  MDMA->CHANNEL[Copy_u8ChannelID].CNDTR = Copy_u16BlockSize;
  SET_BIT(MDMA->CHANNEL[Copy_u8ChannelID].CCR, 0);
}