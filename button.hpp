#ifndef BUTTON_HPP
#define BUTTON_HPP


#include "graphics.hpp"
#include "widgets.hpp"

class Button : public Widget
{
protected:
public:
    Button(int x, int y, int sx, int sy);
    virtual void handle(genv::event ev);
};

#endif // BUTTON_HPP
