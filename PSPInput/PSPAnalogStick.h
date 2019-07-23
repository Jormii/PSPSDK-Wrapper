#ifndef PSP_ANALOG_STICK_H
#define PSP_ANALOG_STICK_H

typedef enum PSPAnalogStickSamplingMode
{
    DIGITAL_SAMPLING = 0,
    ANALOG_SAMPLING = 1
} PSPAnalogStickSamplingMode;

typedef struct PSPAnalogStickData
{
    unsigned int x_axis;
    unsigned int y_axis;
} PSPAnalogStickData;

#endif