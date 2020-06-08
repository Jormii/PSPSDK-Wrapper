#include <stdlib.h>
#include <pspsysmem.h>

#include "./PSPMemoryManagement.h"

unsigned int psp_free_mem_size()
{
    return sceKernelTotalFreeMemSize();
}

unsigned int psp_largest_free_block()
{
    return sceKernelMaxFreeMemSize();
}