/*
 * Sinusoidal_Name_onLCD.c
 *
 *  Created on: Dec 13, 2022
 *      Author: user
 */

#include <util/delay.h>
#include "../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
#include "../02-Hal_Layer/01-LCD_Driver/LCD_Interface.h"
//---------------------------------------------------------------

int main()
{
	LCD_Void_INIT();
	LCD_Void_Write_Cmd(0b00000001); //clear the screen

	while(1)
	{
		LCD_void_Set_Co_Ordinates(0,0);
		LCD_Void_Write_Data('K'); //k
		_delay_ms(300);
		LCD_void_Set_Co_Ordinates(1,1);
		LCD_Void_Write_Data('h');  //h
		_delay_ms(300);
		LCD_void_Set_Co_Ordinates(2,0);
		LCD_Void_Write_Data('a');  //a
		_delay_ms(300);
		LCD_void_Set_Co_Ordinates(3,1);
		LCD_Void_Write_Data('l');  //l
		_delay_ms(300);
		LCD_void_Set_Co_Ordinates(4,0);
		LCD_Void_Write_Data('e');  //e
		_delay_ms(300);
		LCD_void_Set_Co_Ordinates(5,1);
		LCD_Void_Write_Data('d'); //d
		_delay_ms(300);

		LCD_void_Set_Co_Ordinates(7,0);
		LCD_Void_Write_Data('M'); //M
		_delay_ms(300);
		LCD_void_Set_Co_Ordinates(8,1);
		LCD_Void_Write_Data('o'); //O
		_delay_ms(300);
		LCD_void_Set_Co_Ordinates(9,0);
		LCD_Void_Write_Data('h'); //h
		_delay_ms(300);
		LCD_void_Set_Co_Ordinates(10,1);
		LCD_Void_Write_Data('a'); //a
		_delay_ms(300);
		LCD_void_Set_Co_Ordinates(11,0);
		LCD_Void_Write_Data('m'); //m
		_delay_ms(300);
		LCD_void_Set_Co_Ordinates(12,1);
		LCD_Void_Write_Data('e'); //e
		_delay_ms(300);
		LCD_void_Set_Co_Ordinates(13,0);
		LCD_Void_Write_Data('d'); //d
		_delay_ms(300);
		LCD_Void_Write_Cmd(0b00000001); //clear the screen
	}

	return 0;
}
