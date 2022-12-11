/*
 * Turn_on_LED_A0.c
 *
 *  Created on: Dec 12, 2022
 *      Author: user
 */

//-------------------------------------------

#include <util/delay.h>
#include "../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
//--------------------------------------------------------------



int main()
{
	DIO_u8_Set_Pin_Direction(GROUP_A,DIO_u8_PIN_0,DIO_u8_HIGH); //set A0 to output

	while(1)
	{
		DIO_u8_Set_Pin_Value(GROUP_A,DIO_u8_PIN_0,DIO_u8_HIGH);
	}

	return 0;
}

