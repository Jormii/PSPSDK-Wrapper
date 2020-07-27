#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include <pspkernel.h>
#include <pspdebug.h>

#include "./PSPConsole.h"
#include "../PSPIO/PSPIO.h"
#include "../utils/datastructures/LinkedList.h"
#include "../utils/colors/Colors.h"
#include "../utils/display/Display.h"
#include "../utils/math/Math.h"

static void reset_console(Console *console);
static void add_empty_line_to_buffer(Console *console);
static void special_character_found(Console *console, const char *word, size_t word_length, char character_found);
static void clear_screen(Console *console);
static void update_screen(Console *console);
static void update_cursor(Console *console, int x, int y);

void init_console(Console **console, int buffer_size, ConsoleBounds *console_bounds)
{
    pspDebugScreenInit();

    (*console) = malloc(sizeof(Console));
    (*console)->max_characters_per_line = console_bounds->right_margin - console_bounds->left_margin + 1;
    (*console)->max_lines_displayed = console_bounds->bottom_margin - console_bounds->top_margin + 1;
    (*console)->bounds = console_bounds;
    ll_initialize(&((*console)->buffer), buffer_size + 1);

    reset_console(*(console));
}

void destroy_console(Console **console)
{
    ll_destroy(&((*console)->buffer));
    free((*console)->bounds);

    *(console) = NULL;
}

void console_print(Console *console, const char *format, ...)
{
    // Format string
    va_list vararg;
    va_start(vararg, format);

    int string_length = vsnprintf(NULL, 0, format, vararg) + 1;
    va_end(vararg);

    va_start(vararg, format);
    char *string = malloc(string_length);
    vsnprintf(string, string_length, format, vararg);

    va_end(vararg);

    // Process string
    size_t word_length = 0;
    size_t c;
    for (c = 0; c < string_length; ++c)
    {
        if (string[c] == ' ' || string[c] == '\n' || string[c] == '\0')
        {
            special_character_found(console, string + c - word_length, word_length, string[c]);
            word_length = 0;
        }
        else
        {
            word_length += 1;
        }
    }

    console->line_displayed = MAX(0, console->buffer->count - console->max_lines_displayed);
    update_screen(console);
    free(string);
}

void console_clear(Console *console)
{
    clear_screen(console);
    reset_console(console);
}

void console_scroll_up(Console *console)
{
    if (console->line_displayed > 0)
    {
        console->line_displayed -= 1;
        update_screen(console);
    }
}

void console_scroll_down(Console *console)
{
    int max_cursor = MAX(0, console->buffer->count - console->max_lines_displayed);

    // In case the last string in buffer is an empty line
    char *last_string = (char *)console->buffer->tail->data;
    if (last_string[0] == '\0')
    {
        max_cursor -= 1;
    }

    if (console->line_displayed < max_cursor)
    {
        console->line_displayed += 1;
        update_screen(console);
    }
}

static void reset_console(Console *console)
{
    console->cursor_x = console->bounds->left_margin;
    console->cursor_y = console->bounds->top_margin;
    console->line_displayed = 0;
    ll_clear(console->buffer);
    add_empty_line_to_buffer(console);
}

static void add_empty_line_to_buffer(Console *console)
{
    char *empty_string = malloc(console->max_characters_per_line);
    int c;
    for (c = 0; c < console->max_characters_per_line; ++c)
    {
        empty_string[c] = '\0';
    }

    if (ll_append(console->buffer, (void *)empty_string, console->max_characters_per_line) == LL_ERROR_REACHED_MAX_COUNT)
    {
        ll_remove(console->buffer, 0);
        ll_append(console->buffer, (void *)empty_string, console->max_characters_per_line);
    }
}

static void special_character_found(Console *console, const char *word, size_t word_length, char character_found)
{
    if (word_length == 0 && character_found == '\0')
    {
        return;
    }

    char *line = (char *)console->buffer->tail->data;
    int line_length = strlen(line);

    int final_line_length = line_length + word_length + 1; // +1 to consider the special character
    if (final_line_length > console->max_characters_per_line)
    {
        add_empty_line_to_buffer(console);

        line = (char *)console->buffer->tail->data;
        line_length = 0;
    }

    // Update line
    int c;
    for (c = 0; c < word_length + 1; ++c)
    {
        line[line_length + c] = word[c];
    }

    // Add a new line if newline character was found
    if (character_found == '\n')
    {
        add_empty_line_to_buffer(console);
    }
}

static void clear_screen(Console *console)
{
    update_cursor(console, console->bounds->left_margin, console->bounds->top_margin);

    int line;
    for (line = console->bounds->top_margin; line < console->bounds->bottom_margin; ++line)
    {
        int c;
        for (c = 0; c < console->max_characters_per_line; ++c)
        {
            pspDebugScreenPrintf(" ");
        }

        update_cursor(console, console->bounds->left_margin, console->cursor_y + 1);
    }
}

static void update_screen(Console *console)
{
    clear_screen(console);
    update_cursor(console, console->bounds->left_margin, console->bounds->top_margin);

    LinkedListNode *node = NULL;
    int line;
    int limit = MIN(console->buffer->count, console->max_lines_displayed);

    // In order to avoid printing empty lines
    ll_get(console->buffer, console->line_displayed + limit - 1, &node);
    char *last_string_to_print = (char *)node->data;
    if (last_string_to_print[0] == '\0')
    {
        console->line_displayed = MAX(0, console->line_displayed - 1);
        limit = MIN(console->buffer->count - 1, console->max_lines_displayed);
    }

    for (line = 0; line < limit; ++line)
    {
        ll_get(console->buffer, line + console->line_displayed, &node);

        char *string = (char *)node->data;
        pspDebugScreenPrintData(string, node->data_size);

        update_cursor(console, console->bounds->left_margin, console->cursor_y + 1);
    }
}

static void update_cursor(Console *console, int x, int y)
{
    console->cursor_x = x;
    console->cursor_y = y;
    pspDebugScreenSetXY(x, y);
}