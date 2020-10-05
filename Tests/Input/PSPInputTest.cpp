#include "../../PSPInput/PSPInput.hpp"
#include "../../PSPDebug/PSPDebug.hpp"

PSPDebug *debug = PSPDebug::get_instance();
PSPInput *input = PSPInput::get_instance();
unsigned char analog_x = 0;
unsigned char analog_y = 0;

void psp_initialize()
{
}

void psp_main_loop()
{
    debug->clear();

    input->update_input();
    input->get_analog_stick_values(analog_x, analog_y);

    debug->print("Analog stick values are (%d, %d)\n", analog_x, analog_y);
    debug->print("[UP] is pressed: %d\n", input->get_button(UP_BUTTON));
    debug->print("[DOWN] is pressed: %d\n", input->get_button(DOWN_BUTTON));
    debug->print("[LEFT] is pressed: %d\n", input->get_button(LEFT_BUTTON));
    debug->print("[RIGHT] is pressed: %d\n", input->get_button(RIGHT_BUTTON));
    debug->print("[CROSS] is pressed: %d\n", input->get_button(CROSS_BUTTON));
    debug->print("[SQUARE] is pressed: %d\n", input->get_button(SQUARE_BUTTON));
    debug->print("[TRIANGLE] is pressed: %d\n", input->get_button(TRIANGLE_BUTTON));
    debug->print("[CIRCLE] is pressed: %d\n", input->get_button(CIRCLE_BUTTON));
    debug->print("[L] is pressed: %d\n", input->get_button(L_TRIGGER));
    debug->print("[R] is pressed: %d\n", input->get_button(R_TRIGGER));
    debug->print("[START] is pressed: %d\n", input->get_button(START_BUTTON));
    debug->print("[SELECT] is pressed: %d\n", input->get_button(SELECT_BUTTON));
}

void psp_deinitialize()
{
}