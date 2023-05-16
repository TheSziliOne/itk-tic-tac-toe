#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
#include <string>
using namespace genv;
using namespace std;

class ListMenu : public Widget
{
private:
    vector<string> _row;
    vector<string> _visible_rows;

    int _row_number;
    int _top_row;

    vector<int> _visible_row_id;
    int _selected_row;

    string _new_row;
public:
    ListMenu(int x, int y, int sx, int sy, vector<string> v, int row_num);
    virtual void draw();
    virtual void handle(event ev);
    virtual vector<string> vector_change(int starter, int last);
    virtual void scroll_down();
    virtual void scroll_up();
    virtual void refresh();

    virtual void add(string);
    virtual void remove(int);

};

#endif // LIST_HPP_INCLUDED
