TARGET = GraphicsTest
OBJS = ./GraphicsTest.o ../../PSPGraphics/PSPGraphics.o ../../PSPDebug/PSPDebug.o ../../common/callbacks.o ../../common/vram.o

INCDIR =
CFLAGS = -G0 -Wall -O2
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =
LIBS= -lpspgu -lm

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = GraphicsTest

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
