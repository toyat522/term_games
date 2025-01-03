#include "element.h"

void Element::setDir(Dir dir) {
    _next_dir = dir;
}

void Element::setX(double x) {
    _x = x;
}

void Element::setY(double y) {
    _y = y;
}

Element::Dir Element::getDir() {
    return _dir;
}

int Element::getX() {
    return _x;
}

int Element::getY() {
    return _y;
}

void Element::draw() {
    wattron(_win, COLOR_PAIR(_color));
    mvwaddstr(_win, (int)_y, (int)_x, _to_draw.c_str());
    wattroff(_win, COLOR_PAIR(_color));
}

void Element::onTick() {
    _dir = _next_dir;
    if (_dir == Element::Left) _x--;
    else if (_dir == Element::Right) _x++;
    else if (_dir == Element::Up) _y--;
    else if (_dir == Element::Down) _y++;
}

void Element::update() {
    _vel_counter += _vel;
    if (_vel_counter >= 1) {
        _vel_counter = 0;
        onTick();
    }
}
