#include <stdlib.h>
#include <string.h>

#include "./LinkedList.h"

void initialize_linked_list(LinkedList *linked_list, int max_count)
{
    linked_list->head = NULL;
    linked_list->tail = NULL;
    linked_list->count = 0;
    linked_list->max_count = max_count;
    linked_list->total_size = 0;
}

void clear_linked_list(LinkedList *linked_list)
{
    for (int i = 0; i < linked_list->count; ++i)
    {
        remove_linked_list(linked_list, i);
    }
}

int add_linked_list(LinkedList *linked_list, void *data, unsigned long data_size)
{
    if (linked_list->count == linked_list->max_count)
    {
        return ERROR_REACHED_MAX_COUNT;
    }

    // Create new node
    LinkedListNode *node = malloc(sizeof(LinkedListNode));

    void *data_copy = malloc(data_size);
    memcpy(data_copy, data, data_size);

    node->next = NULL;
    node->data = data_copy;
    node->data_size = data_size;

    // Append node to list
    if (linked_list->count == 0)
    {
        linked_list->head = node;
        linked_list->tail = node;
    }
    else
    {
        LinkedListNode *tail = linked_list->tail;
        tail->next = node;
        linked_list->tail = node;
    }

    // Update list variables
    linked_list->count += 1;
    linked_list->total_size += data_size;

    return NO_ERRORS;
}

void remove_linked_list(LinkedList *linked_list, int index)
{
}

void destroy_linked_list(LinkedList *linked_list)
{
}