#ifndef PSP_INPUT_H
#define PSP_INPUT_H

#include "./PSPButtons.h"
#include "./PSPAnalogStick.h"
#include "./PSPSettingButtons.h"

typedef struct PSPInput
{
    unsigned int timeStamp;
    PSPButtonsData buttonsData;
    PSPAnalogStickData analogStickData;
    PSPSettingButtonsData settingButtonsData;
} PSPInput;

void initInput(PSPAnalogStickSamplingMode samplingMode);
void updateInput();
int buttonIsPressed(PSPButton button);
int buttonIsHeldDown(PSPButton button);
int settingButtonIsPressed(PSPSettingButton settingButton);
int settingButtonIsHeldDown(PSPSettingButton settingButton);
void getAnalogStickValues(PSPAnalogStickData *analogStickDataPtr);

#endif