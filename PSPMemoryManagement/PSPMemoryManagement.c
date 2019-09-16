#include <stdlib.h>
#include <pspsysmem.h>

#include "./PSPMemoryManagement.h"

void *psp_malloc(size_t size)
{
    return malloc(size);
}

void *psp_calloc(size_t n_items, size_t item_size)
{
    return calloc(n_items, item_size);
}

void *psp_realloc(void *ptr, size_t size)
{
    return realloc(ptr, size);
}

void psp_free(void *ptr)
{
    free(ptr);
}

unsigned int psp_free_mem_size()
{
    return sceKernelTotalFreeMemSize();
}

unsigned int psp_largest_free_block()
{
    return sceKernelMaxFreeMemSize();
}