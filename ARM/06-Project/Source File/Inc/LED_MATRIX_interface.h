#ifndef LED_MATRIX_INTERFACE_H_
#define LED_MATRIX_INTERFACE_H_


void LED_MATRIX_voidInit(void);
void LED_MATRIX_voidDisableColumns(void);
void LED_MATRIX_voidSetRowVlaue(uint8_t Copy_u8RowValue);
void LED_MATRIX_voidDisplayAsynch(uint8_t Copy_u8Arr[]);
void LED_MATRIX_voidDisplaySynch(uint8_t Copy_u8Arr[]);

#endif




