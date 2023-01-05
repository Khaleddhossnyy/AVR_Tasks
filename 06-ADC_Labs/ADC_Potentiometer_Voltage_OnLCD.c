/*
 * ADC_Potentiometer_Voltage_OnLCD.c
 *
 *  Created on: Jan 5, 2023
 *      Author: user
 */
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

	u16 LOC_Converted_Num=0;
	u16  Num_As_Voltage=0;

	LCD_Void_INIT();
	DIO_u8_Set_Pin_Direction(GROUP_A,DIO_u8_PIN_6,DIO_u8_OUTPUT);
	DIO_u8_Set_Pin_Value(GROUP_A,DIO_u8_PIN_6,1);

	while(1)
	{
		LOC_Converted_Num = ADC_u16_READ_Using_ADC_Interrupt(ADC_u8_Channel_0,0);
		Num_As_Voltage = (LOC_Converted_Num*5)/(1023)*(1000);
		//LCD_void_Write_String("      ",0,0);
		LCD_void_Write_Num(Num_As_Voltage,0,0);
	}

}
//-------------------------------------------------------------------


