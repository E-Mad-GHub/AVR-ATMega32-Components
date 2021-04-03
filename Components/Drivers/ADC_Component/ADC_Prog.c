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

static u8 GlGroup ;

static u8 Read = 1 ;

static u8 Write = 0 ;

static u16 Vals[2][8] ;

/************************************************/




/*************** Static Functions ***************/

static void RefStartConv(void) ;

static void Update(u8 ElementIndex , u16 Value) ;

static void Swap(void) ;

static void StartConv(void) ;

static void HWSet(void);

static void HWReset(void);

/************************************************/


/* Junk */
static void nthng(void) ;



/*************************************************************************************************/
/* Description: Initialization of ADC includes initializing static variables and defining the    */
/*				configurations found in the "config.h" file 							         */
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
	((Register*) LOCAL_ADMUX ) -> ByteAccess  |= (ADC_DEF_CHANNEL) ;

	/* Trigger Type 					*/
	((Register*) LOCAL_ADCSRA ) -> ByteAccess  &= (LOCAL_TRIGG_TYPE_MASK) ;
	((Register*) LOCAL_ADCSRA ) -> ByteAccess  |= (DEF_CHANNEL_TRIGGER)   ;


	/* HW Trigger Type		 			*/
	((Register*) LOCAL_SFIOR  ) -> ByteAccess  |= (HW_TRIGGER_CONFIG)     ;



}

/*																					             */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Starts Conversion of ADC channel set before		 					             */
/*																				            	 */
/* Inputs : void 																		         */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void ADC_vStartConverting( void ) {


	if ((HW_TRIGGER_CONFIG == HW_TRIG_FREE_RUN) ){   //grps[GlGroup].TriggerType == TRIGG_TYPE_SW ||
		/* Start			 				*/
		((Register*) LOCAL_ADCSRA ) -> ByteAccess  |= (LOCAL_START) ;
	}

}

/*																								 */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Fill Array with the values converted from ADC						             */
/*																				            	 */
/* Inputs : Copy_u16ValuePtr 				-> Pointer to Array							         */
/* 			Copy_u8Length 					-> Array Length										 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 ADC_vGetADC( u16 * Copy_u16ValuePtr , u8 Copy_u8Length){

	u8 Local_u8ErrorState = ERROR_OK ;

	if (Copy_u8Length < 8){
		for (u8 count = 0 ; count < Copy_u8Length ; count ++){
			Copy_u16ValuePtr[count] = Vals[Read][count] ;
		}
	}
	else {
		Local_u8ErrorState = ERROR_NOK ;
	}


	return Local_u8ErrorState ;
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
	else {
		Local_u8ErrorState = ERROR_NOK ;
	}

	return Local_u8ErrorState ;
}

/*																								 */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Work the ADC with Blocking Mode	(SW Triggered) 						             */
/*																				            	 */
/* Inputs : Copy_ReturnValue 		-> Value of Conversion										 */
/* 			Copy_ChosenChannel		-> Channel to work on	 									 */
/*																								 */
/* Outputs: void																	             */
/*																					             */

void ADC_SWGetBlocking( u16 * Copy_ReturnValue , u8 Copy_ChosenChannel ) {

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
/* Description: Work the ADC with Blocking Mode	(HW Triggered) 						             */
/*																				            	 */
/* Inputs : Copy_ReturnValue 		-> Value of Conversion										 */
/* 			Copy_ChosenChannel		-> Channel to work on	 									 */
/*																								 */
/* Outputs: void																	             */
/*																					             */

void ADC_HWGetBlocking( u16 * Copy_ReturnValue , u8 Copy_ChosenChannel ) {

	u8 flag = 0 ;


	/* Interrupt Disable	 			*/
	((Register*) LOCAL_ADCSRA ) -> ByteAccess  &= (LOCAL_INTR_MASK)    ;

	/* CHANNEL CHOICE	 				*/
	((Register*) LOCAL_ADMUX )  -> ByteAccess  &= (LOCAL_CHANNEL_MASK)  ;
	((Register*) LOCAL_ADMUX )  -> ByteAccess  |= (Copy_ChosenChannel)  ;



	/* Pulling Wait		 				*/
	while(!flag){

		flag = ( ((Register*) LOCAL_ADCSRA ) -> ByteAccess )&(LOCAL_CONV_FLAG) ;

	}

	*Copy_ReturnValue = ((Register_16*) LOCAL_ADCL ) -> DualAccess ;




}

/*																					             */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Selects ADC Channel 												             */
/*																				            	 */
/* Inputs : Copy_u8Channel 					-> Selected Channel, EX. ADC_CH0		             */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void ADC_vSetChannel( u8 Copy_u8Channel ){

	/* CHANNEL CHOICE	 				*/
	((Register*) LOCAL_ADMUX )  -> ByteAccess  &= (LOCAL_CHANNEL_MASK)  ;
	((Register*) LOCAL_ADMUX )  -> ByteAccess  |= (Copy_u8Channel)  ;

}

/*																					             */
/*************************************************************************************************/




/*************************************************************************************************/
/* Description: Free Running Mode in ADC, just waits on conv. flag and writes the value of 		 */
/* 				ADC conversion in the argument										             */
/*																				            	 */
/* Inputs : *Copy_u16Value 					-> Return value of ADC after Conv.		             */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void ADC_vFreeRun( u16 * Copy_u16Value ){

	/* Pulling Wait		 				*/
   	while(!(( ((Register*) LOCAL_ADCSRA ) -> ByteAccess )&(LOCAL_CONV_FLAG))){

   	}

   	*Copy_u16Value = ((Register_16*) LOCAL_ADCL ) -> DualAccess ;

}

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: ADC Refresh Group API												             */
/*																				            	 */
/* Inputs : Copy_u8GroupIndex 				-> Group Index .. Ex. 0 , 1 , 2 , 3 ... etc          */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void ADC_u8Refresh( u8 Copy_u8GroupIndex ){

	ch_index = 0 ;

	GlGroup = Copy_u8GroupIndex ;

	HWSet();


	/* Interrupt Enable	 				*/
	((Register*) LOCAL_ADCSRA ) -> ByteAccess  &= (LOCAL_INTR_MASK)    ;
	((Register*) LOCAL_ADCSRA ) -> ByteAccess  |= (LOCAL_INTR_ENABLE)  ;


	/* Start Conversion Function		*/
	RefStartConv() ;

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

	RefStartConv() ;




}

/*																					             */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Conversion Initiation Function		 								             */

static void RefStartConv(void){



	switch (ch_index){

	case CHANNEL_NB:

		Swap() ;
		HWReset();
		PtrToFunction();

		break ;

	default:

		StartConv();
		nthng() ;			// i really couldn't see why this should be here so it can continue converting, i tried everything to eliminate it but i wasn't lucky :/

	}



}

/*																					             */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Conversion Initiation Function		 								             */

static void StartConv(void){

	if (grps[GlGroup].TriggerType == TRIGG_TYPE_SW) {

		/* CHANNEL CHOICE	 				*/
		((Register*) LOCAL_ADMUX ) -> ByteAccess  &= (LOCAL_CHANNEL_MASK)  ;
		((Register*) LOCAL_ADMUX ) -> ByteAccess  |= (grps[GlGroup].ArrOfChnls[ch_index]) ;

		/* Start			 				*/
		((Register*) LOCAL_ADCSRA) -> ByteAccess  |= (LOCAL_START) ;

	}
	else {

		/* CHANNEL CHOICE	 				*/
		((Register*) LOCAL_ADMUX ) -> ByteAccess  &= (LOCAL_CHANNEL_MASK)  ;
		((Register*) LOCAL_ADMUX ) -> ByteAccess  |= (grps[GlGroup].ArrOfChnls[ch_index]) ;

		/* Pulling Wait		 				*/
		while(!( ( ((Register*) LOCAL_ADCSRA ) -> ByteAccess )&(LOCAL_CONV_FLAG) )){

		}
	}

}

/*																					             */
/*************************************************************************************************/




/*************************************************************************************************/
/* Description: Array Swaping Function				 								             */

static void Swap(void){

	u8 tmp ;

	tmp   = Read ;
	Read  = Write;
	Write = tmp  ;

}

/*																					             */
/*************************************************************************************************/




/*************************************************************************************************/
/* Description: Value Assign Function				 								             */

static void Update(u8 ElementIndex , u16 Value){


	if ( (ElementIndex < grps[GlGroup].CH_Nb) ){

		Vals[Write][ElementIndex]   = Value ;

	}


}

/*																					             */
/*************************************************************************************************/




/*************************************************************************************************/
/* Description: Set the Trigger Type 				 								             */

static void HWSet(void){

	if (grps[GlGroup].TriggerType == TRIGG_TYPE_SW){
		/* Trigger Type 					*/
		((Register*) LOCAL_ADCSRA ) -> ByteAccess  &= (LOCAL_TRIGG_TYPE_MASK) ;
		((Register*) LOCAL_ADCSRA ) -> ByteAccess  |= (TRIGG_TYPE_SW)   ;
	}
	else {
		/* Trigger Type 					*/
		((Register*) LOCAL_ADCSRA ) -> ByteAccess  &= (LOCAL_TRIGG_TYPE_MASK) ;
		((Register*) LOCAL_ADCSRA ) -> ByteAccess  |= (TRIGG_TYPE_HW)   ;
	}

}

/*																					             */
/*************************************************************************************************/




/*************************************************************************************************/
/* Description: Resets the Trigger Type to the Default state						             */

static void HWReset(void){

	if (grps[GlGroup].TriggerType == TRIGG_TYPE_SW){
		/* Trigger Type 					*/
		((Register*) LOCAL_ADCSRA ) -> ByteAccess  &= (LOCAL_TRIGG_TYPE_MASK) ;
		((Register*) LOCAL_ADCSRA ) -> ByteAccess  |= (DEF_CHANNEL_TRIGGER)   ;
	}

}

/*																					             */
/*************************************************************************************************/






/* Literally Junk Yard */
static void nthng(void){
		DIO_u8SetPinValue( 31 , 0 ) ;
}





