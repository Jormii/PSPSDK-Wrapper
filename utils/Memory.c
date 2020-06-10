#include <stdio.h>
#include <stdlib.h>

#include "./Memory.h"
#include "../PSPDebug/PSPDebug.h"

void print_bytes(unsigned char *address, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
#ifdef PSP
        debug_print("%.2x", address[i]);
#else
        printf("%.2x", address[i]);
#endif
    }
}