/*
 * LCD_Int.h
 *
 *  Created on: Mar 4, 2019
 *      Author: OMDA
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_


#define LCD_PIN_HIGH		(u8)1
#define LCD_PIN_LOW			(u8)0





void LCD_vInitialize(void) ;

void LCD_voidClear ( void ) ;

u8 LCD_u8WriteData( u8* Copy_Pu8Data , u8 Copy_u8XPos , u8 Copy_u8YPos ) ;

void LCD_voidEnable ( void ) ;

void LCD_voidDisable ( void ) ;

void LCD_Vid_WriteNumber(u16 number,u8 Copy_u8XPos , u8 Copy_u8YPos) ;




#endif /* HAL_LCD_LCD_INT_H_ */
