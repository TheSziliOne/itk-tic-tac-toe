#include "szamlalo.hpp"
#include "graphics.hpp"
using namespace genv;

Counter::Counter(int x, int y, int sx, int sy, int starter_value, int min, int max) : Widget(x,y,sx,sy), _min(min), _max(max)
{
    if (starter_value >= _max)
    {
        _value = _max;
    }
    if (starter_value <= _min)
    {
        _value = _min;
    }
    else if (starter_value < _max && starter_value > _min)
    {
        _value = starter_value;
    }
}

void Counter::draw()
{
    gout << move_to(_x, _y) << color(100, 100, 100) << box(_size_x, _size_y);
    gout << color(255,0,0) << move_to(_x + _size_x - _size_x/5 , _y + _size_y/2 + 1) << box(_size_x/5-1,_size_y/2 - 2);
    gout << color(0,255,0) << move_to(_x + _size_x - _size_x/5 , _y+1 ) << box(_size_x/5 -1,_size_y/2 -1);
    gout << move_to(_x+4, _y+_size_y/1.7);
    gout << color(255,255,255);
    gout << text(to_string(_value));
}

void Counter::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x,ev.pos_y))
    {
        if (ev.button == btn_left)
        {
            if (ev.pos_x > _x + _size_x - _size_x / 5 && ev.pos_x < _x + _size_x - _size_x / 5 + _size_x / 5.2 && ev.pos_y > _y + 1 && ev.pos_y < _y + _size_y - _size_y / 2)
            {
                _value = add(1);
            }
            if (ev.pos_x > _x + _size_x - _size_x / 5 && ev.pos_x < _x + _size_x - 1 && ev.pos_y > _y + _size_y - _size_y / 2 -2 && ev.pos_y < _y + _size_y - 1)
            {
                _value = add(-1);
            }
        }
    }
    if(ev.keycode == key_up)
    {
        _value = add(1);
    }
    if(ev.keycode == key_down)
    {
        _value = add(-1);
    }
    if(ev.keycode == key_pgup)
    {
        _value = add(10);
    }
    if(ev.keycode == key_pgdn)
    {
        _value= add(-10);
    }
}

int Counter::add(int add_value)
{
    int sum = _value+add_value;

    if(sum < _max && sum > _min)
    {
        return sum;
    }
    if(sum >= _max)
    {
        return _max;
    }
    if(sum <= _min)
    {
        return _min;
    }
    return 0;
}



