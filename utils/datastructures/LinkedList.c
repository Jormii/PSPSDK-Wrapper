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
    if (index > (linked_list->count - 1) || index < 0)
    {
        return;
    }

    LinkedListNode *removed_node;
    if (index == 0)
    {
        removed_node = linked_list->head;
        if (linked_list->count == 1)
        {
            linked_list->head = NULL;
            linked_list->tail = NULL;
        }
        else
        {
            LinkedListNode *new_head = removed_node->next;
            linked_list->head = new_head;
        }
    }
    else
    {
        LinkedListNode *previous_node = linked_list->head;
        LinkedListNode *node = previous_node->next;
        for (int i = 1; i < index; ++i)
        {
            node = node->next;
            previous_node = previous_node->next;
        }

        removed_node = node;
        LinkedListNode *next_node = node->next;
        previous_node->next = next_node;
        if (next_node == NULL)
        {
            linked_list->tail = previous_node;
        }
    }

    linked_list->count -= 1;
    linked_list->total_size -= removed_node->data_size;
    free(removed_node->data);
    free(removed_node);
}

void destroy_linked_list(LinkedList *linked_list)
{
    clear_linked_list(linked_list);
    free(linked_list);
}