#ifndef PSP_LINKED_LIST_H
#define PSP_LINKED_LIST_H

#include <stdlib.h>

typedef struct PSPListNode
{
    PSPListNode *next;
    void *data;
    size_t dataSize;
} PSPListNode;

void initializeList(PSPListNode *listHead);
PSPListNode *listAddNode(PSPListNode *listHead, void *data, size_t dataSize, int position);
PSPListNode *listAddNodeFront(PSPListNode *listHead, void *data, size_t dataSize);
PSPListNode *listAddNodeBack(PSPListNode *listHead, void *data, size_t dataSize);
int listRemoveNode(PSPListNode *listHead, PSPListNode *nodeToRemove);
int listRemoveFront(PSPListNode *listHead);
int listRemoveBack(PSPListNode *listHead);
PSPListNode *listClear(PSPListNode *listHead);

#endif