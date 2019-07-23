#ifndef PSP_DEBUG_H
#define PSP_DEBUG_H

void init_debug();
void debug_print(const char *string);
void clear_screen();
void set_text_color(unsigned char r, unsigned char g, unsigned char b);
void set_background_color(unsigned char r, unsigned char g, unsigned char b);

int get_cursor_x_position();
void set_cursor_x_position(int new_cursor_x_position);
int get_cursor_y_position();
void set_cursor_y_position(int new_cursor_y_position);
void set_cursor_position(int new_cursor_x_position, int new_cursor_y_position);
int get_left_margin();
void set_left_margin(int new_left_margin);
int get_right_margin();
void set_right_margin(int new_right_margin);
int get_top_margin();
void set_top_margin(int new_top_margin);
int get_bottom_margin();
void set_bottom_margin(int new_bottom_margin);

#endif