/*
 * Traffic_System.c
 *
 *  Created on: Dec 12, 2022
 *      Author: user
 */

//-------------------------------------------------
#include <util/delay.h>
#include "../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
//-------------------------------------------------
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
//-------------------------------------------------

int main()
{
	DIO_u8_Set_PORT_Direction(GROUP_A,0b11111111);
	DIO_u8_Set_PORT_Direction(GROUP_C,0b11111111);
	DIO_u8_Set_PORT_Direction(GROUP_B,0b11111111);

	int Number_Array[10]={Number_0,Number_1,Number_2,Number_3,Number_4,Number_5,Number_6,Number_7,Number_8,Number_9};

	while(1)
	{
		DIO_u8_Set_PORT_Value(GROUP_A,Number_0);
		DIO_u8_Set_PORT_Value(GROUP_C,Number_0);

		DIO_u8_Set_Pin_Value(GROUP_B,DIO_u8_PIN_5,DIO_u8_HIGH); //green led high
		for (int i=1;i<2;i++)
		{
			for (int j =0;j<10;j++)
			{
				DIO_u8_Set_PORT_Value(GROUP_A,Number_Array[j]);
				_delay_ms(1000);
				if (j == 9)
				{
					DIO_u8_Set_PORT_Value(GROUP_A,Number_Array[j]);
					_delay_ms(1000);
					DIO_u8_Set_PORT_Value(GROUP_A,Number_0);
				}
			}
			DIO_u8_Set_PORT_Value(GROUP_C,Number_Array[i]);
			_delay_ms(1000);
			DIO_u8_Set_PORT_Value(GROUP_C,Number_0);
		}
		DIO_u8_Set_Pin_Value(GROUP_B,DIO_u8_PIN_5,DIO_u8_LOW); //green light off
		//_delay_ms(500);



		DIO_u8_Set_Pin_Value(GROUP_B,DIO_u8_PIN_6,DIO_u8_HIGH); //yellow led high
		for (int i=1;i<=3;i++)
		{
			DIO_u8_Set_PORT_Value(GROUP_A,Number_Array[i]);
			_delay_ms(1000);
		}
		DIO_u8_Set_PORT_Value(GROUP_A,Number_0);
		DIO_u8_Set_Pin_Value(GROUP_B,DIO_u8_PIN_6,DIO_u8_LOW); //yellow led off
		//_delay_ms(500);


		DIO_u8_Set_Pin_Value(GROUP_B,DIO_u8_PIN_7,DIO_u8_HIGH); //red led high
		for (int i=1;i<2;i++)
		{
			for (int j =0;j<10;j++)
			{
				DIO_u8_Set_PORT_Value(GROUP_A,Number_Array[j]);
				_delay_ms(1000);
				if (j == 9)
				{
					DIO_u8_Set_PORT_Value(GROUP_A,Number_Array[j]);
					_delay_ms(1000);
					DIO_u8_Set_PORT_Value(GROUP_A,Number_0);
				}
			}
			DIO_u8_Set_PORT_Value(GROUP_C,Number_Array[i]);
			_delay_ms(1000);
			DIO_u8_Set_PORT_Value(GROUP_C,Number_0);
		}
		DIO_u8_Set_Pin_Value(GROUP_B,DIO_u8_PIN_7,DIO_u8_LOW); //red light off
		//_delay_ms(500);

	}
		return 0;
}
