#ifndef PSP_DEBUG_H
#define PSP_DEBUG_H

#include <pspdebug.h>

typedef enum PSPDebugBackground
{
    DISABLED_BACKGROUND_COLOR,
    ENABLED_BACKGROUND_COLOR
} PSPDebugBackground;

typedef struct PSPDebugData
{
    int leftMargin;
    int rightMargin;
    int topMargin;
    int bottomMargin;
    int cursorXPosition;
    int cursorYPosition;

    int enabledBackgroundColor;
    u32 backgroundColor;
} PSPDebugData;

void initDebug(PSPDebugBackground enableBackground);
void print(const char *string);
void clearScreen();
void setTextColor(u8 R, u8 G, u8 B);
void setBackgroundColor(u8 R, u8 G, u8 B);
int getCursorXPosition();
int getCursorYPosition();
void setCursorPosition(int x, int y);
int getLeftMargin();
void setLeftMargin(int x);
int getRightMargin();
void setRightMargin(int x);
int getTopMargin();
void setTopMargin(int y);
int getBottomMargin();
void setBottomMargin(int y);

#endif