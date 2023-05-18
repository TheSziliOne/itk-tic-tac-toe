#include "cell.hpp"
#include "graphics.hpp"
#include "button.hpp"
#include <cmath>;

using namespace genv;

Cell::Cell(int x, int y, int sx, int sy) : Button(x,y,sx,sy)
{
    _is_X = false;
    _is_claimed = false;
}

void Cell::draw()
{

    if (_is_claimed)
    {
        if (_is_X)
        {
            gout << color(255,255,0);
            gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
            gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
            gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
            gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
        }
        else
        {
            gout << move_to(_x+4, _y+4) << color(255,0,0) << box(_size_x-8, _size_y-8);
            gout << move_to(_x+6, _y+6) << color(0,0,0) << box(_size_x-12, _size_y-12);
        }
    }
    else
    {
        gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    }
}




bool Cell::get_is_X()
{
    return _is_X;
}

void  Cell::set_is_X(bool _is_X)
{
    this->_is_X = _is_X;
}
bool Cell::on_claim(bool _is_X)
{
    if (!_is_claimed)
    {
        this -> _is_X = _is_X;
        _is_claimed = true;
        return true;
    }
    return false;
}

bool Cell::get_is_claimed()
{
    return _is_claimed;
}
