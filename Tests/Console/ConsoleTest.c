#include <stdlib.h>

#include "../../PSPConsole/PSPConsole.h"
#include "../../PSPInput/PSPInput.h"
#include "../../utils/display/Display.h"
#include "../../utils/math/Math.h"

Console *text_console;
Console *options_console;

const char *options[] = {"Attack", "Defend", "Item", "Escape"};
int options_size = 4;
int option_selected = 0;

void init_text_console()
{
    ConsoleBounds *bounds = malloc(sizeof(ConsoleBounds));
    bounds->top_margin = 1;
    bounds->left_margin = 1;
    bounds->right_margin = CHAR_CAPACITY_HORIZONTAL - 1;
    bounds->bottom_margin = LINES_CAPACITY_VERTICAL - 4;

    init_console(&text_console, 80, bounds);
}

void init_options_console()
{
    ConsoleBounds *bounds = malloc(sizeof(ConsoleBounds));
    bounds->top_margin = LINES_CAPACITY_VERTICAL - 2;
    bounds->left_margin = 5;
    bounds->right_margin = CHAR_CAPACITY_HORIZONTAL - 5;
    bounds->bottom_margin = LINES_CAPACITY_VERTICAL - 1;

    init_console(&options_console, 2, bounds);
}

void psp_initialize()
{
    init_input();

    init_text_console();
    init_options_console();

    console_print(text_console, "You begin the story of the killing of the hill titan Tawki Pinedawns the Scaly Glen by the human necromancer 'Gobbas' Specialsunk the Blanketed Continents of Ringging with an iron long sword in Budskins the Cat of Mosses in the late winter of 113.\n\n");
    console_print(text_console, "The flying copper arrow misses you!\n\n");
    console_print(text_console, "Skinny bowman: Can it all end so quickly? Begone fear!\n\n");
    console_print(text_console, "You jump away from The flying copper arrow!\n\n");
    console_print(text_console, "You slash the skinny bowman in the right upper leg with your iron long sword, tearing apart the muscle through the long nautilus leather skirt! An artery has been opened by the attack and a sensory nerve has been severed!\n\n");
    console_print(text_console, "The skinny bowman falls over.\n\n");
    console_print(text_console, "You begin the story of the killing of the hill titan Tawki Pinedawns the Scaly Glen by the human necromancer 'Gobbas' Specialsunk the Blanketed Continents of Ringging with an iron long sword in Budskins the Cat of Mosses in the late winter of 113.\n\n");
    console_print(text_console, "The flying copper arrow misses you!\n\n");
    console_print(text_console, "The flying copper arrow misses you!\n\n");
    console_print(text_console, "The flying copper arrow misses you!\n\n");
    console_print(text_console, "You block The flying copper arrow with the +iron shield+!\n\n");
    console_print(text_console, "You stumble over the details.\n\n");
    console_print(text_console, "You jump away from The flying copper arrow!\n\n");
}

void psp_main_loop()
{
    update_input();

    if (get_button_up(UP_BUTTON))
    {
        console_scroll_up(text_console);
    }

    if (get_button_up(DOWN_BUTTON))
    {
        console_scroll_down(text_console);
    }

    if (get_button_down(LEFT_BUTTON))
    {
        option_selected = MAX(0, option_selected - 1);
    }

    if (get_button_down(RIGHT_BUTTON))
    {
        option_selected = MIN(options_size - 1, option_selected + 1);
    }

    console_clear(options_console);
    int i;
    for (i = 0; i < options_size; ++i)
    {
        if (i == option_selected)
        {
            console_print(options_console, "[ ");
        }

        console_print(options_console, "%s", options[i]);

        if (i == option_selected)
        {
            console_print(options_console, " ]");
        }

        console_print(options_console, "     ");
    }
}

void psp_deinitialize()
{
    destroy_console(&text_console);
    destroy_console(&options_console);
}