#include <cstdio>

#include <pspctrl.h>

#include "./PSPInput.hpp"

#define DEFAULT_SAMPLING_CYCLE 0
#define DEFAULT_SAMPLING_MODE PSP_CTRL_MODE_ANALOG

PSPInput *PSPInput::instance = NULL;

typedef struct PSPButtonsData
{
    size_t time_stamp;
    unsigned int buttons_pressed;
    unsigned char analog_x;
    unsigned char analog_y;
} PSPButtonsData;

PSPInput *PSPInput::get_instance()
{
    if (instance == NULL)
    {
        instance = new PSPInput();
    }

    return instance;
}

void PSPInput::update_input()
{
    sceCtrlPeekBufferPositive(input, 1);
    swap_inputs();

    this_frame_data->time_stamp = input->TimeStamp;
    this_frame_data->buttons_pressed = input->Buttons;
    this_frame_data->analog_x = input->Lx;
    this_frame_data->analog_y = input->Ly;
}

bool PSPInput::get_button(PSPButton button)
{
    return get_button_down(button) ||
           (previous_frame_data->buttons_pressed & button &&
            this_frame_data->buttons_pressed & button);
}

bool PSPInput::get_button_down(PSPButton button)
{
    return !(previous_frame_data->buttons_pressed & button) &&
           this_frame_data->buttons_pressed & button;
}

bool PSPInput::get_button_up(PSPButton button)
{
    return previous_frame_data->buttons_pressed & button &&
           !(this_frame_data->buttons_pressed & button);
}

void PSPInput::get_analog_stick_values(unsigned char &analog_x, unsigned char &analog_y)
{
    analog_x = this_frame_data->analog_x;
    analog_y = this_frame_data->analog_y;
}

bool PSPInput::memory_stick_is_connected()
{
    // TODO
    return false;
}

bool PSPInput::disc_is_pressent()
{
    // TODO
    return false;
}

// Private member functions
PSPInput::PSPInput()
{
    sceCtrlSetSamplingCycle(DEFAULT_SAMPLING_CYCLE);
    sceCtrlSetSamplingMode(DEFAULT_SAMPLING_MODE);

    this_frame_data = new PSPButtonsData();
    previous_frame_data = new PSPButtonsData();
    input = new SceCtrlData();
}

void PSPInput::swap_inputs()
{
    previous_frame_data->time_stamp = this_frame_data->time_stamp;
    previous_frame_data->buttons_pressed = this_frame_data->buttons_pressed;
    previous_frame_data->analog_x = this_frame_data->analog_x;
    previous_frame_data->analog_y = this_frame_data->analog_y;
}