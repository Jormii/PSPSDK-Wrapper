#include <stdlib.h>

#include "./PSPMemoryManagement.h"

void *PSPMalloc(size_t size)
{
    return malloc(size);
}