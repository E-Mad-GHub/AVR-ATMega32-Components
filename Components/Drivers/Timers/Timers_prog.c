/************************************************************************************/
/* Description : This is an Program file that contains the public definitions and   */
/*               public functions implementations needed to use the Timers		    */
/*               Component in high efficiency									    */
/* 				                     												*/
/*																					*/
/* Created on  : April 12, 2019 													*/
/* Author      : OMDA																*/
/************************************************************************************/



/* File Guard         */
#ifndef KPD_PROG
#define KPD_PROG


#include "STD_TYPE.h"

#include "DIO_Interface.h"

#include "Timers_Int.h"
#include "Timers_Config.h"
#include "Timers_priv.h"



static void (*PtrToFunctions[INTR_NB])(void) ;










/*************************************************************************************************/
/* Description: Apply the configuration on the "Config.h" file						             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

void TIMERS_u8INIT(void) {





	for(u8 count = 0 ; count < INTR_NB ; count ++){

		PtrToFunctions[count] = NULL ;

	}














/* 	TIMER0 																				*/
	/* Timer0 Mode 				*/
	((Register*) LOCAL_TCCR0) -> ByteAccess &= MODE_CLEAR_MASK_1 ;
	((Register*) LOCAL_TCCR0) -> ByteAccess |= TIMER0_MODE       ;

	/* OC PIN Mode				*/
	((Register*) LOCAL_TCCR0) -> ByteAccess &= OC0_MASK    ;
	((Register*) LOCAL_TCCR0) -> ByteAccess |= TIMER0_OC0_PIN_MODE  ;

	/* Timer0 OVF Intr 			*/
	((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xFE    ;
	((Register*) LOCAL_TIMSK) -> ByteAccess |= TIMER0_OVF_INTR  ;

	/* Timer0 OC Intr 			*/
	((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xFD    ;
	((Register*) LOCAL_TIMSK) -> ByteAccess |= (TIMER0_OC_INTR << 1)  ;

	/* Timer0 Prescaler 		*/
	((Register*) LOCAL_TCCR0) -> ByteAccess &= PRE_CLEAR_MASK    ;
	((Register*) LOCAL_TCCR0) -> ByteAccess |= TIMER0_PRESCALER  ;






/* TIMER1																				*/

	/* Timer1 Mode 				*/
	((Register_16*) LOCAL_TCCR1) -> DualAccess &= MODE_CLEAR_MASK_2 ;
	((Register_16*) LOCAL_TCCR1) -> DualAccess |= TIMER1_MODE       ;


	/* OC1 PIN Mode				*/

	/* Timer1 OVF Intr 			*/
	((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xFB    ;
	((Register*) LOCAL_TIMSK) -> ByteAccess |= (TIMER1_OVF_INTR << 2)  ;

	/* Timer1 OC-A Intr 		*/
	((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xEF    ;
	((Register*) LOCAL_TIMSK) -> ByteAccess |= (TIMER1_OC1_INTR << 4)  ;

	/* Timer1 OC-B Intr 		*/
	((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xF7    ;
	((Register*) LOCAL_TIMSK) -> ByteAccess |= (TIMER1_OC2_INTR << 3)  ;

	/* Timer1 ICU Intr 			*/
	((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xDF    ;
	((Register*) LOCAL_TIMSK) -> ByteAccess |= (TIMER1_ICU_INTR << 5)  ;


	/* Timer1 Prescaler 		*/
	((Register_16*) LOCAL_TCCR1) -> DualAccess &= PRE_CLEAR_MASK_1    ;
	((Register_16*) LOCAL_TCCR1) -> DualAccess |= TIMER1_PRESCALER  ;








/* 	TIMER2 																				*/
	/* Timer2 Mode 				*/
/*	((Register*) LOCAL_TCCR2) -> ByteAccess &= MODE_CLEAR_MASK_1 ;
	((Register*) LOCAL_TCCR2) -> ByteAccess |= TIMER2_MODE       ;
*/
	/* Timer0 Prescaler 		*/
/*	((Register*) LOCAL_TCCR2) -> ByteAccess &= PRE_CLEAR_MASK    ;
	((Register*) LOCAL_TCCR2) -> ByteAccess |= TIMER2_PRESCALER  ;
*/
	/* OC PIN Mode				*/
/*	((Register*) LOCAL_TCCR2) -> ByteAccess &= OC0_MASK    ;
	((Register*) LOCAL_TCCR2) -> ByteAccess |= TIMER0_OC2_PIN_MODE  ;
*/
	/* Timer2 OVF Intr 			*/
/*	((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xBF    ;
	((Register*) LOCAL_TIMSK) -> ByteAccess |= (TIMER2_OVF_INTR << 6)  ;
*/
	/* Timer2 OC Intr 			*/
/*	((Register*) LOCAL_TIMSK) -> ByteAccess &= 0x7F    ;
	((Register*) LOCAL_TIMSK) -> ByteAccess |= (TIMER2_OC_INTR << 7)  ;
*/



	return;
}

/*																								 */
/*************************************************************************************************/







/*************************************************************************************************/
/* Description: Enable Interrupts of Timers											             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 TIMERS_u8EnableIntr(u8 Copy_u8TimerIndex , u8 Copy_u8Intr) {

	u8 Local_u8Error = ERROR_OK  ;


	switch(Copy_u8TimerIndex){

	case 0:
		switch(Copy_u8Intr){

		case OVF_INTR:

			/* Timer0 OVF Intr 			*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xFE    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= INTR_ENABLED  ;
			break ;

		case OC_INTR:
			/* Timer0 OC Intr 			*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xFD    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= (INTR_ENABLED << 1)  ;
			break;

		default:
			Local_u8Error = ERROR_NOK  ;
		}

		break;









	case 1:
		switch(Copy_u8Intr){

		case OVF1_INTR:

			/* Timer1 OVF Intr 			*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xFB    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= (INTR_ENABLED << 2)  ;
			break ;

		case OC1_A_INTR:
			/* Timer1 OC-A Intr 		*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xEF    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= (INTR_ENABLED << 4)  ;
			break;

		case OC1_B_INTR:
			/* Timer1 OC-B Intr 		*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xF7    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= (INTR_ENABLED << 3)  ;
			break;

		case ICU1_INTR:
			/* Timer1 ICU Intr 			*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xDF    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= (INTR_ENABLED << 5)  ;
			break;



		default:
			Local_u8Error = ERROR_NOK  ;
		}

		break;








	case 2:
		switch(Copy_u8Intr){

		case OVF_INTR:

			/* Timer2 OVF Intr 			*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xBF    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= (INTR_ENABLED << 6)  ;
			break ;

		case OC_INTR:
			/* Timer2 OC Intr 			*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0x7F    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= (INTR_ENABLED << 7)  ;
			break;

		default:
			Local_u8Error = ERROR_NOK  ;
		}

		break;



	}

	return Local_u8Error;
}

/*																								 */
/*************************************************************************************************/











/*************************************************************************************************/
/* Description: Disable Interrupts of Timers										             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 TIMERS_u8DisableIntr(u8 Copy_u8TimerIndex , u8 Copy_u8Intr) {

	u8 Local_u8Error = ERROR_OK  ;


	switch(Copy_u8TimerIndex){

	case 0:
		switch(Copy_u8Intr){

		case OVF_INTR:

			/* Timer0 OVF Intr 			*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xFE    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= INTR_DISABLED  ;
			break ;

		case OC_INTR:
			/* Timer0 OC Intr 			*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xFD    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= (INTR_DISABLED << 1)  ;
			break;

		default:
			Local_u8Error = ERROR_NOK  ;
		}

		break;









	case 1:
		switch(Copy_u8Intr){

		case OVF1_INTR:

			/* Timer1 OVF Intr 			*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xFB    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= (INTR_DISABLED << 2)  ;
			break ;

		case OC1_A_INTR:
			/* Timer1 OC-A Intr 		*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xEF    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= (INTR_DISABLED << 4)  ;
			break;

		case OC1_B_INTR:
			/* Timer1 OC-B Intr 		*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xF7    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= (INTR_DISABLED << 3)  ;
			break;

		case ICU1_INTR:
			/* Timer1 ICU Intr 			*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xDF    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= (INTR_DISABLED << 5)  ;
			break;



		default:
			Local_u8Error = ERROR_NOK  ;
		}

		break;








	case 2:
		switch(Copy_u8Intr){

		case OVF_INTR:

			/* Timer2 OVF Intr 			*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0xBF    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= (INTR_DISABLED << 6)  ;
			break ;

		case OC_INTR:
			/* Timer2 OC Intr 			*/
			((Register*) LOCAL_TIMSK) -> ByteAccess &= 0x7F    ;
			((Register*) LOCAL_TIMSK) -> ByteAccess |= (INTR_DISABLED << 7)  ;
			break;

		default:
			Local_u8Error = ERROR_NOK  ;
		}

		break;



	}

	return Local_u8Error;
}

/*																								 */
/*************************************************************************************************/













/*************************************************************************************************/
/* Description: Sets Mode for Timer													             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 TIMERS_u8SetMode(u8 Copy_u8TimerIndex , u16 Copy_u8Mode) {

	u8 Local_u8Error = ERROR_OK  ;


	switch(Copy_u8TimerIndex){

	case 0:

		/* Timer0 Mode 				*/
		((Register*) LOCAL_TCCR0) -> ByteAccess &= MODE_CLEAR_MASK_1 ;
		((Register*) LOCAL_TCCR0) -> ByteAccess |= Copy_u8Mode       ;
		break;

	case 1:
		/* Timer1 Mode 				*/
		((Register_16*) LOCAL_TCCR1) -> DualAccess &= MODE_CLEAR_MASK_2 ;
		((Register_16*) LOCAL_TCCR1) -> DualAccess |= Copy_u8Mode       ;
		break;

	case 2:
		/* Timer2 Mode 				*/
		((Register*) LOCAL_TCCR2) -> ByteAccess &= MODE_CLEAR_MASK_1 ;
		((Register*) LOCAL_TCCR2) -> ByteAccess |= Copy_u8Mode       ;
		break;

	default :
		Local_u8Error = ERROR_NOK  ;

	}


	return Local_u8Error;
}

/*																								 */
/*************************************************************************************************/







/*************************************************************************************************/
/* Description: Sets TCNT0 Register													             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

void TIMERS_u8SetTCNT0(u8 Copy_u8Val) {

	((Register*) LOCAL_TCNT0) -> ByteAccess = Copy_u8Val ;

}

/*																								 */
/*************************************************************************************************/




/*************************************************************************************************/
/* Description: Sets OCR0 Register													             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

void TIMERS_u8SetOCR0(u8 Copy_u8Val) {


	((Register*) LOCAL_TCNT0) -> ByteAccess = Copy_u8Val ;

}

/*																								 */
/*************************************************************************************************/




/*************************************************************************************************/
/* Description: Sets TCNT1 Register													             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

void TIMERS_u8SetTCNT1(u16 Copy_u8Val) {

	((Register_16*) LOCAL_TCNT1) -> DualAccess = Copy_u8Val ;

}

/*																								 */
/*************************************************************************************************/




/*************************************************************************************************/
/* Description: Sets OCR1-A Register												             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

void TIMERS_u8SetOCR1_A(u16 Copy_u8Val) {


	((Register_16*) LOCAL_OCR1_A) -> DualAccess = Copy_u8Val ;		// OCR1-A

}

/*																								 */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Sets OCR1-B Register												             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

void TIMERS_u8SetOCR1_B(u16 Copy_u8Val) {


	((Register_16*) LOCAL_OCR1_B) -> DualAccess = Copy_u8Val ;		// OCR1-B

}

/*																								 */
/*************************************************************************************************/




/*************************************************************************************************/
/* Description: Sets ICR Register													             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

void TIMERS_u8SetICR(u16 Copy_u8Val) {


	((Register_16*) LOCAL_ICR) -> DualAccess = Copy_u8Val ;		// OCR1-B

}

/*																								 */
/*************************************************************************************************/













/*************************************************************************************************/
/* Description: Assigns a Fn to the Function pointer of each Interrupt				             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex 				-> No of Interrupt							         */
/* 			(*Copy_PvoidFuncCallBack)(void) -> the address of the function to be used			 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 TIMERS_u8SetCallBack(u8 Copy_u8IntrIndex , void (*Copy_PvoidFuncCallBack)(void) ) {

	u8 Local_u8ErrorState = ERROR_OK ;

	if(Copy_PvoidFuncCallBack != NULL){
		PtrToFunctions[Copy_u8IntrIndex] = Copy_PvoidFuncCallBack ;
	}

	return Local_u8ErrorState ;
}

/*																								 */
/*************************************************************************************************/






/*************************************************************************************************/
/*								The functions to be used as an ISR								 */
/*																					             */


void __vector_6 (void) __attribute__ ((signal)) ;

void __vector_6 (void) {									// Timer1 Capture Event

	if (PtrToFunctions[2] != NULL)
			PtrToFunctions[2]() ;

}

void __vector_7 (void) __attribute__ ((signal)) ;

void __vector_7 (void) {									// Timer1 Compare A

	if (PtrToFunctions[3] != NULL)
			PtrToFunctions[3]() ;

}

void __vector_8 (void) __attribute__ ((signal)) ;

void __vector_8 (void) {									// Timer1 Compare B

	if (PtrToFunctions[4] != NULL)
			PtrToFunctions[4]() ;

}



void __vector_9 (void) __attribute__ ((signal)) ;

void __vector_9 (void) {									// Timer1 OVF

	if (PtrToFunctions[5] != NULL)
			PtrToFunctions[5]() ;

}



void __vector_10 (void) __attribute__ ((signal)) ;

void __vector_10 (void) {									// Timer0 Compare

	if (PtrToFunctions[0] != NULL)
		PtrToFunctions[0]() ;

}


void __vector_11 (void) __attribute__ ((signal)) ;

void __vector_11 (void) {									// Timer0 OVF

	if (PtrToFunctions[1] != NULL)
			PtrToFunctions[1]() ;

}



/*																								 */
/*************************************************************************************************/





























#endif
