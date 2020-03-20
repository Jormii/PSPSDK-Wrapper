#include <pspkernel.h>

#include "../../common/callbacks.h"
#include "../../PSPDebug/PSPDebug.h"
#include "../../PSPInput/PSPInput.h"

PSP_MODULE_INFO("PSPInputText", PSP_MODULE_USER, 1, 1);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

int main()
{
    init_debug();
    init_input();
    setupCallbacks();

    debug_print("[ Debug ]\n");
    debug_print("Note: This test only reacts to the X button\n\n");

    if (disc_is_present())
    {
        debug_print("DISC IS PRESENT\n");
    }

    if (memory_stick_is_connected())
    {
        debug_print("MEMORY STICK CONNECTED\n");
    }

    while (running())
    {
        update_input();

        if (get_button_down(CROSS_BUTTON))
        {
            debug_print("CROSS BUTTON PRESSED\n");
        }

        if (get_button(CROSS_BUTTON))
        {
            debug_print("CROSS BUTTON IS DOWN\n");
        }

        if (get_button_up(CROSS_BUTTON))
        {
            debug_print("CROSS BUTTON RELEASED\n");
        }
    }

    sceKernelExitGame();
    return 0;
}