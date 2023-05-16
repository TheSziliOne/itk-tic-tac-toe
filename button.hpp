#ifndef BUTTON_HPP
#define BUTTON_HPP


#include "graphics.hpp"
#include "widgets.hpp"

class Button : public Widget {
protected:
    bool _checked;
public:
    Button(int x, int y, int sx, int sy);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() ;
};

#endif // BUTTON_HPP
