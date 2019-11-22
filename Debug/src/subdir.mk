################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/2doParcialLabo.c \
../src/Cachorros.c \
../src/Controller.c \
../src/Extras.c \
../src/LinkedList.c \
../src/parser.c 

OBJS += \
./src/2doParcialLabo.o \
./src/Cachorros.o \
./src/Controller.o \
./src/Extras.o \
./src/LinkedList.o \
./src/parser.o 

C_DEPS += \
./src/2doParcialLabo.d \
./src/Cachorros.d \
./src/Controller.d \
./src/Extras.d \
./src/LinkedList.d \
./src/parser.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


