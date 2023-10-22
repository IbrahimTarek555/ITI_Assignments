#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	EXTI_LINE_0 = 0,
	EXTI_LINE_1,
	EXTI_LINE_2,
	EXTI_LINE_3,
	EXTI_LINE_4,
	EXTI_LINE_5,
	EXTI_LINE_6,
	EXTI_LINE_7,
	EXTI_LINE_8,
	EXTI_LINE_9,
	EXTI_LINE_10,
	EXTI_LINE_11,
	EXTI_LINE_12,
	EXTI_LINE_13,
	EXTI_LINE_14,
	EXTI_LINE_15
}
EXTI_Line_t;

typedef enum
{
	EXTI_RISING_EDGE,
	EXTI_FALLING_EDGE,
	EXTI_ANY_CHANGE
}
EXTI_Trigger_t;

typedef enum
{
	EXTI_PORTA,
	EXTI_PORTB,
	EXTI_PORTC
}
EXTI_Port_t;

void EXTI_voidEnableInterrupt(EXTI_Line_t Copy_enLine);
void EXTI_voidDisableInterrupt(EXTI_Line_t Copy_enLine);
void EXTI_voidEnableEvent(EXTI_Line_t Copy_enLine);
void EXTI_voidDisableEvent(EXTI_Line_t Copy_enLine);
void EXTI_voidSwInterruptRequest(EXTI_Line_t Copy_enLine);
void EXTI_voidReadPendingFlag(EXTI_Line_t Copy_enLine, uint8_t *Copy_penFlagState);
void EXTI_voidClearPendingFlag(EXTI_Line_t Copy_enLine);
void EXTI_voidSelectPort(EXTI_Port_t Copy_enPortNumber, EXTI_Line_t Copy_enLine);
Error_t EXTI_voidSetMode(EXTI_Line_t Copy_enLine, EXTI_Trigger_t Copy_enTriggerType);
Error_t EXTI_enSetCallBack(EXTI_Line_t Copy_enLine, void (*Copy_pvCallBackFunction)(void));

#endif




