# simple AVR Makefile
#
# written by rufusy idachi (http://github.com/rufusy)
# released to the public domain
# check license file

# Makefile
# targets:
#   all:    compiles the source code
#   test:   tests the isp connection to the mcu
#   flash:  writes compiled hex file to the mcu's flash memory
#   disasm: disassembles the code for debugging
#   clean:  removes all .hex, .elf, and .o files in the source code and library directories

# parameters (change this stuff accordingly)
# parameters (change this stuff accordingly)
# project name
PROJECTNAME = ADC
# Source files
# List C/C++/Assembly source files:
# (list all files to compile, e.g. 'a.c b.cpp as.S'):
# Use .cc, .cpp or .C suffix for C++ files, use .S 
# (NOT .s !!!) for assembly source code files.
PRJSRC = main.c gpio.c adc.c
# avr mcu
MCU = atmega328p
# mcu clock frequency
CLK = 16000000
# avr programmer (and port if necessary)
# e.g. PRG = usbtiny -or- PRG = arduino -P /dev/tty.usbmodem411
PRG = arduino -P /dev/ttyACM0
# fuse values for avr: low, high, and extended
# these values are from an Arduino Uno (ATMega328P)
LFU = 0xFF
HFU = 0xDE
EFU = 0x05

#################################################################################################
# \/ stuff nobody needs to worry about until such time that worrying about it is appropriate \/ #
#################################################################################################

# c flags
CFLAGS  = -Os -DF_CPU=$(CLK) -mmcu=$(MCU) 
# c++ flags
CPPFLAGS = 
# include path
INCLUDE := $(foreach dir, $(EXT), -I$(dir))


# executables
AVRDUDE = avrdude -c $(PRG) -p $(MCU)
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE    = avr-size --format=avr --mcu=$(MCU)
CC      = avr-gcc

#compile all files
all: 
	$(CC) $(CFLAGS) -o $(PROJECTNAME).o $(PRJSRC)
	#below line to be reveisted. it has problems
	#$(CC) $(CFLAGS) -o $(PROJECTNAME).elf $(PROJECTNAME).o
	$(OBJCOPY) -O ihex $(PROJECTNAME).o $(PROJECTNAME).hex
	
#test programmer connectivity
test:
	$(AVRDUDE) -v

#write hex file into the mcu
flash: all
	$(AVRDUDE) -U flash:w:$(PROJECTNAME).hex:i

#remove all object, hex & elf files
clean: 
	rm -f *.hex *.elf *.o

# write fuses to mcu
fuse:
	$(AVRDUDE) -U lfuse:w:$(LFU):m -U hfuse:w:$(HFU):m -U efuse:w:$(EFU):m




