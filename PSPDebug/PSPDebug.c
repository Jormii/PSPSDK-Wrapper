#include <stdlib.h>
#include <string.h>
#include <pspdebug.h>
#include "./PSPDebug.h"

#define LINES_CAPACITY_VERTICAL 33
#define CHAR_CAPACITY_HORIZONTAL 69

#define DEFAULT_LEFT_MARGIN 1
#define DEFAULT_RIGHT_MARGIN CHAR_CAPACITY_HORIZONTAL - 1
#define DEFAULT_TOP_MARGIN 1
#define DEFAULT_BOTTOM_MARGIN LINES_CAPACITY_VERTICAL - 1

#define RGB(R, G, B) (R << 24) + (G << 16) + (B << 8) + 0;

typedef struct PSPDebugConfig
{
    int left_margin;
    int right_margin;
    int top_margin;
    int bottom_margin;
    int cursor_x_position;
    int cursor_y_position;

    int enabled_background_color;
    unsigned int background_color;
} PSPDebugConfig;

static PSPDebugConfig debug_config;

static void special_character_found(const char *word, size_t word_length, char character_found);

static void special_character_found(const char *word, size_t word_length, char character_found)
{
    if (word_length == 0 && character_found == '\0')
    {
        return;
    }

    int new_x_cursor_position = debug_config.cursor_x_position + word_length + 1;

    if (new_x_cursor_position > debug_config.right_margin)
    {
        set_cursor_position(debug_config.left_margin, debug_config.cursor_y_position + 1);
        new_x_cursor_position = debug_config.left_margin + word_length + 1;
    }

    if (debug_config.cursor_y_position == debug_config.bottom_margin)
    {
        set_cursor_y_position(debug_config.top_margin);
    }

    pspDebugScreenPrintData(word, word_length);
    set_cursor_x_position(new_x_cursor_position);

    switch (character_found)
    {
    case '\0':
        break;
    case ' ':
        pspDebugScreenPrintData(" ", 1);
        set_cursor_x_position(new_x_cursor_position);
        break;
    case '\n':
        pspDebugScreenPrintf("\n");
        set_cursor_position(debug_config.left_margin, debug_config.cursor_y_position + 1);
        break;
    default:
        break;
    }
}

void init_debug(PSPDebugBackground enable_background)
{
    pspDebugScreenInit();
    pspDebugScreenEnableBackColor(enable_background);

    debug_config.enabled_background_color = enable_background;
    set_background_color(0, 0, 0);

    debug_config.left_margin = DEFAULT_LEFT_MARGIN;
    debug_config.right_margin = DEFAULT_RIGHT_MARGIN;
    debug_config.top_margin = DEFAULT_TOP_MARGIN;
    debug_config.bottom_margin = DEFAULT_BOTTOM_MARGIN;
    set_cursor_position(DEFAULT_LEFT_MARGIN, DEFAULT_TOP_MARGIN);
}

void debug_print(const char *string)
{
    int word_length = 0;
    size_t string_length = strlen(string) + 1;
    size_t c;
    for (c = 0; c < string_length; ++c)
    {
        if (string[c] == ' ' || string[c] == '\n' || string[c] == '\0')
        {
            special_character_found(string + c - word_length, word_length, string[c]);
            word_length = 0;
        }
        else
        {
            ++word_length;
        }
    }
}

void clear_screen()
{
    pspDebugScreenClear();
    set_cursor_position(debug_config.left_margin, debug_config.top_margin);
}

void set_text_color(unsigned char r, unsigned char g, unsigned char b)
{
    unsigned int color = RGB(r, g, b);
    pspDebugScreenSetTextColor(color);
}

void set_background_color(unsigned char r, unsigned char g, unsigned char b)
{
    unsigned int color = RGB(r, g, b);
    debug_config.background_color = color;
    pspDebugScreenSetBackColor(color);
    pspDebugScreenClear();
}

int get_cursor_x_position()
{
    return debug_config.cursor_x_position;
}

void set_cursor_x_position(int new_left_margin)
{
    if (new_left_margin < debug_config.left_margin)
    {
        debug_config.cursor_x_position = debug_config.left_margin;
    }
    else if (new_left_margin > debug_config.right_margin)
    {
        debug_config.cursor_x_position = debug_config.right_margin;
    }
    else
    {
        debug_config.cursor_x_position = new_left_margin;
    }

    pspDebugScreenSetXY(debug_config.cursor_x_position, debug_config.cursor_y_position);
}

int get_cursor_y_position()
{
    return debug_config.cursor_y_position;
}

void set_cursor_y_position(int new_cursor_y_position)
{
    if (new_cursor_y_position < debug_config.top_margin)
    {
        debug_config.cursor_y_position = debug_config.top_margin;
    }
    else if (new_cursor_y_position > debug_config.bottom_margin)
    {
        debug_config.cursor_y_position = debug_config.bottom_margin;
    }
    else
    {
        debug_config.cursor_y_position = new_cursor_y_position;
    }

    pspDebugScreenSetXY(debug_config.cursor_x_position, debug_config.cursor_y_position);
}

void set_cursor_position(int new_cursor_x_position, int new_cursor_y_position)
{
    set_cursor_x_position(new_cursor_x_position);
    set_cursor_y_position(new_cursor_y_position);
}

int get_left_margin()
{
    return debug_config.left_margin;
}

void set_left_margin(int new_left_margin)
{
    if (new_left_margin < DEFAULT_LEFT_MARGIN || new_left_margin >= debug_config.right_margin)
    {
        return;
    }
    debug_config.left_margin = new_left_margin;
}

int get_right_margin()
{
    return debug_config.right_margin;
}

void set_right_margin(int new_right_margin)
{
    if (new_right_margin <= debug_config.left_margin || new_right_margin > DEFAULT_RIGHT_MARGIN)
    {
        return;
    }
    debug_config.right_margin = new_right_margin;
}

int get_top_margin()
{
    return debug_config.top_margin;
}

void set_top_margin(int new_top_margin)
{
    if (new_top_margin < DEFAULT_TOP_MARGIN || new_top_margin >= debug_config.bottom_margin)
    {
        return;
    }
    debug_config.top_margin = new_top_margin;
}

int get_bottom_margin()
{
    return debug_config.bottom_margin;
}

void set_bottom_margin(int new_bottom_margin)
{
    if (new_bottom_margin <= debug_config.top_margin || new_bottom_margin > DEFAULT_BOTTOM_MARGIN)
    {
        return;
    }
    debug_config.bottom_margin = new_bottom_margin;
}