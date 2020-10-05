#ifndef PSP_DEBUG_H
#define PSP_DEBUG_H

#include <cstdio>

#include "../utils/colors/RGB.hpp"

class PSPDebug
{
private:
    static PSPDebug *instance;

    unsigned char cursor_x;
    unsigned char cursor_y;
    unsigned char left_margin;
    unsigned char right_margin;
    unsigned char top_margin;
    unsigned char bottom_margin;

    PSPDebug();
    void special_character_found(const char *word, size_t word_length, char character_found);

public:
    static PSPDebug *get_instance();

    void print(const char *format, ...);
    void clear();
    void change_text_color(RGB rgb);
    void set_cursor_position(unsigned char x, unsigned char y);
    void get_cursor_position(unsigned char &x, unsigned char &y);
};

#endif