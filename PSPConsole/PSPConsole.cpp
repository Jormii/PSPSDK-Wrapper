#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include <pspkernel.h>
#include <pspdebug.h>

#include "./PSPConsole.hpp"
#include "../utils/display/Display.h"

Console::Console(size_t buffer_size, ConsoleBounds *bounds)
{
    pspDebugScreenInit();

    this->buffer_size = buffer_size;
    this->max_characters_horizontally = bounds->right_margin - bounds->left_margin + 1;
    this->max_lines_vertically = bounds->bottom_margin - bounds->top_margin + 1;
    this->cursor = 0;
    this->bounds = bounds;

    reset();
}

Console::~Console()
{
    delete bounds;
    buffer.clear();
    jumps_to_lines.clear();
    color_changes.clear();
}

void Console::print(const char *format, ...)
{
    // Parse string
    va_list vararg;
    va_start(vararg, format);

    int length = vsnprintf(NULL, 0, format, vararg) + 1;
    va_end(vararg);

    va_start(vararg, format);
    char *c_string = (char *)malloc(length);
    vsnprintf(c_string, length, format, vararg);

    string cpp_string(c_string);
    free(c_string);

    // Add string to buffer
    while (exceeds_buffer(cpp_string))
    {
        remove_first_line();
    }

    size_t last_jump = *(jumps_to_lines.end() - 1);
    char line_length = buffer.length() - last_jump;
    size_t character_index = last_jump + line_length;
    char word_length = 0UL;

    for (string::iterator it = cpp_string.begin(); it <= cpp_string.end(); ++it)
    {
        char c = *it;
        if (c == ' ' || c == '\n' || c == '\0')
        {
            word_length += 1; // TODO: What if ' ' or '\n' are the characters that exceed the horizontal limit?

            char final_length = line_length + word_length;
            if (final_length > max_characters_horizontally)
            {
                size_t jump_position = character_index - word_length + 1;
                jumps_to_lines.push_back(jump_position);

                line_length = word_length;
            }
            else
            {
                line_length += word_length;
            }

            word_length = 0;
        }
        else
        {
            word_length += 1;
        }

        if (c == '\n')
        {
            jumps_to_lines.push_back(character_index + 1);
        }

        character_index += 1;
    }

    buffer.append(cpp_string);
    update_screen();
}

void Console::clear()
{
    clear_screen();
    reset();
}

void Console::scroll_up()
{
    if (cursor > 0)
    {
        cursor -= 1;
        clear_screen();
        update_screen();
    }
}

void Console::scroll_down()
{
    size_t max_cursor = max(static_cast<size_t>(0), jumps_to_lines.size() - max_lines_vertically);
    if (cursor < max_cursor)
    {
        cursor += 1;
        clear_screen();
        update_screen();
    }
}

void Console::change_text_color(RGB rgb)
{
    size_t color_change_index = buffer.size();
    color_changes.insert(color_change_entry(color_change_index, rgb));
}

// Not meant to be used by user from now on
void Console::reset()
{
    cursor = 0;
    buffer.clear();

    jumps_to_lines.clear();
    jumps_to_lines.push_back(0);

    color_changes.clear();
}

void Console::clear_screen()
{
    update_print_cursor(bounds->left_margin, bounds->top_margin);

    for (size_t line = bounds->top_margin; line < static_cast<size_t>(bounds->bottom_margin); ++line)
    {
        for (char c = 0; c < max_characters_horizontally; ++c)
        {
            pspDebugScreenPrintf(" ");
        }

        update_print_cursor(bounds->left_margin, print_cursor_y + 1);
    }
}

void Console::update_screen()
{
    update_print_cursor(bounds->left_margin, bounds->top_margin);

    size_t character_index = jumps_to_lines[cursor];
    char lines_printed = 0;
    bool keep_printing = character_index < buffer.length();
    while (keep_printing)
    {
        if (jumps_to_lines[cursor + lines_printed + 1] == character_index)
        {
            if (lines_printed == (max_lines_vertically - 1))
            {
                keep_printing = false;
            }
            else
            {
                lines_printed += 1;
                update_print_cursor(bounds->left_margin, print_cursor_y + 1);
            }
        }

        if (keep_printing)
        {
            if (color_changes.find(character_index) != color_changes.end())
            {
                RGB rgb = color_changes.find(character_index)->second;
                pspDebugScreenSetTextColor(rgb.value());
            }

            pspDebugScreenPrintf("%c", buffer[character_index]);
            character_index += 1;

            keep_printing = character_index < buffer.length();
        }
    }
}

bool Console::exceeds_buffer(string &str)
{
    return (str.length() + buffer.length()) > buffer_size;
}

void Console::remove_first_line()
{
    if (jumps_to_lines.size() == 1)
    {
        buffer.clear();
    }
    else
    {
        size_t line_length = jumps_to_lines[1];
        buffer = buffer.substr(0, line_length - 1);

        jumps_to_lines.erase(jumps_to_lines.begin());
        for (vector<size_t>::iterator it = jumps_to_lines.begin(); it < jumps_to_lines.end(); ++it)
        {
            *it -= line_length;
        }
    }
}

void Console::update_print_cursor(char x, char y)
{
    print_cursor_x = x;
    print_cursor_y = y;
    pspDebugScreenSetXY(x, y);
}