################################################################################
# Edit avrdude parameters only if necessary line 78
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AVR_USART.lss \

FLASH_IMAGE += \
AVR_USART.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: AVR_USART.elf secondary-outputs

# Tool invocations
AVR_USART.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVR_USART.map -mmcu=atmega328p -o "AVR_USART.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVR_USART.lss: AVR_USART.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVR_USART.elf  >"AVR_USART.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVR_USART.hex: AVR_USART.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVR_USART.elf  "AVR_USART.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVR_USART.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p AVR_USART.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: AVR_USART.elf
	@echo 'Invoking: AVRDude'
	/usr/bin/avrdude -pm328p -carduino -P/dev/ttyACM0 -b115200 -Uflash:w:AVR_USART.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVR_USART.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
