#include "button.hpp"
#include "graphics.hpp"
using namespace genv;

Button::Button(int x, int y, int sx, int sy) : Widget(x,y,sx,sy)
{
}

void Button::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
    {
    }
}


