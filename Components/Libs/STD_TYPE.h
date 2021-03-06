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

/* unsigned 8 bit type */
typedef unsigned char      u8   ;

/* signed 8 bit type */
typedef signed char        s8   ;

/* unsigned 16 bit type */
typedef unsigned short int u16  ;

/* signed 16 bit type */
typedef signed short int   s16  ;

/* unsigned 32 bit type */
typedef unsigned long int  u32  ;

/* signed 32 bit type */
typedef signed long int    s32  ;

/* floating type 32 bit */
typedef float              f32  ;

/* floating type 64 bit */
typedef double             f64  ;


typedef union {

	struct{
		u32 NIB0 : 4 ;
		u32 NIB1 : 4 ;
		u32 NIB2 : 4 ;
		u32 NIB3 : 4 ;
		u32 NIB4 : 4 ;
		u32 NIB5 : 4 ;
		u32 NIB6 : 4 ;
		u32 NIB7 : 4 ;
	}NibAccess;

	struct{
		u32 BYTE0 : 8 ;
		u32 BYTE1 : 8 ;
		u32 BYTE2 : 8 ;
		u32 BYTE3 : 8 ;
	}ByteAccess;

	struct{
		u32 HEX0 : 16 ;
		u32 HEX1 : 16 ;
	}HexAccess;

	u32 RegAccess ;

}Register_32;



typedef union {

	u16 DualAccess ;

}Register_16;




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
