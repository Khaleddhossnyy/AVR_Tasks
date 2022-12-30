/*
 * STP_Program.c
 *
 *  Created on: Dec 3, 2022
 *      Author: user
 */
#include "../../04-STD_Libs/STD_Types.h"
#include "../../04-STD_Libs/BIT_CALC.h"
#include <util/delay.h>
#include "../../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
#include "STP_Interface.h"
//--------------------------------------------------------------
void STP_void_Rotate_ACW_Full_Step()
{
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_LOW);
	_delay_ms(10);  //the stepper works with frequancy equals 100 hz so time equals 10 ms

	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_LOW);
	_delay_ms(10);

	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_LOW);
	_delay_ms(10);

	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_HIGH);
	_delay_ms(10);
}
//--------------------------------------------------------------
void STP_void_Rotate_CW_Full_Step()
{
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_HIGH);
	_delay_ms(10);  //the stepper works with frequancy equals 100 hz so time equals 10 ms

	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_LOW);
	_delay_ms(10);

	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_LOW);
	_delay_ms(10);

	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_LOW);
	_delay_ms(10);
}
//--------------------------------------------------------------
void STP_void_Rotate_ACW_Half_Step()
{
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_HIGH);
	_delay_ms(10);  //the stepper works with frequancy equals 100 hz so time equals 10 ms

	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_LOW);
	_delay_ms(10);  //the stepper works with frequancy equals 100 hz so time equals 10 ms

	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_LOW);
	_delay_ms(10);  //the stepper works with frequancy equals 100 hz so time equals 10 ms

	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_LOW);
	_delay_ms(10);  //the stepper works with frequancy equals 100 hz so time equals 10 ms

	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_LOW);
	_delay_ms(10);  //the stepper works with frequancy equals 100 hz so time equals 10 ms

	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_LOW);
	_delay_ms(10);  //the stepper works with frequancy equals 100 hz so time equals 10 ms

	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_HIGH);
	_delay_ms(10);  //the stepper works with frequancy equals 100 hz so time equals 10 ms

	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow ,DIO_u8_LOW);
	DIO_u8_Set_Pin_Value(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange ,DIO_u8_HIGH);
	_delay_ms(10);  //the stepper works with frequancy equals 100 hz so time equals 10 ms
}
//--------------------------------------------------------------
void STP_void_Set_Angle_Dir(u32 Copy_u32_Angle, u8 Copy_u8_Dir)
{
	//mapping the required angle direction to number of steps that the motor will understand
	u32 LOC_u32_Steps = (Copy_u32_Angle*2048)/360; //equation to calculate number of steps needed
	u32 LOC_u32_Index;

	if(Copy_u8_Dir == STEPPER_u8_CW_DIR)
	{
		for(LOC_u32_Index=0; LOC_u32_Index < (LOC_u32_Steps/4); LOC_u32_Index++)
		{
			STP_void_Rotate_CW_Full_Step();//because this function itself implements 4 full steps inside it
		}
	}
	else
	{
		for(LOC_u32_Index=0; LOC_u32_Index < (LOC_u32_Steps/4); LOC_u32_Index++ )
		{
			STP_void_Rotate_ACW_Full_Step();
		}
	}
}
//-------------------------------------------------------------
void STP_void_INIT()
{
	DIO_u8_Set_Pin_Direction(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Blue,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Direction(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Pink,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Direction(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Yellow,DIO_u8_HIGH);
	DIO_u8_Set_Pin_Direction(STEPPER_u8_Coils_PORT,STEPPER_u8_Coil_Orange,DIO_u8_HIGH);
}
//--------------------------------------------------------------
