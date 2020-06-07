TARGET = BaseMain
OBJS = $(MODULE_OBJS_ABS) ./BaseMain.o ./callbacks.o

INCDIR =
CFLAGS = -G0 -Wall -O2
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR = $(OUTPUT_DIR)
LDFLAGS =
LIBS = -lm

BUILD_PRX = 1 

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak