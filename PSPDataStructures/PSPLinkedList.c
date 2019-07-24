#include "./PSPLinkedList.h"

void initializeList(PSPListNode *listHead)
{
    listHead->next = NULL;
    listHead->data = NULL;
    listHead->dataSize = 0;
}

PSPListNode *listAddNode(PSPListNode *listHead, void *data, size_t dataSize, int position)
{
}

PSPListNode *listAddNodeFront(PSPListNode *listHead, void *data, size_t dataSize)
{
    if (listHead->data == NULL) {
        
    }
}

PSPListNode *listAddNodeBack(PSPListNode *listHead, void *data, size_t dataSize)
{
}

int listRemoveNode(PSPListNode *listHead, PSPListNode *nodeToRemove)
{
}

int listRemoveFront(PSPListNode *listHead)
{
}

int listRemoveBack(PSPListNode *listHead)
{
}

PSPListNode *listClear(PSPListNode *listHead)
{
}