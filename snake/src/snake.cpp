#include "snake.h"

void Snake::grow() {
    _bodies.push_back(std::make_shared<Body>(_x, _y, _color, _win));
}

void Snake::setDir(Dir dir) {
    if (_bodies.size() <= 1 || (dir + _dir) % 2 == 1) {
        _dir = dir;
    }
}

void Snake::update() {
    if (_dir == Right) {
        _vx = _vel;
        _vy = 0;
    } else if (_dir == Left) {
        _vx = -_vel;
        _vy = 0;
    } else if (_dir == Down) {
        _vx = 0;
        _vy = _vel;
    } else if (_dir == Up) {
        _vx = 0;
        _vy = -_vel;
    }

    double prev_x = _x;
    double prev_y = _y;
    Element::update();

    if ((int)prev_x != (int)_x || (int)prev_y != (int)_y) {
        for (int i = _bodies.size() - 1; i >= 1; i--) {
            _bodies[i]->setX(_bodies[i - 1]->getX());
            _bodies[i]->setY(_bodies[i - 1]->getY());
        }
        _bodies[0]->setX(_x);
        _bodies[0]->setY(_y);
    }
}

void Snake::draw() {
    for (auto& body : _bodies) {
        body->draw();
    }
}
