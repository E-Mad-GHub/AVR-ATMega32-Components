/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the Switch Component in    		    */
/* 				 high efficiency													*/
/* 				 This Driver Supports AVR ATmel32                                   */
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


#ifndef EXTINT_COMPONENT_INTERFACE_H_
#define EXTINT_COMPONENT_INTERFACE_H_




/******* Configurations Dependencies ********/
/*									        */

/* Defining Private Variables               */
#define MCR_GIE_ENABLED 			(u8)1
#define MCR_GIE_DISABLED 			(u8)0

/*									        */
/********************************************/




/*************************************************************************************************/
/* Description: Enables the GIE from SREG register	 								             */
/*																				            	 */
/* Inputs : void														 			             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void MCR_u8EnableGIE( ) ;

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Disables the GIE from SREG register	 								             */
/*																				            	 */
/* Inputs : void														 			             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void MCR_u8DisableGIE( ) ;

/*																					             */
/*************************************************************************************************/






#endif /* EXTINT_COMPONENT_EXTINT_INTERFACE_H_ */
