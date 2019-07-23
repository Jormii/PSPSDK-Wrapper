#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>

#include "../common/callback.h"

#define VERS 1 //Talk about this
#define REVS 0

PSP_MODULE_INFO("Hello World", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

#define printf pspDebugScreenPrintf

int main(void)
{
    pspDebugScreenInit();
    pspDebugScreenClearLineDisable();
    setupExitCallback();

    int i;
    for (i = 0; i <= 45; ++i)
    {
        printf("%d\n", i);
        if (i >= 32)
        {
            pspDebugScreenSetXY(0, 32);
        }
    }

    while (isRunning())
    {
        sceDisplayWaitVblankStart();
    }

    sceKernelExitGame();

    return 0;
}