#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include <pspdebug.h>

#include "./PSPDebug.hpp"
#include "../utils/display/Display.h"

PSPDebug *PSPDebug::instance = NULL;

PSPDebug *PSPDebug::get_instance()
{
    if (instance == NULL)
    {
        instance = new PSPDebug();
    }

    return instance;
}

void PSPDebug::print(const char *format, ...)
{
    // Format string
    va_list vararg;
    va_start(vararg, format);

    int length = vsnprintf(NULL, 0, format, vararg) + 1;
    va_end(vararg);

    va_start(vararg, format);
    char *c_string = (char *)malloc(length);
    vsnprintf(c_string, length, format, vararg);

    va_end(vararg);

    // Process string
    size_t word_length = 0;
    size_t string_length = strlen(c_string) + 1;
    for (size_t c = 0; c < string_length; ++c)
    {
        if (c_string[c] == ' ' || c_string[c] == '\n' || c_string[c] == '\0')
        {
            special_character_found(c_string + c - word_length, word_length, c_string[c]);
            word_length = 0;
        }
        else
        {
            word_length += 1;
        }
    }

    free(c_string);
}

void PSPDebug::clear()
{
    pspDebugScreenClear();
    set_cursor_position(left_margin, top_margin);
}

void PSPDebug::change_text_color(RGB rgb)
{
    pspDebugScreenSetTextColor(rgb.value());
}

void PSPDebug::set_cursor_position(unsigned char x, unsigned char y)
{
    cursor_x = x;
    cursor_y = y;
    pspDebugScreenSetXY(x, y);
}

void PSPDebug::get_cursor_position(unsigned char &x, unsigned char &y)
{
    x = cursor_x;
    y = cursor_y;
}

// Private member functions
void PSPDebug::special_character_found(const char *word, size_t word_length, char character_found)
{
    if (word_length == 0 && character_found == '\0')
    {
        return;
    }

    unsigned char new_cursor_x = cursor_x + word_length;
    if (character_found != '\0')
    {
        new_cursor_x += 1;
    }

    if (new_cursor_x > right_margin)
    {
        set_cursor_position(left_margin, cursor_y + 1);
        new_cursor_x = left_margin + word_length + 1;
    }

    if (cursor_y == bottom_margin)
    {
        clear();
    }

    pspDebugScreenPrintData(word, word_length);
    set_cursor_position(new_cursor_x, cursor_y);

    switch (character_found)
    {
    case '\0':
        break;
    case ' ':
        pspDebugScreenPrintf(" ");
        set_cursor_position(new_cursor_x, cursor_y);
        break;
    case '\n':
        pspDebugScreenPrintf("\n");
        set_cursor_position(left_margin, cursor_y + 1);
        break;
    default:
        break;
    }
}

PSPDebug::PSPDebug()
{
    pspDebugScreenInit();

    cursor_x = 0;
    cursor_y = 0;
    left_margin = 0;
    right_margin = CHAR_CAPACITY_HORIZONTAL;
    top_margin = 0;
    bottom_margin = LINES_CAPACITY_VERTICAL;
}