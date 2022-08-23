/**
 * @file SPI_config.h
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _SPI_CONFIG_H
#define _SPI_CONFIG_H

/*  Options: MASTER_MODE,SLAVE_MODE  */
#define SPI_MODE MASTER_MODE
/* write pair both port,pin like: GPIOA,PIN0 */
#define MSPI_SLAVE_PIN GPIOA,PIN0

#endif // !_SPI_CONFIG_H