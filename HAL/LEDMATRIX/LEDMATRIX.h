/**
 * @file LEDMATRIX.h
 * @author sherif emad (sherifemad53@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _LEDMATRIX_H
#define _LEDMATRIX_H

/* Please wire pair (PORT , PIN) EX: (GPIOA,PIN0)*/
#define LEDMATRIX_ROW0_PIN GPIOA,0
#define LEDMATRIX_ROW1_PIN GPIOA,1
#define LEDMATRIX_ROW2_PIN GPIOA,2
#define LEDMATRIX_ROW3_PIN GPIOA,3
#define LEDMATRIX_ROW4_PIN GPIOA,4
#define LEDMATRIX_ROW5_PIN GPIOA,5
#define LEDMATRIX_ROW6_PIN GPIOA,6
#define LEDMATRIX_ROW7_PIN GPIOA,7

/* Please wire pair (PORT , PIN) EX: (GPIOA,PIN0)*/
//Note: PIN2 GPIOB not on board also PIN3,PIN4 don't use
#define LEDMATRIX_COLUMN0_PIN GPIOB,0
#define LEDMATRIX_COLUMN1_PIN GPIOB,1 
#define LEDMATRIX_COLUMN2_PIN GPIOB,5
#define LEDMATRIX_COLUMN3_PIN GPIOB,6
#define LEDMATRIX_COLUMN4_PIN GPIOB,7
#define LEDMATRIX_COLUMN5_PIN GPIOB,8
#define LEDMATRIX_COLUMN6_PIN GPIOB,9
#define LEDMATRIX_COLUMN7_PIN GPIOB,10


#endif // !_LEDMATRIX_H