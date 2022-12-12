/*
 * DIO_Interface.h
 *
 *  Created on: Nov 20, 2022
 *      Author: user
 */

//this file includes what the user needs to use this driver for example the functions, pin names and numbers, group name

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
//-----------------------------------
#define GROUP_A 0
#define GROUP_B 1
#define GROUP_C 2
#define GROUP_D 3
//-----------------------------------
#define DIO_u8_ERROR_INIT_VAL 0
#define DIO_u8_PORT_ID_ERROR 1
#define DIO_u8_PIN_ID_ERROR 2
#define DIO_u8_PIN_VAL_ERROR 3
#define DIO_u8_PIN_DIR_ERROR 4
#define DIO_u8_PORT_VAL_ERROR 5
#define DIO_u8_PORT_DIR_ERROR 6
//-----------------------------------
#define DIO_u8_PIN_0 0
#define DIO_u8_PIN_1 1
#define DIO_u8_PIN_2 2
#define DIO_u8_PIN_3 3
#define DIO_u8_PIN_4 4
#define DIO_u8_PIN_5 5
#define DIO_u8_PIN_6 6
#define DIO_u8_PIN_7 7
//-----------------------------------
#define DIO_u8_HIGH 1
#define DIO_u8_LOW 0
//-----------------------------------
#define DIO_u8_INPUT 0
#define DIO_u8_OUTPUT 1
//-----------------------------------
#include "DIO_Private.h"
#include "DIO_Config.h"
#include "STD_Types.h"
#include "BIT_CALC.h"
//-----------------------------------
u8 DIO_u8_Set_Pin_Value(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_NO , u8 Copy_u8_Value);
u8 DIO_u8_Set_Pin_Direction(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_NO , u8 Copy_u8_Direction);
u8 DIO_u8_Set_PORT_Value(u8 Copy_u8_Port_ID, u8 Copy_u8_PORT_Value);
u8 DIO_u8_Set_PORT_Direction(u8 Copy_u8_Port_ID, u8 Copy_u8_PORT_Direction);
u8 DIO_u8_Get_Pin_Value(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_NO , u8 *Copy_u8_Value);
u8 DIO_u8_Get_PORT_Value(u8 Copy_u8_Port_ID, u8 *Copy_u8_Value);
//-----------------------------------

#endif /* DIO_INTERFACE_H_ */
