/************************************************************************************/
/* Description : This is a Private file that contains the private definitions and   */
/*               Private functions needed to use the ADC Component 		 	        */
/* 				 This Driver Supports AVR ATmel32                                   */
/*																					*/
/* Created on  : April 16, 2019 													*/
/* Author      : OMDA																*/
/************************************************************************************/



/* File Guard  			*/
#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_





/********* Hardware Dependencies ************/
/*									        */

/* Defining SREG Register ADDRESS           */
#define LOCAL_ADMUX 				0x27
#define LOCAL_ADCSRA				0x26
#define LOCAL_SFIOR					0x50
#define LOCAL_ADCH					0x25
#define LOCAL_ADCL					0x24


/* Defining Masks				           */
#define LOCAL_REF_MASK  			0x3F
#define LOCAL_PRES_MASK				0xF8
#define LOCAL_ADJS_MASK				0xDF
#define LOCAL_STATUS_MASK			0x7F
#define LOCAL_CHANNEL_MASK			0xE0
#define LOCAL_START					0x40
#define LOCAL_CONV_FLAG				0x10
#define LOCAL_INTR_MASK				0xF7
#define LOCAL_INTR_ENABLE			0x08



/*									        */
/********************************************/



#endif /* EXTINT_COMPONENT_EXTINT_PRIV_H_ */
