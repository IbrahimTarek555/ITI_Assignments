#include <stdint.h>

#include "../Inc/Defines.h"

#include "../Inc/GPIO_interface.h"
#include "../Inc/RCC_interface.h"
#include "../Inc/SYSTICK_interface.h"
#include "../Inc/LED_MATRIX_interface.h"
#include "../Inc/DAC_interface.h"
#include "../Inc/TFT_interface.h"
#include "../Inc/NVIC_interface.h"
#include "../Inc/EXTI_interface.h"
#include "../Inc/MSPI_Interface.h"

#include "../Inc/Audio.h"
#include "../Inc/Image.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


/*Define Global flag*/
uint8_t Main_u8ModeFlag = 0u;
uint16_t Main_u16ModeCounter = 0u;

static GPIO_PinConfig_t Main_stTFT_A0 = {
		.AltFunc = GPIO_AF0,
		.OutputSpeed = GPIO_LOW,
		.OutputType = GPIO_PUSH_PULL,
		.PinMode = GPIO_OUTPUT,
		.PinNum = GPIO_PIN2,
		.Port = GPIO_PORTA,
		.PullType = GPIO_NO_PULL
};

static GPIO_PinConfig_t Main_stTFT_Reset = {
		.AltFunc = GPIO_AF0,
		.OutputSpeed = GPIO_LOW,
		.OutputType = GPIO_PUSH_PULL,
		.PinMode = GPIO_OUTPUT,
		.PinNum = GPIO_PIN1,
		.Port = GPIO_PORTA,
		.PullType = GPIO_NO_PULL
};


static GPIO_PinConfig_t Main_stTFT_CLK = {
		.AltFunc = GPIO_AF5,
		.OutputSpeed = GPIO_MIDIUM,
		.OutputType = GPIO_PUSH_PULL,
		.PinMode = GPIO_ALTERNATE_FUNCTION,
		.PinNum = GPIO_PIN5,
		.Port = GPIO_PORTA,
		.PullType = GPIO_NO_PULL
};

static GPIO_PinConfig_t Main_stTFT_MOSI = {
		.AltFunc = GPIO_AF5,
		.OutputSpeed = GPIO_MIDIUM,
		.OutputType = GPIO_PUSH_PULL,
		.PinMode = GPIO_ALTERNATE_FUNCTION,
		.PinNum = GPIO_PIN7,
		.Port = GPIO_PORTA,
		.PullType = GPIO_NO_PULL
};

static GPIO_PinConfig_t Main_stPinB0 = {
		.AltFunc = GPIO_AF0,
		.OutputSpeed = GPIO_MIDIUM,
		.OutputType = GPIO_PUSH_PULL,
		.PinMode = GPIO_INPUT,
		.PinNum = GPIO_PIN0,
		.Port = GPIO_PORTB,
		.PullType = GPIO_PULL_UP
};

static GPIO_PinConfig_t Main_stPinB1 = {
		.AltFunc = GPIO_AF0,
		.OutputSpeed = GPIO_MIDIUM,
		.OutputType = GPIO_PUSH_PULL,
		.PinMode = GPIO_INPUT,
		.PinNum = GPIO_PIN1,
		.Port = GPIO_PORTB,
		.PullType = GPIO_PULL_UP
};
static GPIO_PinConfig_t Main_stPinB3 = {
		.AltFunc = GPIO_AF0,
		.OutputSpeed = GPIO_MIDIUM,
		.OutputType = GPIO_PUSH_PULL,
		.PinMode = GPIO_INPUT,
		.PinNum = GPIO_PIN3,
		.Port = GPIO_PORTB,
		.PullType = GPIO_PULL_UP
};

GPIO_PinConfig_t MAIN_stDacArr[8] = {
		{GPIO_PORTA, GPIO_PIN9, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_MIDIUM, GPIO_NO_PULL, GPIO_AF0},
		{GPIO_PORTA, GPIO_PIN10, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_MIDIUM, GPIO_NO_PULL, GPIO_AF0},
		{GPIO_PORTA, GPIO_PIN11, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_MIDIUM, GPIO_NO_PULL, GPIO_AF0},
		{GPIO_PORTA, GPIO_PIN12, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_MIDIUM, GPIO_NO_PULL, GPIO_AF0},
		{GPIO_PORTB, GPIO_PIN7, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_MIDIUM, GPIO_NO_PULL, GPIO_AF0},
		{GPIO_PORTC, GPIO_PIN13, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_MIDIUM, GPIO_NO_PULL, GPIO_AF0},
		{GPIO_PORTC, GPIO_PIN14, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_MIDIUM, GPIO_NO_PULL, GPIO_AF0},
		{GPIO_PORTC, GPIO_PIN15, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_MIDIUM, GPIO_NO_PULL, GPIO_AF0}};


int main(void)
{
	uint8_t Local_u8AmrMatrixArr[24][8] = {
			{255, 189, 189, 129, 189, 189, 129, 255},
			{255, 123, 123, 3, 123, 123, 3, 255},
			{255, 246, 246, 6, 246, 246, 6, 255},
			{255, 237, 237, 13, 237, 236, 13, 255},
			{255, 219, 219, 27, 218, 217, 27, 255},
			{255, 183, 183, 55, 181, 178, 55, 255},
			{255, 110, 110, 110, 106, 100, 110, 255},
			{255, 221, 221, 221, 213, 201, 221, 255},
			{255, 186, 186, 186, 170, 146, 186, 255},
			{255, 117, 117, 117, 84, 37, 116, 255},
			{255, 235, 235, 235, 168, 74, 232, 255},
			{255, 215, 215, 214, 81, 149, 209, 255},
			{255, 174, 174, 173, 163, 43, 163, 255},
			{255, 93, 93, 91, 71, 87, 71, 255},
			{255, 186, 186, 182, 142, 174, 142, 255},
			{255, 117, 117, 108, 29, 93, 28, 255},
			{255, 235, 235, 216, 59, 187, 56, 255},
			{255, 215, 215, 176, 119, 119, 112, 255},
			{255, 175, 175, 96, 239, 239, 224, 255},
			{255, 94, 94, 192, 222, 222, 192, 255},
			{255, 189, 189, 129, 189, 189, 129, 255}
	};

	uint8_t Local_u8MounirMatrixArr[27][8] = {
			{255, 186, 186, 186, 170, 146, 186, 255},
			{255, 116, 117, 117, 85, 37, 116, 255},
			{255, 232, 235, 235, 171, 75, 232, 255},
			{255, 208, 214, 214, 86, 150, 208, 255},
			{255, 161, 173, 173, 173, 45, 161, 255},
			{255, 66, 90, 90, 90, 90, 66, 255},
			{255, 133, 181, 181, 181, 180, 133, 255},
			{255, 11, 107, 106, 106, 105, 11, 255},
			{255, 23, 214, 213, 213, 211, 23, 255},
			{255, 46, 172, 170, 170, 166, 46, 255},
			{255, 93, 89, 85, 85, 77, 93, 255},
			{255, 186, 179, 171, 171, 155, 186, 255},
			{255, 116, 102, 86, 86, 54, 116, 255},
			{255, 232, 205, 173, 173, 109, 232, 255},
			{255, 209, 155, 91, 91, 219, 209, 255},
			{255, 162, 54, 182, 182, 182, 162, 255},
			{255, 69, 109, 109, 108, 109, 68, 255},
			{255, 139, 219, 219, 216, 218, 136, 255},
			{255, 23, 183, 182, 177, 181, 17, 255},
			{255, 46, 110, 109, 99, 107, 35, 255},
			{255, 93, 221, 219, 199, 215, 71, 255},
			{255, 186, 186, 182, 142, 174, 142, 255},
			{255, 117, 117, 109, 29, 92, 29, 255},
			{255, 235, 235, 219, 58, 185, 59, 255},
			{255, 215, 215, 183, 117, 114, 119, 255},
			{255, 174, 174, 110, 234, 228, 238, 255},
			{255, 93, 93, 221, 213, 201, 221, 255},
	};

	uint8_t Local_u8MatrixOuterCounter = 0u;
	uint8_t Local_u8MatrixInnerCounter = 0u;
	uint8_t Local_u8Counter = 0u;

	SYSTICK_Config_t Local_stSystickConfig =
	{
			.Exception_Request = DISABLE,
			.Prescaler = SYSTICK_AHB_BY_8,
			.ClkFreq = 16
	};

	SYSTICK_enInit(&Local_stSystickConfig);

	RCC_enAHB1_EnableClk(GPIOA_EN);
	RCC_enAHB1_EnableClk(GPIOB_EN);
	RCC_enAHB1_EnableClk(GPIOC_EN);
	RCC_enAPB2_EnableClk(SYSCFG_EN);

	RCC_enAPB2_EnableClk(SPI1_EN);

	GPIO_enPinInit(&Main_stTFT_A0);
	GPIO_enPinInit(&Main_stTFT_Reset);
	GPIO_enPinInit(&Main_stTFT_CLK);
	GPIO_enPinInit(&Main_stTFT_MOSI);
	GPIO_enPinInit(&Main_stPinB0);
	GPIO_enPinInit(&Main_stPinB1);
	GPIO_enPinInit(&Main_stPinB3);
	LED_MATRIX_voidInit();

	for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
		GPIO_enPinInit(&MAIN_stDacArr[Local_u8Counter]);
	}

	/* Initialize SPI */
	MSPI_voidInit();

	TFT_voidInit(&Main_stTFT_A0, &Main_stTFT_Reset);
	TFT_voidErase();


	/*Configure the project external interrupts*/
	NVIC_voidEnableInterrupt(NVIC_EXTI0);
	NVIC_voidEnableInterrupt(NVIC_EXTI1);
	NVIC_voidEnableInterrupt(NVIC_EXTI3);
	EXTI_voidEnableInterrupt(EXTI_LINE_0);
	EXTI_voidEnableInterrupt(EXTI_LINE_1);
	EXTI_voidEnableInterrupt(EXTI_LINE_3);
	EXTI_voidSelectPort(EXTI_PORTB, EXTI_LINE_0);
	EXTI_voidSelectPort(EXTI_PORTB, EXTI_LINE_1);
	EXTI_voidSelectPort(EXTI_PORTB, EXTI_LINE_3);
	EXTI_voidSetMode(EXTI_LINE_0, EXTI_FALLING_EDGE);
	EXTI_voidSetMode(EXTI_LINE_1, EXTI_FALLING_EDGE);
	EXTI_voidSetMode(EXTI_LINE_3, EXTI_FALLING_EDGE);

	while(1)
	{
		if(Main_u8ModeFlag == 0u)
		{
		}
		else if(Main_u8ModeFlag == 1u)
		{
			DAC_enSetValue(MAIN_stDacArr, Audio_u8AmrDiabSongArr[Main_u16ModeCounter]);

			Main_u16ModeCounter++;
			if(!(Main_u16ModeCounter % 20u))
			{
				Local_u8MatrixOuterCounter++;

				if(Local_u8MatrixOuterCounter == 40u)
				{
					Local_u8MatrixInnerCounter++;
					Local_u8MatrixOuterCounter = 0u;
					if(Local_u8MatrixInnerCounter == 21u)
					{
						Local_u8MatrixInnerCounter = 0u;
					}
				}

				LED_MATRIX_voidDisplayAsynch(Local_u8AmrMatrixArr[Local_u8MatrixInnerCounter]);
			}
			if(Main_u16ModeCounter == 60000u)
			{
				Main_u16ModeCounter = 0u;
			}
			SYSTICK_voidDelayUS(125u);
		}
		else if(Main_u8ModeFlag == 2u)
		{
			DAC_enSetValue(MAIN_stDacArr, Audio_u8MounirSongArr[Main_u16ModeCounter]);

			Main_u16ModeCounter++;
			if(!(Main_u16ModeCounter % 20u))
			{
				Local_u8MatrixOuterCounter++;

				if(Local_u8MatrixOuterCounter == 40u)
				{
					Local_u8MatrixInnerCounter++;
					Local_u8MatrixOuterCounter = 0u;
					if(Local_u8MatrixInnerCounter == 27u)
					{
						Local_u8MatrixInnerCounter = 0u;
					}
				}

				LED_MATRIX_voidDisplayAsynch(Local_u8MounirMatrixArr[Local_u8MatrixInnerCounter]);
			}
			if(Main_u16ModeCounter == 60000u)
			{
				Main_u16ModeCounter = 0u;
			}
			SYSTICK_voidDelayUS(125u);
		}
	}
}

void EXTI0_IRQHandler(void)
{
	Main_u8ModeFlag = 0u;
	EXTI_voidClearPendingFlag(EXTI_LINE_0);
	TFT_voidErase();
	Main_u16ModeCounter = 0u;
}

void EXTI1_IRQHandler(void)
{
	Main_u8ModeFlag = 1u;
	TFT_voidDisplayImage(Image_u16AmrDiabArr);
	EXTI_voidClearPendingFlag(EXTI_LINE_1);
	Main_u16ModeCounter = 0u;
}

void EXTI3_IRQHandler(void)
{
	Main_u8ModeFlag = 2u;
	TFT_voidDisplayImage(Image_u16MohamedMounirArr);
	EXTI_voidClearPendingFlag(EXTI_LINE_3);
	Main_u16ModeCounter = 0u;
}
