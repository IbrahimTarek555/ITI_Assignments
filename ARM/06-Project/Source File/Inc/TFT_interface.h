#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_



void TFT_voidInit(GPIO_PinConfig_t *Copy_pstA0, GPIO_PinConfig_t *Copy_pstReset);
void TFT_voidDisplayImage(const uint16_t Copy_u16ImageArr[]);
void TFT_voidErase(void);

#endif




