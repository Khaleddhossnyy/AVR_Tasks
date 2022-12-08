/*
 * DC_Motor_H_Bridge.c
 *
 *  Created on: Dec 6, 2022
 *      Author: user
 */
#include <util/delay.h>
#include "../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
#include "../02-Hal_Layer/01-LCD_Driver/LCD_Interface.h"
#include "../02-Hal_Layer/02-Keypad_Driver/KEYPAD_Interface.h"
#include "../02-Hal_Layer/03-Stepper_Motor_Driver/STP_Interface.h"
#include "../03-MCAL_Layer/02-EXTI_Driver/EXTI_Interface.h"


void MOVE_CW()
{
	DIO_u8_Set_Pin_Value(GROUP_A,DIO_u8_PIN_0,DIO_u8_HIGH);
	_delay_ms(500);
	DIO_u8_Set_Pin_Value(GROUP_A,DIO_u8_PIN_1,DIO_u8_LOW);
	_delay_ms(500);
}

void MOVE_ACW()
{
	DIO_u8_Set_Pin_Value(GROUP_A,DIO_u8_PIN_0,DIO_u8_LOW);
	_delay_ms(500);
	DIO_u8_Set_Pin_Value(GROUP_A,DIO_u8_PIN_1,DIO_u8_HIGH);
	_delay_ms(500);
}

void STOP()
{
	DIO_u8_Set_Pin_Value(GROUP_A,DIO_u8_PIN_0,DIO_u8_LOW);
	_delay_ms(500);
	DIO_u8_Set_Pin_Value(GROUP_A,DIO_u8_PIN_1,DIO_u8_LOW);
	_delay_ms(500);
}


int main()
{
	DIO_u8_Set_Pin_Direction(GROUP_D,DIO_u8_PIN_0,DIO_u8_INPUT);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_0,DIO_u8_HIGH);

	DIO_u8_Set_Pin_Direction(GROUP_D,DIO_u8_PIN_7,DIO_u8_INPUT);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_7,DIO_u8_HIGH);

	DIO_u8_Set_Pin_Direction(GROUP_D,DIO_u8_PIN_6,DIO_u8_INPUT);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_6,DIO_u8_HIGH);

	DIO_u8_Set_Pin_Direction(GROUP_A,DIO_u8_PIN_0,DIO_u8_OUTPUT);
	DIO_u8_Set_Pin_Direction(GROUP_A,DIO_u8_PIN_1,DIO_u8_OUTPUT);

	u8 Pointer_SW1;
	u8 Pointer_SW2;
	u8 Pointer_SW3;
	while(1)
	{
		DIO_u8_Get_Pin_Value(GROUP_D,DIO_u8_PIN_0,&Pointer_SW1);
		DIO_u8_Get_Pin_Value(GROUP_D,DIO_u8_PIN_7,&Pointer_SW2);
		DIO_u8_Get_Pin_Value(GROUP_D,DIO_u8_PIN_6,&Pointer_SW3);

		if (Pointer_SW1 == DIO_u8_LOW)//move clock wise (A0->0, A1->1)
		{
			MOVE_CW();
		}

		else if(Pointer_SW2 == DIO_u8_LOW) //move anti clock wise
		{
			MOVE_ACW();
		}

		else if(Pointer_SW3 == DIO_u8_LOW)//stop
		{
			STOP();
		}
	}
}
