#include <string.h>
#include <pspdebug.h>

#include "./PSPConsole.h"

#define RGB(R, G, B) (R) + (G << 8) + (B << 16);

typedef struct PSPConsoleCursor
{
    unsigned char horizontal;
    unsigned char vertical;
} PSPConsoleCursor;

static PSPConsoleMargin margin;
static PSPConsoleCursor cursor;
static unsigned char console_initialized;

static void set_cursor_x_position(int new_cursor_x_position);
static void set_cursor_y_position(int new_cursor_y_position);
static void set_cursor_position(int new_cursor_x_position, int new_cursor_y_position);
static void special_character_found(const char *word, size_t word_length, char character_found);

static void set_cursor_x_position(int new_cursor_x_position)
{
    if (new_cursor_x_position < margin.left_margin)
    {
        cursor.horizontal = margin.left_margin;
    }
    else if (new_cursor_x_position > margin.right_margin)
    {
        cursor.horizontal = margin.right_margin;
    }
    else
    {
        cursor.horizontal = new_cursor_x_position;
    }

    pspDebugScreenSetXY(cursor.horizontal, cursor.vertical);
}

static void set_cursor_y_position(int new_cursor_y_position)
{
    if (new_cursor_y_position < margin.top_margin)
    {
        cursor.vertical = margin.top_margin;
    }
    else if (new_cursor_y_position > margin.bottom_margin)
    {
        cursor.vertical = margin.bottom_margin;
    }
    else
    {
        cursor.vertical = new_cursor_y_position;
    }

    pspDebugScreenSetXY(cursor.horizontal, cursor.vertical);
}

static void set_cursor_position(int new_cursor_x_position, int new_cursor_y_position)
{
    set_cursor_x_position(new_cursor_x_position);
    set_cursor_y_position(new_cursor_y_position);
}

static void special_character_found(const char *word, size_t word_length, char character_found)
{
    if (word_length == 0 && character_found == '\0')
    {
        return;
    }

    int new_x_cursor_position = cursor.horizontal + word_length + 1;

    if (new_x_cursor_position > margin.right_margin)
    {
        set_cursor_position(margin.left_margin, cursor.vertical + 1);
        new_x_cursor_position = margin.left_margin + word_length + 1;
    }

    if (cursor.vertical == margin.bottom_margin)
    {
        clear_screen();
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
        set_cursor_position(margin.left_margin, cursor.vertical + 1);
        break;
    default:
        break;
    }
}

void init_debug()
{
    if (console_initialized)
    {
        return;
    }
    console_initialized = 1;

    pspDebugScreenInit();
    set_background_color(0, 0, 0);

    margin.left_margin = DEFAULT_LEFT_MARGIN;
    margin.right_margin = DEFAULT_RIGHT_MARGIN;
    margin.top_margin = DEFAULT_TOP_MARGIN;
    margin.bottom_margin = DEFAULT_BOTTOM_MARGIN;

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
    set_cursor_position(margin.left_margin, margin.top_margin);
}

void set_text_color(unsigned char r, unsigned char g, unsigned char b)
{
    unsigned int color = RGB(r, g, b);
    pspDebugScreenSetTextColor(color);
}

void set_background_color(unsigned char r, unsigned char g, unsigned char b)
{
    unsigned int color = RGB(r, g, b);

    pspDebugScreenSetBackColor(color);
    clear_screen();
}

int get_left_margin()
{
    return margin.left_margin;
}

void set_left_margin(int new_left_margin)
{
    if (new_left_margin < DEFAULT_LEFT_MARGIN || new_left_margin >= margin.right_margin)
    {
        return;
    }
    margin.left_margin = new_left_margin;
}

int get_right_margin()
{
    return margin.right_margin;
}

void set_right_margin(int new_right_margin)
{
    if (new_right_margin <= margin.left_margin || new_right_margin > DEFAULT_RIGHT_MARGIN)
    {
        return;
    }
    margin.right_margin = new_right_margin;
}

int get_top_margin()
{
    return margin.top_margin;
}

void set_top_margin(int new_top_margin)
{
    if (new_top_margin < DEFAULT_TOP_MARGIN || new_top_margin >= margin.bottom_margin)
    {
        return;
    }
    margin.top_margin = new_top_margin;
}

int get_bottom_margin()
{
    return margin.bottom_margin;
}

void set_bottom_margin(int new_bottom_margin)
{
    if (new_bottom_margin <= margin.top_margin || new_bottom_margin > DEFAULT_BOTTOM_MARGIN)
    {
        return;
    }
    margin.bottom_margin = new_bottom_margin;
}