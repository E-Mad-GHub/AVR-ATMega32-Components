/*
 * STD_TYPE.h
 *
 *  Created on: Jan 29, 2019
 *      Author: OMDA
 */

#ifndef STD_TYPE_H_
#define STD_TYPE_H_

#define NULL ((void *)0)

/************* Errors ***************/
/*									*/
#define ERROR_NOK 1
#define ERROR_OK  0
/*									*/
/************************************/


typedef unsigned char u8 ;

typedef union {

	struct{
		u8 Bit0 : 1 ;
		u8 Bit1 : 1 ;
		u8 Bit2 : 1 ;
		u8 Bit3 : 1 ;
		u8 Bit4 : 1 ;
		u8 Bit5 : 1 ;
		u8 Bit6 : 1 ;
		u8 Bit7 : 1 ;
	}BitAccess;

	u8 ByteAccess ;

}Register;




#endif /* STD_TYPE_H_ */
