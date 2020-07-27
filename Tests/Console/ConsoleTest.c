#include <stdlib.h>

#include "../../PSPConsole/PSPConsole.h"
#include "../../PSPInput/PSPInput.h"
#include "../../utils/display/Display.h"

Console *text_console;
Console *options_console;

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

    int i;
    for (i = 0; i < 50; ++i)
    {
        console_print(text_console, "[%d]\n", i);
    }

    console_print(options_console, "Options");
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
        console_clear(options_console);
        console_print(options_console, "Options\n");
        console_print(options_console, "A\tB\tC");
    }

    if (get_button_down(RIGHT_BUTTON))
    {
        console_clear(options_console);
        console_print(options_console, "Options\n");
        console_print(options_console, "A\tB\tC");
    }
}

void psp_deinitialize()
{
    destroy_console(&text_console);
    destroy_console(&options_console);
}