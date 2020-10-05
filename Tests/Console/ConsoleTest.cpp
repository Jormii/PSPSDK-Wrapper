#include <stdlib.h>

#include "../../PSPConsole/PSPConsole.hpp"
extern "C"
{
#include "../../PSPInput/PSPInput.h"
#include "../../utils/display/Display.h"
#include "../../PSPDebug/PSPDebug.hpp"
#include "../../utils/math/Math.h"
};

Console *text_console;
Console *options_console;

const char *options[] = {"Attack", "Defend", "Item", "Escape"};
int options_size = 4;
int option_selected = 0;

void init_text_console()
{
    ConsoleBounds *bounds = new ConsoleBounds();

    bounds->top_margin = 1;
    bounds->left_margin = 1;
    bounds->right_margin = CHAR_CAPACITY_HORIZONTAL - 1;
    bounds->bottom_margin = LINES_CAPACITY_VERTICAL - 3;

    text_console = new Console(2 * LINES_CAPACITY_VERTICAL * CHAR_CAPACITY_HORIZONTAL, bounds);
}

void init_options_console()
{
    ConsoleBounds *bounds = new ConsoleBounds();
    bounds->top_margin = LINES_CAPACITY_VERTICAL - 2;
    bounds->left_margin = 5;
    bounds->right_margin = CHAR_CAPACITY_HORIZONTAL - 5;
    bounds->bottom_margin = LINES_CAPACITY_VERTICAL - 1;

    options_console = new Console(2 * CHAR_CAPACITY_HORIZONTAL, bounds);
}

void print_text()
{
    text_console->change_text_color(RGB(255, 0, 0));
    text_console->print("You begin the story of the killing of the hill titan Tawki Pinedawns the Scaly Glen by the human necromancer 'Gobbas' Specialsunk the Blanketed Continents of Ringging with an iron long sword in Budskins the Cat of Mosses in the late winter of 113.\n\n");
    text_console->change_text_color(RGB(0, 255, 0));
    text_console->print("The flying copper arrow misses you!\n\n");
    text_console->change_text_color(RGB(0, 0, 255));
    text_console->print("Skinny bowman: Can it all end so quickly? Begone fear!\n\n");
    text_console->change_text_color(rgb_white);
    text_console->print("You jump away from The flying copper arrow!\n\n");
    text_console->print("You slash the skinny bowman in the right upper leg with your iron long sword, tearing apart the muscle through the long nautilus leather skirt! An artery has been opened by the attack and a sensory nerve has been severed!\n\n");
    text_console->print("The skinny bowman falls over.\n\n");
    text_console->print("You begin the story of the killing of the hill titan Tawki Pinedawns the Scaly Glen by the human necromancer 'Gobbas' Specialsunk the Blanketed Continents of Ringging with an iron long sword in Budskins the Cat of Mosses in the late winter of 113.\n\n");
    text_console->print("The flying copper arrow misses you!\n\n");
    text_console->print("The flying copper arrow misses you!\n\n");
    text_console->print("The flying copper arrow misses you!\n\n");
    text_console->print("You block The flying copper arrow with the +iron shield+!\n\n");
    text_console->print("You stumble over the details.\n\n");
    text_console->print("You jump away from The flying copper arrow!\n\n");
}

void print_options()
{
    for (int i = 0; i < options_size; ++i)
    {
        if (i == option_selected)
        {
            options_console->change_text_color(RGB(255, 255, 0));
            options_console->print("[ ");
        }
        else
        {
            options_console->change_text_color(rgb_white);
        }

        options_console->print("%s", options[i]);

        if (i == option_selected)
        {
            options_console->print(" ]");
        }

        options_console->print("     ");
    }
}

void psp_initialize()
{
    init_input();
    init_debug();

    init_text_console();
    init_options_console();

    print_text();
    print_options();
}

void psp_main_loop()
{
    update_input();

    if (get_button_up(UP_BUTTON))
    {
        text_console->scroll_up();
    }

    if (get_button_up(DOWN_BUTTON))
    {
        text_console->scroll_down();
    }

    bool update_options = false;
    if (get_button_down(LEFT_BUTTON))
    {
        update_options = true;
        option_selected = max(0, option_selected - 1);
    }

    if (get_button_down(RIGHT_BUTTON))
    {
        update_options = true;
        option_selected = min(options_size - 1, option_selected + 1);
    }

    if (update_options)
    {
        options_console->clear();
        print_options();
    }
}

void psp_deinitialize()
{
    delete text_console;
    delete options_console;
}