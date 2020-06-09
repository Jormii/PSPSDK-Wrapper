#include "LinkedList.h"
#include <stdio.h>

void print_bytes(unsigned char *address, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%.2x", address[i]);
    }
}

int main()
{
    LinkedList *list = NULL;
    ll_initialize(&list, 10);

    for (int i = 0; i < 7; ++i)
    {
        int code = ll_append(list, (void *)(&i), sizeof(int));
        if (code != LL_NO_ERRORS)
        {
            printf("Couldn't add %d to the list. Error: %d\n", i, code);
        }
    }

    ll_remove(list, 0);
    ll_remove(list, 0);
    ll_remove(list, 1);
    ll_remove(list, list->count - 2);
    ll_remove(list, list->count - 1);
    ll_remove(list, list->count - 1);

    char *string = "The Game";
    ll_append(list, (void *)string, 9);

    LinkedListNode *node = list->head;
    for (int i = 0; i < list->count; ++i)
    {
        printf("Data: ");
        unsigned char *address = (unsigned char *)(node->data);
        print_bytes(address, node->data_size);
        printf("\n");
        node = node->next;
    }

    LinkedListNode *node_ptr = 0;
    ll_get(list, 0, &node_ptr);
    print_bytes((unsigned char *)(node_ptr->data), node_ptr->data_size);
    printf("\n");

    printf("%s\n", (char *)(list->tail->data));
    ll_destroy(&list);

    return 0;
}