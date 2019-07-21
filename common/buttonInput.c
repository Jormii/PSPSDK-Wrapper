#include "./buttonInput.h"

void initButtons(SampleMode samplingMode)
{
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(samplingMode);
}

void updateButtons()
{
    sceCtrlPeekBufferPositive(&controllerData, 1);
}

int buttonPressed(PSPButton button)
{
    if (controllerData.Buttons != 0)
    {
        return -1;
    }

    return controllerData.Buttons & button;
}