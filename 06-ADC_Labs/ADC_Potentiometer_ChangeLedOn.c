/*
 * ADC_Potentiometer_ChangeLedOn.c
 *
 *  Created on: Jan 5, 2023
 *      Author: user
 */
//--------------------------------------------------------------------
#include <util/delay.h>
#include "../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
#include "../02-Hal_Layer/01-LCD_Driver/LCD_Interface.h"
#include "../02-Hal_Layer/02-Keypad_Driver/KEYPAD_Interface.h"
#include "../02-Hal_Layer/03-Stepper_Motor_Driver/STP_Interface.h"
#include "../03-MCAL_Layer/02-EXTI_Driver/EXTI_Interface.h"
#include "../03-MCAL_lAyer/03-ADC_Driver/ADC_Interface.h"
//--------------------------------------------------------------------
int main()
{
	ADC_void_INIT_Using_AutoTrigger(); //to use free running mode
	DIO_u8_Set_Pin_Direction(GROUP_C,DIO_u8_PIN_0,DIO_u8_OUTPUT);
	DIO_u8_Set_Pin_Direction(GROUP_C,DIO_u8_PIN_1,DIO_u8_OUTPUT);
	DIO_u8_Set_Pin_Direction(GROUP_C,DIO_u8_PIN_2,DIO_u8_OUTPUT);
	DIO_u8_Set_Pin_Direction(GROUP_A,DIO_u8_PIN_0,DIO_u8_LOW);

	u16 LOC_Converted_Num=0;
	u8  Num_As_Voltage=0;
	while(1)
	{
		LOC_Converted_Num = ADC_u16_READ_Using_ADC_Interrupt(ADC_u8_Channel_0,0);
		Num_As_Voltage = (LOC_Converted_Num*5)/(1023);

		if( (Num_As_Voltage>0) && (Num_As_Voltage<1.5))
		{
			DIO_u8_Set_Pin_Value(GROUP_C,DIO_u8_PIN_1,0);
			DIO_u8_Set_Pin_Value(GROUP_C,DIO_u8_PIN_2,0);
			DIO_u8_Set_Pin_Value(GROUP_C,DIO_u8_PIN_0,1);
		}
		else if((Num_As_Voltage>1.5) && (Num_As_Voltage<3))
		{
			DIO_u8_Set_Pin_Value(GROUP_C,DIO_u8_PIN_0,0);
			DIO_u8_Set_Pin_Value(GROUP_C,DIO_u8_PIN_2,0);
			DIO_u8_Set_Pin_Value(GROUP_C,DIO_u8_PIN_1,1);
		}
		else if(Num_As_Voltage>3)
		{
			DIO_u8_Set_Pin_Value(GROUP_C,DIO_u8_PIN_1,0);
			DIO_u8_Set_Pin_Value(GROUP_C,DIO_u8_PIN_2,1);
		}

	}

}
//-------------------------------------------------------------------
