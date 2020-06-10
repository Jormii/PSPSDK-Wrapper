MODULE_OBJS = ./LinkedListTest.o ../../PSPDebug/PSPDebug.o ../../utils/datastructures/LinkedList.o ../../utils/Memory.o

PSP_EBOOT_TITLE = PSPLinkedListTests
# PSP_EBOOT_ICON = ICON0.png (144x80 icon)
# PSP_EBOOT_PIC1 = PIC1.png (480x272 background)
# PSP_EBOOT_SND0 = SND0.at3

# Don't modify the following
MODULE_OBJS_ABS = $(abspath $(MODULE_OBJS))
OUTPUT_DIR = $(CURDIR)
EXTRA_TARGETS = EBOOT.PBP

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

clean:
	$(MAKE) -C ../../common clean