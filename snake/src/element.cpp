#include "element.h"

void Element::setX(double x) {
    _x = x;
}

void Element::setY(double y) {
    _y = y;
}

void Element::setVx(double vx) {
    _vx = vx;
}

void Element::setVy(double vy) {
    _vy = vy;
}

int Element::getX() {
    return (int)_x;
}

int Element::getY() {
    return (int)_y;
}

void Element::draw() {
    wattron(_win, COLOR_PAIR(_color));
    mvwaddstr(_win, (int)_y, (int)_x, _to_draw.c_str());
    wattroff(_win, COLOR_PAIR(_color));
}

void Element::update() {
    _x += _vx;
    _y += _vy;
}
