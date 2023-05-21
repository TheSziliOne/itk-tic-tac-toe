#ifndef CELL_HPP
#define CELL_HPP
#include "widgets.hpp"
using namespace genv;

class Cell : public Widget
{
private:
    bool _is_X;
    bool _is_claimed;
public:
    Cell(int x, int y, int sx, int sy);
    bool get_is_X();
    void set_is_X(bool _is_X);
    bool get_is_claimed();
    void draw();
    bool on_claim(bool _is_X);
    virtual void handle(genv::event ev);
};

#endif // CELL_HPP
