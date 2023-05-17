#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
#include "szamlalo.hpp"
#include "list.hpp"
#include "button.hpp"
#include "application.hpp"
#include <fstream>
using namespace std;
using namespace genv;

int main()
{
    Application app = Application(640,480);
    app.start();
    return 0;
}
