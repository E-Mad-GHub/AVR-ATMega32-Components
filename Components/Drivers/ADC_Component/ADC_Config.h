/************************************************************************************/
/* Description : This is a Configuration file that contains the Allowed Customizati-*/
/*               ons for ADC Component    			                               */
/*               allowed only for Application Engineers 							*/
/*																					*/
/* Created on  : April 16, 2019 													*/
/* Author      : OMDA																*/
/************************************************************************************/





#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_





/* Define GIE (Global Interrupt Enable) INITIAL STATE *******/
/*										 					*/

#define INIT_STATE				ADC_ENABLED
#define ADC_REF_VOLTAGE			REF_2_5
#define ADC_PRESCALER			PRE_OVER_2
#define ADC_ADJUSTMENT			ADJ_RIGHT

#define ADC_CHANNEL				ADC_CH0








/* For Chain of Converters 				*/
#define CHANNEL_NB				3

u8 Ch_Chosen[CHANNEL_NB] = {
							ADC_CH0,
							ADC_CH1,
							ADC_CH2,
/*							ADC_CH3,
							ADC_CH4,
							ADC_CH5,
							ADC_CH6,
							ADC_CH7
*/							} ;

/****************************************/




/*															*/
/************************************************************/








#endif /* SSEG_COMPONENT_SSEG_CONFIG_H_ */
