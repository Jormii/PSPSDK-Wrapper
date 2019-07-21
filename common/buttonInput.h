#ifndef BUTTON_INPUT_H
#define BUTTON_INPUT_H

#include <pspctrl.h>

#define MEMORY_STICK PSP_CTRL_MS;

typedef enum PSPButton
{
    START = PSP_CTRL_START,
    SELECT = PSP_CTRL_SELECT,
    HOME = PSP_CTRL_HOME,

    UP = PSP_CTRL_UP,
    RIGHT = PSP_CTRL_RIGHT,
    DOWN = PSP_CTRL_DOWN,
    LEFT = PSP_CTRL_LEFT,

    TRIANGLE = PSP_CTRL_TRIANGLE,
    CIRCLE = PSP_CTRL_CIRCLE,
    CROSS = PSP_CTRL_CROSS,
    SQUARE = PSP_CTRL_SQUARE,

    L_TRIGGER = PSP_CTRL_LTRIGGER,
    R_TRIGGER = PSP_CTRL_RTRIGGER
} PSPButton;

typedef enum SampleMode
{
    ANALOG = PSP_CTRL_MODE_ANALOG,
    DIGITAL = PSP_CTRL_MODE_DIGITAL
} SampleMode;

static SceCtrlData controllerData;

void initButtons(SampleMode samplingMode);
void updateButtons();
int buttonPressed(PSPButton button);

#endif