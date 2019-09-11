#include <pspkernel.h>

#include "../../common/callback.h"
#include "../../PSPDebug/PSPDebug.h"

#define VERS 1
#define REVS 0

PSP_MODULE_INFO("HelloWorld", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

int main()
{
    init_debug();
    setupExitCallback();

    debug_print("Hello world\n");
    debug_print("~ PSPWrapper\n");

    while (isRunning())
    {
    }

    sceKernelExitGame();

    return 0;
}