/*
 * Toggle_TwoLeds_Using_TwoInterrupts.c
 *
 *  Created on: Dec 30, 2022
 *      Author: user
 */
//-----------------------------------------------------------
#include <util/delay.h>
#include "../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
#include "../02-Hal_Layer/01-LCD_Driver/LCD_Interface.h"
#include "../02-Hal_Layer/02-Keypad_Driver/KEYPAD_Interface.h"
#include "../02-Hal_Layer/03-Stepper_Motor_Driver/STP_Interface.h"
#include "../03-MCAL_Layer/02-EXTI_Driver/EXTI_Interface.h"
#include "../03-MCAL_Layer/02-EXTI_Driver/EXTI_Private.h"
//-----------------------------------------------------------
static u8 Int0_toggler = 0b0;
static u8 Int1_toggler = 0b0;
u8 Int0_flag;
u8 Int1_flag;

void Toggle_Led_Int0()
{
	Int0_flag=0;
	DIO_u8_Set_Pin_Value(GROUP_C,DIO_u8_PIN_7,Int0_toggler^=0b1);
	_delay_ms(200);
	Int0_flag=1;
}

void Toggle_Led_Int1()
{
	Int1_flag=0;
	DIO_u8_Set_Pin_Value(GROUP_C,DIO_u8_PIN_6,Int1_toggler^=0b1);
	_delay_ms(200);
	Int1_flag=1;
}
//-----------------------------------------------------------
int main()
{
	DIO_u8_Set_PORT_Direction(GROUP_C,DIO_u8_HIGH);

	DIO_u8_Set_PORT_Direction(GROUP_D,DIO_u8_LOW);
	DIO_u8_Set_PORT_Value(GROUP_D,DIO_u8_HIGH);

	EXTI_void_GLOBAL_ENABLE_DISABLE(EXTI_u8_GLOBAL_Enable);

	EXTI_void_Set_Call_Back(EXTI_u8_INT0,Toggle_Led_Int0);
	EXTI_void_SET_Level(EXTI_u8_INT0,EXTI_u8_EXT_INT0_IOC);
	EXTI_void_Enable(EXTI_u8_INT0);

	EXTI_void_Set_Call_Back(EXTI_u8_INT1,Toggle_Led_Int1);
	EXTI_void_SET_Level(EXTI_u8_INT1,EXTI_u8_EXT_INT1_IOC);
	EXTI_void_Enable(EXTI_u8_INT1);

	while(1)
	{
		if(Int0_flag==1 || Int1_flag==1)
		{
			DIO_u8_Set_PORT_Value(GROUP_C,DIO_u8_LOW);
		}
	}

}
//------------------------------------------------------------
