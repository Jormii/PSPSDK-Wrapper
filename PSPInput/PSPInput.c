#include <pspctrl.h>
#include "./PSPInput.h"

#define DEFAULT_SAMPLING_CYCLE 0
#define DEFAULT_SAMPLING_MODE PSP_CTRL_MODE_ANALOG

typedef struct PSPInput
{
    unsigned int time_stamp;
    PSPButtonsData buttons_data;
    PSPAnalogStickData analog_stick_data;
    PSPSettingButtonsData setting_buttons_data;
} PSPInput;

static PSPInput this_frame_input;
static PSPInput previous_frame_input;

static void swap_inputs();

static void swap_inputs()
{
    previous_frame_input.time_stamp = this_frame_input.time_stamp;
    previous_frame_input.buttons_data.buttons_pressed = this_frame_input.buttons_data.buttons_pressed;
    previous_frame_input.analog_stick_data.x_axis = this_frame_input.analog_stick_data.x_axis;
    previous_frame_input.analog_stick_data.y_axis = this_frame_input.analog_stick_data.y_axis;
    previous_frame_input.setting_buttons_data.setting_buttons_pressed = this_frame_input.setting_buttons_data.setting_buttons_pressed;
}

void init_input()
{
    sceCtrlSetSamplingCycle(DEFAULT_SAMPLING_CYCLE);
    sceCtrlSetSamplingMode(DEFAULT_SAMPLING_MODE);
}

void update_input()
{
    SceCtrlData input;
    sceCtrlPeekBufferPositive(&input, 1);

    swap_inputs();
    this_frame_input.time_stamp = input.TimeStamp;
    this_frame_input.buttons_data.buttons_pressed = input.Buttons;
    this_frame_input.analog_stick_data.x_axis = input.Lx;
    this_frame_input.analog_stick_data.y_axis = input.Ly;
    this_frame_input.setting_buttons_data.setting_buttons_pressed = input.Buttons;
}

int get_button(PSPButton button)
{
    return get_button_down(button) ||
           (previous_frame_input.buttons_data.buttons_pressed & button &&
            this_frame_input.buttons_data.buttons_pressed & button);
}

int get_button_down(PSPButton button)
{
    return !(previous_frame_input.buttons_data.buttons_pressed & button) &&
           this_frame_input.buttons_data.buttons_pressed & button;
}

int get_button_up(PSPButton button)
{
    return previous_frame_input.buttons_data.buttons_pressed & button &&
           !(this_frame_input.buttons_data.buttons_pressed & button);
}

void get_analog_stick_values(PSPAnalogStickData *analog_stick_data_ptr)
{
    analog_stick_data_ptr->x_axis = this_frame_input.analog_stick_data.x_axis;
    analog_stick_data_ptr->y_axis = this_frame_input.analog_stick_data.y_axis;
}

int memory_stick_is_connected()
{
    return this_frame_input.setting_buttons_data.setting_buttons_pressed & MEMORY_STICK_PRESENT;
}

int disc_is_present()
{
    return this_frame_input.setting_buttons_data.setting_buttons_pressed & DISC_PRESENT;
}