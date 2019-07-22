#ifndef PSP_DEBUG_TEXT_H
#define PSP_DEBUG_TEXT_H

#define MAXIMUM_NUMBER_OF_PARAGRAPHS 5
#define PSP_DEBUG_TEXT_DEFAULT_FRONT 0
#define PSP_DEBUG_TEXT_DEFAULT_REAR -1
#define PSP_DEBUG_TEXT_DEFAULT_ITEM_COUNT 0

typedef struct PSPDebugText {
    char *paragraphs[MAXIMUM_NUMBER_OF_PARAGRAPHS];
    int front;
    int rear;
    int paragraphCount;
} PSPDebugText;

void initDebugText();
int isEmpty();
int isFull();
int size();
int insert(const char *string);
int poll();

int insert(const char *string)
{

    if (!isFull())
    {

        if (rear == MAX - 1)
        {
            rear = -1;
        }

        intArray[++rear] = data;
        paragraphCount
++;
    }
}

int removeData()
{
    int data = intArray[front++];

    if (front == MAX)
    {
        front = 0;
    }

    paragraphCount--;
    return data;
}

#endif