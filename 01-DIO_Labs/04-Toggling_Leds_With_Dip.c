#include <util/delay.h>
#include "../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
#include "../02-Hal_Layer/01-LCD_Driver/LCD_Interface.h"
#include "../02-Hal_Layer/02-Keypad_Driver/KEYPAD_Interface.h"
#include "../02-Hal_Layer/03-Stepper_Motor_Driver/STP_Interface.h"
#include "../03-MCAL_Layer/02-EXTI_Driver/EXTI_Interface.h"
//-----------------------------------------------------------
void All_Flashing()
{
	DIO_u8_Set_PORT_Value(GROUP_D,0b11111111);
	_delay_ms(500);
	DIO_u8_Set_PORT_Value(GROUP_D,0b00000000);
	_delay_ms(500);
}

void Shift_Left()
{
	for(int i =0;i<8;i++)
	{
		DIO_u8_Set_Pin_Value(GROUP_D,i,DIO_u8_HIGH);
		_delay_ms(250);
		DIO_u8_Set_Pin_Value(GROUP_D,i,DIO_u8_LOW);
		_delay_ms(250);
	}
}

void Shift_Right()
{
	for(int i =7;i>=0;i--)
	{
		DIO_u8_Set_Pin_Value(GROUP_D,i,DIO_u8_HIGH);
		_delay_ms(250);
		DIO_u8_Set_Pin_Value(GROUP_D,i,DIO_u8_LOW);
		_delay_ms(250);
	}
}

void Converge()
{

	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_0,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_1,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_2,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_3,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_4,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_5,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_6,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_7,DIO_u8_HIGH);
	_delay_ms(300);
	//DIO_u8_Set_PORT_Value(GROUP_D,0b11000011); _delay_ms(300);

	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_0,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_1,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_2,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_3,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_4,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_5,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_6,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_7,DIO_u8_LOW);
	_delay_ms(300);
	//DIO_u8_Set_PORT_Value(GROUP_D,0b01100110); _delay_ms(300);

	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_0,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_1,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_2,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_3,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_4,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_5,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_6,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_7,DIO_u8_LOW);
	_delay_ms(300);
	//DIO_u8_Set_PORT_Value(GROUP_D,0b00111100); _delay_ms(300);

	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_0,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_1,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_2,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_3,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_4,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_5,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_6,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_7,DIO_u8_LOW);
	_delay_ms(300);
	//DIO_u8_Set_PORT_Value(GROUP_D,0b00011000);
}

void Diverge()
{
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_0,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_1,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_2,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_3,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_4,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_5,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_6,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_7,DIO_u8_LOW);
	_delay_ms(300);
	//DIO_u8_Set_PORT_Value(GROUP_D,0b00011000); _delay_ms(300);

	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_0,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_1,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_2,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_3,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_4,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_5,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_6,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_7,DIO_u8_LOW);
	_delay_ms(300);
	//DIO_u8_Set_PORT_Value(GROUP_D,0b00111100); _delay_ms(300);

	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_0,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_1,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_2,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_3,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_4,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_5,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_6,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_7,DIO_u8_LOW);
	_delay_ms(300);
	//DIO_u8_Set_PORT_Value(GROUP_D,0b01100110); _delay_ms(300);

	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_0,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_1,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_2,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_3,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_4,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_5,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_6,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(GROUP_D,DIO_u8_PIN_7,DIO_u8_HIGH);
	_delay_ms(300);
	//DIO_u8_Set_PORT_Value(GROUP_D,0b11000011); _delay_ms(300);
}

void pingpong()
{
	Shift_Left();
	_delay_ms(250);
	 Shift_Right();
}

void Snake()
{
	DIO_u8_Set_PORT_Value(GROUP_D,0b00000000);
	u8 LOC_u8_D_Pointer;
	for(int i =0;i<8;i++)
	{
     	DIO_u8_Get_PORT_Value(GROUP_D,&LOC_u8_D_Pointer);
		DIO_u8_Set_PORT_Value(GROUP_D,LOC_u8_D_Pointer | (1<<i));
		_delay_ms(300);
	}
}

void Diverge_Converge()
{
	 Diverge();
	 Converge();
}
//-----------------------------------------------------------
int main()
{
	DIO_u8_Set_PORT_Direction(GROUP_A,DIO_u8_INPUT);
	DIO_u8_Set_PORT_Value(GROUP_A,0b11111111);

	DIO_u8_Set_PORT_Direction(GROUP_D,0b11111111);

	u8 Pointer_D1;
	u8 Pointer_D2;
	u8 Pointer_D3;
	u8 Pointer_D4;
	u8 Pointer_D5;
	u8 Pointer_D6;
	u8 Pointer_D7;
	u8 Pointer_D8;

	while(1)
	{
		DIO_u8_Get_Pin_Value(GROUP_A,DIO_u8_PIN_0,&Pointer_D1);
		DIO_u8_Get_Pin_Value(GROUP_A,DIO_u8_PIN_1,&Pointer_D2);
		DIO_u8_Get_Pin_Value(GROUP_A,DIO_u8_PIN_2,&Pointer_D3);
		DIO_u8_Get_Pin_Value(GROUP_A,DIO_u8_PIN_3,&Pointer_D4);
		DIO_u8_Get_Pin_Value(GROUP_A,DIO_u8_PIN_4,&Pointer_D5);
		DIO_u8_Get_Pin_Value(GROUP_A,DIO_u8_PIN_5,&Pointer_D6);
		DIO_u8_Get_Pin_Value(GROUP_A,DIO_u8_PIN_6,&Pointer_D7);
		DIO_u8_Get_Pin_Value(GROUP_A,DIO_u8_PIN_7,&Pointer_D8);
		DIO_u8_Set_PORT_Value(GROUP_D,0b00000000);

		if ( Pointer_D1 == DIO_u8_LOW)
		{
			 All_Flashing();
		}

		else if ( Pointer_D2 == DIO_u8_LOW)
		{
			Shift_Left();
		}

		else if(Pointer_D3 == DIO_u8_LOW)
		{
			Shift_Right();
		}

		else if(Pointer_D4 == DIO_u8_LOW)
		{
			//All_Flashing();
			Converge();
		}

		else if(Pointer_D5 == DIO_u8_LOW)
		{
			Diverge();
		}

		else if(Pointer_D6 == DIO_u8_LOW)
		{
			pingpong();
		}

		else if(Pointer_D7 == DIO_u8_LOW)
		{
			Snake();
		}

		else if(Pointer_D8 == DIO_u8_LOW)
		{
			Diverge_Converge();
		}

	}

	return 0;
}


