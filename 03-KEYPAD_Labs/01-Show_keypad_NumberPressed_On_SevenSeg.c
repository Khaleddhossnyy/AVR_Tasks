/*
 * Show_keypad_NumberPressed_On_SevenSeg.c
 *
 *  Created on: Dec 30, 2022
 *      Author: user
 */
//--------------------------------------------------------
#include "../04-STD_Libs/BIT_CALC.h"
#include "../04-STD_Libs/STD_Types.h"
#include <util/delay.h>
#include "../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
#include "../02-Hal_Layer/01-LCD_Driver/LCD_Interface.h"
#include "../02-Hal_Layer/02-Keypad_Driver/KEYPAD_Interface.h"
//--------------------------------------------------------
#define Number_0 0b11111100  //abcdefgDOT  --> mapping of the seven segments with the code
#define Number_1 0b01100000
#define Number_2 0b11011010
#define Number_3 0b11110010
#define Number_4 0b01100110
#define Number_5 0b10110110
#define Number_6 0b10111110
#define Number_7 0b11100000
#define Number_8 0b11111110
#define Number_9 0b11110110
#define Keys_Num 9
//--------------------------------------------------------
int main()
{
	DIO_u8_Set_PORT_Direction(GROUP_B,DIO_u8_OUTPUT);
	DIO_u8_Set_PORT_Value(GROUP_B,0b00000000);

	u8 Number_Array[9]={Number_1,Number_2,Number_3,Number_4,Number_5,Number_6,Number_7,Number_8,Number_9};
	u8 Counter;

	KPD_void_INIT();
	u8 Keys_Status[Keys_Num]={};

	while(1)
	{
		KPD_void_Get_Status(Keys_Status);
		for(Counter=0; Counter<9 ;Counter++)
		{
			if(Keys_Status[Counter] == 0)
			{
				DIO_u8_Set_PORT_Value(GROUP_B,0b00000000);
				DIO_u8_Set_PORT_Value(GROUP_B,Number_Array[Counter]);
			}
		}
	}
}

