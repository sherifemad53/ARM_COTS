/**
 * @file BIT_MATH.h
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _BIT_MATH_H
#define _BIT_MATH_H

# define SET_BIT(x,bit_number) ((x) |= ((1)<<(bit_number)))
# define CLR_BIT(x,bit_number) ((x) &= ~((1)<<(bit_number)))
# define TOGGLE_BIT(x,bit_number) ((x) ^= ((1)<<(bit_number)))
# define GET_BIT(x,bit_number) (((x)>>(bit_number)) & (1))


#endif