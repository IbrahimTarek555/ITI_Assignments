#include <stdint.h>

#include "../Inc/Defines.h"

#include "../Inc/Stm32F401cc.h"

#include "../Inc/GPIO_interface.h"
#include "../Inc/SYSTICK_interface.h"
#include "../Inc/MSPI_Interface.h"

#include "../Inc/TFT_config.h"
#include "../Inc/TFT_interface.h"
#include "../Inc/TFT_private.h"

static GPIO_PinConfig_t *TFT_pstA0 = NULL, *TFT_pstReset = NULL;

void TFT_voidInit(GPIO_PinConfig_t *Copy_pstA0, GPIO_PinConfig_t *Copy_pstReset)
{
	TFT_pstReset = Copy_pstReset;
	TFT_pstA0 = Copy_pstA0;

	/* Reset Pulse */
	GPIO_enSetPinValue(TFT_pstReset, GPIO_PIN_HIGH);
	SYSTICK_voidDelayUS(100);
	GPIO_enSetPinValue(TFT_pstReset, GPIO_PIN_LOW);
	SYSTICK_voidDelayUS(1);
	GPIO_enSetPinValue(TFT_pstReset, GPIO_PIN_HIGH);
	SYSTICK_voidDelayUS(100);
	GPIO_enSetPinValue(TFT_pstReset, GPIO_PIN_LOW);
	SYSTICK_voidDelayUS(100);
	GPIO_enSetPinValue(TFT_pstReset, GPIO_PIN_HIGH);
	SYSTICK_voidDelayMS(120);

	/* Sleep Out Command*/
	TFT_voidWriteCmd(0x11);
	SYSTICK_voidDelayMS(150);

	/* Color Mode Command */
	TFT_voidWriteCmd(0x3A);
	TFT_voidWriteData(0x05);

	/* Display On Command */
	TFT_voidWriteCmd(0x29);
}

static void TFT_voidWriteData(uint8_t Copy_u8Data)
{
	/* Define variable to receive the incoming data from SPI function */
	uint8_t Local_u8Temp;

	/* Set A0 pin to high */
	GPIO_enSetPinValue(TFT_pstA0, GPIO_PIN_HIGH);

	/* Send data over SPI */
	MSPI_voidSendRecieveDataSync(Copy_u8Data, &Local_u8Temp);
}

static void TFT_voidWriteCmd(uint8_t Copy_u8Cmd)
{
	/* Define variable to receive the incoming data from SPI function */
	uint8_t Local_u8Temp;

	/* Set A0 pin to low */
	GPIO_enSetPinValue(TFT_pstA0, GPIO_PIN_LOW);

	/* Send command over SPI */
	MSPI_voidSendRecieveDataSync(Copy_u8Cmd, &Local_u8Temp);
}


void TFT_voidDisplayImage(const uint16_t Copy_u16ImageArr[])
{
	/* Define Counter */
	uint16_t Local_u16Counter;

	/* Set x address */
	TFT_voidWriteCmd(0x2A);
	TFT_voidWriteData(0x00);
	TFT_voidWriteData(0x00);
	TFT_voidWriteData(0x00);
	TFT_voidWriteData(0x7F);

	/* Set y address */
	TFT_voidWriteCmd(0x2B);
	TFT_voidWriteData(0x00);
	TFT_voidWriteData(0x00);
	TFT_voidWriteData(0x00);
	TFT_voidWriteData(0x9F);

	/* RAM write */
	TFT_voidWriteCmd(0x2C);

	for(Local_u16Counter = 0; Local_u16Counter < 20480; Local_u16Counter++)
	{
		TFT_voidWriteData(Copy_u16ImageArr[Local_u16Counter] >> 8);
		TFT_voidWriteData(Copy_u16ImageArr[Local_u16Counter] & 0x00FF);
	}
}

void TFT_voidErase(void)
{
	/* Define Counter */
	uint16_t Local_u16Counter;

	/* Set x address */
	TFT_voidWriteCmd(0x2A);
	TFT_voidWriteData(0x00);
	TFT_voidWriteData(0x00);
	TFT_voidWriteData(0x00);
	TFT_voidWriteData(0x7F);

	/* Set y address */
	TFT_voidWriteCmd(0x2B);
	TFT_voidWriteData(0x00);
	TFT_voidWriteData(0x00);
	TFT_voidWriteData(0x00);
	TFT_voidWriteData(0x9F);

	/* RAM write */
	TFT_voidWriteCmd(0x2C);

	for(Local_u16Counter = 0; Local_u16Counter < 20480; Local_u16Counter++)
	{
		TFT_voidWriteData(0xff);
		TFT_voidWriteData(0xff);
	}
}
