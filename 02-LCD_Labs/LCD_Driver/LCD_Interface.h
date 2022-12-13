/*
 * LCD_Interface.h
 *
 *  Created on: Nov 25, 2022
 *      Author: user
 */

#ifndef HAL_LAYER_01_LCD_DRIVER_LCD_INTERFACE_H_
#define HAL_LAYER_01_LCD_DRIVER_LCD_INTERFACE_H_


//----------------------------------------------
void LCD_Void_INIT();
void LCD_Void_Write_Cmd(u8 Copy_u8_Cmd);
void LCD_Void_Write_Data(u8 Copy_u8_Data);
void LCD_void_Write(u8 Copy_u8_Val);
void LCD_void_Set_DDRAM_ADD(u8 Copy_u8DDRAM_ADD);
void LCD_void_Set_Co_Ordinates(u8 Copy_u8_X_Pos, u8 Copy_u8_Y_Pos);
void LCD_void_Write_String(u8 *Ptr_u8_String, u8 Copy_u8_X_Pos, u8 Copy_u8_Y_Pos);
void LCD_void_Set_CGRAM_ADD(u8 Copy_u8_CGRAM_ADD);
//void LCD_void_Write_Num(u32 Copy_u32_Num_VAL, u8 Copy_u8_X_Pos, u8 Copy_u8_Y_Pos);
void LCD_void_Write_Num(u32 Copy_u32Num,u8 Copy_u8x_Pos,u8 Copy_u8y_Pos);
static void reverse(u8 *PTR_u8Arr,u8 Copy_u8Length);
static void swap(u8 *PTR_u8Num1,u8 *PTR_u8Num2);
u32  LCD_u8_Count_Num_Digits(u32 Copy_u32_Num_VAL);
void LCD_void_Write_Spaces(u32 Copy_void_Num_Spaces);
//----------------------------------------------


#endif /* 02_HAL_LAYER_01_LCD_DRIVER_LCD_INTERFACE_H_ */
