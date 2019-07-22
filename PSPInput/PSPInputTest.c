#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>

#include "../common/callback.h"
#include "./PSPInput.h"

PSP_MODULE_INFO("Button Input", PSP_MODULE_USER, 1, 1);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

#define printf pspDebugScreenPrintf

int main()
{
    pspDebugScreenInit();
    setupExitCallback();

    pspDebugScreenSetXY(1, 1);
    printf("[ DEBUG ]\n\n");

    initInput(ANALOG_SAMPLING);
    updateInput();
    if (discIsPresent())
    {
        printf("DISC_IS_PRESSENT\n");
    }
    if (memoryStickIsConnected())
    {
        printf("MEMORY_STICK_CONNECTED\n");
    }
    while (isRunning())
    {
        updateInput();

        if (getButton(CROSS_BUTTON))
        {
            printf("CROSS BUTTON IS DOWN\n");
        }
        if (getButtonDown(CROSS_BUTTON))
        {
            printf("CROSS BUTTON PRESSED\n");
        }
        if (getButtonUp(CROSS_BUTTON))
        {
            printf("CROSS BUTTON RELEASED\n");
        }

        sceDisplayWaitVblankStart();
    }

    sceKernelExitGame();
    return 0;
}