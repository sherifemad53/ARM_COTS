#ifndef _BIT_MATH_H
#define _BIT_MATH_H

# define SET_BIT(x,bit_number) ((x) |= ((1)<<(bit_number)))
# define CLR_BIT(x,bit_number) ((x) &= ~((1)<<(bit_number)))
# define TOGGLE_BIT(x,bit_number) ((x) ^= ((1)<<(bit_number)))
# define GET_BIT(x,bit_number) (((x)>>(bit_number)) & (1))


#endif