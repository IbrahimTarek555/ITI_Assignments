#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/**
 * @brief Enum which carries the interrupt vector table position, only for the EXT peripherals (system exceptions are not here).
 */
typedef enum
{
	NVIC_WWDG,              /**< NVIC_WWDG */
	NVIC_EXTI16,            /**< NVIC_EXTI16 */
	NVIC_EXTI21,            /**< NVIC_EXTI21 */
	NVIC_EXTI22,            /**< NVIC_EXTI22 */
	NVIC_FLASH,             /**< NVIC_FLASH */
	NVIC_RCC,               /**< NVIC_RCC */
	NVIC_EXTI0,             /**< NVIC_EXTI0 */
	NVIC_EXTI1,             /**< NVIC_EXTI1 */
	NVIC_EXTI2,             /**< NVIC_EXTI2 */
	NVIC_EXTI3,             /**< NVIC_EXTI3 */
	NVIC_EXTI4,             /**< NVIC_EXTI4 */
	NVIC_DMA1_STREAM0,      /**< NVIC_DMA1_STREAM0 */
	NVIC_DMA1_STREAM1,      /**< NVIC_DMA1_STREAM1 */
	NVIC_DMA1_STREAM2,      /**< NVIC_DMA1_STREAM2 */
	NVIC_DMA1_STREAM3,      /**< NVIC_DMA1_STREAM3 */
	NVIC_DMA1_STREAM4,      /**< NVIC_DMA1_STREAM4 */
	NVIC_MNVIC_DMA1_STREAM5,/**< NVIC_MNVIC_DMA1_STREAM5 */
	NVIC_MNVIC_DMA1_STREAM6,/**< NVIC_MNVIC_DMA1_STREAM6 */
	NVIC_ADC,               /**< NVIC_ADC */
	NVIC_EXTI9,             /**< NVIC_EXTI9 */
	NVIC_EXTI8,             /**< NVIC_EXTI8 */
	NVIC_EXTI7,             /**< NVIC_EXTI7 */
	NVIC_EXTI6,             /**< NVIC_EXTI6 */
	NVIC_EXTI5,             /**< NVIC_EXTI5 */
	NVIC_TIM1_BRK_TIM9,     /**< NVIC_TIM1_BRK_TIM9 */
	NVIC_TIM1_UP,           /**< NVIC_TIM1_UP */
	NVIC_TIM1_TRG_COM_TIM11,/**< NVIC_TIM1_TRG_COM_TIM11 */
	NVIC_TIM1_CC,           /**< NVIC_TIM1_CC */
	NVIC_TIM2,              /**< NVIC_TIM2 */
	NVIC_TIM3,              /**< NVIC_TIM3 */
	NVIC_TIM4,              /**< NVIC_TIM4 */
	NVIC_I2C1_EV,           /**< NVIC_I2C1_EV */
	NVIC_I2C1_ER,           /**< NVIC_I2C1_ER */
	NVIC_I2C2_EV,           /**< NVIC_I2C2_EV */
	NVIC_I2C2_ER,           /**< NVIC_I2C2_ER */
	NVIC_SPI1,              /**< NVIC_SPI1 */
	NVIC_SPI2,              /**< NVIC_SPI2 */
	NVIC_USART1,            /**< NVIC_USART1 */
	NVIC_USART2,            /**< NVIC_USART2 */
	NVIC_EXTI15_10=40,      /**< NVIC_EXTI15_10 */
	NVIC_EXTI17_RTC_ALARM,  /**< NVIC_EXTI17_RTC_ALARM */
	NVIC_EXTI18_OTG_FS_WKUP,/**< NVIC_EXTI18_OTG_FS_WKUP */
	NVIC_DMA1_STREAM7=47,   /**< NVIC_DMA1_STREAM7 */
	NVIC_SDIO=49,           /**< NVIC_SDIO */
	NVIC_TIM5,              /**< NVIC_TIM5 */
	NVIC_SPI3,              /**< NVIC_SPI3 */
	NVIC_DMA2_STREAM0=56,   /**< NVIC_DMA2_STREAM0 */
	NVIC_DMA2_STREAM1,      /**< NVIC_DMA2_STREAM1 */
	NVIC_DMA2_STREAM2,      /**< NVIC_DMA2_STREAM2 */
	NVIC_DMA2_STREAM3,      /**< NVIC_DMA2_STREAM3 */
	NVIC_DMA2_STREAM4,      /**< NVIC_DMA2_STREAM4 */
	NVIC_OTG_FS=67,         /**< NVIC_OTG_FS */
	NVIC_DMA2_STREAM5,      /**< NVIC_DMA2_STREAM5 */
	NVIC_DMA2_STREAM6,      /**< NVIC_DMA2_STREAM6 */
	NVIC_DMA2_STREAM7,      /**< NVIC_DMA2_STREAM7 */
	NVIC_USART6,            /**< NVIC_USART6 */
	NVIC_I2C3_EV,           /**< NVIC_I2C3_EV */
	NVIC_I2C3_ER,           /**< NVIC_I2C3_ER */
	NVIC_FPU=81,            /**< NVIC_FPU */
	NVIC_POS_SPI4=84        /**< NVIC_POS_SPI4 */
}NVIC_VectorTablePos_t;


typedef enum
{
	NVIC_16GROUP_0SUB=3,
	NVIC_8GROUP_2SUB,
	NVIC_4GROUP_4SUB,
	NVIC_2GROUP_8SUB,
	NVIC_0GROUP_16SUB
}NVIC_PriorityGroupMode_t;


void NVIC_voidEnableInterrupt(NVIC_VectorTablePos_t Copy_enInterrupt);
void NVIC_voidDisableInterrupt(NVIC_VectorTablePos_t Copy_enInterrupt);
void NVIC_voidEnableInterruptPending(NVIC_VectorTablePos_t Copy_enInterrupt);
void NVIC_voidDisableInterruptPending(NVIC_VectorTablePos_t Copy_enInterrupt);
void NVIC_voidGetActiveFlag(NVIC_VectorTablePos_t Copy_enInterrupt, Defines_Status_t *Copy_penFlagState);
void NVIC_voidReadPendingFlag(NVIC_VectorTablePos_t Copy_enInterrupt, Defines_Status_t *Copy_penFlagState);
void NVIC_voidSetInterruptPriority(NVIC_VectorTablePos_t Copy_enInterrupt, uint8_t Copy_u8Group, uint8_t Copy_u8SubGroup);
void NVIC_voidSetInterruptGroupMode(NVIC_PriorityGroupMode_t Copy_enGroupMode);


#endif




