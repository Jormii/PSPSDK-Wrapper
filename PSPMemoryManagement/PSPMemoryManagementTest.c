#include <pspkernel.h>
#include <string.h>
#include <stdlib.h>

#include "../common/callback.h"
#include "../PSPDebug/PSPDebug.h"
#include "../PSPInput/PSPInput.h"
#include "./PSPMemoryManagement.h"

PSP_MODULE_INFO("Button Input", PSP_MODULE_USER, 1, 1);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

int main()
{
    init_debug();
    init_input();
    setupExitCallback();

    debug_print("AA\n");

    char *string = PSPMalloc(20);
    sprintf(string, "Puntero al string %p\n", string);
    debug_print(string);

    while (isRunning())
    {
        debug_print("It just works\n");
        update_input();
    }

    sceKernelExitGame();
    return 0;
}