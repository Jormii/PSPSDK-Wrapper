#ifndef PSP_INPUT_H
#define PSP_INPUT_H

#include "./PSPButtons.h"
#include "./PSPAnalogStick.h"
#include "./PSPSettingButtons.h"

void init_input(PSPAnalogStickSamplingMode sampling_mode);
void update_input();
int get_button(PSPButton button);
int get_button_down(PSPButton button);
int get_button_up(PSPButton button);
void get_analog_stick_values(PSPAnalogStickData *analog_stick_data_ptr);
int memory_stick_is_connected();
int disc_is_present();

#endif