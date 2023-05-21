#include "panel.hpp"
#include "graphics.hpp"

using namespace genv;

Panel::Panel(int x, int y, int sx, int sy, bool is_p1) : Widget(x,y,sx,sy),_is_p1(is_p1)
{

}

void Panel::draw()
{
    if(_is_p1)
    {
        gout << color(255,255,0);
        gout << move_to(640/2.5, 480/1.1);
        gout << text("Jatekos 1 nyert!");
    }
    if(!_is_p1)
    {
        gout << color(255,0,0);
        gout << move_to(640/2.5, 480/1.1);
        gout << text("Jatekos 2 nyert!");
    }

}

void Panel::handle(event ev)
{
}
