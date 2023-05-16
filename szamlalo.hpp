#ifndef SZAMLALO_H
#define SZAMLALO_H

#include "graphics.hpp"
#include "widgets.hpp"

using namespace std;

class Counter : public Widget
{
private:
    int _value;
    int _min;
    int _max;
    virtual int add(int value);
public:
    Counter(int x, int y, int sx, int sy, int starter_value, int min, int max);
    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // SZAMLALO_H
