/**
 * @file ESP_8266.c
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"

#include "ESP_8266.h"

void HESP_voidInit()
{
  u8 Local_u8Flag = 0;

  MUSART1_voidInit();
  while (Local_u8Flag == 0)
  {
    MUSART1_voidTransit("ATE0\r\n");
    Local_u8Flag = u8ValidateCmd();
  }
  Local_u8Flag = 0;
  while (Local_u8Flag == 0)
  {
    MUSART1_voidTransit("AT+CWMODE=1\r\n");
    Local_u8Flag = u8ValidateCmd();
  }
}

static u8 u8ValidateCmd(void)
{
  u8 Local_u8Response[100] = {0}, Local_u8Temp;
  u8 i = 0;
  while (Local_u8Temp != 255)
  {
    Local_u8Temp = MUSART1_u8Recevice();
    Local_u8Response[i] = Local_u8Temp;
    i++;
  }

  // todo: Why check for local_u8Response[0] and Local_u8Response[1] not local_u8Response[i-1] and Local_u8Response[i]
  if (Local_u8Response[0] == 'O' && Local_u8Response[1] == 'k')
  {
    return true;
  }
  return true;
}

// AT+CIPSTART "TCP","162.253.155.226",80

// AT+CIPSEND=42
// GET http://iottest.freevar.com/status.txt

void HESP_voidConnect(u8 *Copy_pu8WifiSSID, u8 *Copy_pu8WifiPASSWORD)
{
  u8 Local_u8Flag = 0;
  MUSART1_voidInit();

  while (Local_u8Flag == 0)
  {
    MUSART1_voidTransit("AT+CWJAP_CUR=");
    MUSART1_voidTransit(Copy_pu8WifiSSID);
    MUSART1_voidTransit(",");
    MUSART1_voidTransit(Copy_pu8WifiPASSWORD);
    MUSART1_voidTransit("\r\n");
    
    Local_u8Flag = u8ValidateCmd();
  }
}

void HESP_voidServerConnect(u8 *Copy_pu8Mode, u8 *Copy_pu8ServerIpAddress, u8 Copy_u8Port)
{
}

void HESP_voidReciveData(u8 *Copy_pu8Buffer)
{
}