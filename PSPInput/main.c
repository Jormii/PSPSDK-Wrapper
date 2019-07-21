#include <pspkernel.h>
#include <pspdebug.h>

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
    initInput(ANALOG_SAMPLING);

    pspDebugScreenSetXY(15, 15);
    printf("[ DEBUG ]");

    pspDebugScreenSetXY(15, 40);

    while (isRunning())
    {
        if (buttonIsPressed(CROSS_BUTTON))
        {
            printf("CROSS");
        }
        else if (buttonIsPressed(SQUARE_BUTTON))
        {
            printf("SQUARE");
        }
    }

    sceKernelExitGame();
    return 0;
}