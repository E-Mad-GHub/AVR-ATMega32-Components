/*
 * LCD_Conf.h
 *
 *  Created on: Mar 4, 2019
 *      Author: OMDA
 */

#ifndef HAL_LCD_LCD_CONF_H_
#define HAL_LCD_LCD_CONF_H_


/**** Defining the Pin Number in Numbers ****/
/*                                          */

/* GPIO A									*/
#define       ARM_PIN0        (u8)0
#define       ARM_PIN1        (u8)1
#define       ARM_PIN2        (u8)2
#define       ARM_PIN3        (u8)3
#define       ARM_PIN4        (u8)4
#define       ARM_PIN5        (u8)5
#define       ARM_PIN6        (u8)6
#define       ARM_PIN7        (u8)7
#define       ARM_PIN8        (u8)8
#define       ARM_PIN9        (u8)9
#define       ARM_PIN10       (u8)10
#define       ARM_PIN11       (u8)11
#define       ARM_PIN12       (u8)12
#define       ARM_PIN13       (u8)13
#define       ARM_PIN14       (u8)14
#define       ARM_PIN15       (u8)15

/* GPIO B									*/
#define       ARM_PIN16       (u8)16
#define       ARM_PIN17       (u8)17
#define       ARM_PIN18       (u8)18
#define       ARM_PIN19       (u8)19
#define       ARM_PIN20       (u8)20
#define       ARM_PIN21       (u8)21
#define       ARM_PIN22       (u8)22
#define       ARM_PIN23       (u8)23
#define       ARM_PIN24       (u8)24
#define       ARM_PIN25       (u8)25
#define       ARM_PIN26       (u8)26
#define       ARM_PIN27       (u8)27
#define       ARM_PIN28       (u8)28
#define       ARM_PIN29       (u8)29
#define       ARM_PIN30       (u8)30
#define       ARM_PIN31       (u8)31

/* GPIO C									*/
#define       ARM_PIN32       (u8)32
#define       ARM_PIN33       (u8)33
#define       ARM_PIN34       (u8)34

/* GPIO D									*/
#define       ARM_PIN35       (u8)35
#define       ARM_PIN36       (u8)36

/*                                          */
/********************************************/




#define LCD_RS				ARM_PIN9
#define LCD_RW				ARM_PIN10
#define LCD_ENABLE			ARM_PIN11


#define LCD_D0				ARM_PIN0
#define LCD_D1              ARM_PIN1
#define LCD_D2              ARM_PIN2
#define LCD_D3              ARM_PIN3

#define LCD_D4              ARM_PIN4
#define LCD_D5              ARM_PIN5
#define LCD_D6              ARM_PIN6
#define LCD_D7              ARM_PIN7

#define LCD_BACKLIGHT_GND   ARM_PIN8





#endif /* HAL_LCD_LCD_CONF_H_ */
