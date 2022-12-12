/*
 * DIO_Program.c
 *
 *  Created on: Nov 20, 2022
 *      Author: user
 */

#include "DIO_Interface.h"
//---------------------------------------------------------------------------------------
u8 DIO_u8_Set_Pin_Value(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_NO , u8 Copy_u8_Value)
{
	u8 Loc_u8_Error_State=DIO_u8_ERROR_INIT_VAL; //initially make error state = 0

	if( (Copy_u8_Port_ID>=DIO_Min_u8_PORT_ID) && (Copy_u8_Port_ID<=DIO_Max_u8_PORT_ID) )
	{
		if( (Copy_u8_Pin_NO >= DIO_Min_u8_PIN_ID) && (Copy_u8_Pin_NO<=DIO_Max_u8_PIN_ID) )
		{
			if( (Copy_u8_Value == DIO_Min_u8_PIN_VAL) || (Copy_u8_Value ==DIO_Max_u8_PIN_VAL) )
			{
				switch(Copy_u8_Port_ID)
					{
						case GROUP_A:
							Assign_Bit(DIO_u8_PORTA, Copy_u8_Pin_NO , Copy_u8_Value);
						break;

						case GROUP_B:
							Assign_Bit(DIO_u8_PORTB, Copy_u8_Pin_NO , Copy_u8_Value);
						break;

						case GROUP_C:
							Assign_Bit(DIO_u8_PORTC, Copy_u8_Pin_NO , Copy_u8_Value);
						break;

						case GROUP_D:
							Assign_Bit(DIO_u8_PORTD, Copy_u8_Pin_NO , Copy_u8_Value);
						break;
					}
			}
			else
			{
				 Loc_u8_Error_State=DIO_u8_PIN_VAL_ERROR; //entered value is wrong
			}
		}
		else
		{
			 Loc_u8_Error_State=DIO_u8_PIN_ID_ERROR; //entered pin is wrong
		}

	}
	else
	{
		 Loc_u8_Error_State=DIO_u8_PORT_ID_ERROR; //entered port is wrong
	}

return Loc_u8_Error_State;
}
//---------------------------------------------------------------------------------------
u8 DIO_u8_Set_Pin_Direction(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_NO , u8 Copy_u8_Direction)
{
	u8 Loc_u8_Error_State=DIO_u8_ERROR_INIT_VAL; //initially make error state = 0

	if( (Copy_u8_Port_ID>=DIO_Min_u8_PORT_ID) && (Copy_u8_Port_ID<=DIO_Max_u8_PORT_ID) )
	{
		if( (Copy_u8_Pin_NO >= DIO_Min_u8_PIN_ID) && (Copy_u8_Pin_NO<=DIO_Max_u8_PIN_ID) )
		{
			if( (Copy_u8_Direction == DIO_Min_u8_PIN_DIR) || (Copy_u8_Direction ==DIO_Max_u8_PIN_DIR) )
			{
				switch(Copy_u8_Port_ID)
					{
						case GROUP_A:
							Assign_Bit(DIO_u8_DDRA, Copy_u8_Pin_NO , Copy_u8_Direction);
						break;

						case GROUP_B:
							Assign_Bit(DIO_u8_DDRB, Copy_u8_Pin_NO , Copy_u8_Direction);
						break;

						case GROUP_C:
							Assign_Bit(DIO_u8_DDRC, Copy_u8_Pin_NO , Copy_u8_Direction);
						break;

						case GROUP_D:
							Assign_Bit(DIO_u8_DDRD, Copy_u8_Pin_NO , Copy_u8_Direction);
						break;
					}
			}
			else
			{
				 Loc_u8_Error_State= DIO_u8_PIN_DIR_ERROR; //entered direction is wrong
			}
		}
		else
		{
			 Loc_u8_Error_State=DIO_u8_PIN_ID_ERROR; //entered pin is wrong
		}

	}
	else
	{
		 Loc_u8_Error_State=DIO_u8_PORT_ID_ERROR; //entered port is wrong
	}

	return Loc_u8_Error_State;
}
//---------------------------------------------------------------------------------------
u8 DIO_u8_Set_PORT_Value(u8 Copy_u8_Port_ID, u8 Copy_u8_PORT_Value)
{
	u8 Loc_u8_Error_State=DIO_u8_ERROR_INIT_VAL; //initially make error state = 0

	if( (Copy_u8_Port_ID>=DIO_Min_u8_PORT_ID) && (Copy_u8_Port_ID <=DIO_Max_u8_PORT_ID) )
	{
		if( (Copy_u8_PORT_Value >= DIO_Min_u8_PORT_VAL) || (Copy_u8_PORT_Value <= DIO_Max_u8_PORT_VAL) )//redundant check
		{
			switch(Copy_u8_Port_ID)
				{
					case GROUP_A:
						DIO_u8_PORTA=Copy_u8_PORT_Value;
					break;

					case GROUP_B:
						DIO_u8_PORTB=Copy_u8_PORT_Value;
					break;

					case GROUP_C:
						DIO_u8_PORTC=Copy_u8_PORT_Value;
					break;

					case GROUP_D:
						DIO_u8_PORTD=Copy_u8_PORT_Value;
					break;
				}
		}
		else
		{
			 Loc_u8_Error_State=DIO_u8_PORT_VAL_ERROR; //entered value is wrong
		}

	}
	else
	{
		 Loc_u8_Error_State=DIO_u8_PORT_ID_ERROR; //entered port is wrong
	}

	return Loc_u8_Error_State;
}
//---------------------------------------------------------------------------------------
u8 DIO_u8_Set_PORT_Direction(u8 Copy_u8_Port_ID, u8 Copy_u8_PORT_Direction)
{
	u8 Loc_u8_Error_State=DIO_u8_ERROR_INIT_VAL; //initially make error state = 0
	if( (Copy_u8_Port_ID>=DIO_Min_u8_PORT_ID) && (Copy_u8_Port_ID<=DIO_Max_u8_PORT_ID) )
	{
		if( (Copy_u8_PORT_Direction == DIO_Min_u8_PORT_DIR) || (Copy_u8_PORT_Direction == DIO_Max_u8_PORT_DIR) )//redundant check
		{
			switch(Copy_u8_Port_ID)
				{
					case GROUP_A:
						DIO_u8_DDRA=Copy_u8_PORT_Direction;
					break;

					case GROUP_B:
						DIO_u8_DDRB=Copy_u8_PORT_Direction;
					break;

					case GROUP_C:
						DIO_u8_DDRC=Copy_u8_PORT_Direction;
					break;

					case GROUP_D:
						DIO_u8_DDRD=Copy_u8_PORT_Direction;
					break;
				}
		}
		else
		{
			 Loc_u8_Error_State=DIO_u8_PORT_DIR_ERROR; //entered value is wrong
		}

	}
	else
	{
		 Loc_u8_Error_State=DIO_u8_PORT_ID_ERROR; //entered port is wrong
	}

	return Loc_u8_Error_State;
}
//---------------------------------------------------------------------------------------
u8 DIO_u8_Get_Pin_Value(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_NO , u8 *Copy_u8_Value)
{
	u8 Loc_u8_Error_State=DIO_u8_ERROR_INIT_VAL; //initially make error state = 0
	if( (Copy_u8_Port_ID>=DIO_Min_u8_PORT_ID) && (Copy_u8_Port_ID<=DIO_Max_u8_PORT_ID) )
	{
		if( (Copy_u8_Pin_NO >= DIO_Min_u8_PIN_ID) && (Copy_u8_Pin_NO<=DIO_Max_u8_PIN_ID) )
		{
			switch(Copy_u8_Port_ID)
				{
					case GROUP_A:
						*Copy_u8_Value=Get_Bit(DIO_u8_PINA, Copy_u8_Pin_NO);
					break;

					case GROUP_B:
						*Copy_u8_Value=Get_Bit(DIO_u8_PINB, Copy_u8_Pin_NO);
					break;

					case GROUP_C:
						*Copy_u8_Value=Get_Bit(DIO_u8_PINC, Copy_u8_Pin_NO);
					break;

					case GROUP_D:
						*Copy_u8_Value=Get_Bit(DIO_u8_PIND, Copy_u8_Pin_NO);
					break;
				}
		}
		else
		{
			 Loc_u8_Error_State=DIO_u8_PIN_ID_ERROR; //entered pin is wrong
		}

	}
	else
	{
		 Loc_u8_Error_State=DIO_u8_PORT_ID_ERROR; //entered port is wrong
	}
	return Loc_u8_Error_State;
}
//---------------------------------------------------------------------------------------
u8 DIO_u8_Get_PORT_Value(u8 Copy_u8_Port_ID, u8 *Copy_u8_Value)
{
	u8 Loc_u8_Error_State=DIO_u8_ERROR_INIT_VAL; //initially make error state = 0
	if( (Copy_u8_Port_ID>=DIO_Min_u8_PORT_ID) && (Copy_u8_Port_ID<=DIO_Max_u8_PORT_ID) )
	{
		switch(Copy_u8_Port_ID)
			{
				case GROUP_A:
					*Copy_u8_Value=DIO_u8_PINA;
				break;

				case GROUP_B:
					*Copy_u8_Value=DIO_u8_PINB;
				break;

				case GROUP_C:
					*Copy_u8_Value=DIO_u8_PINC;
				break;

				case GROUP_D:
					*Copy_u8_Value=DIO_u8_PIND;
				break;
			}
	}
	else
	{
		 Loc_u8_Error_State=DIO_u8_PORT_ID_ERROR; //entered port is wrong
	}
	return Loc_u8_Error_State;
}
//---------------------------------------------------------------------------------------
