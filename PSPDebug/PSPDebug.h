#ifndef PSP_DEBUG_H
#define PSP_DEBUG_H

#include <pspdebug.h>

#define LINES_CAPACITY_VERTICAL 33
#define CHAR_CAPACITY_HORIZONTAL 69

#define DEFAULT_LEFT_MARGIN 1
#define DEFAULT_RIGHT_MARGIN CHAR_CAPACITY_HORIZONTAL - 1
#define DEFAULT_TOP_MARGIN 1
#define DEFAULT_BOTTOM_MARGIN LINES_CAPACITY_VERTICAL - 1

typedef enum PSPDebugBackground
{
    DISABLED_BACKGROUND_COLOR,
    ENABLED_BACKGROUND_COLOR
} PSPDebugBackground;

typedef struct PSPDebugConfig
{
    int leftMargin;
    int rightMargin;
    int topMargin;
    int bottomMargin;
    int cursorXPosition;
    int cursorYPosition;

    int enabledBackgroundColor;
    u32 backgroundColor;
} PSPDebugConfig;

void initDebug(PSPDebugBackground enableBackground);
void print(const char *string);
void clearScreen();
void setTextColor(u8 R, u8 G, u8 B);
void setBackgroundColor(u8 R, u8 G, u8 B);

int getCursorXPosition();
void setCursorXPosition(int x);
int getCursorYPosition();
void setCursorYPosition(int y);
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