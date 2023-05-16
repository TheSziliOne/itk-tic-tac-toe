#include "application.hpp"
#include "graphics.hpp"

using namespace genv;

Application::Application(int width, int height) : _width(width),_height(height)
{}

void Application::draw()
{
    gout.open(_width,_height);

}

void Application::event_loop()
{
    draw();
    event ev;
    int focus = -1;
    while(gin >> ev )
    {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<_widgets.size();i++) {
                if (_widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            _widgets[focus]->handle(ev);
        }
        for (Widget * w : _widgets) {
            w->draw();
        }
        gout << refresh;
    }


}
