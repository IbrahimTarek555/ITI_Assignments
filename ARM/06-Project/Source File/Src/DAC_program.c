#include <stdint.h>

#include "../Inc/Defines.h"

#include "../Inc/Stm32F401cc.h"

#include "../Inc/GPIO_interface.h"

#include "../Inc/DAC_interface.h"
#include "../Inc/DAC_private.h"


Error_t DAC_enSetValue(const GPIO_PinConfig_t *Copy_pstPinsArr, uint8_t Copy_u8Value)
{
	/* Define Error State */
	Error_t Local_enErrorState = OK;

	/* Set the value to the pins */
	GPIO_enSetPinValue(&Copy_pstPinsArr[0], ((Copy_u8Value >> 0) & 0b1u));
	GPIO_enSetPinValue(&Copy_pstPinsArr[1], ((Copy_u8Value >> 1) & 0b1u));
	GPIO_enSetPinValue(&Copy_pstPinsArr[2], ((Copy_u8Value >> 2) & 0b1u));
	GPIO_enSetPinValue(&Copy_pstPinsArr[3], ((Copy_u8Value >> 3) & 0b1u));
	GPIO_enSetPinValue(&Copy_pstPinsArr[4], ((Copy_u8Value >> 4) & 0b1u));
	GPIO_enSetPinValue(&Copy_pstPinsArr[5], ((Copy_u8Value >> 5) & 0b1u));
	GPIO_enSetPinValue(&Copy_pstPinsArr[6], ((Copy_u8Value >> 6) & 0b1u));
	GPIO_enSetPinValue(&Copy_pstPinsArr[7], ((Copy_u8Value >> 7) & 0b1u));

	/* Return Error State */
	return Local_enErrorState;
}
