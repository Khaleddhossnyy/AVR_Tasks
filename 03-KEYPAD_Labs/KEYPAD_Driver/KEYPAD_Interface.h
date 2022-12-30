/*
 * KEYPAD_Interface.h
 *
 *  Created on: Nov 26, 2022
 *      Author: user
 */

#ifndef HAL_LAYER_02_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_
#define HAL_LAYER_02_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_
//-----------------------------------------------------
#define KPD_u8_ROWS     4
#define KPD_u8_COLS     4

#define KPD_u8_KEYS_NUM KPD_u8_ROWS*KPD_u8_COLS

#define KPD_u8_KEY_PRESSED 0
#define KPD_u8_KEY_NOT_PRESSED 1
//-----------------------------------------------------

//-----------------------------------------------------
void KPD_void_Get_Status(u8 *PTR_u8_KPD_Status);
void KPD_void_INIT();
//-----------------------------------------------------


#endif /* 02_HAL_LAYER_02_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_ */
