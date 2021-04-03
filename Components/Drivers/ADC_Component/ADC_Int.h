/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the ADC Component in    		    */
/* 				 high efficiency													*/
/* 				 This Driver Supports AVR ATmel32                                   */
/*																					*/
/* Created on  : April 16, 2019 													*/
/* Author      : OMDA																*/
/************************************************************************************/



/*  File Guard  			*/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_



/* Defining the type "CHANNELS" which will be used by the "Refresh" Function */

typedef struct{
	u8 FinFlag ;
	u16 Value  ;
}CHANNELS ;

/*****************************************************************************/





/******* Configurations Dependencies ********/
/*									        */

/* Defining Reference Voltage               */
#define REF_EXTERNAL_VOLT 				0x00
#define REF_VCC							0x40
#define REF_2_5							0xC0

/* Defining Prescaler Value	                */
#define PRE_OVER_2						0x00
#define PRE_OVER_4						0x02
#define PRE_OVER_8						0x03
#define PRE_OVER_16						0x04
#define PRE_OVER_32						0x05
#define PRE_OVER_64						0x06
#define PRE_OVER_128					0x07

/* Defining Adjustment Value                */
#define ADJ_RIGHT						0x00
#define ADJ_LEFT						0x20

/* Defining ADC Enable Mask	                */
#define ADC_ENABLED						0x80
#define ADC_DISABLED					0x00

/* Defining Channels 		                */
#define ADC_CH0							0x00
#define ADC_CH1							0x01
#define ADC_CH2							0x02
#define ADC_CH3							0x03

#define ADC_CH4							0x04
#define ADC_CH5							0x05
#define ADC_CH6							0x06
#define ADC_CH7							0x07


/*									        */
/********************************************/




/*************************************************************************************************/
/* Description: Initialization of ADC includes initializing static variables and defining the    */
/*				configurations found in the "config.h" file 							         */
/*																				            	 */
/* Inputs : void														 			             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void ADC_vInit( void ) ;

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Work the ADC with Blocking Mode		 								             */
/*																				            	 */
/* Inputs : void														 			             */
/* 																								 */
/* Outputs: void																	             */
/*																					             */

void ADC_GetBlocking( u16 * Copy_ReturnValue , u8 Copy_ChosenChannel )  ;

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Assigns a Fn to the pointer in the ISH								             */
/*																				            	 */
/* Inputs : (*Copy_PvoidFuncCallBack)(void) -> the address of the function to be used			 */
/* 																								 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 ADC_u8SetCallBack( void (*Copy_PvoidFuncCallBack)(void) ) ;

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: ADC Refresh API														             */
/*																				            	 */
/* Inputs : Copy_u8ReturnAddress 			-> Address of the return Array Variable		         */
/* 			Copy_u8NumOfElements            -> Array Number of elements							 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 ADC_u8Refresh( CHANNELS * Copy_u8ReturnAddress , u8 Copy_u8NumOfElements);

/*																					             */
/*************************************************************************************************/








#endif /* EXTINT_COMPONENT_EXTINT_INTERFACE_H_ */
