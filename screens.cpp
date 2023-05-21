#include "screens.hpp"
#include "graphics.hpp"
#include "application.hpp"

using namespace genv;

void Screens::draw_screen(int width, int height)
{
    gout.open(width,height);
}

