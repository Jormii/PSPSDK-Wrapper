#include <stdlib.h>
#include "./PSPInput.h"

static PSPInput thisFrameInput;
static PSPInput previousFrameInput;

static void swapInputs();

static void swapInputs()
{
    previousFrameInput.timeStamp = thisFrameInput.timeStamp;
    previousFrameInput.buttonsData.buttonsPressed = thisFrameInput.buttonsData.buttonsPressed;
    previousFrameInput.analogStickData.xAxis = thisFrameInput.analogStickData.xAxis;
    previousFrameInput.analogStickData.yAxis = thisFrameInput.analogStickData.yAxis;
    previousFrameInput.settingButtonsData.settingButtonsPressed = thisFrameInput.settingButtonsData.settingButtonsPressed;
}

void initInput(PSPAnalogStickSamplingMode samplingMode)
{
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(samplingMode);
}

void updateInput()
{
    SceCtrlData input;
    sceCtrlPeekBufferPositive(&input, 1);

    swapInputs();
    thisFrameInput.timeStamp = input.TimeStamp;
    thisFrameInput.buttonsData.buttonsPressed = input.Buttons;
    thisFrameInput.analogStickData.xAxis = input.Lx;
    thisFrameInput.analogStickData.yAxis = input.Ly;
    thisFrameInput.settingButtonsData.settingButtonsPressed = input.Buttons;
}

int buttonIsPressed(PSPButton button)
{
    return previousFrameInput.buttonsData.buttonsPressed & button &&
           !buttonIsHeldDown(button);
}

int buttonIsHeldDown(PSPButton button)
{
    return previousFrameInput.buttonsData.buttonsPressed & button &&
           thisFrameInput.buttonsData.buttonsPressed & button;
}

int settingButtonIsPressed(PSPSettingButton settingButton)
{
    return previousFrameInput.settingButtonsData.settingButtonsPressed & settingButton &&
           !settingButtonIsHeldDown(settingButton);
}

int settingButtonIsHeldDown(PSPSettingButton settingButton)
{
    return previousFrameInput.settingButtonsData.settingButtonsPressed & settingButton &&
           thisFrameInput.settingButtonsData.settingButtonsPressed & settingButton;
}

void getAnalogStickValues(PSPAnalogStickData *analogStickDataPtr)
{
    analogStickDataPtr->xAxis = previousFrameInput.analogStickData.xAxis;
    analogStickDataPtr->yAxis = previousFrameInput.analogStickData.yAxis;
}

int memoryStickIsConnected()
{
    return thisFrameInput.settingButtonsData.settingButtonsPressed & MEMORY_STICK_PRESENT;
}

int discIsPresent()
{
    return thisFrameInput.settingButtonsData.settingButtonsPressed & DISC_PRESENT;
}