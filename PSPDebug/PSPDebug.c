#include <string.h>
#include "./PSPDebug.h"
#include "./PSPDebugText.h"

#define RGB(R, G, B) (R << 24) + (G << 16) + (B << 8) + 0;

static PSPDebugConfig debugConfig;

static void spaceCharacterFound(const char *word, size_t wordLength);
static void newLineCharacterFound(const char *word, size_t wordLength);
static void nullCharacterFound(const char *word, size_t wordLength);

static void spaceCharacterFound(const char *word, size_t wordLength)
{
    int newXCursorPosition = debugConfig.cursorXPosition + wordLength + 1;
    if (newXCursorPosition > debugConfig.rightMargin)
    {
        setCursorPosition(debugConfig.leftMargin, debugConfig.cursorYPosition + 1);
        newXCursorPosition = debugConfig.leftMargin + wordLength + 1;
    }
    pspDebugScreenPrintData(word, wordLength);
    pspDebugScreenPrintData(" ", 1);
    setCursorXPosition(newXCursorPosition);
}

static void newLineCharacterFound(const char *word, size_t wordLength)
{
}

static void nullCharacterFound(const char *word, size_t wordLength)
{
    spaceCharacterFound(word, wordLength);
}

void initDebug(PSPDebugBackground enableBackground)
{
    pspDebugScreenInit();
    pspDebugScreenClearLineDisable();
    pspDebugScreenEnableBackColor(enableBackground);

    debugConfig.leftMargin = DEFAULT_LEFT_MARGIN;
    debugConfig.rightMargin = DEFAULT_RIGHT_MARGIN;
    debugConfig.topMargin = DEFAULT_TOP_MARGIN;
    debugConfig.bottomMargin = DEFAULT_BOTTOM_MARGIN;
    setCursorPosition(DEFAULT_LEFT_MARGIN, DEFAULT_TOP_MARGIN);
    debugConfig.enabledBackgroundColor = enableBackground;
    setBackgroundColor(0, 0, 0);
}

void debugPrint(const char *string)
{
    int wordLength = 0;
    size_t stringLength = strlen(string) + 1;
    size_t c;
    for (c = 0; c < stringLength; ++c)
    {
        if (string[c] == ' ')
        {
            spaceCharacterFound(string + c - wordLength, wordLength);
            wordLength = 0;
        }
        else if (string[c] == '\n')
        {
            newLineCharacterFound(string + c - wordLength, wordLength);
            wordLength = 0;
        }
        else if (string[c] == '\0')
        {
            nullCharacterFound(string + c - wordLength, wordLength);
            wordLength = 0;
        }
        else
        {
            ++wordLength;
        }
    }
}

void clearScreen()
{
    pspDebugScreenClear();
}

void setTextColor(u8 R, u8 G, u8 B)
{
    u32 color = RGB(R, G, B);
    pspDebugScreenSetTextColor(color);
}

void setBackgroundColor(u8 R, u8 G, u8 B)
{
    u32 color = RGB(R, G, B);
    debugConfig.backgroundColor = color;
    pspDebugScreenSetBackColor(color);
    pspDebugScreenClear();
}

int getCursorXPosition()
{
    return debugConfig.cursorXPosition;
}

void setCursorXPosition(int x)
{
    if (x < debugConfig.leftMargin)
    {
        debugConfig.cursorXPosition = debugConfig.leftMargin;
    }
    else if (x > debugConfig.rightMargin)
    {
        debugConfig.cursorXPosition = debugConfig.rightMargin;
    }
    else
    {
        debugConfig.cursorXPosition = x;
    }

    pspDebugScreenSetXY(debugConfig.cursorXPosition, debugConfig.cursorYPosition);
}

int getCursorYPosition()
{
    return debugConfig.cursorYPosition;
}

void setCursorYPosition(int y)
{
    if (y < debugConfig.topMargin)
    {
        debugConfig.cursorYPosition = debugConfig.topMargin;
    }
    else if (y > debugConfig.bottomMargin)
    {
        debugConfig.cursorYPosition = debugConfig.bottomMargin;
    }
    else
    {
        debugConfig.cursorYPosition = y;
    }

    pspDebugScreenSetXY(debugConfig.cursorXPosition, debugConfig.cursorYPosition);
}

void setCursorPosition(int x, int y)
{
    setCursorXPosition(x);
    setCursorYPosition(y);
}

int getLeftMargin()
{
    return debugConfig.leftMargin;
}

void setLeftMargin(int x)
{
    if (x < DEFAULT_LEFT_MARGIN || x >= debugConfig.rightMargin)
    {
        return;
    }
    debugConfig.leftMargin = x;
}

int getRightMargin()
{
    return debugConfig.rightMargin;
}

void setRightMargin(int x)
{
    if (x <= debugConfig.leftMargin || x > DEFAULT_RIGHT_MARGIN)
    {
        return;
    }
    debugConfig.rightMargin = x;
}

int getTopMargin()
{
    return debugConfig.topMargin;
}

void setTopMargin(int y)
{
    if (y < DEFAULT_TOP_MARGIN || y >= debugConfig.bottomMargin)
    {
        return;
    }
    debugConfig.topMargin = y;
}

int getBottomMargin()
{
    return debugConfig.bottomMargin;
}

void setBottomMargin(int y)
{
    if (y <= debugConfig.topMargin || y > DEFAULT_BOTTOM_MARGIN)
    {
        return;
    }
    debugConfig.bottomMargin = y;
}