#include "../../PSPDebug/PSPDebug.h"

void psp_initialization()
{
    init_debug();
}

void psp_main_loop()
{
    clear_screen();
    debug_print("Ay LMAO");
}

void psp_deinitialize()
{
}