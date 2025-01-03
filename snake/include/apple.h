#ifndef APPLE_H_
#define APPLE_H_

#include "element.h"

#include <random>

class Apple : public Element {
public:
    Apple(WINDOW* win) : Apple(0, 0, win) {}

    Apple(double x, double y, WINDOW* win) :
        Apple(x, y, COLOR_RED, win) {}

    Apple(double x, double y, int color, WINDOW* win) :
        Element(x, y, color, "\u25CF", win), _gen(std::random_device{}()) {}

    void move();

private:
    std::mt19937 _gen;
};

#endif
