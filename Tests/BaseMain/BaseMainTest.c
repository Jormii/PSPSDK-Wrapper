#include "../../PSPDebug/PSPDebug.h"

int i = 0;
int max = 100;

void psp_initialize()
{
    init_debug();
    debug_print("AY LMAO");
}

void psp_main_loop()
{
    if (i < max)
    {
        debug_print("o");
        i += 1;
    }
}

void psp_deinitialize()
{
}