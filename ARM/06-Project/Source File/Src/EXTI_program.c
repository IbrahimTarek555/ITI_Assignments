#include <stdint.h>

#include "../Inc/Defines.h"

#include "../Inc/Stm32F401cc.h"

#include "../Inc/EXTI_interface.h"
#include "../Inc/EXTI_private.h"

void EXTI_voidEnableInterrupt(EXTI_Line_t Copy_enLine)
{
	EXTI -> IMR |= 0b1u << Copy_enLine;
}

void EXTI_voidDisableInterrupt(EXTI_Line_t Copy_enLine)
{
	EXTI -> IMR &= ~(0b1u << Copy_enLine);
}

void EXTI_voidEnableEvent(EXTI_Line_t Copy_enLine)
{
	EXTI -> EMR |= 0b1u << Copy_enLine;
}

void EXTI_voidDisableEvent(EXTI_Line_t Copy_enLine)
{
	EXTI -> EMR &= ~(0b1u << Copy_enLine);
}

void EXTI_voidSwInterruptRequest(EXTI_Line_t Copy_enLine)
{
	EXTI -> SWIER |= 0b1u << Copy_enLine;
}

void EXTI_voidReadPendingFlag(EXTI_Line_t Copy_enLine, uint8_t *Copy_penFlagState)
{
	*Copy_penFlagState = (((EXTI -> PR) >> Copy_enLine) & 0b1u);
}

void EXTI_voidClearPendingFlag(EXTI_Line_t Copy_enLine)
{
	EXTI -> PR |= 0b1u << Copy_enLine;
}

void EXTI_voidSelectPort(EXTI_Port_t Copy_enPortNumber, EXTI_Line_t Copy_enLine)
{
	/*Set those bits based on the entered port and EXTI*/
	SYSCFG -> EXTICR[Copy_enLine / 4] &= ~(0b1111u << ((Copy_enLine % 4u) * 4u));
	SYSCFG -> EXTICR[Copy_enLine / 4] |= (Copy_enPortNumber << ((Copy_enLine % 4u) * 4u));
}

Error_t EXTI_voidSetMode(EXTI_Line_t Copy_enLine, EXTI_Trigger_t Copy_enTriggerType)
{
	Error_t Local_enErrorState = OK;

	switch(Copy_enTriggerType)
	{
	case EXTI_FALLING_EDGE:	EXTI -> FTSR |= 0b1u << Copy_enLine;	break;
	case EXTI_RISING_EDGE:	EXTI -> RTSR |= 0b1u << Copy_enLine;	break;
	case EXTI_ANY_CHANGE:	EXTI -> FTSR |= 0b1u << Copy_enLine;	EXTI -> RTSR |= 0b1u << Copy_enLine;	break;
	default: 				Local_enErrorState = NOK;	break;
	}

	return Local_enErrorState;
}

//Error_t EXTI_enSetCallBack(EXTI_Line_t Copy_enLine, void (*Copy_pvCallBackFunction)(void))
//{
//
//}
