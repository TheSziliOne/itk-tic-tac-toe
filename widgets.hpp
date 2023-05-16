#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include <functional>
#include <fstream>

class Widget
{
protected:
    int _x;
    int _y;
    int _size_x;
    int _size_y;
public:
    Widget(int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
};
#endif // WIDGETS_HPP_INCLUDED
