/*
 * STP_Interface.h
 *
 *  Created on: Dec 3, 2022
 *      Author: user
 */

#ifndef HAL_LAYER_03_STEPPER_MOTOR_DRIVER_STP_INTERFACE_H_
#define HAL_LAYER_03_STEPPER_MOTOR_DRIVER_STP_INTERFACE_H_

//--------------------------------------------------------
#define STEPPER_u8_Coils_PORT 		GROUP_A

#define STEPPER_u8_Coil_Blue    DIO_u8_PIN_0
#define STEPPER_u8_Coil_Pink	DIO_u8_PIN_1
#define STEPPER_u8_Coil_Yellow	DIO_u8_PIN_2
#define STEPPER_u8_Coil_Orange  DIO_u8_PIN_3

#define STEPPER_u8_CW_DIR 0
#define STEPPER_u8_ACW_DIR 1
//--------------------------------------------------------
void STP_void_Rotate_CW_Full_Step();
void STP_void_Rotate_ACW_Full_Step();
void STP_void_Rotate_CW_Half_Step();
void STP_void_Set_Angle_Dir(u32 Copy_u32_Angle, u8 Copy_u8_Dir);
void STP_void_INIT();
//----------------------------------------------------------
#endif /* 02_HAL_LAYER_03_STEPPER_MOTOR_DRIVER_STP_INTERFACE_H_ */
