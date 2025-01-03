#ifndef BODY_H_
#define BODY_H_

#include "element.h"

class Body : public Element {
public:
    Body(int x, int y, int color, WINDOW* win) :
        Element(x, y, color, "\u25A0", win) {}
};

#endif
