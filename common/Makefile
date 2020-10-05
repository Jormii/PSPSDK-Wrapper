TARGET = BaseMain
OBJS = $(MODULE_OBJS_ABS) ./Main.o ./callbacks.o

INCDIR =
CFLAGS = -G0 -Wall -O2
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti -fexceptions
ASFLAGS = $(CFLAGS)

LIBDIR = ./
LDFLAGS =
LIBS = -lm -lstdc++

BUILD_PRX = 1 

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

clean:
	$(shell mv $(wildcard *.elf) $(OUTPUT_DIR))
	$(shell mv $(wildcard *.SFO) $(OUTPUT_DIR))
	$(shell mv ./EBOOT.PBP $(OUTPUT_DIR))