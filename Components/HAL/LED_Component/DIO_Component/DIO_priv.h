/************************************************************************************/
/* Description : This is an Private file that contains the private definitions and  */
/*               functions implementations needed to use the DIO Component  	    */
/* 				 in high efficiency													*/
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/

/* File Guard                       */
#ifndef DIO_COMPONENT_DIO_PRIV_H_
#define DIO_COMPONENT_DIO_PRIV_H_



/********* Hardware Dependencies *********/
/*									     */

#define LOCAL_NB_OF_PINS_IN_PORT   8

#define LOCAL_DIO_MAXPINNB         31
#define LOCAL_DIO_PORT_MAXPINNB    3

#define LOCAL_DDRA_REG             0x3A
#define LOCAL_PORTA_REG            0x3B
#define LOCAL_PINA_REG			   0x39

#define LOCAL_DDRB_REG             0x37
#define LOCAL_PORTB_REG            0x38
#define LOCAL_PINB_REG			   0x36

#define LOCAL_DDRC_REG             0x34
#define LOCAL_PORTC_REG            0x35
#define LOCAL_PINC_REG			   0x33

#define LOCAL_DDRD_REG             0x31
#define LOCAL_PORTD_REG            0x32
#define LOCAL_PIND_REG			   0x30

#define LOCAL_PORTA_CHOICE	       0
#define LOCAL_PORTB_CHOICE	       1
#define LOCAL_PORTC_CHOICE	       2
#define LOCAL_PORTD_CHOICE	       3

/*									     */
/*****************************************/


/********* Shift Function ****************/
/*									     */

#define PRIVATE_SHIFT_ONE(X)    (X<<(1))
#define PRIVATE_SHIFT_TWO(X)    (X<<(2))
#define PRIVATE_SHIFT_THREE(X)  (X<<(3))
#define PRIVATE_SHIFT_FOUR(X)   (X<<(4))
#define PRIVATE_SHIFT_FIVE(X)   (X<<(5))
#define PRIVATE_SHIFT_SIX(X)    (X<<(6))
#define PRIVATE_SHIFT_SEVEN(X)  (X<<(7))

/*									     */
/*****************************************/


/******** Byte Preparation *********************************************************************************************************************************************************************************************************************************************************/
/*																																														                                                                                           */

#define PRIVATE_DIO_BYTE_CONCATENATE(VAR7,VAR6,VAR5,VAR4,VAR3,VAR2,VAR1,VAR0)   PRIVATE_SHIFT_SEVEN(VAR7) | PRIVATE_SHIFT_SIX(VAR6) | PRIVATE_SHIFT_FIVE(VAR5) | PRIVATE_SHIFT_FOUR(VAR4) | PRIVATE_SHIFT_THREE(VAR3) | PRIVATE_SHIFT_TWO(VAR2) | PRIVATE_SHIFT_ONE(VAR1) | VAR0

/*																																														                                                                                           */
/***********************************************************************************************************************************************************************************************************************************************************************************/



/****** Ports and Values Initial *************************************************************************************************************************************************************************************************/
/*																																																			            	     */

#define DIO_PORTA_INIT_DIRECTION  PRIVATE_DIO_BYTE_CONCATENATE(DIO_PIN7_DIRECTION,DIO_PIN6_DIRECTION,DIO_PIN5_DIRECTION,DIO_PIN4_DIRECTION,DIO_PIN3_DIRECTION,DIO_PIN2_DIRECTION,DIO_PIN1_DIRECTION,DIO_PIN0_DIRECTION)
#define DIO_PORTB_INIT_DIRECTION  PRIVATE_DIO_BYTE_CONCATENATE(DIO_PIN15_DIRECTION,DIO_PIN14_DIRECTION,DIO_PIN13_DIRECTION,DIO_PIN12_DIRECTION,DIO_PIN11_DIRECTION,DIO_PIN10_DIRECTION,DIO_PIN9_DIRECTION,DIO_PIN8_DIRECTION)
#define DIO_PORTC_INIT_DIRECTION  PRIVATE_DIO_BYTE_CONCATENATE(DIO_PIN23_DIRECTION,DIO_PIN22_DIRECTION,DIO_PIN21_DIRECTION,DIO_PIN20_DIRECTION,DIO_PIN19_DIRECTION,DIO_PIN18_DIRECTION,DIO_PIN17_DIRECTION,DIO_PIN16_DIRECTION)
#define DIO_PORTD_INIT_DIRECTION  PRIVATE_DIO_BYTE_CONCATENATE(DIO_PIN31_DIRECTION,DIO_PIN30_DIRECTION,DIO_PIN29_DIRECTION,DIO_PIN28_DIRECTION,DIO_PIN27_DIRECTION,DIO_PIN26_DIRECTION,DIO_PIN25_DIRECTION,DIO_PIN24_DIRECTION)

#define DIO_PORTA_INIT_VAL        PRIVATE_DIO_BYTE_CONCATENATE(DIO_PIN7_INIT_VAL,DIO_PIN6_INIT_VAL,DIO_PIN5_INIT_VAL,DIO_PIN4_INIT_VAL,DIO_PIN3_INIT_VAL,DIO_PIN2_INIT_VAL,DIO_PIN1_INIT_VAL,DIO_PIN0_INIT_VAL)
#define DIO_PORTB_INIT_VAL        PRIVATE_DIO_BYTE_CONCATENATE(DIO_PIN15_INIT_VAL,DIO_PIN14_INIT_VAL,DIO_PIN13_INIT_VAL,DIO_PIN12_INIT_VAL,DIO_PIN11_INIT_VAL,DIO_PIN10_INIT_VAL,DIO_PIN9_INIT_VAL,DIO_PIN8_INIT_VAL)
#define DIO_PORTC_INIT_VAL        PRIVATE_DIO_BYTE_CONCATENATE(DIO_PIN23_INIT_VAL,DIO_PIN22_INIT_VAL,DIO_PIN21_INIT_VAL,DIO_PIN20_INIT_VAL,DIO_PIN19_INIT_VAL,DIO_PIN18_INIT_VAL,DIO_PIN17_INIT_VAL,DIO_PIN16_INIT_VAL)
#define DIO_PORTD_INIT_VAL        PRIVATE_DIO_BYTE_CONCATENATE(DIO_PIN31_INIT_VAL,DIO_PIN30_INIT_VAL,DIO_PIN29_INIT_VAL,DIO_PIN28_INIT_VAL,DIO_PIN27_INIT_VAL,DIO_PIN26_INIT_VAL,DIO_PIN25_INIT_VAL,DIO_PIN24_INIT_VAL)

/*																																																			             	     */
/*********************************************************************************************************************************************************************************************************************************/




#endif /* DIO_COMPONENT_DIO_PRIV_H_ */
