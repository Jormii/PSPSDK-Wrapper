MODULE_OBJS = ./BaseMainTest.o ../../PSPDebug/PSPDebug.o

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = PSPBaseMainTest
# PSP_EBOOT_ICON = ICON0.png (144x80 icon)
# PSP_EBOOT_PIC1 = PIC1.png (480x272 background)
# PSP_EBOOT_SND0 = SND0.at3

# Don't modify the following
MODULE_OBJS_ABS = $(abspath $(MODULE_OBJS))
MAKEFILE_PATH = $(abspath $(lastword $(MAKEFILE_LIST)))
OUTPUT_DIR = $(abspath $(notdir $(patsubst %/,%,$(dir $(MAKEFILE_PATH)))))

export MODULE_OBJS_ABS
export OUTPUT_DIR
export EXTRA_TARGETS
export PSP_EBOOT_TITLE

ifdef PSP_EBOOT_ICON
export PSP_EBOOT_ICON
endif

ifdef PSP_EBOOT_PIC1
export PSP_EBOOT_PIC1
endif

ifdef PSP_EBOOT_SND0
export PSP_EBOOT_SND0
endif

make-main:
	$(MAKE) -C ../../common/ MAKEFLAGS=