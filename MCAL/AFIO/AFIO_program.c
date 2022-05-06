/***************************************************************************/
/* Name:Sherif Emad Saad                                                   */
/* Version:v1                                                              */
/* Date:27/4/2022                                                          */
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"

void MAFIO_voidSetEXTICongif(u8 copy_u8Line, u8 copy_u8SelectedPort)
{
  u8 local_u8RegIndex = 0;
  if (copy_u8Line <= 3)
  {
    local_u8RegIndex = 0;
  }
  else if (copy_u8Line <= 7)
  {
    local_u8RegIndex = 1;
    copy_u8Line -= 4;
  }
  else if (copy_u8Line <= 11)
  {
    local_u8RegIndex = 2;
    copy_u8Line -= 8;
  }
  else if (copy_u8Line <= 15)
  {
    local_u8RegIndex = 3;
    copy_u8Line -= 12;
  }

  AFIO->AFIO_EXTICR[local_u8RegIndex] &= ~((0b1111) << (copy_u8Line * 4));
  AFIO->AFIO_EXTICR[local_u8RegIndex] |= ((copy_u8SelectedPort) << (copy_u8Line * 4));
}

// void MAFIO_voidSetEXTICongif(u8 copy_u8Line, u8 copy_u8SelectedPort)
// {
//   if (copy_u8Line >= 0 && copy_u8Line <= 3)
//   {
//     AFIO->AFIO_EXTICR[0] &= ~((0b1111) << (copy_u8Line * 4));
//     AFIO->AFIO_EXTICR[0] |= (copy_u8SelectedPort) << (copy_u8Line * 4);
//   }
//   if (copy_u8Line >= 4 && copy_u8Line <= 7)
//   {
//     copy_u8Line -= 4;
//     AFIO->AFIO_EXTICR[1] &= ~((0b1111) << (copy_u8Line * 4));
//     AFIO->AFIO_EXTICR[1] |= copy_u8SelectedPort << copy_u8Line * 4;
//   }
//   if (copy_u8Line >= 8 && copy_u8Line <= 11)
//   {
//     copy_u8Line -= 8;
//     AFIO->AFIO_EXTICR[2] &= ~((0b1111) << (copy_u8Line * 4));
//     AFIO->AFIO_EXTICR[2] |= copy_u8SelectedPort << copy_u8Line * 4;
//   }
//   if (copy_u8Line >= 12 && copy_u8Line <= 15)
//   {
//     copy_u8Line -= 12;
//     AFIO->AFIO_EXTICR[3] &= ~((0b1111) << (copy_u8Line * 4));
//     AFIO->AFIO_EXTICR[3] |= copy_u8SelectedPort << copy_u8Line * 4;
//   }
// }
