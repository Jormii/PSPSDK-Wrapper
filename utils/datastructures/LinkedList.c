#include <stdlib.h>
#include <string.h>

#include "./LinkedList.h"

void ll_initialize(LinkedList **linked_list, int max_count)
{
    (*linked_list) = (LinkedList *)malloc(sizeof(LinkedList));
    (*linked_list)->head = NULL;
    (*linked_list)->tail = NULL;
    (*linked_list)->count = 0;
    (*linked_list)->max_count = max_count;
    (*linked_list)->total_size = 0;
}

void ll_clear(LinkedList *linked_list)
{
    LinkedListNode *node = linked_list->head;
    while (node->next != NULL)
    {
        LinkedListNode *next_node = node->next;

        free(node->data);
        free(node);

        node = next_node;
    }

    linked_list->head = NULL;
    linked_list->tail = NULL;
    linked_list->count = 0;
    linked_list->total_size = 0;
}

int ll_append(LinkedList *linked_list, void *data, unsigned long data_size)
{
    if (linked_list->count == linked_list->max_count)
    {
        return LL_ERROR_REACHED_MAX_COUNT;
    }

    // Create new node
    LinkedListNode *node = (LinkedListNode *)malloc(sizeof(LinkedListNode));

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

    return LL_NO_ERRORS;
}

int ll_remove(LinkedList *linked_list, int index)
{
    if (!ll_valid_index(linked_list, index))
    {
        return LL_ERROR_WRONG_INDEX;
    }

    LinkedListNode *previous_node = NULL;
    LinkedListNode *node = linked_list->head;

    int i;
    for (i = 0; i < index; ++i)
    {
        previous_node = node;
        node = previous_node->next;
    }

    int index_is_head = index == 0;
    int index_is_tail = index == (linked_list->count - 1);
    if (index_is_head && index_is_tail)
    {
        linked_list->head = NULL;
        linked_list->tail = NULL;
    }
    else if (index_is_head)
    {
        linked_list->head = node->next;
    }
    else if (index_is_tail)
    {
        previous_node->next = NULL;
        linked_list->tail = previous_node;
    }
    else
    {
        previous_node->next = node->next;
    }

    linked_list->count -= 1;
    linked_list->total_size -= node->data_size;
    free(node->data);
    free(node);

    return LL_NO_ERRORS;
}

int ll_get(LinkedList *linked_list, int index, LinkedListNode **node_ptr)
{
    if (!ll_valid_index(linked_list, index))
    {
        return LL_ERROR_WRONG_INDEX;
    }

    LinkedListNode *node = linked_list->head;
    int i;
    for (i = 0; i < index; ++i)
    {
        node = node->next;
    }

    *(node_ptr) = node;
    return LL_NO_ERRORS;
}

void ll_destroy(LinkedList **linked_list)
{
    ll_clear(*linked_list);
    free(*linked_list);

    *(linked_list) = NULL;
}

int ll_valid_index(LinkedList *linked_list, int index)
{
    return index >= 0 && index < linked_list->count;
}