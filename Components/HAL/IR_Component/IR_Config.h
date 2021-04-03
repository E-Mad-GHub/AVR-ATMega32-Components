/************************************************************************************/
/* Description : This is a Configuration file that contains the Allowed Customizati-*/
/*               ons for Seven Segments Component                                   */
/*               allowed only for Application Engineers 							*/
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/





#ifndef IR_COMPONENT_SSEG_CONFIG_H_
#define IR_COMPONENT_SSEG_CONFIG_H_



#include "IR_Interface.h"
#include "IR_priv.h"





/***************** Public Configuration *********************/
/*															*/

#define NO_OF_IR 			1

/*															*/
/************************************************************/









/* Define Parameters of IRs used ****************************/
/*															*/
/* choose between IR_DETECT_HIGH or IR_DETECT_LOW			*/
#define IR_TYPE				IR_DETECT_HIGH

/*															*/
/************************************************************/




/***********************************************************************/
/* Description : Assigning No of IR Connected to the AVR			   */
/*                                                       			   */
/*																       */

IR_Au8PinDefinitions[NO_OF_IR] = { IR_PIN0 };

/*                                                       			   */
/*																       */
/***********************************************************************/





#endif /* SSEG_COMPONENT_SSEG_CONFIG_H_ */
