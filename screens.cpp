#include "screens.hpp"
#include "graphics.hpp"
#include "application.hpp"

using namespace genv;

void Screens::victory_screen(int width, int height)
{
    gout << move_to(0,0);
    gout << color(0,0,0);
    gout << box(width,height);

}
