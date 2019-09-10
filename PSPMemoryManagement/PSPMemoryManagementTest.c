#include <pspkernel.h>
#include <string.h>

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
    strcpy(string, "AAA\n");
    debug_print(string);
    debug_print("IT WORKS?!");

    while (isRunning())
    {
        update_input();
    }

    sceKernelExitGame();
    return 0;
}