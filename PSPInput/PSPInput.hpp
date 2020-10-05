#ifndef PSP_INPUT_H
#define PSP_INPUT_H

#include "./PSPButton.hpp"

struct PSPButtonsData;
struct SceCtrlData;

class PSPInput
{
private:
    static PSPInput *instance;

    PSPButtonsData *this_frame_data;
    PSPButtonsData *previous_frame_data;
    SceCtrlData *input;

    PSPInput();
    void swap_inputs();

public:
    static PSPInput *get_instance();
    void update_input();
    bool get_button(PSPButton button);
    bool get_button_down(PSPButton button);
    bool get_button_up(PSPButton button);
    void get_analog_stick_values(unsigned char &analog_x, unsigned char &analog_y);
    bool memory_stick_is_connected();
    bool disc_is_pressent();
};

#endif