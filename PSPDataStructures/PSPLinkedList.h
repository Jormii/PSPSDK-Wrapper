#ifndef PSP_LINKED_LIST_H
#define PSP_LINKED_LIST_H

typedef unsigned long size_t;

typedef struct PSPListNode
{
    PSPListNode *next;
    void *data;
    size_t data_size;
} PSPListNode;

void initialize_list(PSPListNode *list_head);
PSPListNode *list_add_node(PSPListNode *list_head, void *data, size_t data_size, int position);
PSPListNode *list_add_node_front(PSPListNode *list_head, void *data, size_t data_size);
PSPListNode *list_add_node_back(PSPListNode *list_head, void *data, size_t data_size);
int list_remove_node(PSPListNode *list_head, PSPListNode *node_to_remove);
int list_remove_front(PSPListNode *list_head);
int list_remove_back(PSPListNode *list_head);
PSPListNode *list_clear(PSPListNode *list_head);

#endif