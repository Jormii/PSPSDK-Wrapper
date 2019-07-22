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
    setupExitCallback();

    char characters[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    char c;
    for (c = '0'; c <= '{'; ++c)
    {
        printf("%c", characters[c % 10]);
    }

    while (isRunning())
    {
        sceDisplayWaitVblankStart();
    }

    sceKernelExitGame();

    return 0;
}