#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
#include "szamlalo.hpp"
#include "list.hpp"
#include "button.hpp"
#include <fstream>
using namespace std;
using namespace genv;

void event_loop(vector<Widget*>& widgets) {
    event ev;
    int focus = -1;
    while(gin >> ev )
    {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (Widget * w : widgets) {
            w->draw();
        }
        gout << refresh;
    }
}


int main()
{
    gout.open(400,400);

    vector<Widget*> w;

    Widget * b1 = new Button(100,10,50,50);
    Widget * b2 = new Button(100,58,50,50);

    w.push_back(b1);
    w.push_back(b2);
    for (Widget * wg : w) {
        wg->draw();
    }

    gout << refresh;
    event_loop(w);
    return 0;
}
