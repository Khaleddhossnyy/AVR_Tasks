

//--------------------------------------------------------------------------
#include <util/delay.h>
#include "../03-MCAL_Layer/01-DIO_Driver/DIO_Interface.h"
//--------------------------------------------------------------



int main()
{
	DIO_u8_Set_Pin_Direction(GROUP_A,DIO_u8_PIN_0,DIO_u8_HIGH); //set A0 to output

	DIO_u8_Set_Pin_Value(GROUP_A,DIO_u8_PIN_0,DIO_u8_HIGH);
	_delay_ms(1000);
	DIO_u8_Set_Pin_Value(GROUP_A,DIO_u8_PIN_0,DIO_u8_LOW);

	return 0;
}
