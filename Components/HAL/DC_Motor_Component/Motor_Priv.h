/************************************************************************************/
/* Description : This is a Private file that contains the private definitions and   */
/*               Private functions needed to use the Motor Component                */
/* 				 This Driver Supports AVR ATmel32 - STM32F103                       */
/*																					*/
/* Created on  : Mar 10, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


#ifndef MOTOR_PRIV_H_
#define MOTOR_PRIV_H_






/* Define Motors Active Type ********************************/
/*															*/
#define MOT_ACTIVE_HIGH		(u8)1
#define MOT_ACTIVE_LOW		(u8)0

/*															*/
/************************************************************/

/* Define Motors Initial Direction **********************************/
/*																	*/
#define MOT_DIRECTION_CLOCKWISE			(u8)5
#define MOT_DIRECTION_ACLOCKWISE		(u8)6

/*																	*/
/********************************************************************/

/* Define Motors Initial Direction **********************************/
/*																	*/

#define MOT_STATE_ON					(u8)7
#define MOT_STATE_OFF	 				(u8)8

/*																	*/
/********************************************************************/









#endif /* MOTOR_PRIV_H_ */
