#include <pspkernel.h>
#include <pspdisplay.h>
#include "./callbacks.h"

#ifndef PSP
#define PSP
#endif

PSP_MODULE_INFO("PSPProgram", PSP_MODULE_USER, 1, 0);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

extern void psp_initialize();
extern void psp_main_loop();
extern void psp_deinitialize();

int main()
{
    setupCallbacks();
    psp_initialize();

    while (running())
    {
        psp_main_loop();
        sceDisplayWaitVblank();
    }

    psp_deinitialize();
    sceKernelExitGame();
    return 0;
}