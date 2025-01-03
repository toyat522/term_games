#include "snake.h"

void Snake::reset(int x, int y, double vel, Dir dir) {
    _x = x;
    _y = y;
    _vel = vel;
    _dir = dir;
    _next_dir = dir;
    _bodies = {std::make_shared<Body>(_x, _y, _color, _win)};
}

void Snake::grow() {
    int n = _bodies.size() - 1;
    _bodies.push_back(std::make_shared<Body>(
        _bodies[n]->getX(), _bodies[n]->getY(), _color, _win)
    );
}

void Snake::speedUp() {
    _vel += _vel_inc;
}

void Snake::setDir(Dir dir) {
    if (_bodies.size() <= 1 || (dir + _dir) % 2 == 1) {
        _next_dir = dir;
    }
}

void Snake::_moveBodies() {
    for (int i = _bodies.size() - 1; i >= 1; i--) {
        _bodies[i]->setX(_bodies[i - 1]->getX());
        _bodies[i]->setY(_bodies[i - 1]->getY());
    }
    _bodies[0]->setX(_x);
    _bodies[0]->setY(_y);
}

bool Snake::isWallCollide() {
    int width, height;
    getmaxyx(_win, height, width);
    return _x > width - 2 || _x < 1 || _y > height - 2 || _y < 1;
}

bool Snake::isSelfCollide() {
    for (int i = 2; i < _bodies.size(); i++) {
        if (_bodies[i]->getX() == _x && _bodies[i]->getY() == _y)
            return true;
    }
    return false;
}

void Snake::onTick() {
    Element::onTick();
    _moveBodies();
}

void Snake::update() {
    Element::update();
}

void Snake::draw() {
    for (auto& body : _bodies) {
        body->draw();
    }
}
