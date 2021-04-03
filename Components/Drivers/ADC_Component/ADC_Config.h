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


#define ADC_DEF_CHANNEL			ADC_CH0

#define DEF_CHANNEL_TRIGGER		TRIGG_TYPE_HW

#define HW_TRIGGER_CONFIG		HW_TRIG_FREE_RUN






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









/* New Way	****************************************************************************/




#define NB_OF_GROUPS			3

GROUP grps[NB_OF_GROUPS] = {

									/* Group 0	-> Group Index = 0						*/
									{ 3 ,                /* Number of Channels in Group */
									TRIGG_TYPE_HW ,		 /* Triggering Type for Group	*/
									(u8  []){			 /* Channels Exist in the Group */
											ADC_CH0,
											ADC_CH2,
											ADC_CH1
											}
									},

									/* Group 1	-> Group Index = 1						*/
					     			{ 3 ,                /* Number of Channels in Group */
					     			TRIGG_TYPE_SW ,		 /* Triggering Type for Group	*/
					     			(u8  []){			 /* Channels Exist in the Group */
					     					ADC_CH3,
											ADC_CH4,
											ADC_CH5
					     					}
					     			},

} ;

/****************************************************************************************/













#endif /* SSEG_COMPONENT_SSEG_CONFIG_H_ */
