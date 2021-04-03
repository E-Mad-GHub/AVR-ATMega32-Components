/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the Switch Component in    		    */
/* 				 high efficiency													*/
/* 				 This Driver Supports AVR ATmel32                                   */
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


#ifndef IR_COMPONENT_IR_INTERFACE_H_
#define IR_COMPONENT_IR_INTERFACE_H_



#define IR_DETECT       				  (u8)5
#define IR_NO_DETECT     		   	 	(u8)6



/*************************************   AVR  DEFINITIONS   ************************************/
/* Description : Defining Available Pins On AVR ATmel32, Which contain 32 Pins 				   */
/* Ranges from (0 -> 31) 																	   */
/*                                                                                             */
/* Example : #define IR_PIN21  													               */
/*																						       */
#define IR_PIN0    			       (u8)0
#define IR_PIN1    			       (u8)1
#define IR_PIN2    			       (u8)2
#define IR_PIN3    			       (u8)3
#define IR_PIN4    			       (u8)4
#define IR_PIN5    			       (u8)5
#define IR_PIN6    			       (u8)6
#define IR_PIN7    			       (u8)7
/*							 	   															   */
#define IR_PIN8    			       (u8)8
#define IR_PIN9    			       (u8)9
#define IR_PIN10    			   (u8)10
#define IR_PIN11    			   (u8)11
#define IR_PIN12    			   (u8)12
#define IR_PIN13    			   (u8)13
#define IR_PIN14    			   (u8)14
#define IR_PIN15    			   (u8)15
/*																							   */
#define IR_PIN16    			   (u8)16
#define IR_PIN17    			   (u8)17
#define IR_PIN18    			   (u8)18
#define IR_PIN19    			   (u8)19
#define IR_PIN20    			   (u8)20
#define IR_PIN21    			   (u8)21
#define IR_PIN22    			   (u8)22
#define IR_PIN23    			   (u8)23
/*																							   */
#define IR_PIN24    			   (u8)24
#define IR_PIN25    			   (u8)25
#define IR_PIN26    			   (u8)26
#define IR_PIN27    			   (u8)27
#define IR_PIN28    			   (u8)28
#define IR_PIN29    			   (u8)29
#define IR_PIN30    			   (u8)30
#define IR_PIN31    			   (u8)31
/*																						       */
/***********************************************************************************************/




/*************************************************************************************************/
/* Description: Write a Number on the Seven Segments 								             */
/*																				            	 */
/* Inputs : Copy_u8IRNb    -> No of the desired Switch				 			                 */
/* 			*Copy_u8State   -> The Value to be returned 										 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 IR_u8GetIRState(u8 Copy_u8IRIndex , u8 * Copy_u8IRState) ;

/*																					             */
/*************************************************************************************************/



#endif /* IR_COMPONENT_IR_INTERFACE_H_ */
