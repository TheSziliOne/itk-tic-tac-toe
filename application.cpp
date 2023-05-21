#include "application.hpp"
#include "graphics.hpp"
#include "cell.hpp"
#include "panel.hpp"

using namespace genv;
using namespace std;

Application::Application(int width, int height) : _width(width),_height(height)
{
    _is_player_one = true;
}

void Application::restart_panel()
{
    Panel* p = new Panel(640,480,200,50, !_is_player_one);
    p->draw();
}

void Application::logic()
{
    int p1_points = 0;
    int p2_points = 0;
    int kx = 15;
    int ky = 15;

//-------------Oszlopra win condition check-------------------//
    for(int x = 0; x < kx; x++)
    {
        for(int y = 0; y < ky; y++)
        {
            if(_cells[x][y]->get_is_X() == true && _cells[x][y]->get_is_claimed())
            {
                p1_points++;
                p2_points = 0;

                if (p1_points == 5)
                {
                   _is_won = true;
                }
                if (y == 14)
                {
                    p1_points = 0;
                }
            }
            else if(_cells[x][y]->get_is_X() == false && _cells[x][y]->get_is_claimed())
            {
                p2_points++;
                p1_points = 0;

                if (p2_points == 5)
                {
                    _is_won = true;
                }
                if (y == 14)
                {
                    p2_points = 0;
                }
            }
            else
            {
                p1_points = 0;
                p2_points = 0;
            }
        }

    p1_points = 0;
    p2_points = 0;

    }
//-------------Sorra win condition check-------------------//
    for(int x = 0; x < kx; x++)
    {
        for(int y = 0; y < ky; y++)
        {
            if(_cells[y][x]->get_is_X() == true && _cells[y][x]->get_is_claimed())
            {
                p1_points++;
                p2_points = 0;

                if (p1_points == 5)
                {
                   _is_won = true;
                }
                if (y == 14)
                {
                    p1_points = 0;
                }
            }
            else if(_cells[y][x]->get_is_X() == false && _cells[y][x]->get_is_claimed())
            {
                p2_points++;
                p1_points = 0;

                if (p2_points == 5)
                {
                    _is_won = true;
                }
                if (y == 14)
                {
                    p2_points = 0;
                }
            }
            else
            {
                p1_points = 0;
                p2_points = 0;
            }
        }

    p1_points = 0;
    p2_points = 0;

    }
//-------------Jobbról-Balra dőlő diagonális win condition check-------------------//

    for(int i = 0; i < 15; i++)
    {
        diagonal_check_RtoL_bhalf(i);
    }
    for(int i = 0; i < 15; i++)
    {
        diagonal_check_RtoL_uhalf(i);
    }

//-------------Balról-Jobbra dőlő diagonális win condition check-------------------//

    for(int i = 0; i < 15; i++)
    {
        diagonal_check_LtoR_bhalf(i);
    }

    for(int i = 0; i < 15; i++)
    {
        diagonal_check_LtoR_uhalf(i);
    }

    p1_points = 0;
    p2_points = 0;

//--------------------------------------------------------------------------------//
}

void Application::start_screen()
{
    gout.open(_width,_height);
}

void Application::start()
{
    setup();
    event_loop();

}

void Application::setup()
{
    for(int x = 0; x < 15; x++)
    {
        for(int y = 0; y < 15; y++)
        {
            int ix = 25;
            int iy = 25;

            _cells[x][y] = new Cell(_width/4.8 + (x * (ix)), _height/15 + (y * (iy)) ,ix,iy);
        }
    }
}


void Application::event_loop()
{

    start_screen();
    event ev;
    int focus = -1;
    while(gin >> ev )
    {
        logic();
        if (ev.type == ev_mouse && ev.button==btn_left && !_is_won)
        {
            for (size_t i=0;i<_widgets.size();i++)
            {
                if (_widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                        focus = i;
                        break;
                }
            }
            for(int x = 0; x < 15; x++)
            {
                for(int y = 0; y < 15; y++)
                {

                    if (_cells[x][y]->is_selected(ev.pos_x, ev.pos_y))
                    {
                        if (_cells[x][y] -> on_claim(_is_player_one)){
                            _is_player_one = !_is_player_one;
                        }
                        break;
                    }
                }
            }
        }
        if (focus!=-1) {
            _widgets[focus]->handle(ev);
        }       
        for (Widget * w : _widgets) {
            w->draw();
        }
        for(int x = 0; x < 15; x++)
        {
            for(int y = 0; y < 15; y++)
            {
                _cells[x][y]->draw();
            }
        }
        if(_is_won)
        {
            restart_panel();
        }
        gout << refresh;
    }
}

void Application::diagonal_check_RtoL_bhalf(int _y)
{
    int p1_points = 0;
    int p2_points = 0;
    int x = 0;
    for (int y = _y; y < 15; y++)
    {

        if(_cells[x][y]->get_is_X() == true && _cells[x][y]->get_is_claimed())
        {
            p1_points++;
            p2_points = 0;

            if (p1_points == 5)
            {
               _is_won = true;
            }
            if (y == 14)
            {
                p1_points = 0;
            }
        }
        else if(_cells[x][y]->get_is_X() == false && _cells[x][y]->get_is_claimed())
        {
            p2_points++;
            p1_points = 0;

            if (p2_points == 5)
            {
                _is_won = true;
            }
            if (y == 14)
            {
                p2_points = 0;
            }
        }
        else
        {
            p1_points = 0;
            p2_points = 0;
        }
        x++;
    }
}

void Application::diagonal_check_RtoL_uhalf(int _x)
{
    int p1_points = 0;
    int p2_points = 0;
    int y = 0;
    for (int x = _x; x < 15; x++)
    {
        if(_cells[x][y]->get_is_X() == true && _cells[x][y]->get_is_claimed())
        {
            p1_points++;
            p2_points = 0;

            if (p1_points == 5)
            {
               _is_won = true;
            }
            if (x == 14)
            {
                p1_points = 0;
            }
        }
        else if(_cells[x][y]->get_is_X() == false && _cells[x][y]->get_is_claimed())
        {
            p2_points++;
            p1_points = 0;

            if (p2_points == 5)
            {
               _is_won = true;
            }
            if (x == 14)
            {
                p2_points = 0;
            }
        }
        else
        {
            p1_points = 0;
            p2_points = 0;
        }
        y++;
    }
}

void Application::diagonal_check_LtoR_bhalf(int _x)
{
    int p1_points = 0;
    int p2_points = 0;
    int y = 14;
    for (int x = _x; x < 15; x++)
    {

        if(_cells[x][y]->get_is_X() == true && _cells[x][y]->get_is_claimed())
        {
            p1_points++;
            p2_points = 0;

            if (p1_points == 5)
            {
               _is_won = true;
            }
            if (y == 0)
            {
                p1_points = 0;
            }
        }
        else if(_cells[x][y]->get_is_X() == false && _cells[x][y]->get_is_claimed())
        {
            p2_points++;
            p1_points = 0;

            if (p2_points == 5)
            {
                _is_won = true;
            }
            if (y == 0)
            {
                p2_points = 0;
            }
        }
        else
        {
            p1_points = 0;
            p2_points = 0;
        }
        y--;
    }
}

void Application::diagonal_check_LtoR_uhalf(int _y)
{
    int p1_points = 0;
    int p2_points = 0;
    int x = 0;
    for (int y = _y; y >= 0; y--)
    {

        if(_cells[x][y]->get_is_X() == true && _cells[x][y]->get_is_claimed())
        {
            p1_points++;
            p2_points = 0;

            if (p1_points == 5)
            {
               _is_won = true;
            }
            if (y == 0)
            {
                p1_points = 0;
            }
        }
        else if(_cells[x][y]->get_is_X() == false && _cells[x][y]->get_is_claimed())
        {
            p2_points++;
            p1_points = 0;

            if (p2_points == 5)
            {
                _is_won = true;
            }
            if (y == 0)
            {
                p2_points = 0;
            }
        }
        else
        {
            p1_points = 0;
            p2_points = 0;
        }
        x++;
    }
}

int Application::get_width()
{
    return _width;
}

int Application::get_height()
{
    return _height;
}

bool Application ::get_is_player_pne()
{
    return _is_player_one;
}
