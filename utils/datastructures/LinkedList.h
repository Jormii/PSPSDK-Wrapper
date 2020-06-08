#ifndef PSP_LINKED_LIST_H
#define PSP_LINKED_LIST_H

#define NO_ERRORS 0
#define ERROR_REACHED_MAX_COUNT -1

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

/*
Functions yet to implement:
    - int contains(e)
    - e get(index)
    - void remove(e)
*/

void initialize_linked_list(LinkedList *linked_list, int max_count);
void clear_linked_list(LinkedList *linked_list);
int add_linked_list(LinkedList *linked_list, void *data, unsigned long data_size);
void remove_linked_list(LinkedList *linked_list, int index);
void destroy_linked_list(LinkedList *linked_list);

#endif