#include <string.h>
#include "./PSPDebug.h"

#define RGB(R, G, B) (R << 24) + (G << 16) + (B << 8) + 255;

static PSPDebugData debugData;

void initDebug(PSPDebugBackground enableBackground)
{
    pspDebugScreenInit();
    pspDebugScreenEnableBackColor(enableBackground);

    debugData.leftMargin = 0;
    debugData.rightMargin = 10;
    debugData.topMargin = 0;
    debugData.bottomMargin = 10;
    debugData.cursorXPosition = 0;
    debugData.cursorYPosition = 0;
    debugData.enabledBackgroundColor = enableBackground;
    debugData.backgroundColor = RGB(0, 0, 0);
}

void print(const char *string)
{
    int wordLength = 0;
    size_t stringLength = strlen(string);
    for (size_t c = 0; c < stringLength; ++c)
    {
        if (string[c] == 32)
        {
            if ((debugData.cursorXPosition + wordLength) > debugData.rightMargin)
            {
                pspDebugScreenPuts("\n");
                pspDebugScreenPrintData(string - c, wordLength);
                ++c;
                wordLength = 0;

                debugData.cursorXPosition = pspDebugScreenGetX();
                debugData.cursorYPosition = pspDebugScreenGetY();
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
}

void setTextColor(u8 R, u8 G, u8 B)
{
}

void setBackgroundColor(u8 R, u8 G, u8 B)
{
}

int getCursorXPosition()
{
    debugData.cursorXPosition;
}

int getCursorYPosition()
{
    debugData.cursorYPosition;
}

void setCursorPosition(int x, int y)
{
    debugData.cursorXPosition = x;
    debugData.cursorYPosition = y;
    pspDebugScreenSetXY(x, y);
}

int getLeftMargin()
{
    return debugData.leftMargin;
}

void setLeftMargin(int x)
{
    debugData.leftMargin = x;
}

int getRightMargin()
{
    return debugData.rightMargin;
}

void setRightMargin(int x)
{
    debugData.rightMargin = x;
}

int getTopMargin()
{
    return debugData.topMargin;
}

void setTopMargin(int y)
{
    debugData.topMargin = y;
}

int getBottomMargin()
{
    return debugData.bottomMargin;
}

void setBottomMargin(int y)
{
    debugData.bottomMargin = y;
}