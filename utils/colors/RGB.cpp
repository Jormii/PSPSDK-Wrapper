#include "./RGB.hpp"

RGB::RGB(unsigned char r, unsigned char g, unsigned char b)
{
    // Find how to calcular hex
    this->r = r;
    this->g = g;
    this->b = b;
}

RGB::~RGB()
{
}

unsigned int RGB::value()
{
    return r + (g << 8) + (b << 16);
}