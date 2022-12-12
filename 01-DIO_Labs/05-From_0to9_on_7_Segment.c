/*
 * From_1to9_on_7_Segment.c
 *
 *  Created on: Dec 12, 2022
 *      Author: user
 */

#include <util/delay.h>
#include "../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
//-----------------------------------------------------------------
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
//-----------------------------------------------------------------
//-----------------------------------------------------------------
int main()
{
	    DIO_u8_Set_PORT_Direction(GROUP_A,0b11111111); //make port A direction as output
		while(1)
		{
			u8 Number_Array[10]={Number_0,Number_1,Number_2,Number_3,Number_4,Number_5,Number_6,Number_7,Number_8,Number_9};
			//DIO_u8_Set_PORT_Value(GROUP_A,0b11111111);
			for (u8 i=0 ;i<10; i++)
			{
				DIO_u8_Set_PORT_Value(GROUP_A,Number_Array[i]);
				_delay_ms(1000);
			}
		}
	return 0;
}
