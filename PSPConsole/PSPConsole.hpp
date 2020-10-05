#ifndef PSP_CONSOLE_H
#define PSP_CONSOLE_H

#include <vector>
#include <string>
#include <map>
#include "../utils/colors/RGB.hpp"

/* TODO
    - Add support for dynamic bounds
    - Remove flickering
    - Make other console's text in the same line not dissapear
*/

using namespace std;

typedef pair<size_t, RGB> color_change_entry;

typedef struct ConsoleBounds
{
    char left_margin;
    char right_margin;
    char top_margin;
    char bottom_margin;
} ConsoleBounds;

class Console
{
private:
    size_t buffer_size;
    char max_characters_horizontally;
    char max_lines_vertically;
    size_t cursor;
    char print_cursor_x;
    char print_cursor_y;
    ConsoleBounds *bounds;
    string buffer;
    vector<size_t> jumps_to_lines;
    map<size_t, RGB> color_changes;

public:
    Console(size_t buffer_size, ConsoleBounds *bounds);
    ~Console();

    void print(const char *format, ...);
    void clear();
    void scroll_up();
    void scroll_down();
    void change_text_color(RGB rgb);

    // Not meant to be used by user
    void reset();
    void clear_screen();
    void update_screen();
    bool exceeds_buffer(string &str);
    void remove_first_line();
    void update_print_cursor(char x, char y);
};

#endif