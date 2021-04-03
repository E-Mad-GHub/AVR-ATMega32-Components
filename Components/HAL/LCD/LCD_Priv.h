/*
 * LCD_Priv.h
 *
 *  Created on: Mar 4, 2019
 *      Author: OMDA
 */

#ifndef HAL_LCD_LCD_PRIV_H_
#define HAL_LCD_LCD_PRIV_H_




#define MAX_X_POS    (u8)16
#define MAX_Y_POS    (u8)2



static u8 LCD_u8WriteCommand( u8 Copy_u8Command ) ;

static u8 LCD_u8WriteChar ( u8 Copy_u8Data )      ;

static void EnableSequence() ;

static void SetByteVal( u8 Data ) ;

static void SetByteVal( u8 Data ) ;








#endif /* HAL_LCD_LCD_PRIV_H_ */
