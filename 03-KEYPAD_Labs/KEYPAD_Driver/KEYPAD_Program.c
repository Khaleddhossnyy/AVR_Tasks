/*
 * 02-KEYPAD.c
 *
 *  Created on: Nov 26, 2022
 *      Author: user
 */

#include "../../04-STD_Libs/BIT_CALC.h"
#include "../../04-STD_Libs/STD_Types.h"
#include <util/delay.h>
#include "../../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
#include "KEYPAD_Config.h"
#include "KEYPAD_Interface.h"
#include "KEYPAD_Private.h"
//--------------------------------------------------------------
u8 KPD_Au8_ROWS_Pins[KPD_u8_ROWS]={KPD_u8_ROW_0_PIN,KPD_u8_ROW_1_PIN,KPD_u8_ROW_2_PIN,KPD_u8_ROW_3_PIN}; //array to save the pin values of the rows
u8 KPD_Au8_COLS_Pins[KPD_u8_COLS]={KPD_u8_COL_0_PIN,KPD_u8_COL_1_PIN,KPD_u8_COL_2_PIN,KPD_u8_COL_3_PIN}; //array to save the pin values of the columns
//--------------------------------------------------------------
void KPD_void_Get_Status(u8 *PTR_u8_KPD_Status)
{
	u8 LOC_u8_COL_Index;
	u8 LOC_u8_ROW_Index;
	u8 LOC_Key_Number;
	for(LOC_u8_COL_Index=0; LOC_u8_COL_Index < KPD_u8_COLS ; LOC_u8_COL_Index++)
	{
		DIO_u8_Set_Pin_Value(KPD_u8_COLS_PORT, KPD_Au8_COLS_Pins[LOC_u8_COL_Index],DIO_u8_LOW);//column low and row low means there's a switch pressed
		for( LOC_u8_ROW_Index=0;  LOC_u8_ROW_Index < KPD_u8_ROWS ; LOC_u8_ROW_Index++ )
		{
			LOC_Key_Number = LOC_u8_COL_Index+ LOC_u8_ROW_Index*4;
			DIO_u8_Get_Pin_Value( KPD_u8_ROWS_PORT,  KPD_Au8_ROWS_Pins[LOC_u8_ROW_Index] ,&PTR_u8_KPD_Status[LOC_Key_Number]);
		}
		DIO_u8_Set_Pin_Value(KPD_u8_COLS_PORT, KPD_Au8_COLS_Pins[LOC_u8_COL_Index],DIO_u8_HIGH);
	}
}
//----------------------------------------------------------------
void KPD_void_INIT()
{
	u8 LOC_u8_COL_Index;
	u8 LOC_u8_ROW_Index;
	for(LOC_u8_COL_Index=0; LOC_u8_COL_Index < KPD_u8_COLS ; LOC_u8_COL_Index++) //set columns as output
	{
		DIO_u8_Set_Pin_Direction(KPD_u8_COLS_PORT, KPD_Au8_COLS_Pins[LOC_u8_COL_Index],DIO_u8_OUTPUT);
	}
	for(LOC_u8_ROW_Index=0;  LOC_u8_ROW_Index < KPD_u8_ROWS ; LOC_u8_ROW_Index++)//set rows as input on built in pull up resistance
	{
		DIO_u8_Set_Pin_Direction(KPD_u8_ROWS_PORT, KPD_Au8_ROWS_Pins[LOC_u8_ROW_Index],DIO_u8_INPUT);
		DIO_u8_Set_Pin_Value(KPD_u8_ROWS_PORT, KPD_Au8_ROWS_Pins[LOC_u8_ROW_Index],DIO_u8_HIGH);
	}
}
//----------------------------------------------------------------
