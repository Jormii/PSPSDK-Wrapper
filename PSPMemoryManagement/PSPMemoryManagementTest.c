#include <pspkernel.h>
#include <string.h>
#include <stdio.h>

#include "../common/callback.h"
#include "../PSPDebug/PSPDebug.h"
#include "./PSPMemoryManagement.h"

PSP_MODULE_INFO("Button Input", PSP_MODULE_USER, 1, 1);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

int main()
{
    init_debug();
    setupExitCallback();

    debug_print("[ Debug ]\n\n");

    char *first_string = psp_malloc(8);
    char *second_string = psp_malloc(8);
    char *third_string = psp_calloc(1, sizeof(char));

    char *aux_string = psp_malloc(50);
    sprintf(aux_string, "Pointer to first string: %p\n", first_string);
    debug_print(aux_string);
    sprintf(aux_string, "Pointer to second string: %p\n", second_string);
    debug_print(aux_string);
    sprintf(aux_string, "Pointer to third string: %p\n", third_string);
    debug_print(aux_string);

    first_string = psp_realloc(first_string, 1024);
    debug_print("After realloc\n");
    sprintf(aux_string, "Pointer to first string: %p\n", first_string);
    debug_print(aux_string);
    sprintf(aux_string, "Pointer to second string: %p\n", second_string);
    debug_print(aux_string);
    sprintf(aux_string, "Pointer to third string: %p\n", third_string);
    debug_print(aux_string);

    psp_free(first_string);
    psp_free(second_string);
    psp_free(third_string);
    debug_print("After free\n");
    sprintf(aux_string, "Pointer to first string: %p\n", first_string);
    debug_print(aux_string);
    sprintf(aux_string, "Pointer to second string: %p\n", second_string);
    debug_print(aux_string);
    sprintf(aux_string, "Pointer to third string: %p\n", third_string);
    debug_print(aux_string);

    while (isRunning())
    {
    }

    sceKernelExitGame();
    return 0;
}