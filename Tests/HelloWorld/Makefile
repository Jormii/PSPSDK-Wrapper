TARGET = HelloWorld
OBJS   = ./PSPHelloWorld.o ../../common/callbacks.o ../../PSPDebug/PSPDebug.o

INCDIR   =
CFLAGS   = -G0 -Wall -O2
CXXFLAGS = $(CFLAGS) -fno-rtti -fexceptions -fno-exceptions
ASFLAGS  = $(CFLAGS)

LIBDIR  =
LDFLAGS =
LIBS    = -lm -lstdc++

BUILD_PRX = 1 

EXTRA_TARGETS   = EBOOT.PBP
PSP_EBOOT_TITLE = HelloWorld
# PSP_EBOOT_ICON= ICON0.png
# PSP_EBOOT_PIC1= PIC1.png
# PSP_EBOOT_SND0= SND0.at3

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
