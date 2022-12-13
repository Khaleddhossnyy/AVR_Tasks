/*
 * Shifting_My_Name_onLCD.c
 *
 *  Created on: Dec 13, 2022
 *      Author: user
 */

#include <util/delay.h>
#include "../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
#include "../02-Hal_Layer/01-LCD_Driver/LCD_Interface.h"
//--------------------------------------------------------


int main()
{
	LCD_Void_INIT();
	u8 My_Name[7]= {'K','h','a','l','e','d','\0'};
	LCD_Void_Write_Cmd(0b00000001); //clear the screen
	_delay_ms(500);

	while(1)
	{
		for (int i=0;i<11;i++) //shift right to left
		{
			LCD_void_Write_String(My_Name,i,0);
			_delay_ms(500);
			LCD_Void_Write_Cmd(0b00000001); //clear the screen
		}

		for (int i=9;i>0;i--) //shift left to right
		{
			LCD_void_Write_String(My_Name,i,0);
			_delay_ms(500);
			LCD_Void_Write_Cmd(0b00000001); //clear the screen
		}


	}
	return 0;
}

