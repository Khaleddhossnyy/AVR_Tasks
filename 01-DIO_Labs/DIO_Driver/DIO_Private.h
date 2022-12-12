/*
 * DIO_Private.h
 *
 *  Created on: Nov 20, 2022
 *      Author: user
 */

//this file includes data which is for the driver itself for example: addresses of the register
//4 DDR , 4 port, 4 Pin
//registers are got form the register summary in the datasheet
//register address are in hex

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

//-----------------------DDR---------------------------------------
#define DIO_u8_DDRA *((volatile u8 *)0x3A) //pointer to u8 and volatile it to not be interrupted and derefrenced to call it directly in the code,A
#define DIO_u8_DDRB *((volatile u8 *)0x37) //b
#define DIO_u8_DDRC *((volatile u8 *)0x34) //c
#define DIO_u8_DDRD *((volatile u8 *)0x31) //d
//-----------------------------------------------------------------

//-----------------------PORT--------------------------------------
#define DIO_u8_PORTA *((volatile u8 *)0x3B)//a
#define DIO_u8_PORTB *((volatile u8 *)0x38)//b
#define DIO_u8_PORTC *((volatile u8 *)0x35)//c
#define DIO_u8_PORTD *((volatile u8 *)0x32)//d
//-----------------------------------------------------------------

//-----------------------PIN---------------------------------------
#define DIO_u8_PINA *((volatile u8 *)0x39)//a
#define DIO_u8_PINB *((volatile u8 *)0x36)//b
#define DIO_u8_PINC *((volatile u8 *)0x33)//c
#define DIO_u8_PIND *((volatile u8 *)0x30)//d
//-----------------------------------------------------------------

//-------------Macros to avoid using magic numbers-----------------
#define DIO_Min_u8_PORT_ID 0
#define DIO_Max_u8_PORT_ID 3

#define DIO_Min_u8_PIN_ID 0
#define DIO_Max_u8_PIN_ID 7

#define DIO_Min_u8_PIN_VAL 0
#define DIO_Max_u8_PIN_VAL 1

#define DIO_Min_u8_PIN_DIR 0
#define DIO_Max_u8_PIN_DIR 1

#define DIO_Min_u8_PORT_VAL 0b00000000
#define DIO_Max_u8_PORT_VAL 0b11111111 //255,0xff

#define DIO_Min_u8_PORT_DIR 0b00000000
#define DIO_Max_u8_PORT_DIR 0b11111111 //255,0xff
//-----------------------------------------------------------------


#endif /* DIO_PRIVATE_H_ */
