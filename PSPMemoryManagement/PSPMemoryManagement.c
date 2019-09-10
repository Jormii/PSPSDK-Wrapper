#include <stdlib.h>

#include "./PSPMemoryManagement.h"

void *psp_malloc(size_t size)
{
    return malloc(size);
}

void *psp_calloc(size_t n_items, size_t item_size)
{
    return calloc(n_items, item_size);
}

void *psp_realloc(void *pointer, size_t size)
{
    return realloc(pointer, size);
}

void psp_free(void *pointer)
{
    free(pointer);
}