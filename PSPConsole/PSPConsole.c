#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include <pspdebug.h>

#include "./PSPConsole.h"
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

void init_console(Console **console, int line_capacity, ConsoleBounds *console_bounds)
{
    pspDebugScreenInit();

    int buffer_size = line_capacity + 1;

    (*console) = malloc(sizeof(Console));
    (*console)->line_capacity = buffer_size;
    (*console)->max_characters_per_line = console_bounds->right_margin - console_bounds->left_margin + 1;
    (*console)->bounds = console_bounds;
    ll_initialize(&((*console)->buffer), buffer_size);

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

    update_screen(console);
    free(string);
}

void console_clear(Console *console)
{
    clear_screen(console);
    reset_console(console);
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
    for (line = console->bounds->top_margin; line <= console->bounds->bottom_margin; ++line)
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
    int limit = MIN(console->buffer->count, console->bounds->bottom_margin - console->bounds->top_margin + 1);
    int offset = MAX(0, console->buffer->count - (console->bounds->bottom_margin - console->bounds->top_margin + 1));
    for (line = 0; line < limit; ++line)
    {
        ll_get(console->buffer, line + offset, &node);

        char *string = (char *)node->data;
        if (strlen(string) != 0)
        {
            pspDebugScreenPrintData(string, node->data_size);
            update_cursor(console, console->bounds->left_margin, console->cursor_y + 1);
        }
    }
}

static void update_cursor(Console *console, int x, int y)
{
    console->cursor_x = x;
    console->cursor_y = y;
    pspDebugScreenSetXY(x, y);
}