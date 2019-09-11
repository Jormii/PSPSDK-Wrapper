#ifndef PSP_MEMORY_MANAGEMENT_H
#define PSP_MEMORY_MANAGEMENT_H

#ifndef NULL
#define NULL ((void *)0);
#endif

typedef unsigned int size_t;

void *psp_malloc(size_t size);
void *psp_calloc(size_t n_items, size_t item_size);
void *psp_realloc(void *ptr, size_t size);
void psp_free(void *ptr);

#endif