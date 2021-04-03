/************************************************************************************/
/* Description : This is an Program file that contains the public definitions and   */
/*               public functions implementations needed to use the Seven Segments  */
/*               Component in high efficiency									    */
/* 				                     												*/
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/

#include "STD_TYPE.h"

#include "MCU_Config.h"
#include "MCU_Int.h"
#include "MCU_Priv.h"






/*************************************************************************************************/
/* Description: Enables the GIE from SREG register	 								             */
/*																				            	 */
/* Inputs : void														 			             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void MCR_u8EnableGIE( ) {

	((Register*) LOCAL_SREG ) -> ByteAccess  |= (LOCAL_GIE_MASK) ;

}

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Disables the GIE from SREG register	 								             */
/*																				            	 */
/* Inputs : void														 			             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void MCR_u8DisableGIE( ) {

	((Register*) LOCAL_SREG ) -> ByteAccess  &= ~(LOCAL_GIE_MASK) ;

}

/*																					             */
/*************************************************************************************************/

















