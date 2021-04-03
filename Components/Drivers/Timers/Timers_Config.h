/************************************************************************************/
/* Description : This is a Configuration file that contains the Allowed Customizati-*/
/*               ons for Timers Component 		                                    */
/*               allowed only for Application Engineers 							*/
/*																					*/
/* Created on  : April 12, 2019														*/
/* Author      : OMDA																*/
/************************************************************************************/





#ifndef KPD_COMPONENT_SSEG_CONFIG_H_
#define KPD_COMPONENT_SSEG_CONFIG_H_







/* Define modes of Timers ***********************************/
/*															*/

/* choose modes of timers									*/

/* Timer0 Settings											*/
#define TIMER0_MODE				MODE_NORMAL0
#define TIMER0_OC0_PIN_MODE		OC0_NON_INV

#define TIMER0_OVF_INTR			INTR_ENABLED
#define TIMER0_OC_INTR			INTR_ENABLED

#define TIMER0_PRESCALER		PRE_CLK_OVER_01

/* Timer1 Settings											*/
#define TIMER1_MODE				MODE_NORMAL1

#define TIMER1_OVF_INTR			INTR_ENABLED
#define TIMER1_OC1_INTR			INTR_ENABLED
#define TIMER1_OC2_INTR			INTR_DISABLED
#define TIMER1_ICU_INTR			INTR_ENABLED

#define TIMER1_PRESCALER		PRE_CLK_OVER_08



/* Timer2 Settings											*/
#define TIMER2_MODE				MODE_NORMAL0
#define TIMER0_OC2_PIN_MODE		OC0_NON_INV

#define TIMER2_OVF_INTR			INTR_ENABLED
#define TIMER2_OC_INTR			INTR_ENABLED

#define TIMER2_PRESCALER		PRE_CLK_OVER_08

/*															*/
/************************************************************/







#endif /* SSEG_COMPONENT_SSEG_CONFIG_H_ */
