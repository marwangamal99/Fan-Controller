################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LM35.c \
../adc.c \
../dcmotor.c \
../gpio.c \
../lcd.c \
../main.c \
../pwm.c 

OBJS += \
./LM35.o \
./adc.o \
./dcmotor.o \
./gpio.o \
./lcd.o \
./main.o \
./pwm.o 

C_DEPS += \
./LM35.d \
./adc.d \
./dcmotor.d \
./gpio.d \
./lcd.d \
./main.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


