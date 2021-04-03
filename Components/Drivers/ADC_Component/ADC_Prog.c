/************************************************************************************/
/* Description : This is an Program file that contains the public definitions and   */
/*               public functions implementations needed to use the ADC			    */
/*               Component in high efficiency									    */
/* 				                     												*/
/*																					*/
/* Created on  : April 16, 2019 													*/
/* Author      : OMDA																*/
/************************************************************************************/

#include "STD_TYPE.h"



#include "ADC_Int.h"
#include "ADC_Priv.h"
#include "ADC_Config.h"



/**************  SHARED RESOURCES **************/

static void (*PtrToFunction)(void) ;

static u8 ch_index = 0 ;

static CHANNELS * Container = NULL ;

static u8 ContainerElements = 0 ;

/************************************************/




/*************** Static Functions ***************/

static void StartConv(void) ;

static u8 SetContainer( CHANNELS * Copy_u8ReturnAddress , u8 Copy_u8NumOfElements) ;

static void Update(u8 ElementIndex , u16 Value) ;

/************************************************/




/*************************************************************************************************/
/* Description: Enables the GIE from SREG register	 								             */
/*																				            	 */
/* Inputs : void														 			             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void ADC_vInit( void ) {


	/* Variables Initializations ************************/

	PtrToFunction = NULL ;

	ch_index = 0 ;
	/****************************************************/





	/* REFRENCE VOLTAGE 				*/
	((Register*) LOCAL_ADMUX ) -> ByteAccess  &= (LOCAL_REF_MASK)  ;
	((Register*) LOCAL_ADMUX ) -> ByteAccess  |= (ADC_REF_VOLTAGE) ;

	/* PRESCALER CHOICE 				*/
	((Register*) LOCAL_ADCSRA ) -> ByteAccess  &= (LOCAL_PRES_MASK)  ;
	((Register*) LOCAL_ADCSRA ) -> ByteAccess  |= (ADC_PRESCALER) ;

	/* ADJUSTMENT CHOICE 				*/
	((Register*) LOCAL_ADMUX ) -> ByteAccess  &= (LOCAL_ADJS_MASK)  ;
	((Register*) LOCAL_ADMUX ) -> ByteAccess  |= (ADC_ADJUSTMENT) ;

	/* STATUS CHOICE	 				*/
	((Register*) LOCAL_ADCSRA ) -> ByteAccess  &= (LOCAL_STATUS_MASK)  ;
	((Register*) LOCAL_ADCSRA ) -> ByteAccess  |= (INIT_STATE) ;

	/* CHANNEL CHOICE	 				*/
	((Register*) LOCAL_ADMUX ) -> ByteAccess  &= (LOCAL_CHANNEL_MASK)  ;
	((Register*) LOCAL_ADMUX ) -> ByteAccess  |= (ADC_CHANNEL) ;



}

/*																					             */
/*************************************************************************************************/







/*************************************************************************************************/
/* Description: Assigns a Fn to the pointer in the ISH								             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex 				-> No of Interrupt							         */
/* 			(*Copy_PvoidFuncCallBack)(void) -> the address of the function to be used			 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 ADC_u8SetCallBack( void (*Copy_PvoidFuncCallBack)(void) ) {

	u8 Local_u8ErrorState = ERROR_OK ;

	if(Copy_PvoidFuncCallBack != NULL){
		PtrToFunction = Copy_PvoidFuncCallBack ;
	}

	return Local_u8ErrorState ;
}

/*																								 */
/*************************************************************************************************/








/*************************************************************************************************/
/* Description: Disables the GIE from SREG register	 								             */
/*																				            	 */
/* Inputs : void														 			             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void ADC_GetBlocking( u16 * Copy_ReturnValue , u8 Copy_ChosenChannel ) {

	u8 flag = 0 ;


	/* Interrupt Disable	 			*/
	((Register*) LOCAL_ADCSRA ) -> ByteAccess  &= (LOCAL_INTR_MASK)    ;

	/* CHANNEL CHOICE	 				*/
	((Register*) LOCAL_ADMUX )  -> ByteAccess  &= (LOCAL_CHANNEL_MASK)  ;
	((Register*) LOCAL_ADMUX )  -> ByteAccess  |= (Copy_ChosenChannel)  ;


	/* Start			 				*/
	((Register*) LOCAL_ADCSRA ) -> ByteAccess  |= (LOCAL_START) ;

	/* Pulling Wait		 				*/
	while(!flag){

		flag = ( ((Register*) LOCAL_ADCSRA ) -> ByteAccess )&(LOCAL_CONV_FLAG) ;

	}

	*Copy_ReturnValue = ((Register_16*) LOCAL_ADCL ) -> DualAccess ;




}

/*																					             */
/*************************************************************************************************/






/*************************************************************************************************/
/* Description: ADC Refresh API														             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex 				-> No of Interrupt							         */
/* 			(*Copy_PvoidFuncCallBack)(void) -> the address of the function to be used			 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 ADC_u8Refresh( CHANNELS * Copy_u8ReturnAddress , u8 Copy_u8NumOfElements){

	u8 Local_u8ErrorState = ERROR_OK ;

	Local_u8ErrorState = SetContainer( Copy_u8ReturnAddress , Copy_u8NumOfElements) ;

	for(u8 count = 0 ; count < Copy_u8NumOfElements ; count ++){
		Container[count].FinFlag = 0 ;
		Container[count].Value   = 0 ;
	}

	ch_index = 0 ;


	/* Interrupt Enable	 				*/
	((Register*) LOCAL_ADCSRA ) -> ByteAccess  &= (LOCAL_INTR_MASK)    ;
	((Register*) LOCAL_ADCSRA ) -> ByteAccess  |= (LOCAL_INTR_ENABLE)  ;


	/* Start Conversion Function		*/
	StartConv() ;


	return Local_u8ErrorState ;

}

/*																								 */
/*************************************************************************************************/






/*************************************************************************************************/
/* Description: ADC ISR								 								             */
/*																				            	 */
/* 																								 */
/*																					             */

void __vector_16 (void) __attribute__ ((signal)) ;

void __vector_16 (void) {									// ADC Conversion Done


	Update(ch_index , ((Register_16*) LOCAL_ADCL ) -> DualAccess) ;


	ch_index ++ ;




	if (ch_index == CHANNEL_NB){

		/* Interrupt Disable	 				*/
		((Register*) LOCAL_ADCSRA ) -> ByteAccess  &= (LOCAL_INTR_MASK)    ;



		if(PtrToFunction != NULL){
			PtrToFunction();
		}

	}
	else if (ch_index < CHANNEL_NB){

		StartConv() ;

	}



}

/*																					             */
/*************************************************************************************************/




























/*************************************************************************************************/
/* Description: Conversion Initiation Function		 								             */

static void StartConv(void){


	/* CHANNEL CHOICE	 				*/
	((Register*) LOCAL_ADMUX ) -> ByteAccess  &= (LOCAL_CHANNEL_MASK)  ;
	((Register*) LOCAL_ADMUX ) -> ByteAccess  |= (Ch_Chosen[ch_index]) ;


	/* Start			 				*/
	((Register*) LOCAL_ADCSRA) -> ByteAccess  |= (LOCAL_START) ;


}

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Value Assign Function				 								             */

static void Update(u8 ElementIndex , u16 Value){


	if ( (ElementIndex <= ContainerElements) ){

		Container[ElementIndex].Value   = Value ;
		Container[ElementIndex].FinFlag = 1     ;

	}


}

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Setting The Container Address		 								             */

static u8 SetContainer( CHANNELS * Copy_u8ReturnAddress , u8 Copy_u8NumOfElements){

	u8 Local_u8ErrorState = ERROR_OK ;


	if ( (Copy_u8NumOfElements <= CHANNEL_NB) ){
		Container         = Copy_u8ReturnAddress ;
		ContainerElements = Copy_u8NumOfElements ;
	}
	else {
		Local_u8ErrorState = ERROR_NOK ;
	}

	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/



