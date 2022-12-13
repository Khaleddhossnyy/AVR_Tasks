/*
 * Writing_My_Name_onLCD.c
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
	u8 My_Name[18]= {'K','h','a','l','e','d',' ',' ',' ','M','o','h','a','m','e','d',' ','\0'};

	while(1)
	{
		LCD_void_Write_String(My_Name,0,0);
	}
	return 0;
}
