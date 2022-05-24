#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#*****************************************************************************
# Final Course submission makefile.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <file>.i --> this rule generates the intermediate file outputted from preprocessor from the corresponding C file, it also generates the dependecy .d file
#      <file>.asm --> generates the assembly file from the corresponding C file
#      <file>.o --> compiles all the source files and generates the corresponding object file
#      compile-all --> compiles all the src files without linking and generates the corresponding object files
#      build --> links the object files into one executable file named c1m2.out and generates the memory map of the executable, it also shows a brief information about the output code size on the CLI 
#      clean --> removes all the generated files whether .i, .o, .d, .map, .s, .out
#*****************************************************************************
include sources.mk

# Platform Overrides
BASENAME = course1
 
# Architecture Flags
ifeq ($(PLATFORM), MSP432)
	LINKER_FILE = -T msp432p401r.lds 
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
else
	CPU = x86_64
	ARCH:=$(shell arch)
endif 

# Compiler Flags
ifeq ($(PLATFORM), MSP432)
	LD = arm-none-eabi-ld
	CC = arm-none-eabi-gcc
	LDFLAGS = -Wl,-Map=$(BASENAME).map $(LINKER_FILE) 
	#	-Wl,option: Pass option as an option to the linker. 
	#	ex:-Wl,-Map,main.map passes -Map main.map to the linker.
	CFLAGS = -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb -Wall -O0 -g -std=c99
	# -Werror: Warnings are treated as compilation errors. 
	# -Wall: Enable all warnings.
	# -O0: Reduce compilation time and make debugging produce the expected results. This is the default.    
	CPPFLAGs = -M -MF test.d
	DEFINEFLAG = -DMSP432
else
	LDFLAGS = -Wl,-Map=$(BASENAME).map
	CC = gcc
	CFLAGS = -Wall -O0 -g -std=c99
	CPPFLAGs = -M -MF test2.d
	DEFINEFLAG = -DHOST
endif

ifeq ($(VERBOSE), TRUE)
	CFLAGS += -DVERBOSE
endif

ifeq ($(COURSE1), TRUE)
	CFLAGS += -DCOURSE1
endif

# More Declared Variables
OBJS:= $(SOURCES:.c=.o)
ASMS:= $(SOURCES:.c=.s)
PPS:= $(SOURCES:.c=.i)
MAPS:= $(SOURCES:.c=.map)
OUTS:= $(SOURCES:.c=.out)

#*****************************************************************************
# Target: <file>.i
# Prerequisites: the .c file
# Output: the .d as well as .i files
#*****************************************************************************
%.i : %.c
	$(CC) $(CPPFLAGs) $(DEFINEFLAG) $<
	$(CC) $(DEFINEFLAG) -E -o $@ $<
#$(CC) $(CPPFLAGs) -E -o $@ $< 
### -E: Stop after the preprocessing stage; do not run the compiler proper. The output is in the form of preprocessed source code, which is sent to the standard output. 

#*****************************************************************************
# Target: <file>.asm
# Prerequisites: the .c file
# Output: the .asm file whether from the .c file or the object file
#*****************************************************************************
%.asm : %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) -S $<
	objdump $(OBJS) -D
# -S: Stop after the stage of compilation and do not assemble.

#*****************************************************************************
# Target: <file>.o
# Prerequisites: the .c file
# Output: the .o file corresponding to the provided .c file
#*****************************************************************************
%.o : %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) -c $<

#*****************************************************************************
# Target: compile-all
# Prerequisites: the source files
# Output: all source files are compiled but without linking and their corresponding .o files are generated
#*****************************************************************************
.PHONY: compile-all
compile-all: $(SOURCES)
#$(OBJS): $(SOURCES)
	$(CC) $(DEFINEFLAG) $(CFLAGS) -c $(SOURCES) -lm

#*****************************************************************************
# Target: build
# Prerequisites: the main.out file
# Output: the final executable file after linking and a brief report regarding the application size
#*****************************************************************************
.PHONY: build
build: $(OUTS)
	$(OUTS): $(SOURCES)
	$(CC) $(DEFINEFLAG) $(CFLAGS) $(LDFLAGS) -o course1.out $^ -lm
	size -Atd course1.out

#*****************************************************************************
# Target: clean
# Prerequisites: None
# Output: all generated file are removed and the directory is cleaned for a new build
#*****************************************************************************
.PHONY: clean
clean:
#rm -f $(OBJS) main.out $(ASMS) $(PPS) $(MAPS)
	rm -f *.i *.d *.map *.s *.out *.o

