#include <stdio.h>
#include <stdlib.h>

#include "../../PSPDebug/PSPDebug.h"
#include "../../utils/Memory.h"
#include "../../utils/datastructures/LinkedList.h"

void psp_initialize()
{
    init_debug();

    LinkedList *list = NULL;
    ll_initialize(&list, 10);
    int i;
    for (i = 0; i < 7; ++i)
    {
        int code = ll_append(list, (void *)&i, sizeof(int));

        int length = snprintf(NULL, 0, "Added %d to the list. Return code: %d\n", i, code);
        char *string = malloc(length + 1);
        sprintf(string, "Added %d to the list. Return code: %d\n", i, code);
        debug_print(string);
        free(string);
    }

    debug_print("\nRemoving some elements: Indeces: 0, 0, 1, L-2, L-1\n");
    ll_remove(list, 0);
    ll_remove(list, 0);
    ll_remove(list, 1);
    ll_remove(list, list->count - 2);
    ll_remove(list, list->count - 1);

    debug_print("Adding a string to the list\n");
    char *string = "The Game";
    ll_append(list, (void *)string, 9);

    debug_print("\nContent of the list:\n");
    LinkedListNode *node = list->head;
    for (i = 0; i < list->count; ++i)
    {
        unsigned char *address = (unsigned char *)(node->data);
        print_bytes(address, node->data_size);
        debug_print("\n");
        node = node->next;
    }

    debug_print("Retrieving second element:");
    LinkedListNode *node_ptr = NULL;
    ll_get(list, 1, &node_ptr);
    print_bytes((unsigned char *)(node_ptr->data), node_ptr->data_size);
    debug_print("\n");

    debug_print("Printing tail of the list:");
    int length = snprintf(NULL, 0, "%s\n", (char *)(list->tail->data));
    string = malloc(length + 1);
    sprintf(string, "%s\n", (char *)(list->tail->data));
    debug_print(string);
    free(string);

    ll_destroy(&list);
}

void psp_main_loop()
{
}

void psp_deinitialize()
{
}