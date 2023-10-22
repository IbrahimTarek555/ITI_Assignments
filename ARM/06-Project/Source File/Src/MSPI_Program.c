/*
 * MSPI_Program.c
 *
 *  Created on: Oct 2, 2023
 *      Author: Shereef Mahmoud
 */

#include <stdint.h>

#include "../Inc/BIT_MATH.h"
#include "../Inc/Defines.h"

#include "../Inc/Stm32F401cc.h"

#include "../Inc/MSPI_Interface.h"
#include "../Inc/MSPI_Private.h"
#include "../Inc/MSPI_Config.h"

void MSPI_voidInit(void)
{
	SPI1 -> CR1 = 0x0347;
}

void MSPI_voidSendRecieveDataSync(uint8_t Copy_u8TransmitData,uint8_t* Copy_u8RecievedData)
{
	/*Send Data*/
	SPI1 -> DR = Copy_u8TransmitData;

	/*Wait flag*/
	while(GET_BIT(SPI1 -> SR, BSY));

	/*Return for the received data*/
	*Copy_u8RecievedData = SPI1 -> DR;
}

void MSPI_voidSendRecieveDataAsync(uint8_t Copy_u8TransmitData, void(*Copy_pvoidCallBack)(uint8_t Copy_u8Data))
{
		/*Send Data*/
		SPI1 -> DR = Copy_u8TransmitData;
}
