#ifndef RGB_H
#define RGB_H

class RGB
{
private:
    unsigned char r;
    unsigned char g;
    unsigned char b;

public:
    RGB(unsigned char r, unsigned char g, unsigned char b);
    ~RGB();

    unsigned int value();
};

const RGB rgb_white = RGB(255, 255, 255);

#endif