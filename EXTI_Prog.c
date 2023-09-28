/*
 * EXTI_Prog.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Eslam
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_Init.h"

#define MCUCR   *((volatile u8 *) 0x55)
#define MCUCSR  *((volatile u8 *) 0x54)
#define GICR    *((volatile u8 *) 0x5B)
#define GIFR    *((volatile u8 *) 0x5A)


void MEXTI_voidSenseControl(u8 A_u8EXTI_Line, u8 A_u8EXTI_Sense){
	switch(A_u8EXTI_Line)
	{
	case EXTI_Line0:
		switch (A_u8EXTI_Sense)
		{
		case EXTI_LOWLEVEL:
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;
		case EXTI_ONChange:
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;
		case EXTI_FALLING:
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;
		case EXTI_RISING:
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;
		}
		break;
	case EXTI_Line1:
		switch (A_u8EXTI_Sense){
		case EXTI_LOWLEVEL:
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;
		case EXTI_ONChange:
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;
		case EXTI_FALLING:
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;
		case EXTI_RISING:
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;
		}
		break;
	case EXTI_Line2:
		switch (A_u8EXTI_Sense){
		case EXTI_FALLING:
			CLR_BIT(MCUCSR,6);
			break;
		case EXTI_RISING:
			SET_BIT(MCUCR,6);
			break;
		}
		break;
	}
}

void MEXTI_voidEnable (u8 A_u8EXTI_Line){
	switch(A_u8EXTI_Line)
	{
	case EXTI_Line0: SET_BIT(GICR,6); break;
	case EXTI_Line1: SET_BIT(GICR,7); break;
	case EXTI_Line2: SET_BIT(GICR,5); break;
	}
}
void MEXTI_voidDisable(u8 A_u8EXTI_Line){
	switch(A_u8EXTI_Line)
		{
		case EXTI_Line0: CLR_BIT(GICR,6); break;
		case EXTI_Line1: CLR_BIT(GICR,7); break;
		case EXTI_Line2: CLR_BIT(GICR,5); break;
		}
}
