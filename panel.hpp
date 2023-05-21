#ifndef PANEL_H
#define PANEL_H
#include "widgets.hpp"
#include "application.hpp"

class Panel : public Widget
{
private:
    bool _is_p1;
public:
    Panel(int x,int y,int sx,int sy,bool is_p1);
    void draw();
    void handle(genv::event ev);
};

#endif // PANEL_H
