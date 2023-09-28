/*
 * GIE_Prog.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Eslam
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_Init.h""

#define SREG    *((volatile u8 *) 0x5F)

void MGIE_voidEnable(){
	SET_BIT(SREG,7);
}
void MGIE_voidDisable(){
	CLR_BIT(SREG,7);
}
