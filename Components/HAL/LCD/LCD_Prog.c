/*
 * LCD_Prog.c
 *
 *  Created on: Mar 4, 2019
 *      Author: OMDA
 */

#ifndef HAL_LCD_LCD_PROG_C_
#define HAL_LCD_LCD_PROG_C_



#include "STD_TYPE.h"
#include "BIT_CALC.h"
#include "delay_milli_Interface.h"

#include "DIO_Interface.h"

#include "LCD_Int.h"
#include "LCD_Conf.h"
#include "LCD_Priv.h"




void LCD_Vid_WriteNumber(u16 number,u8 Copy_u8XPos , u8 Copy_u8YPos)
{
  u8 temp;
  u16 reversed_number=1;
  u8 Local_u8Address ;


	if ( (Copy_u8XPos < MAX_X_POS) && (Copy_u8YPos < MAX_Y_POS) ){

		Local_u8Address  = Copy_u8XPos + (Copy_u8YPos*0x40) ;
		Local_u8Address |= 0x80 ;

		LCD_u8WriteCommand(Local_u8Address);



			  if(number==0)
				  LCD_u8WriteChar('0');
			  while (number!=0)
			  {
				  temp=number%10;
				  number=number/10;
				  reversed_number=reversed_number*10+temp;
			  }
			  while(reversed_number!=1)
			  {
				  temp=reversed_number%10;
				  reversed_number=reversed_number/10;

				  LCD_u8WriteChar(temp+48);
			  }

	}


}






void LCD_vInitialize(void){

	delay_milliSecond(40);

	LCD_u8WriteCommand( 0b00111000 ) ;

	delay_milliSecond(2);

	LCD_u8WriteCommand( 0b00001100 ) ;

	delay_milliSecond(2);

	LCD_u8WriteCommand( 0b00000001 ) ;

	delay_milliSecond(2);

	DIO_u8SetPinValue( LCD_BACKLIGHT_GND , LCD_PIN_LOW ) ;








	/*  writing my chars  */

	LCD_u8WriteCommand(0b01000000) ;






	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 10 ) ;
	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 14 ) ;
	LCD_u8WriteChar( 10 ) ;
	LCD_u8WriteChar( 14 ) ;
	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 0x00 ) ;


	//////////////////////
	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 4 ) ;
	LCD_u8WriteChar( 4 ) ;
	LCD_u8WriteChar( 31 ) ;
	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 0x00 ) ;


	//////////////////////
	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 14 ) ;
	LCD_u8WriteChar( 10 ) ;
	LCD_u8WriteChar( 31 ) ;
	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 0x00 ) ;


	//////////////////////
	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 7 ) ;
	LCD_u8WriteChar( 4 ) ;
	LCD_u8WriteChar( 31 ) ;
	LCD_u8WriteChar( 0x00 ) ;
	LCD_u8WriteChar( 0x00 ) ;


	LCD_u8WriteCommand(0b10000000) ;





}



void LCD_voidClear ( void ){
	LCD_u8WriteCommand( 0b00000001 ) ;
	LCD_u8WriteCommand(0b10000000) ;
}


void LCD_voidDisable ( void ){
	LCD_u8WriteCommand( 0b00001000 ) ;
	delay_milliSecond(2);
	DIO_u8SetPinValue( LCD_BACKLIGHT_GND , LCD_PIN_HIGH ) ;
}

void LCD_voidEnable ( void ){
	LCD_u8WriteCommand( 0b00001100 ) ;
	delay_milliSecond(2);
	DIO_u8SetPinValue( LCD_BACKLIGHT_GND , LCD_PIN_LOW ) ;
}


u8 LCD_u8WriteData ( u8* Copy_Pu8Data , u8 Copy_u8XPos , u8 Copy_u8YPos ) {

	u8 Local_u8ErrorState = ERROR_OK ;

	u8 Local_u8Address ;

	if ( (Copy_u8XPos < MAX_X_POS) && (Copy_u8YPos < MAX_Y_POS) ){

		Local_u8Address  = Copy_u8XPos + (Copy_u8YPos*0x40) ;
		Local_u8Address |= 0x80 ;

		LCD_u8WriteCommand(Local_u8Address);



		while (*Copy_Pu8Data != '\0'){

			LCD_u8WriteChar(*(Copy_Pu8Data));
			Copy_Pu8Data ++				  ;
			Local_u8Address ++ 			  ;

			if( Local_u8Address == 0x90 ){

				Local_u8Address = 0xC0  ;
				LCD_u8WriteCommand(Local_u8Address) ;

			}
			else if ( Local_u8Address == 0xD0 ){

				Local_u8Address = 0x80 ;
				LCD_u8WriteCommand(Local_u8Address);

			}

		}

	}
	else {
		Local_u8ErrorState = ERROR_NOK ;
	}


	return Local_u8ErrorState ;

}










static u8 LCD_u8WriteChar ( u8 Copy_u8Data ) {

	u8 Local_u8ErrorState = ERROR_OK ;

	DIO_u8SetPinValue( LCD_ENABLE , LCD_PIN_LOW ) ;

	DIO_u8SetPinValue( LCD_RS , LCD_PIN_HIGH ) ;


	SetByteVal( Copy_u8Data ) ;


	EnableSequence() ;

	return Local_u8ErrorState ;
}



static u8 LCD_u8WriteCommand( u8 Copy_u8Command ) {

	u8 Local_u8ErrorState = ERROR_OK ;

	DIO_u8SetPinValue( LCD_ENABLE , LCD_PIN_LOW ) ;

	DIO_u8SetPinValue( LCD_RS , LCD_PIN_LOW ) ;


	SetByteVal( Copy_u8Command ) ;


	EnableSequence() ;

	return Local_u8ErrorState ;
}




















static void EnableSequence(){

	DIO_u8SetPinValue( LCD_ENABLE , LCD_PIN_HIGH ) ;

	delay_milliSecond(2) ;

	DIO_u8SetPinValue( LCD_ENABLE , LCD_PIN_LOW ) ;

}


static void SetByteVal( u8 Data ){

	DIO_u8SetPinValue( LCD_D0 , GET_BIT(Data,0) ) ;
	DIO_u8SetPinValue( LCD_D1 , GET_BIT(Data,1) ) ;
	DIO_u8SetPinValue( LCD_D2 , GET_BIT(Data,2) ) ;
	DIO_u8SetPinValue( LCD_D3 , GET_BIT(Data,3) ) ;

	DIO_u8SetPinValue( LCD_D4 , GET_BIT(Data,4) ) ;
	DIO_u8SetPinValue( LCD_D5 , GET_BIT(Data,5) ) ;
	DIO_u8SetPinValue( LCD_D6 , GET_BIT(Data,6) ) ;
	DIO_u8SetPinValue( LCD_D7 , GET_BIT(Data,7) ) ;

}






#endif
