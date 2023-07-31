/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: TWI_register.h		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file TWI_register.h
 * @author Ibrahim Tarek
 * @brief This file contains TWI module registers' memory locations.
 * @version 1.00
 */

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define TWBR			*((volatile uint8 *) 0x20)	/*TWI Bit Rate Register*/

#define TWCR			*((volatile uint8 *) 0x56)	/*TWI Control Register*/
#define TWCR_TWIE		0u							//TWI Interrupt Enable
#define TWCR_R			1u							//Reserved Bit
#define TWCR_TWEN		2u							//TWI Enable Bit
#define TWCR_TWWC		3u							//TWI Write Collision Flag
#define TWCR_TWSTO		4u							//TWI Stop Condition Bit
#define TWCR_TWSTA		5u							//TWI Start Condition Bit
#define TWCR_TWEA		6u							//TWI Enable Acknowledge Bit
#define TWCR_TWINT		7u							//TWI Interrupt Flag

#define TWSR			*((volatile uint8 *) 0x21)	/*TWI Status Register*/
#define TWSR_TWPS0		0u							//TWI Prescaler Bit 0
#define TWSR_TWPS1		1u							//TWI Prescaler Bit 1
#define TWSR_R			2u							//Reserved Bit
#define TWSR_TWS3		3u							//TWI Status Bit 3
#define TWSR_TWS4		4u							//TWI Status Bit 4
#define TWSR_TWS5		5u							//TWI Status Bit 5
#define TWSR_TWS6		6u							//TWI Status Bit 6
#define TWSR_TWS7		7u							//TWI Status Bit 7

#define TWDR			*((volatile uint8 *) 0x23)	/*TWI Data Register*/

#define TWAR			*((volatile uint8 *) 0x22)	/*TWI (Slave) Address Register*/
#define TWAR_TWGCE		0u							//TWI General Call Recognition Enable Bit
#define TWAR_TWA1		1u							//TWI (Slave) Address Register Bit 1
#define TWAR_TWA2		2u							//TWI (Slave) Address Register Bit 2
#define TWAR_TWA3		3u							//TWI (Slave) Address Register Bit 3
#define TWAR_TWA4		4u							//TWI (Slave) Address Register Bit 4
#define TWAR_TWA5		5u							//TWI (Slave) Address Register Bit 5
#define TWAR_TWA6		6u							//TWI (Slave) Address Register Bit 6

#endif
