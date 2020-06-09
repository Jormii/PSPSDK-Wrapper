#include <stdio.h>
#include <stdlib.h>

#include "./Memory.h"
#include "../PSPDebug/PSPDebug.h"

void print_bytes(unsigned char *address, int size)
{
    int i;
#ifdef PSP
    for (i = 0; i < size; ++i)
    {
        int length = snprintf(NULL, 0, "%.2x", address[i]);
        char *string = malloc(length + 1);
        sprintf(string, "%.2x", address[i]);
        debug_print(string);
        free(string);
    }
#else
    for (i = 0; i < size; ++i)
    {
        printf("%.2x", address[i]);
    }
#endif
}