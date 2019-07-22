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
int getButton(PSPButton button);
int getButtonDown(PSPButton button);
int getButtonUp(PSPButton button);
void getAnalogStickValues(PSPAnalogStickData *analogStickDataPtr);
int memoryStickIsConnected();
int discIsPresent();

#endif