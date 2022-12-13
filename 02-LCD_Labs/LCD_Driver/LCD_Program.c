/*
 * LCD_Program.c
 *
 *  Created on: Nov 25, 2022
 *      Author: user
 */
//---------------------------------------------------------
#include "../../04-STD_Libs/STD_Types.h"
#include "../../04-STD_Libs/BIT_CALC.h"
#include "../../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"
#include "LCD_Interface.h"
#include <util/delay.h>
#include <string.h>
//---------------------------------------------------------
void LCD_Void_INIT()
{
	DIO_u8_Set_PORT_Direction(LCD_u8_CTRL_PORT,0b11111111);
	DIO_u8_Set_PORT_Direction(LCD_u8_DATA_PORT,0b11111111);
	_delay_us(40);
	LCD_Void_Write_Cmd(0b00111000);
	_delay_us(50);
	LCD_Void_Write_Cmd(0b00001100);
	_delay_us(50);
	LCD_Void_Write_Cmd(0b00000001);
	_delay_ms(2);

}
//---------------------------------------------------------
void LCD_Void_Write_Cmd(u8 Copy_u8_Cmd)
{
	DIO_u8_Set_Pin_Value(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,LCD_u8_RS_Cmd);
	LCD_void_Write(Copy_u8_Cmd);
}
//---------------------------------------------------------
void LCD_Void_Write_Data(u8 Copy_u8_Data)
{
	DIO_u8_Set_Pin_Value(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,LCD_u8_RS_Data);
	LCD_void_Write(Copy_u8_Data);
}
//---------------------------------------------------------
void LCD_void_Write(u8 Copy_u8_Val)
{
	DIO_u8_Set_Pin_Value(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,LCD_u8_RW_Write);
	//DIO_u8_Set_PORT_Value(LCD_u8_DATA_PORT,Copy_u8_Val);

	DIO_u8_Set_Pin_Value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_0,Get_Bit(Copy_u8_Val,0));
	DIO_u8_Set_Pin_Value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_1,Get_Bit(Copy_u8_Val,1));
	DIO_u8_Set_Pin_Value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_2,Get_Bit(Copy_u8_Val,2));
	DIO_u8_Set_Pin_Value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_3,Get_Bit(Copy_u8_Val,3));
	DIO_u8_Set_Pin_Value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_4,Get_Bit(Copy_u8_Val,4));
	DIO_u8_Set_Pin_Value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_5,Get_Bit(Copy_u8_Val,5));
	DIO_u8_Set_Pin_Value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_6,Get_Bit(Copy_u8_Val,6));
	DIO_u8_Set_Pin_Value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_7,Get_Bit(Copy_u8_Val,7));

	DIO_u8_Set_Pin_Value(LCD_u8_CTRL_PORT,LCD_u8_Enable_PIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_u8_Set_Pin_Value(LCD_u8_CTRL_PORT,LCD_u8_Enable_PIN,DIO_u8_LOW);
}
//---------------------------------------------------------
void LCD_void_Set_DDRAM_ADD(u8 Copy_u8_DDRAM_ADD) //0b1 and concatinate 7 bits to make full 8 bits command
{
	//LCD_Void_INIT();
	LCD_Void_Write_Cmd(0b10000000 | Copy_u8_DDRAM_ADD);
}
//---------------------------------------------------------
void LCD_void_Write_String(u8 *Ptr_u8_String, u8 Copy_u8_X_Pos, u8 Copy_u8_Y_Pos)
{
	u8 LOC_u8_DDRAM_ADD = Copy_u8_X_Pos + (Copy_u8_Y_Pos*64);
	LCD_void_Set_DDRAM_ADD(LOC_u8_DDRAM_ADD);
	while(*Ptr_u8_String != '\0')
	{
		if(LOC_u8_DDRAM_ADD == 16)
		{
			LOC_u8_DDRAM_ADD = 64;
			LCD_void_Set_DDRAM_ADD(LOC_u8_DDRAM_ADD);
		}
		else if(LOC_u8_DDRAM_ADD == 80)
		{
			LOC_u8_DDRAM_ADD = 0;
			LCD_void_Set_DDRAM_ADD(LOC_u8_DDRAM_ADD);
		}
		LCD_Void_Write_Data(*Ptr_u8_String);
		Ptr_u8_String++;
		LOC_u8_DDRAM_ADD++;
	}
}
//---------------------------------------------------------
void LCD_void_Set_Co_Ordinates(u8 Copy_u8_X_Pos, u8 Copy_u8_Y_Pos)
{
	u8 LOC_u8_DDRAM_ADD = Copy_u8_X_Pos + (Copy_u8_Y_Pos*64);
	LCD_void_Set_DDRAM_ADD(LOC_u8_DDRAM_ADD);
}
//---------------------------------------------------------
void LCD_void_Set_CGRAM_ADD(u8 Copy_u8_CGRAM_ADD)
{
	LCD_Void_Write_Cmd(0b01000000 | Copy_u8_CGRAM_ADD);
}
//---------------------------------------------------------
u32  LCD_u8_Count_Num_Digits(u32 Copy_u32_Num_VAL)
{
	u8 LOC_u8_Last_Digit;
	u8 LOC_u16_Counter=0;
	while(Copy_u32_Num_VAL != 0)  //how to get all digits of a number
	{
		LOC_u8_Last_Digit = Copy_u32_Num_VAL % 10;   //Last digit
		LOC_u16_Counter++;
		Copy_u32_Num_VAL = Copy_u32_Num_VAL /10;
	}
	return LOC_u16_Counter;
}
//---------------------------------------------------------
void LCD_void_Write_Spaces(u32 Copy_u32_Num_Spaces)
{
	u32 LOC_u32_Num_Spaces;
	for(LOC_u32_Num_Spaces=0; LOC_u32_Num_Spaces<=Copy_u32_Num_Spaces ;LOC_u32_Num_Spaces++)
	{
		LCD_Void_Write_Data(' ');
	}
}
//---------------------------------------------------------
/*void LCD_void_Write_Num(u32 Copy_u32_Num_VAL,u8 Copy_u8_X_Pos, u8 Copy_u8_Y_Pos)
{
	u8 LOC_u8_Last_Digit;
	u8 LOC_u8_Last_Digit_Char[12]={};
	u8 LOC_u16_Counter=0;

	u8 LOC_u8_DDRAM_ADD = Copy_u8_X_Pos + (Copy_u8_Y_Pos*64);
	LCD_void_Set_DDRAM_ADD(LOC_u8_DDRAM_ADD);

	while(Copy_u32_Num_VAL != 0)  //how to get all digits of a number
		{
			LOC_u8_Last_Digit = Copy_u32_Num_VAL % 10;   //Last digit

			LOC_u8_Last_Digit_Char[LOC_u16_Counter]=LOC_u8_Last_Digit + '0' ;
			LOC_u16_Counter++;
			Copy_u32_Num_VAL = Copy_u32_Num_VAL /10;
		}
	for (int LOC_u16_NoOfDigits=LOC_u16_Counter;LOC_u16_NoOfDigits>=0;LOC_u16_NoOfDigits--)
	{
		LCD_Void_Write_Data( LOC_u8_Last_Digit_Char[LOC_u16_NoOfDigits]);
	}

	//LOC_u8_DDRAM_ADD++;
}*/
//--------------------------------------------------------
static void swap(u8 *PTR_u8Num1,u8 *PTR_u8Num2){
	u8 LOC_u8_Temp = *PTR_u8Num1 ;
	*PTR_u8Num1 = *PTR_u8Num2 ;
	*PTR_u8Num2 = LOC_u8_Temp ;
}
//--------------------------------------------------------
static void reverse(u8 *PTR_u8Arr,u8 Copy_u8Length){
	u8 LOC_u8Start = 0 ;
	u8 LOC_u8End   = Copy_u8Length-1;
	while(LOC_u8Start<LOC_u8End){
		swap(&PTR_u8Arr[LOC_u8Start],&PTR_u8Arr[LOC_u8End]);
		LOC_u8Start++;
		LOC_u8End--;
	}

}
//--------------------------------------------------------
void LCD_void_Write_Num(u32 Copy_u32Num,u8 Copy_u8x_Pos,u8 Copy_u8y_Pos)
{
	u8 LOC_u8Rem ;
	u8 LOC_u8ArrIndex = 0;
	u8 ARR_u8Str[11];
	if(Copy_u32Num ==0)
	{
		ARR_u8Str[LOC_u8ArrIndex] = '0';
		LOC_u8ArrIndex++;
	}
	while(Copy_u32Num !=0){
		LOC_u8Rem = Copy_u32Num%10 ;
		ARR_u8Str[LOC_u8ArrIndex] = LOC_u8Rem + '0' ;
		LOC_u8ArrIndex++;
		Copy_u32Num = Copy_u32Num/10;

	}

	ARR_u8Str[LOC_u8ArrIndex] = '\0';
	reverse(ARR_u8Str,LOC_u8ArrIndex);
	LCD_void_Write_String(ARR_u8Str,Copy_u8x_Pos,Copy_u8y_Pos);
}
//------------------------------------------------------------
