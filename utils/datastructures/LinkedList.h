#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define LL_NO_ERRORS 0
#define LL_ERROR_WRONG_INDEX -1
#define LL_ERROR_REACHED_MAX_COUNT -2

/* TODO: Functions yet to implement
    - int contains(e)
    - void remove(e)
*/

typedef struct LinkedListNode
{
    struct LinkedListNode *next;
    void *data;
    unsigned long data_size;
} LinkedListNode;

typedef struct LinkedList
{
    struct LinkedListNode *head;
    struct LinkedListNode *tail;
    int count;
    int max_count;
    unsigned long total_size;
} LinkedList;

void ll_initialize(LinkedList **linked_list, int max_count);
void ll_clear(LinkedList *linked_list);
int ll_append(LinkedList *linked_list, void *data, unsigned long data_size);
int ll_remove(LinkedList *linked_list, int index);
int ll_get(LinkedList *linked_list, int index, LinkedListNode **node_ptr);
void ll_destroy(LinkedList **linked_list);

int ll_valid_index(LinkedList *linked_list, int index);

#endif