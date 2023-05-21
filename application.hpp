#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "widgets.hpp"
#include "cell.hpp"

using namespace std;

class Application
{
private:
    vector<Widget*> _widgets;
    Cell* _cells[15][15];
    int _width, _height;
    bool _is_player_one;
    void start_screen();
    void event_loop();
    void setup();
    void logic();
    void diagonal_check_RtoL_bhalf(int y);
    void diagonal_check_RtoL_uhalf(int y);
    void diagonal_check_LtoR_bhalf(int y);
    void diagonal_check_LtoR_uhalf(int y);
    void restart_panel();
    bool _is_won  = false;
public:
    Application(int width,int height);
    int get_width();
    int get_height();
    bool get_is_player_pne();
    void start();
};

#endif // APPLICATION_HPP
