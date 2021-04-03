

/*************************************************************************************************/
/*																																															 */
/* THIS IS A HEADER FILE FOR SETTING BITS NUMBERED AS (No) IN A VARIABLE (X), THIS IS TO BE USED */
/* ________________________DURING ALL THE 9 MONTHS COURSE AND AFTER_____________________________ */
/* 																																															 */
/*************************************************************************************************/


/* HEADER FILE GUARD NAMED AS "BIT_CALC_ME" */
#ifndef BIT_CALC_ME
#define BIT_CALC_ME
/********************************************/



/*************************************************************************************************/
/*																			                     */
/* _________________________________BIT CHANGERS MACROS_________________________________________ */
/*                                                                                               */

/* CHANGING BIT NUMBER (No) IN VARIABLE (X) TO 1   												 */
#define   SET_BIT(X,No)           		X|=(1<<(No))


/* CHANGING BIT NUMBER (No) IN VARIABLE (X) TO 0                                                 */
#define   CLR_BIT(X,No)           		X&=(~(1<<(No)))

/* TOGGLING BIT NUMBER (No) IN VARIABLE (X) TO 1   										         */
#define   TOGGLE_BIT(X,No)         		X^=(1<<(No))

/* ASSIGN BIT NUMBER (No) IN VARIABLE (X) TO (VAL) 									             */
#define   ASSIGN_BIT(X,No,Val) 	   		X= (X&(~(1<<(No)))) | (((Val)==1)?(1<<(No)):(0<<(No)))

/* ASSIGN BYTE VALUE   */
#define   SET_BYTE(X) 	   				X= (0xff)
#define   CLR_BYTE(X) 	   				X= (0x00)


/*************************************************************************************************/


/* RETURNS BIT NUMBER (No) IN VARIABLE (X)                                                       */
#define   GET_BIT(X,No)            	   			((X >> (No)) & 1)

/* CHANGING HIGH NIBBLE IN VARIABLE (X) TO 1s 													 */
#define   SET_HIGH_NIBB(X)         	   			X|=(0xF0)

/* CHANGING LOW NIBBLE IN VARIABLE (X) TO 1s 													 */
#define   SET_LOW_NIBB(X)          	   			X|=(0x0F)

/* CHANGING HIGH NIBBLE IN VARIABLE (X) TO 0s 													 */
#define   CLR_HIGH_NIBB(X)         	   			X&=(0x0F)

/* CHANGING LOW NIBBLE IN VARIABLE (X) TO 0s 													 */
#define   CLR_LOW_NIBB(X)          	   			X&=(0xF0)

/* TOGGLING HIGH NIBBLE IN VARIABLE (X) 													     */
#define   TOGGLE_HIGH_NIBB(X)      	   			X^=(0xF0)

/* TOGGLING LOW NIBBLE IN VARIABLE (X) 												  	         */
#define   TOGGLE_LOW_NIBB(X)       	   			X^=(0x0F)

/* CIRCULAR SHIFT VARIABLE (X) NUMBER (No) OF BITS												 */
#define   CIRC_SHIFT_RIGHT(X,No)       			X=((X>>(No))|(x<<((8*sizeof(x))-No)))


/*														   									     */
/*																								 */
/*************************************************************************************************/


/**************************************************************************************************************************/
/*						                            	Nibble Assign			        		                          */

#define 	BIT_CAST(b0)			    				CNVRT_HELPER(b0)
#define 	CNVRT_HELPER(b0)							0b##b0

//#define  	ASSIGN_NIBBLE( NN , VAL , REG )				REG=( (REG & (~(0xF << (NN*4)))) | ( BIT_CAST(VAL) << (NN*4) ) )

#define  	ASSIGN_NIBBLE( NN , VAL , REG )				(REG)=(u32)( ( (REG) & (u32)(~( (0b1111) << (NN*4) )) ) | ((u32)( (VAL) << (NN*4) ) ))

/*																														  */
/**************************************************************************************************************************/





/*************************************************************************************************/
/*						            	Byte Concatenation										 */
#define BYTE_CONC(b7,b6,b5,b4,b3,b2,b1,b0)				BYTE_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define BYTE_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)			0b##b7##b6##b5##b4##b3##b2##b1##b0
/*																								 */
/*************************************************************************************************/



/*   END OF FILE GUARD   */
#endif
/*************************/
