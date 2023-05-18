#ifndef CELL_HPP
#define CELL_HPP
#include "button.hpp"
using namespace genv;

class Cell : public Button
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
};

#endif // CELL_HPP
