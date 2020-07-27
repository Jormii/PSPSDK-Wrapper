#ifndef PSP_CONSOLE_H
#define PSP_CONSOLE_H

#include "../utils/datastructures/LinkedList.h" // TODO: Find a way to remove this

/* TODO
    - Add support for dynamic bounds
    - Remove flickering
    - Make other console's text in the same line not dissapear
    - Add support for color
*/

typedef struct ConsoleBounds
{
    char left_margin;
    char right_margin;
    char top_margin;
    char bottom_margin;
} ConsoleBounds;

typedef struct Console
{
    int line_displayed;
    int max_characters_per_line;
    int max_lines_displayed;
    int cursor_x;
    int cursor_y;
    ConsoleBounds *bounds;
    LinkedList *buffer;
} Console;

void init_console(Console **console, int line_capacity, ConsoleBounds *console_bounds);
void destroy_console(Console **console);
void console_print(Console *console, const char *format, ...);
void console_clear(Console *console);
void console_scroll_up(Console *console);
void console_scroll_down(Console *console);

#endif