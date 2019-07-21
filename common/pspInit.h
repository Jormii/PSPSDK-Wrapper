#ifndef PSP_INIT_H
#define PSP_INIT_H

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>

#include "../common/callback.h"

#define printf pspDebugScreenPrintf

#define VERS 1
#define REVS 1

PSP_MODULE_INFO("Button Input", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

void initPSP();

#endif