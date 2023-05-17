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
    void draw();
    void event_loop();
    void setup();
    void logic();
public:
    Application(int width,int height);
    void start();
};

#endif // APPLICATION_HPP
