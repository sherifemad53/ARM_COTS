/***************************************************************************/
/* Name:Sherif Emad Saad                                                   */
/* Version:v1                                                              */
/* Date:1/5/2022                                                           */
/***************************************************************************/

#ifndef _DMA_CONFIG_H
#define _DMA_CONFIG_H

#define CHANNEL_MEMTOMEM 1
#define CHANNEL_MEMTOPER 0

/*
  Options:
          ENABLE,DISABLE
*/

/*
    1- mem to mem ??
    2- very high priority
    3- source size,destination size
    4- MINC,PINC active ??
    5- no circuilar means no repeat
    6- direction :
    7- transfer interrupt enable
    8- enable the channel
  */
#define CHANNAL1 ENABLE
#if CHANNEL1 == ENABLE
  #define CHANNEL1_MEMTOMEM ENABLE
  #if CHANNEL1_MEMTOMEM == ENABLE
  #else
  #endif


  /*
    CHANNEL1_PRIORITY Options:
            VERY_HIGH,HIGH,MEDIUM,LOW
  */
  #define CHANNEL1_PRIORITY VERY_HIGH
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
  #define CHANNEL1_MEMSIZE SIZE_8_BITS
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
  #define CHANNEL1_PERSIZE SIZE_8_BITS
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

  #define MEMORY_INCREMENT_MODE ENABLE
  #if MEMORY_INCREMENT_MODE == ENABLE
  #else
  #endif

  /*
  PERIPHERAL_INCREMENT_MODE Options:
                                ENABLE,DISABLE
  */

  #define PERIPHERAL_INCREMENT_MODE ENABLE
  #if PERIPHERAL_INCREMENT_MODE == ENABLE
  #else
  #endif

  //CIRCULAR_MODE: DMA don't stop after reaching the max blocksize it restarts again 
  /*
  CIRCULAR_MODE Options:
                        ENABLE,DISABLE
  */

  #define CIRCULAR_MODE ENABLE
  #if CIRCULAR_MODE == ENABLE
  #else
  #endif

  /*
  DATA_TRANSFER_DIRECTION Options:
                        READ_FROM_PERIPHERAL,READ_FROM_MEMORY
  */

  #define DATA_TRANSFER_DIRECTION READ_FROM_PERIPHERAL
  #if DATA_TRANSFER_DIRECTION == READ_FROM_PERIPHERAL
  #elif DATA_TRANSFER_DIRECTION == READ_FROM_MEMORY
  #endif


  //TRANSFER COMPLETE INTERRUPT FOR CHANNEL1
  #define CHANNEL1_INTERRUPT_TRANSFER_COMPLETE ENABLE
  #if CHANNEL1_INTERRUPT_TRANSFER_COMPLETE == ENABLE
  //todo enable interrupt
  #endif

  //TRANSFER ERROR INTERRUPT FOR CHANNEL1
  #define CHANNEL1_INTERRUPT_TRANSFER_ERROR ENABLE
  #if CHANNEL1_INTERRUPT_TRANSFER_ERROR == ENABLE
  #endif

  //HALF TRANSFER COMPLETE INTERRUPT FOR CHANNEL1
  #define CHANNEL1_INTERRUPT_TRANSFER_HALFCOMPLETE ENABLE
  #if CHANNEL1_INTERRUPT_TRANSFER_HALFCOMPLETE == ENABLE
  #endif

#endif

#endif // !_DMA_CONFIG_H