


#include "delay_milli_Interface.h"
#include "delay_milli_priv.h"



void delay_milliSecond(u32 value){



/**************************  OPERATIONS  ****************************/
/*																    */

	value = (u32)value*Milli2Micro;

	value = (u32)(value - InContext - OutContext - OperationsDelay) ;

	value = (u32)(value / MIC2MILL) ;



/*																	*/
/********************************************************************/


/****************************** LOOP ********************************/
/*																	*/


	for (u32 ii = 0 ; ii < (u32)value ; ii++){

		/* One milli Second loop 									*/
		for (u16 i = 0 ; i < (u16)MAX_TO_1m ; i++){

			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");

		}

	}

}


