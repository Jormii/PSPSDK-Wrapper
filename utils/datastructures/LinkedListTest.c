#include "LinkedList.h"
#include <stdio.h>

int main()
{
    LinkedList list;
    initialize_linked_list(&list, 5);

    for (int i = 0; i < 10; ++i)
    {
        int code = add_linked_list(&list, (void *)(&i), sizeof(int));
        if (code == NO_ERRORS)
        {
            LinkedListNode *tail = list.tail;
            void *data = tail->data;

            int *v = (int *)data;
            printf("Data: 0x%x\n", *v);
        }
        else
        {
            printf("Couldn't add %d to the list. Error: %d\n", i, code);
        }
    }

    return 0;
}