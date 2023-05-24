################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/startup_mk64f12.c 

C_DEPS += \
./startup/startup_mk64f12.d 

OBJS += \
./startup/startup_mk64f12.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DPRINTF_FLOAT_ENABLE=0 -DSCANF_FLOAT_ENABLE=0 -DPRINTF_ADVANCED_ENABLE=0 -DSCANF_ADVANCED_ENABLE=0 -DFRDM_K64F -DFREEDOM -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/kokssik/Documents/MCUXpresso_11.7.1_9221/workspace/frdmk64f_hello_world/source" -I"/home/kokssik/Documents/MCUXpresso_11.7.1_9221/workspace/frdmk64f_hello_world/utilities" -I"/home/kokssik/Documents/MCUXpresso_11.7.1_9221/workspace/frdmk64f_hello_world/drivers" -I"/home/kokssik/Documents/MCUXpresso_11.7.1_9221/workspace/frdmk64f_hello_world/device" -I"/home/kokssik/Documents/MCUXpresso_11.7.1_9221/workspace/frdmk64f_hello_world/component/uart" -I"/home/kokssik/Documents/MCUXpresso_11.7.1_9221/workspace/frdmk64f_hello_world/component/lists" -I"/home/kokssik/Documents/MCUXpresso_11.7.1_9221/workspace/frdmk64f_hello_world/CMSIS" -I"/home/kokssik/Documents/MCUXpresso_11.7.1_9221/workspace/frdmk64f_hello_world/board" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_mk64f12.d ./startup/startup_mk64f12.o

.PHONY: clean-startup

