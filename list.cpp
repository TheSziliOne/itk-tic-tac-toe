#include "list.hpp"
#include "graphics.hpp"
#include <vector>
#include <iostream>

using namespace genv;
using namespace std;

ListMenu::ListMenu(int x, int y, int s_x, int s_y, vector<string> v, int row_num):Widget(x,y,s_x,s_y),_row(v),_row_number(row_num)
{
    _top_row=0;
    _selected_row=0;

    refresh();
}

void ListMenu::draw()
{

    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y)
         << move_to(_x+1, _y+1) << color(0,0,0) << box(_size_x-2, _size_y-2);


    for(int i = 0; i < (int)_visible_rows.size();i++)
    {
        if(_top_row + i == _selected_row)
        {
            gout << move_to(_x, _y + 1 + i * 30) << color(255,255,255) << box(_size_x, 30)
                 << move_to(_x + 1, _y + 1 + i * 30) << color(0,255,0) << box(_size_x-2,30-2)
                 << move_to(_x + 2, _y + 20 + i * 30) << color (0,0,0) << text(_visible_rows.at(i));

        }

        else
        {
            gout << move_to(_x, _y +1 + i * 30) << color(255,255,255) << box(_size_x, 30)
                 << move_to(_x + 1, _y + 1 + i * 30) << color(0,0,0) << box(_size_x-2, 30-2)
                 << move_to(_x + 2, _y + 20 + i * 30) << color (255,255,255) << text(_visible_rows.at(i));
        }
    }
}

void ListMenu::handle(event ev)
{

    if(ev.type==ev_mouse && ev.button==btn_wheeldown)
    {
        scroll_down();
    }

    else if(ev.type==ev_mouse && ev.button==btn_wheelup)
    {
        scroll_up();
    }

    for(int i=0;i<_row_number;i++)
    {
        if(ev.type==ev_mouse && ev.pos_x<_x+_size_x && ev.pos_x>_x && ev.pos_y>_y+i*30 && ev.pos_y<_y+(i+1)*30 && ev.button==btn_left)
        {
            _selected_row=_top_row+i;
        }
    }
}

void ListMenu::scroll_up()
{
    if (_top_row>0)
    {
        _top_row -= 1;
        refresh();
    }
}

void ListMenu::scroll_down()
{
    if (_top_row + _row_number < (int)_row.size())
    {
        _top_row +=1 ;
        refresh();
    }
}

vector<string> ListMenu::vector_change(int starter, int last)
{
    vector<string> result(_row.begin() + starter,_row.begin() + last);
    return result;
}

void ListMenu::refresh()
{
    if(_row_number < (int)_row.size())
    {
        _visible_rows = vector_change(_top_row,_top_row+_row_number);
    }

    else
    {
        _visible_rows=_row;
    }
}

void ListMenu::add(string new_row)
{
    _row.push_back(new_row);
    refresh();
}

void ListMenu::remove(int index)
{
    if(index >=  0 and index <= (int)_row.size())
    {
        _row.erase(_row.begin() + index);
    }
    refresh();
}


