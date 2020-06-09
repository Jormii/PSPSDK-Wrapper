#include "../../utils/datastructures/LinkedList.h"
#include "../../PSPDebug/PSPDebug.h"

LinkedList list;
int i = 0;
int max = 10;

void psp_initialize()
{
    init_debug();
    ll_initialize(&list, 5);
}

void psp_main_loop()
{
    if (i < max)
    {
        int code = ll_append(&list, (void *)(&i), sizeof(int));
        if (code == LL_NO_ERRORS)
        {
            // LinkedListNode *tail = list.tail;
            // void *data = tail->data;

            // int *v = (int *)data;
            debug_print("Added a value into the list\n");
            // printf("Data: 0x%x\n", *v);
        }
        else
        {
            debug_print("Couldn't add value to the list\n");
            // printf("Couldn't add %d to the list. Error: %d\n", i, code);
        }
        i += 1;
    }
}

void psp_deinitialize()
{
    ll_destroy(&list);
}