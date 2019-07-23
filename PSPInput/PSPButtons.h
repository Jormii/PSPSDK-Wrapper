#ifndef PSP_BUTTONS_H
#define PSP_BUTTONS_H

typedef enum PSPButton
{
    START_BUTTON = 0x000008,
    SELECT_BUTTON = 0x000001,
    UP_BUTTON = 0x000010,
    RIGHT_BUTTON = 0x000020,
    DOWN_BUTTON = 0x000040,
    LEFT_BUTTON = 0x000080,
    TRIANGLE_BUTTON = 0x001000,
    CIRCLE_BUTTON = 0x002000,
    CROSS_BUTTON = 0x004000,
    SQUARE_BUTTON = 0x008000,
    L_TRIGGER = 0x000100,
    R_TRIGGER = 0x000200
} PSPButton;

typedef struct PSPButtonsData
{
    unsigned int buttons_pressed;
} PSPButtonsData;

#endif