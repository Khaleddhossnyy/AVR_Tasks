/*
 * ContinousAnimation_Changed_using_Interrupt.c
 *
 *  Created on: Dec 31, 2022
 *      Author: user
 */

#include <util/delay.h>
#include "../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
#include "../02-Hal_Layer/01-LCD_Driver/LCD_Interface.h"
#include "../02-Hal_Layer/02-Keypad_Driver/KEYPAD_Interface.h"
#include "../02-Hal_Layer/03-Stepper_Motor_Driver/STP_Interface.h"
#include "../03-MCAL_Layer/02-EXTI_Driver/EXTI_Interface.h"
#include "../03-MCAL_Layer/02-EXTI_Driver/EXTI_Private.h"
//-----------------------------------------------------------
void Change_Animation()
{
	DIO_u8_Set_PORT_Value(GROUP_B,0b11111111);
	_delay_ms(150);
	DIO_u8_Set_PORT_Value(GROUP_B,0b00000000);
	_delay_ms(150);
}
//-----------------------------------------------------------
int main()
{
	DIO_u8_Set_PORT_Direction(GROUP_B,DIO_u8_HIGH);

	DIO_u8_Set_PORT_Direction(GROUP_D,DIO_u8_LOW);
	DIO_u8_Set_PORT_Value(GROUP_D,DIO_u8_HIGH);

	EXTI_void_Set_Call_Back(EXTI_u8_INT0,Change_Animation);
	EXTI_void_SET_Level(EXTI_u8_INT0,EXTI_u8_EXT_INT0_IOC);
	EXTI_void_Enable(EXTI_u8_INT0);
	EXTI_void_GLOBAL_ENABLE_DISABLE(EXTI_u8_GLOBAL_Enable);

	while(1)
	{
		for(int i =0;i<8;i++)
		{
			DIO_u8_Set_Pin_Value(GROUP_B,i,DIO_u8_HIGH);
			_delay_ms(150);
			DIO_u8_Set_Pin_Value(GROUP_B,i,DIO_u8_LOW);
			_delay_ms(150);
		}
	}

}
//------------------------------------------------------------

