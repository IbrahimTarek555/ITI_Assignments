################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_program.c \
../DIO_program.c \
../GIE_program.c \
../IR_program.c \
../MOTOR_program.c \
../PORT_program.c \
../TIMERS_program.c \
../TWI_program.c \
../UART_program.c \
../ULTSONIC_program.c 

OBJS += \
./CLCD_program.o \
./DIO_program.o \
./GIE_program.o \
./IR_program.o \
./MOTOR_program.o \
./PORT_program.o \
./TIMERS_program.o \
./TWI_program.o \
./UART_program.o \
./ULTSONIC_program.o 

C_DEPS += \
./CLCD_program.d \
./DIO_program.d \
./GIE_program.d \
./IR_program.d \
./MOTOR_program.d \
./PORT_program.d \
./TIMERS_program.d \
./TWI_program.d \
./UART_program.d \
./ULTSONIC_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


