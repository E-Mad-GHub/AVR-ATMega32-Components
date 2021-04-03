/************************************************************************************/
/* Description : This is an Program file that contains the public definitions and   */
/*               public functions implementations needed to use the Motor Component */
/*               in high efficiency												    */
/* 				                     												*/
/*																					*/
/* Created on  : Mar 10, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/





/* File Guard         */
#ifndef MOTOR_PROG
#define MOTOR_PROG




#include "STD_TYPE.h"
#include "BIT_CALC.h"

#include "ARM_DIO_Int.h"

#include "Servo_Motor_Conf.h"
#include "Servo_Motor_Int.h"
#include "Servo_Motor_Priv.h"




static u8 Local_Stu8MotON_FLAG[MOT_NO_OF_MOTORS]  ;


static u8 Local_Stu8Mot_OldDirection[MOT_NO_OF_MOTORS]  ;





/*************************************************************************************************************************************************************/
/* Description: Initialize the Motor Pins and  value (if needed) 																				             */
/*																																							 */
/* Inputs : Void															     																		     */
/* Outputs: u8Error -> Error State																															 */
/*																																							 */

u8 Mot_u8Init(void) {
	u8 Local_u8ErrorState = ERROR_OK ;



			for (u8 Local_u8MotNb = 0 ; Local_u8MotNb < MOT_NO_OF_MOTORS ; Local_u8MotNb ++){

					if( Mot_Au8ArrayToMotInitState[Local_u8MotNb] == MOT_STATE_ON ){

						if ( Mot_Au8ArrayToMotInitDirection[Local_u8MotNb] == MOT_DIRECTION_CLOCKWISE ) {
							Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Local_u8MotNb][0] , Mot_Au8ArrayToMotType[Local_u8MotNb] )  ;
							Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Local_u8MotNb][1] , !Mot_Au8ArrayToMotType[Local_u8MotNb] ) ;

							Local_Stu8Mot_OldDirection[Local_u8MotNb] = MOT_DIRECTION_CLOCKWISE ;
							Local_Stu8MotON_FLAG[Local_u8MotNb]=1 ;

						}
						else if( Mot_Au8ArrayToMotInitDirection[Local_u8MotNb] == MOT_DIRECTION_ACLOCKWISE ){
							Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Local_u8MotNb][1] , Mot_Au8ArrayToMotType[Local_u8MotNb] )  ;
							Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Local_u8MotNb][0] , !Mot_Au8ArrayToMotType[Local_u8MotNb] ) ;

							Local_Stu8Mot_OldDirection[Local_u8MotNb] = MOT_DIRECTION_ACLOCKWISE ;
							Local_Stu8MotON_FLAG[Local_u8MotNb]=1 ;

						}
					}
					else if( Mot_Au8ArrayToMotInitState[Local_u8MotNb] == MOT_STATE_OFF ){
						Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Local_u8MotNb][1] , !Mot_Au8ArrayToMotType[Local_u8MotNb] )  ;
						Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Local_u8MotNb][0] , !Mot_Au8ArrayToMotType[Local_u8MotNb] ) ;

						Local_Stu8MotON_FLAG[Local_u8MotNb]=0 ;
					}

			}





	return Local_u8ErrorState ;
}


/*																																							 */
/*************************************************************************************************************************************************************/







/*************************************************************************************************************************************************************/
/* Description: Set the Motor Direction to clockwise and set the required Pins 																	             */
/*																																							 */
/* Inputs : u8 Copy_u8MotorIndex															     														     */
/* Outputs: u8Error -> Error State																															 */
/*																																							 */

u8 Mot_u8RotateCW(u8 Copy_u8MotorIndex) {
	u8 Local_u8ErrorState = ERROR_OK ;


	if( Local_Stu8MotON_FLAG[Copy_u8MotorIndex] == 1){

		if( Local_Stu8Mot_OldDirection[Copy_u8MotorIndex] == MOT_DIRECTION_ACLOCKWISE ){

			Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Copy_u8MotorIndex][0] , !Mot_Au8ArrayToMotType[Copy_u8MotorIndex] ) ;
			Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Copy_u8MotorIndex][1] , !Mot_Au8ArrayToMotType[Copy_u8MotorIndex] ) ;

			delay_milliSecond(500);

		}

		Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Copy_u8MotorIndex][0] , Mot_Au8ArrayToMotType[Copy_u8MotorIndex] )  ;
		Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Copy_u8MotorIndex][1] , !Mot_Au8ArrayToMotType[Copy_u8MotorIndex] ) ;

		Local_Stu8Mot_OldDirection[Copy_u8MotorIndex] = MOT_DIRECTION_CLOCKWISE ;


	}

	return Local_u8ErrorState ;
}


/*																																							 */
/*************************************************************************************************************************************************************/








/*************************************************************************************************************************************************************/
/* Description: Set the Motor Direction to Anti-clockwise and set the required Pins 															             */
/*																																							 */
/* Inputs : u8 Copy_u8MotorIndex															     														     */
/* Outputs: u8Error -> Error State																															 */
/*																																							 */

u8 Mot_u8RotateACW(u8 Copy_u8MotorIndex) {
	u8 Local_u8ErrorState = ERROR_OK ;

	if( Local_Stu8MotON_FLAG[Copy_u8MotorIndex] == 1){

		if( Local_Stu8Mot_OldDirection[Copy_u8MotorIndex] == MOT_DIRECTION_CLOCKWISE ){

			Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Copy_u8MotorIndex][0] , !Mot_Au8ArrayToMotType[Copy_u8MotorIndex] ) ;
			Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Copy_u8MotorIndex][1] , !Mot_Au8ArrayToMotType[Copy_u8MotorIndex] ) ;

			delay_milliSecond(500);

		}

		Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Copy_u8MotorIndex][1] , Mot_Au8ArrayToMotType[Copy_u8MotorIndex] )  ;
		Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Copy_u8MotorIndex][0] , !Mot_Au8ArrayToMotType[Copy_u8MotorIndex] ) ;

		Local_Stu8Mot_OldDirection[Copy_u8MotorIndex] = MOT_DIRECTION_ACLOCKWISE ;

	}



	return Local_u8ErrorState ;
}


/*																																							 */
/*************************************************************************************************************************************************************/








/*************************************************************************************************************************************************************/
/* Description: Set the Motor State to off and zero its flag																					             */
/*																																							 */
/* Inputs : u8 Copy_u8MotorIndex															     														     */
/* Outputs: u8Error -> Error State																															 */
/*																																							 */

u8 Mot_u8MotOff(u8 Copy_u8MotorIndex) {
	u8 Local_u8ErrorState = ERROR_OK ;



		Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Copy_u8MotorIndex][0] , !Mot_Au8ArrayToMotType[Copy_u8MotorIndex] )  ;
		Local_u8ErrorState = DIO_u8SetPinValue(Motor_Au8ArrayToPins[Copy_u8MotorIndex][1] , !Mot_Au8ArrayToMotType[Copy_u8MotorIndex] ) ;



		Local_Stu8MotON_FLAG[Copy_u8MotorIndex]  = 0 ;





	return Local_u8ErrorState ;
}


/*																																							 */
/*************************************************************************************************************************************************************/







/*************************************************************************************************************************************************************/
/* Description: Set the Motor State to on and open its flag																					             */
/*																																							 */
/* Inputs : u8 Copy_u8MotorIndex															     														     */
/* Outputs: u8Error -> Error State																															 */
/*																																							 */

u8 Mot_u8MotOn(u8 Copy_u8MotorIndex) {
	u8 Local_u8ErrorState = ERROR_OK ;

	Local_Stu8MotON_FLAG[Copy_u8MotorIndex]  = 1 ;

	if( Local_Stu8Mot_OldDirection[Copy_u8MotorIndex] == MOT_DIRECTION_CLOCKWISE ){
		Local_u8ErrorState = Mot_u8RotateCW(Copy_u8MotorIndex) ;
	}
	else if( Local_Stu8Mot_OldDirection[Copy_u8MotorIndex] == MOT_DIRECTION_ACLOCKWISE ){
		Local_u8ErrorState = Mot_u8RotateACW(Copy_u8MotorIndex) ;
	}



	return Local_u8ErrorState ;
}


/*																																							 */
/*************************************************************************************************************************************************************/








#endif
