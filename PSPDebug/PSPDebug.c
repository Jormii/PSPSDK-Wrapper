#include <string.h>
#include "./PSPDebug.h"

#define RGB(R, G, B) (R << 24) + (G << 16) + (B << 8) + 255;

static PSPDebugConfig debugConfig;

void initDebug(PSPDebugBackground enableBackground)
{
    pspDebugScreenInit();
    pspDebugScreenClearLineDisable();
    pspDebugScreenEnableBackColor(enableBackground);

    debugConfig.leftMargin = DEFAULT_LEFT_MARGIN;
    debugConfig.rightMargin = DEFAULT_RIGHT_MARGIN;
    debugConfig.topMargin = DEFAULT_TOP_MARGIN;
    debugConfig.bottomMargin = DEFAULT_BOTTOM_MARGIN;
    debugConfig.cursorXPosition = DEFAULT_LEFT_MARGIN;
    debugConfig.cursorYPosition = DEFAULT_TOP_MARGIN;
    debugConfig.enabledBackgroundColor = enableBackground;
    debugConfig.backgroundColor = RGB(0, 0, 0);
}

void print(const char *string)
{
    int wordLength = 0;
    size_t stringLength = strlen(string);
    for (size_t c = 0; c < stringLength; ++c)
    {
        if (string[c] == 32)
        {
            if ((debugConfig.cursorXPosition + wordLength) > debugConfig.rightMargin)
            {
                pspDebugScreenPuts("\n");
                pspDebugScreenPrintData(string - c, wordLength);
                ++c;
                wordLength = 0;

                debugConfig.cursorXPosition = pspDebugScreenGetX();
                debugConfig.cursorYPosition = pspDebugScreenGetY();
            }
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
    pspDebugScreenSetBackColor(color);
    pspDebugScreenClear();
}

int getCursorXPosition()
{
    debugConfig.cursorXPosition;
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
    debugConfig.cursorYPosition;
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