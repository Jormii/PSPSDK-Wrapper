#include "../../PSPDebug/PSPDebug.hpp"

void psp_initialize()
{
    PSPDebug *debug = PSPDebug::get_instance();
    debug->print("Welcome to the PSP screen debugger!\n");

    unsigned char cursor_x = 0;
    unsigned char cursor_y = 0;
    debug->get_cursor_position(cursor_x, cursor_y);
    debug->print("The current cursor position before printing this line was (%d, %d)\n", cursor_x, cursor_y);

    debug->change_text_color(RGB(255, 0, 0));
    debug->print("This text is printed in red\n");

    debug->set_cursor_position(0, 15);
    debug->change_text_color(RGB(255, 255, 0));
    debug->print("This really long line is printed far away from the others and its color is ");
    debug->change_text_color(RGB(0, 255, 0));
    debug->print("yellow");
    debug->change_text_color(RGB(255, 255, 0));
    debug->print(". Pretty cool, huh?");
}

void psp_main_loop()
{
}

void psp_deinitialize()
{
}