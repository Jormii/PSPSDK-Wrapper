TARGET = PSPMemoryManagementTest
OBJS = ./PSPMemoryManagementTest.o ../../PSPMemoryManagement/PSPMemoryManagement.o ../../PSPDebug/PSPDebug.o ../../common/callbacks.o

INCDIR =
CFLAGS = -G0 -O2 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS  = $(CFLAGS)

LIBDIR = ./
LDFLAGS =
LIBS = -lm

BUILD_PRX = 1 

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = PSPMemoryManagementTest
# PSP_EBOOT_ICON= ICON0.png
# PSP_EBOOT_PIC1= PIC1.png
# PSP_EBOOT_SND0= SND0.at3

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak