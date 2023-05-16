#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "widgets.hpp"

using namespace std;

class Application
{
private:
    vector<Widget*> _widgets;
    int _width, _height;
    void draw();
public:
    Application(int width,int height);
    void event_loop();
};

#endif // APPLICATION_HPP
