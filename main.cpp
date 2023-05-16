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
    vector<string> a;
    a.push_back("1 elem");
    a.push_back("2 elem");
    a.push_back("3 elem");
    a.push_back("4 elem");
    vector<string> b;
    b.push_back("elso");
    b.push_back("masodik");
    b.push_back("harmadik");
    b.push_back("negyedik");
    b.push_back("otodik");

    vector<Widget*> w;

    Widget * c1 = new Counter(10,10,50,25,50,-10,10); //x koordináta, y koordináta, szélesség, magasság, kezdőérték, minimum érték, maximum érték
    Widget * c2 = new Counter(10,50,40,25,0,-20,20);
    Widget * lm1 = new ListMenu(65,100,100,60,a,2); //x koordináta, y koordináta, szélesség, magasság,string elemeket tartalmazó vektor, összes látható sor
    Widget * lm2 = new ListMenu(200,100,100,150,b,5);
    Widget * b1 = new Button(100,10,50,50);

    w.push_back(c1);
    w.push_back(c2);
    w.push_back(lm1);
    w.push_back(lm2);
    w.push_back(b1);
    for (Widget * wg : w) {
        wg->draw();
    }

    gout << refresh;
    event_loop(w);
    return 0;
}
