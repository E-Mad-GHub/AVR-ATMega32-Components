/************************************************************************************/
/* Description : This is a configuration file that contains the public Configuration*/
/*               needed to use the Motor Component in high efficiency               */
/* 				 This Driver Supports AVR ATmel32 - STM32F103 ARM     			    */
/*																					*/
/* Created on  : Mar 10, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/





#ifndef MOTOR_CONF_H_
#define MOTOR_CONF_H_






/* Define Number of Motors used *****************************/
/*															*/
#define MOT_NO_OF_MOTORS		1
/*															*/
/************************************************************/





/* Define the Motor Pins ****************************************************/
/* Range : Choose Pins from the interface file       		    			*/
/*		  													    			*/
/* Note: the clockwise direction will put high on first pin 				*/
/*		 and low on the second pin in case of active high					*/
/*		  													    			*/
/* Choose Pins as example  MOTOR_PIN33										*/


u8 Motor_Au8ArrayToPins[MOT_NO_OF_MOTORS][2] = {
											{MOTOR_PIN0 , MOTOR_PIN1 }
								  	  	    };

/*		  													    			*/
/****************************************************************************/






/* Define the Motor Active Type *********************************/
/* Range : MOT_ACTIVE_LOW									    */
/*		   MOT_ACTIVE_HIGH									    */

u8 Mot_Au8ArrayToMotType[MOT_NO_OF_MOTORS]={MOT_ACTIVE_HIGH} ;

/*															    */
/****************************************************************/




/* Define the Motor Initial Direction *******************************************/
/* Range : MOT_DIRECTION_CLOCKWISE									   			*/
/*		   MOT_DIRECTION_ACLOCKWISE								    			*/

u8 Mot_Au8ArrayToMotInitDirection[MOT_NO_OF_MOTORS]={MOT_DIRECTION_CLOCKWISE} ;

/*															    				*/
/********************************************************************************/






/* Define the Motor Initial State ***********************************************/
/* Range : MOT_STATE_ON												   			*/
/*		   MOT_STATE_OFF								    					*/

u8 Mot_Au8ArrayToMotInitState[MOT_NO_OF_MOTORS]={MOT_STATE_ON} ;

/*															    				*/
/********************************************************************************/








#endif /* MOTOR_CONF_H_ */
