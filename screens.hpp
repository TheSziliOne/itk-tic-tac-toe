#ifndef SCREENS_HPP
#define SCREENS_HPP

#include "widgets.hpp"

class Screens: public Widget
{
public:
    bool is_menu = true;
    void draw();
};

#endif // SCREENS_HPP
