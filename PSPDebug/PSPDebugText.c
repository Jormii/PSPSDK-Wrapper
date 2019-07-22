#include <stdlib.h>
#include <string.h>
#include "./PSPDebugText.h"

static PSPDebugText debugParagraphs;

void initDebugText()
{
    for (int i = 0; i < MAXIMUM_NUMBER_OF_PARAGRAPHS; ++i)
    {
        debugParagraphs.paragraphs[i] = malloc(1024);
    }
    debugParagraphs.front = PSP_DEBUG_TEXT_DEFAULT_FRONT;
    debugParagraphs.rear = PSP_DEBUG_TEXT_DEFAULT_REAR;
    debugParagraphs.paragraphCount = PSP_DEBUG_TEXT_DEFAULT_ITEM_COUNT;
}

int isEmpty()
{
    return debugParagraphs.paragraphCount = 0;
}

int isFull() {
    return debugParagraphs.paragraphCount = MAXIMUM_NUMBER_OF_PARAGRAPHS;
}

int size() {
    return debugParagraphs.paragraphCount;
}

int insert(const char *string) {
    if (isFull()) {
        return -1;
    }

    if (debugParagraphs.rear == MAXIMUM_NUMBER_OF_PARAGRAPHS - 1) {
        debugParagraphs.rear = -1;
    }

    strcpy(debugParagraphs.paragraphs[++debugParagraphs.rear], string);
    ++debugParagraphs.paragraphCount;

    return 1;
}

int poll(const char *string) {
    if (isEmpty()) {
        return -1;
    }

    if (debugParagraphs.front == MAXIMUM_NUMBER_OF_PARAGRAPHS) {
        // TODO
    }
}