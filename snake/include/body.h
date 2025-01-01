#ifndef BODY_H_
#define BODY_H_

#include "element.h"

class Body : public Element {
public:
    Body(double x, double y, int color, WINDOW* win) {
        _x = x;
        _y = y;
        _color = color;
        _to_draw = "\u25A0";
        _win = win;
    }
};

#endif
