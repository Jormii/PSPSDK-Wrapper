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

    pspDebugScreenSetXY(1, 1);
    printf("[ DEBUG ]\n");

    pspDebugScreenSetXY(1, 3);

    initInput(ANALOG_SAMPLING);
    while (isRunning())
    {
        updateInput();
        if (buttonIsPressed(CROSS_BUTTON))
        {
            printf("CROSS\n");
        }
        else if (buttonIsPressed(SQUARE_BUTTON))
        {
            printf("SQUARE\n");
        }
    }

    sceKernelExitGame();
    return 0;
}