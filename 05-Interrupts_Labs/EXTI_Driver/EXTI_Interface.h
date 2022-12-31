/*
 * EXTI_Interface.h
 *
 *  Created on: Dec 3, 2022
 *      Author: user
 */

#ifndef MCAL_LAYER_02_EXTI_DRIVER_EXTI_INTERFACE_H_
#define MCAL_LAYER_02_EXTI_DRIVER_EXTI_INTERFACE_H_
//---------------------------------------------------
	//EXTI is a peripheral inside the MICRO controller so it will be placed in the MCAL
//---------------------------------------------------
#define EXTI_u8_INT0 0
#define EXTI_u8_INT1 1
#define EXTI_u8_INT2 2

#define EXTI_u8_EXT_INT0_LOW_Level     0b00
#define EXTI_u8_EXT_INT0_IOC		   0b01
#define EXTI_u8_EXT_INT0_FALLING_Edge  0b10
#define EXTI_u8_EXT_INT0_RISING_Edge   0b11

#define EXTI_u8_EXT_INT1_LOW_Level     0b00
#define EXTI_u8_EXT_INT1_IOC		   0b01
#define EXTI_u8_EXT_INT1_FALLING_Edge  0b10
#define EXTI_u8_EXT_INT1_RISING_Edge   0b11

#define EXTI_u8_EXT_INT2_FALLING_Edge  0b0
#define EXTI_u8_EXT_INT2_RISING_Edge   0b1

#define EXTI_u8_INT_Enable   0b1
#define EXTI_u8_INT_Disable  0b0

#define EXTI_u8_GLOBAL_Enable    0b1
#define EXTI_u8_GLOBAL_Disable   0b0
//---------------------------------------------------
void EXTI_void_SET_Level(u8 Copy_u8_INT_Index, u8 Copy_u8_INT_Level);
void EXTI_void_Enable(u8 Copy_u8_INT_Index);
void EXTI_void_Disable(u8 Copy_u8_INT_Index);
void EXTI_void_GLOBAL_ENABLE_DISABLE(u8 Copy_Global_Enable);
void EXTI_void_Set_Call_Back(u8 Copy_u8_INT_Index, void (*P_void_Call_Back)(void));
//--------------------------------------------------
#endif /* 03_MCAL_LAYER_02_EXTI_DRIVER_EXTI_INTERFACE_H_ */
