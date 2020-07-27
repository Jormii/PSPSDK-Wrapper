#include <stdlib.h>

#include "../../PSPConsole/PSPConsole.h"
#include "../../PSPInput/PSPInput.h"
#include "../../utils/display/Display.h"

Console *console = NULL;
int times_x_pressed = 0;

void init_first_console()
{
    ConsoleBounds *bounds = malloc(sizeof(ConsoleBounds));
    bounds->left_margin = 30;
    bounds->right_margin = CHAR_CAPACITY_HORIZONTAL - 10;
    bounds->top_margin = 5;
    bounds->bottom_margin = LINES_CAPACITY_VERTICAL - 10;
    init_console(&console, LINES_CAPACITY_VERTICAL, bounds);
}

void init_other_console()
{
    Console *other_console = NULL;
    ConsoleBounds *bounds = malloc(sizeof(ConsoleBounds));
    bounds->left_margin = 0;
    bounds->right_margin = 7;
    bounds->top_margin = 0;
    bounds->bottom_margin = LINES_CAPACITY_VERTICAL;
    init_console(&other_console, LINES_CAPACITY_VERTICAL, bounds);

    int i;
    for (i = 0; i < LINES_CAPACITY_VERTICAL; ++i)
    {
        console_print(other_console, "[%d]\n", i);
    }

    destroy_console(&other_console);
}

void psp_initialize()
{
    init_input();

    init_first_console();
    init_other_console();

    const char *name = "Lena";
    console_print(console, "Hey %s\n", name);
}

void psp_main_loop()
{
    update_input();

    if (get_button_down(CROSS_BUTTON))
    {
        times_x_pressed += 1;
        console_print(console, "X has been pressed %d times\n", times_x_pressed);
    }

    if (get_button_down(CIRCLE_BUTTON))
    {
        console_clear(console);
    }

    if (get_button_down(UP_BUTTON))
    {
        console_scroll_up(console);
    }

    if (get_button_down(DOWN_BUTTON))
    {
        console_scroll_down(console);
    }
}

void psp_deinitialize()
{
    destroy_console(&console);
}