#ifndef PSP_ANALOG_STICK_H
#define PSP_ANALOG_STICK_H

#include <pspctrl.h>

typedef enum PSPAnalogStickSamplingMode
{
    ANALOG_SAMPLING = PSP_CTRL_MODE_ANALOG,
    DIGITAL_SAMPLING = PSP_CTRL_MODE_DIGITAL
} PSPAnalogStickSamplingMode;

typedef struct PSPAnalogStickData
{
    unsigned int xAxis;
    unsigned int yAxis;
} PSPAnalogStickData;

#endif