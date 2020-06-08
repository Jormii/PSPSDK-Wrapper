#include "LinkedList.c" // TODO: .h
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
    LinkedList list;
    initialize_linked_list(&list, 10);

    for (int i = 0; i < 7; ++i)
    {
        int code = add_linked_list(&list, (void *)(&i), sizeof(int));
        if (code != NO_ERRORS)
        {
            printf("Couldn't add %d to the list. Error: %d\n", i, code);
        }
    }

    remove_linked_list(&list, 0);
    remove_linked_list(&list, 0);
    remove_linked_list(&list, 1);
    remove_linked_list(&list, list.count - 2);
    remove_linked_list(&list, list.count - 1);

    char *string = "The Game";
    add_linked_list(&list, (void *)string, 9);

    LinkedListNode *node = list.head;
    for (int i = 0; i < list.count; ++i)
    {
        printf("Data: ");
        unsigned char *address = (unsigned char *)(node->data);
        print_bytes(address, node->data_size);
        printf("\n");
        node = node->next;
    }

    printf("%s\n", (char *)(list.tail->data));
    destroy_linked_list(&list);

    return 0;
}