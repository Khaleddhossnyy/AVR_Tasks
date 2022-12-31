/*
 * EXTI_Private.h
 *
 *  Created on: Dec 3, 2022
 *      Author: user
 */

#ifndef MCAL_LAYER_02_EXTI_DRIVER_EXTI_PRIVATE_H_
#define MCAL_LAYER_02_EXTI_DRIVER_EXTI_PRIVATE_H_
//-----------------------------------------------
#define EXTI_u8_INT_BIT_0 0
#define EXTI_u8_INT_BIT_1 1
#define EXTI_u8_INT_BIT_2 2
#define EXTI_u8_INT_BIT_3 3
#define EXTI_u8_INT_BIT_4 4
#define EXTI_u8_INT_BIT_5 5
#define EXTI_u8_INT_BIT_6 6
#define EXTI_u8_INT_BIT_7 7

#define EXTI_u8_LVL_BIT_0 0
#define EXTI_u8_LVL_BIT_1 1

#define Null ((void*)0)
//------------4 Interrupt Registers -------------
#define EXTI_u8_MCUCR  *((volatile u8 *)0x55)
#define EXTI_u8_MCUCSR  *((volatile u8 *)0x54)
#define EXTI_u8_GICR  *((volatile u8 *)0x5B)
#define EXTI_u8_SREG  *((volatile u8 *)0x5F)
//-----------------------------------------------
void __vector_1(void)__attribute__((signal)); //calls INT0
void __vector_2(void)__attribute__((signal)); //calls INT1
void __vector_3(void)__attribute__((signal)); //calls INT2
//------------------------------------------------
#endif /* 03_MCAL_LAYER_02_EXTI_DRIVER_EXTI_PRIVATE_H_ */
