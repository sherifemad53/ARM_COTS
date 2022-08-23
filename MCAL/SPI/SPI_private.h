/**
 * @file SPI_private.h
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _SPI_PRIAVTE_H
#define _SPI_PRIAVTE_H

#define MASTER_MODE 1
#define SLAVE_MODE 0

typedef struct SPI_private
{
  volatile u32 CR1;
  volatile u32 CR2;
  volatile u32 SR;
  volatile u32 DR;
  volatile u32 CRCPR;
  volatile u32 RXCRCR;
  volatile u32 TXCRCR;
  volatile u32 I2SCFGR;
  volatile u32 I2SPR;  
}MSPI_t;


#define SPI1_BASS_ADDRESS 0x40013000
#define SPI2_BASS_ADDRESS 0x40003800

#define MSPI1 ((volatile MSPI_t*) SPI1_BASS_ADDRESS)

#define MSPI2 ((volatile MSPI_t*) SPI2_BASS_ADDRESS)

#endif // !_SPI_PRIAVTE_H