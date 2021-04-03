/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the Motor Component in high efficie-*/
/* 				 ncy																*/
/* 				 This Driver Supports AVR ATmel32 - STM32F103                       */
/*																					*/
/* Created on  : Mar 10, 2019  														*/
/* Author      : OMDA																*/
/************************************************************************************/




#ifndef MOTOR_INT_H_
#define MOTOR_INT_H_





/*************************************   PIN  DEFINITIONS   *****************************************/
/* Description : Defining MOTOR Pins On AVR-ARM , Which contain 32-37 Pins Ranges from (0 -> 31-37) */
/*                                                                                             	  	*/
/* Example : #define MOTOR_Pin21  													             	*/
/*																						          	*/

#define MOTOR_PIN0    			   (u8)0
#define MOTOR_PIN1    			   (u8)1
#define MOTOR_PIN2    			   (u8)2
#define MOTOR_PIN3    			   (u8)3
#define MOTOR_PIN4    			   (u8)4
#define MOTOR_PIN5    			   (u8)5
#define MOTOR_PIN6    			   (u8)6
#define MOTOR_PIN7    			   (u8)7

#define MOTOR_PIN8    			   (u8)8
#define MOTOR_PIN9    			   (u8)9
#define MOTOR_PIN10    			   (u8)10
#define MOTOR_PIN11    			   (u8)11
#define MOTOR_PIN12    			   (u8)12
#define MOTOR_PIN13    			   (u8)13
#define MOTOR_PIN14    			   (u8)14
#define MOTOR_PIN15    			   (u8)15

#define MOTOR_PIN16    			   (u8)16
#define MOTOR_PIN17    			   (u8)17
#define MOTOR_PIN18    			   (u8)18
#define MOTOR_PIN19    			   (u8)19
#define MOTOR_PIN20    			   (u8)20
#define MOTOR_PIN21    			   (u8)21
#define MOTOR_PIN22    			   (u8)22
#define MOTOR_PIN23    			   (u8)23

#define MOTOR_PIN24    			   (u8)24
#define MOTOR_PIN25    			   (u8)25
#define MOTOR_PIN26    			   (u8)26
#define MOTOR_PIN27    			   (u8)27
#define MOTOR_PIN28    			   (u8)28
#define MOTOR_PIN29    			   (u8)29
#define MOTOR_PIN30    			   (u8)30
#define MOTOR_PIN31    			   (u8)31

#define MOTOR_PIN32    			   (u8)32
#define MOTOR_PIN33    			   (u8)33
#define MOTOR_PIN34    			   (u8)34

#define MOTOR_PIN35    			   (u8)35
#define MOTOR_PIN36    			   (u8)36

/*																						          	*/
/****************************************************************************************************/






/*************************************************************************************************************************************************************/
/* Description: Initialize the Motor Pins and  value (if needed) 																				             */
/*																																							 */
/* Inputs : Void															     																		     */
/* Outputs: u8Error -> Error State																															 */
/*																																							 */

u8 Mot_u8Init(void);

/*																																							 */
/*************************************************************************************************************************************************************/




/*************************************************************************************************************************************************************/
/* Description: Set the Motor Direction to clockwise and set the required Pins 																	             */
/*																																							 */
/* Inputs : u8 Copy_u8MotorIndex															     														     */
/* Outputs: u8Error -> Error State																															 */
/*																																							 */

u8 Mot_u8RotateCW(u8 Copy_u8MotorIndex);

/*																																							 */
/*************************************************************************************************************************************************************/






/*************************************************************************************************************************************************************/
/* Description: Set the Motor Direction to Anti-clockwise and set the required Pins 															             */
/*																																							 */
/* Inputs : u8 Copy_u8MotorIndex															     														     */
/* Outputs: u8Error -> Error State																															 */
/*																																							 */

u8 Mot_u8RotateACW(u8 Copy_u8MotorIndex);

/*																																							 */
/*************************************************************************************************************************************************************/








/*************************************************************************************************************************************************************/
/* Description: Set the Motor State to off and zero its flag																					             */
/*																																							 */
/* Inputs : u8 Copy_u8MotorIndex															     														     */
/* Outputs: u8Error -> Error State																															 */
/*																																							 */

u8 Mot_u8MotOff(u8 Copy_u8MotorIndex);

/*																																							 */
/*************************************************************************************************************************************************************/






/*************************************************************************************************************************************************************/
/* Description: Set the Motor State to on and zero its flag																						             */
/*																																							 */
/* Inputs : u8 Copy_u8MotorIndex															     														     */
/* Outputs: u8Error -> Error State																															 */
/*																																							 */

u8 Mot_u8MotOn(u8 Copy_u8MotorIndex);

/*																																							 */
/*************************************************************************************************************************************************************/











#endif /* MOTOR_INT_H_ */
