#include <stdint.h>

#include "../Inc/Defines.h"

#include "../Inc/Stm32F401cc.h"

#include "../Inc/NVIC_interface.h"
#include "../Inc/NVIC_private.h"

static NVIC_PriorityGroupMode_t NVIC_enPriorityMode = NVIC_16GROUP_0SUB;

void NVIC_voidEnableInterrupt(NVIC_VectorTablePos_t Copy_enInterrupt)
{
	NVIC -> ISER[Copy_enInterrupt / 32u] |= (0b1u << (Copy_enInterrupt % 32u));
}

void NVIC_voidDisableInterrupt(NVIC_VectorTablePos_t Copy_enInterrupt)
{
	NVIC -> ICER[Copy_enInterrupt / 32u] |= (0b1u << (Copy_enInterrupt % 32u));
}

void NVIC_voidEnableInterruptPending(NVIC_VectorTablePos_t Copy_enInterrupt)
{
	NVIC -> ISPR[Copy_enInterrupt / 32u] |= (0b1u << (Copy_enInterrupt % 32u));
}

void NVIC_voidDisableInterruptPending(NVIC_VectorTablePos_t Copy_enInterrupt)
{
	NVIC -> ICPR[Copy_enInterrupt / 32u] |= (0b1u << (Copy_enInterrupt % 32u));
}

void NVIC_voidGetActiveFlag(NVIC_VectorTablePos_t Copy_enInterrupt, Defines_Status_t *Copy_penFlagState)
{
	*Copy_penFlagState = (NVIC -> IABR[Copy_enInterrupt / 32u] >> (Copy_enInterrupt / 32u)) & 0b1u;
}

void NVIC_voidReadPendingFlag(NVIC_VectorTablePos_t Copy_enInterrupt, Defines_Status_t *Copy_penFlagState)
{
	*Copy_penFlagState = (NVIC -> ISPR[Copy_enInterrupt / 32u] >> (Copy_enInterrupt / 32u)) & 0b1u;
}

void NVIC_voidSetInterruptPriority(NVIC_VectorTablePos_t Copy_enInterrupt, uint8_t Copy_u8Group, uint8_t Copy_u8SubGroup)
{
	NVIC -> IPR[Copy_enInterrupt] = ((Copy_u8Group << (NVIC_enPriorityMode - 3u)) | Copy_u8SubGroup) << 4u;
}

void NVIC_voidSetInterruptGroupMode(NVIC_PriorityGroupMode_t Copy_enGroupMode)
{
	SCB_AIRCR = (SCB_AIRCR_VICTKEY | (Copy_enGroupMode << 8u));
	NVIC_enPriorityMode = Copy_enGroupMode;
}
