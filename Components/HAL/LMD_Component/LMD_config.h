/************************************************************************************/
/* Description : This is a configuration file that contains the public Configuration*/
/*               needed to use the led Component in high efficiency                 */
/* 				 This Driver Supports AVR ATmel32                      			    */
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/







/* File Guard ***********************************************/
#ifndef LMD_COMPONENT_LMD_CONFIG_H_
#define LMD_COMPONENT_LMD_CONFIG_H_


#include "LMD_Interface.h"
#include "LMD_priv.h"



/* Define Configs of LMDs used ******************************/
/*															*/

/* Choose LMD_ACTIVE_ROW or LMD_ACTIVE_COL					*/
#define LMD_TYPE      	  		LMD_ACTIVE_ROW						/* I DONT KNOW WHAT SHOULD I DO ABOUT IT, THE USER SHOULD GENERATE THE IMAGE BUT IN DIFFERENT FORM */

/* Choose LMD_ACTIVE_LOW or LMD_ACTIVE_HIGH					*/
#define LMD_ACTIVE_TYPE			LMD_ACTIVE_LOW


#define LMD_ACTIVE_PORT			LOCAL_PORTA_CHOICE

/* First for Red Color and Second for Green Color 			*/
u8 LMA_COLOR_PORT[2] = {  LOCAL_PORTC_CHOICE,
						  LOCAL_PORTD_CHOICE} ;


/*															*/
/************************************************************/



#endif /* LMD_COMPONENT_LMD_CONFIG_H_ */
