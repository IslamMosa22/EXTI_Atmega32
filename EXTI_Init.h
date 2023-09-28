/*
 * EXTI_Init.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Eslam
 */
#ifndef MCAL_EXTI_EXTI_INIT_H_
#define MCAL_EXTI_EXTI_INIT_H_


#define EXTI_Line0    0
#define EXTI_Line1    1
#define EXTI_Line2    2

#define EXTI_LOWLEVEL 0
#define EXTI_ONChange 1
#define EXTI_FALLING  2
#define EXTI_RISING   3

void MEXTI_voidSenseControl(u8 A_u8EXTI_Line, u8 A_u8EXTI_Sense);
void MEXTI_voidEnable (u8 A_u8EXTI_Line);
void MEXTI_voidDisable(u8 A_u8EXTI_Line);


#endif /* MCAL_EXTI_EXTI_INIT_H_ */
