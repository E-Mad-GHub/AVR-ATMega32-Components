/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the Timers Component in    		    */
/* 				 high efficiency													*/
/* 				 This Driver Supports AVR ATmel32                                   */
/*																					*/
/* Created on  : April 12, 2019 													*/
/* Author      : OMDA																*/
/************************************************************************************/


#ifndef TIMERS_INT_H_
#define TIMERS_INT_H_





/*************************************   Timer  Modes   ****************************************/
/*                                                                                             */
/*																						       */

/* For Timer0 & Timer2 ONLY	    							  				            */
#define MODE_NORMAL0			   	(u8)0            /* Normal Operating Mode 			*/
#define MODE_PWM_PC			    	(u8)1	         /* PWM Phase Correct Mode 			*/
#define MODE_CTC			    	(u8)2	         /* Clear Timer in Compare Mode     */
#define MODE_PWM_FM			    	(u8)3            /* PWM Fast Mode 					*/

#define MODE_CLEAR_MASK_1	    	(u8)0xFC
/****************************************************************************************/


/* For Timer1 ONLY														                */
#define MODE_NORMAL1			    (u16)0x0000
#define MODE_PWM_PC_08_BIT		    (u16)0x0100
#define MODE_PWM_PC_09_BIT		    (u16)0x0200
#define MODE_PWM_PC_10_BIT		    (u16)0x0300
#define MODE_PWM_PC_ICR_TRIG	   	(u16)0x0210
#define MODE_PWM_PC_OCR_TRIG	   	(u16)0x0310

#define MODE_PWM_PFC_ICR_TRIG	   	(u16)0x0010
#define MODE_PWM_PFC_OCR_TRIG	    (u16)0x0110

#define MODE_CTC_OCR_TRIG		    (u16)0x0008
#define MODE_CTC_ICR_TRIG		    (u16)0x0018

#define MODE_PWM_FM_08_BIT		    (u16)0x0108
#define MODE_PWM_FM_09_BIT		    (u16)0x0208
#define MODE_PWM_FM_10_BIT		    (u16)0x0308
#define MODE_PWM_FM_ICR_TRIG		(u16)0x0218
#define MODE_PWM_FM_OCR_TRIG		(u16)0x0318

#define MODE_CLEAR_MASK_2		    (u16)0xFCE7
/****************************************************************************************/


/*																						       */
/***********************************************************************************************/







/*********************************   Timer  OCx Pin Mode   *************************************/
/*                                                                                             */
/*																						       */

#define OC0_DISCONNECTED			(u8)0x00
#define OC0_TOGGLE					(u8)0x10
#define OC0_NON_INV					(u8)0x20
#define OC0_INV						(u8)0x30

#define OC0_MASK					(u8)0xCF

/*																						       */
/***********************************************************************************************/






/**********************************   Timer  Prescalers   **************************************/
/*                                                                                             */
/*																						       */

#define PRE_NO_CLOCK				(u8)0x00
#define PRE_CLK_OVER_01				(u8)0x01
#define PRE_CLK_OVER_08				(u8)0x02
#define PRE_CLK_OVER_64				(u8)0x03

#define PRE_CLK_OVER_256			(u8)0x04
#define PRE_CLK_OVER_1024			(u8)0x05
#define PRE_CLK_EXT_FALLING			(u8)0x06
#define PRE_CLK_EXT_RISING			(u8)0x07

#define PRE_CLEAR_MASK				(u8)0xF8
#define PRE_CLEAR_MASK_1			(u16)0xFFF8

/*																						       */
/***********************************************************************************************/




/**********************************   Timer  Interrupts   **************************************/
/*                                                                                             */
/*																						       */

#define INTR_ENABLED 				(u8)1
#define INTR_DISABLED 				(u8)0

/*																						       */
/***********************************************************************************************/



/*************************************   Timer  Types   ****************************************/
/*                                                                                             */
/*																						       */

#define TIMER0						(u8)0
#define TIMER1						(u8)1
#define TIMER2						(u8)2

/*																						       */
/***********************************************************************************************/



/**********************************   Guiding Definitions   ************************************/
/*                                                                                             */
/*																						       */

/* ISR Handlers    */
#define TIMER0_COMPARE 				(u8)0
#define TIMER0_OVF					(u8)1
#define TIMER1_CAPTURE				(u8)2
#define TIMER1_COMPARE_A			(u8)3
#define TIMER1_COMPARE_B			(u8)4
#define TIMER1_OVF					(u8)5



#define OVF_INTR					(u8)1
#define OC_INTR						(u8)2

#define OVF1_INTR					(u8)1
#define OC1_A_INTR					(u8)2
#define OC1_B_INTR					(u8)3
#define ICU1_INTR					(u8)4

/*																						       */
/***********************************************************************************************/


















































/*************************************************************************************************/
/* Description: Apply the configuration on the "Config.h" file						             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

void TIMERS_u8INIT(void) ;

/*																								 */
/*************************************************************************************************/







/*************************************************************************************************/
/* Description: Assigns a Fn to the Function pointer of each Interrupt				             */
/*																				            	 */
/* Inputs : Copy_u8IntrIndex 				-> No of Interrupt							         */
/* 			(*Copy_PvoidFuncCallBack)(void) -> the address of the function to be used			 */
/* Outputs: u8Error 						-> Error State							             */
/*																					             */

u8 TIMERS_u8SetCallBack(u8 Copy_u8IntrIndex , void (*Copy_PvoidFuncCallBack)(void) ) ;


/*
Interrupt Types(Copy_u8IntrIndex):
			TIMER0_Comp
			TIMER0_OVF

 *
 */


/*																								 */
/*************************************************************************************************/












/*************************************************************************************************/
/* Description: Enable Interrupts of Timers											             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 TIMERS_u8EnableIntr(u8 Copy_u8TimerIndex , u8 Copy_u8Intr) ;

/*
Timer Types(Copy_u8TimerIndex):
			TIMER0
			TIMER1
            TIMER2
 *
 */



/*
Interrupt Types(Copy_u8Intr):
			OVF_INTR
			OC_INTR

			OVF1_INTR
			OC1_A_INTR
			OC1_B_INTR
			ICU1_INTR
 *
 */


/*																								 */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Disable Interrupts of Timers										             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 TIMERS_u8DisableIntr(u8 Copy_u8TimerIndex , u8 Copy_u8Intr) ;


/*
Timer Types(Copy_u8TimerIndex):
			TIMER0
			TIMER1
            TIMER2
 *
 */



/*
Interrupt Types(Copy_u8Intr):
			OVF_INTR
			OC_INTR

			OVF1_INTR
			OC1_A_INTR
			OC1_B_INTR
			ICU1_INTR
 *
 */


/*																								 */
/*************************************************************************************************/






/*************************************************************************************************/
/* Description: Sets Mode for Timer													             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 TIMERS_u8SetMode(u8 Copy_u8TimerIndex , u16 Copy_u8Mode) ;


/*
Timer Types(Copy_u8TimerIndex):
			TIMER0
			TIMER1
            TIMER2
 *
 */



/*
Timer0/2 Modes (Copy_u8Mode):
			MODE_NORMAL0
			MODE_PWM_PC
			MODE_CTC
			MODE_PWM_FM

 Timer1 Modes (Copy_u8Mode):
            MODE_NORMAL1
            MODE_PWM_PC_08_BIT
            MODE_PWM_PC_09_BIT
            MODE_PWM_PC_10_BIT
            MODE_PWM_PC_ICR_TRIG
            MODE_PWM_PC_OCR_TRIG

            MODE_PWM_PFC_ICR_TRIG
            MODE_PWM_PFC_OCR_TRIG

            MODE_CTC_OCR_TRIG
            MODE_CTC_ICR_TRIG

            MODE_PWM_FM_08_BIT
            MODE_PWM_FM_09_BIT
            MODE_PWM_FM_10_BIT
            MODE_PWM_FM_ICR_TRIG
            MODE_PWM_FM_OCR_TRIG
*/

/*																								 */
/*************************************************************************************************/






/*************************************************************************************************/
/* Description: Sets TCNT0 Register													             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

void TIMERS_u8SetTCNT0(u8 Copy_u8Val) ;

/*																								 */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Sets OCR0 Register													             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

void TIMERS_u8SetOCR0(u8 Copy_u8Val) ;

/*																								 */
/*************************************************************************************************/






/*************************************************************************************************/
/* Description: Sets TCNT1 Register													             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

void TIMERS_u8SetTCNT1(u16 Copy_u8Val) ;

/*																								 */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Sets OCR1-A Register												             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

void TIMERS_u8SetOCR1_A(u16 Copy_u8Val) ;

/*																								 */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Sets OCR1-B Register												             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

void TIMERS_u8SetOCR1_B(u16 Copy_u8Val) ;

/*																								 */
/*************************************************************************************************/



/*************************************************************************************************/
/* Description: Sets ICR Register													             */
/*																				            	 */
/* Inputs : void													 			                 */
/* 																								 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

void TIMERS_u8SetICR(u16 Copy_u8Val) ;

/*																								 */
/*************************************************************************************************/











#endif /* KPD_COMPONENT_KPD_INTERFACE_H_ */
