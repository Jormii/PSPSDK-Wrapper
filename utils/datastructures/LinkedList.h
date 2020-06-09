#ifndef PSP_LINKED_LIST_H
#define PSP_LINKED_LIST_H

#define NO_ERRORS 0
#define ERROR_WRONG_INDEX -1
#define ERROR_REACHED_MAX_COUNT -2
#define ERROR_REMOVING_NULL_NODE -3

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

void initialize_linked_list(LinkedList **linked_list, int max_count);
void clear_linked_list(LinkedList *linked_list);
int add_linked_list(LinkedList *linked_list, void *data, unsigned long data_size);
int remove_linked_list(LinkedList *linked_list, int index);
void destroy_linked_list(LinkedList **linked_list);

int index_belongs_to_linked_list(LinkedList *linked_list, int index);

#endif