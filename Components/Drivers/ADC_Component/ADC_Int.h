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

/* Defining Trigger Types					*/
#define TRIGG_TYPE_HW					0X20
#define TRIGG_TYPE_SW					0X00

/* Defining HW Trigger Types				*/
#define   HW_TRIG_FREE_RUN				0x00
#define   HW_TRIG_ANALOG_COMP           0x20
#define   HW_TRIG_EXTI0                 0x40

#define   HW_TRIG_T0_COMP_MATCH         0x60
#define   HW_TRIG_T0_OVF                0x80

#define   HW_TRIG_T1_COMP_MATCH         0xA0
#define   HW_TRIG_T1_OVF                0xC0
#define   HW_TRIG_T1_ICU                0xE0



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
/* Description: Selects ADC Channel 												             */
/*																				            	 */
/* Inputs : Copy_u8Channel 					-> Selected Channel, EX. ADC_CH0		             */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void ADC_vSetChannel( u8 Copy_u8Channel );

/*																					             */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Free Running Mode in ADC, just waits on conv. flag and writes the value of 		 */
/* 				ADC conversion in the argument										             */
/*																				            	 */
/* Inputs : *Copy_u16Value 					-> Return value of ADC after Conv.		             */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void ADC_vFreeRun( u16 * Copy_u16Value );

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Starts Conversion of ADC channel set before		 					             */
/*																				            	 */
/* Inputs : void 																		         */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void ADC_vStartConverting( void );

/*																					             */
/*************************************************************************************************/


/*************************************************************************************************/
/* Description: Fill Array with the values converted from ADC						             */
/*																				            	 */
/* Inputs : Copy_u16ValuePtr 				-> Pointer to Array							         */
/* 			Copy_u8Length 					-> Array Length										 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 ADC_vGetADC( u16 * Copy_u16ValuePtr , u8 Copy_u8Length);

/*																					             */
/*************************************************************************************************/




/*************************************************************************************************/
/* Description: Work the ADC with Blocking Mode	(SW Triggered) 						             */
/*																				            	 */
/* Inputs : Copy_ReturnValue 		-> Value of Conversion										 */
/* 			Copy_ChosenChannel		-> Channel to work on	 									 */
/*																								 */
/* Outputs: void																	             */
/*																					             */

void ADC_SWGetBlocking( u16 * Copy_ReturnValue , u8 Copy_ChosenChannel )  ;

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

void ADC_HWGetBlocking( u16 * Copy_ReturnValue , u8 Copy_ChosenChannel )  ;

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
/* Description: ADC Refresh Group API												             */
/*																				            	 */
/* Inputs : Copy_u8GroupIndex 				-> Group Index .. Ex. 0 , 1 , 2 , 3 ... etc          */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

void ADC_u8Refresh( u8 Copy_u8GroupIndex );

/*																					             */
/*************************************************************************************************/








#endif /* EXTINT_COMPONENT_EXTINT_INTERFACE_H_ */
