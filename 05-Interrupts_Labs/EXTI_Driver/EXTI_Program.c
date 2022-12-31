/*
 * EXTI_Program.c
 *
 *  Created on: Dec 3, 2022
 *      Author: user
 */
#include "../../04-STD_Libs/STD_Types.h"
#include "../../04-STD_Libs/BIT_CALC.h"
#include <util/delay.h>
#include "../../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
//-----------------------------------------------------------
void EXTI_void_SET_Level(u8 Copy_u8_INT_Index, u8 Copy_u8_INT_Level) //which interrupt and which level do you want to set this interrupt to
{
	switch(Copy_u8_INT_Index)
	{
	 	 case EXTI_u8_INT0:
	 		 Assign_Bit(EXTI_u8_MCUCR,EXTI_u8_INT_BIT_0,Get_Bit(Copy_u8_INT_Level,EXTI_u8_LVL_BIT_0));
	 		 Assign_Bit(EXTI_u8_MCUCR,EXTI_u8_INT_BIT_1,Get_Bit(Copy_u8_INT_Level,EXTI_u8_LVL_BIT_1));
		 break;

	 	 case EXTI_u8_INT1:
	 		Assign_Bit(EXTI_u8_MCUCR,EXTI_u8_INT_BIT_2,Get_Bit(Copy_u8_INT_Level,EXTI_u8_LVL_BIT_0));
	 		Assign_Bit(EXTI_u8_MCUCR,EXTI_u8_INT_BIT_3,Get_Bit(Copy_u8_INT_Level,EXTI_u8_LVL_BIT_1));
	 	 break;

	 	 case EXTI_u8_INT2:
	 		Assign_Bit(EXTI_u8_MCUCSR,EXTI_u8_INT_BIT_6,Get_Bit(Copy_u8_INT_Level,EXTI_u8_LVL_BIT_0));
	     break;
	}
}
//------------------------------------------------------------
void EXTI_void_Enable(u8 Copy_u8_INT_Index)
{
	switch(Copy_u8_INT_Index)
		{
		 case EXTI_u8_INT0:
			 Assign_Bit(EXTI_u8_GICR,EXTI_u8_INT_BIT_6,EXTI_u8_INT_Enable);
			 //Set_Bit(EXTI_u8_GICR,6);
		 break;

		 case EXTI_u8_INT1:
			 Assign_Bit(EXTI_u8_GICR,EXTI_u8_INT_BIT_7,EXTI_u8_INT_Enable);
		 break;

		 case EXTI_u8_INT2:
			 Assign_Bit(EXTI_u8_GICR,EXTI_u8_INT_BIT_5,EXTI_u8_INT_Enable);
		 break;
		}
}
//------------------------------------------------------------
void EXTI_void_Disable(u8 Copy_u8_INT_Index)
{
	switch(Copy_u8_INT_Index)
		{
		 case EXTI_u8_INT0:
			 Assign_Bit(EXTI_u8_GICR,EXTI_u8_INT_BIT_6,EXTI_u8_INT_Disable);
		 break;

		 case EXTI_u8_INT1:
			 Assign_Bit(EXTI_u8_GICR,EXTI_u8_INT_BIT_7,EXTI_u8_INT_Disable);
		 break;

		 case EXTI_u8_INT2:
			 Assign_Bit(EXTI_u8_GICR,EXTI_u8_INT_BIT_5,EXTI_u8_INT_Disable);
		 break;
		}
}
//------------------------------------------------------------
void EXTI_void_GLOBAL_ENABLE_DISABLE(u8 Copy_Global_Enable)
{
	switch (Copy_Global_Enable)
	{
		case EXTI_u8_GLOBAL_Enable:
			Set_Bit(EXTI_u8_SREG ,7);
		break;

		case EXTI_u8_GLOBAL_Disable:
			Clear_Bit(EXTI_u8_SREG ,7);
		break;
	}
}

//-----------------------------------------------------------
void (*A_void_Call_Back[3])(void)={Null,Null,Null}; //array of pointer to functions, each interrupt will call one of them
//-----------------------------------------------------------
void __vector_1(void)
{
	if(A_void_Call_Back[0] != Null)
	{
		A_void_Call_Back[0](); //how to call a pointer to function
	}
}
//-----------------------------------------------------------
void __vector_2(void)
{
	if(A_void_Call_Back[1] != Null)
	{
		A_void_Call_Back[1]();
	}
}
//-----------------------------------------------------------
void __vector_3(void)
{
	if(A_void_Call_Back[2] != Null)
	{
		A_void_Call_Back[2]();
	}
}
//-----------------------------------------------------------
void EXTI_void_Set_Call_Back(u8 Copy_u8_INT_Index, void (*P_void_Call_Back)(void))
{
	A_void_Call_Back[Copy_u8_INT_Index] = P_void_Call_Back; //points to the function that the user will send in the main
}
//----------------------------------------------------------
