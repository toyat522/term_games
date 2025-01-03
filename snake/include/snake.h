#ifndef SNAKE_H_
#define SNAKE_H_

#include "body.h"
#include "element.h"

#include <memory>
#include <vector>

class Snake : public Element {
public:

    Snake(WINDOW* win) : Snake(0, 0, 0, Right, win) {}

    Snake(int x, int y, double vel, Dir dir, WINDOW* win) :
        Snake(x, y, vel, dir, COLOR_GREEN, 0.02, win) {}

    Snake(int x, int y, double vel, Dir dir, double vel_inc, WINDOW* win) :
        Snake(x, y, vel, dir, COLOR_GREEN, vel_inc, win) {}

    Snake(int x, int y, double vel, double vel_inc, WINDOW* win) :
        Snake(x, y, vel, Right, COLOR_GREEN, vel_inc, win) {}

    Snake(int x, int y, double vel, Dir dir, int color, double vel_inc, WINDOW* win) :
        Element(x, y, vel, dir, color, win), _vel_inc(vel_inc) {
        _bodies.push_back(std::make_shared<Body>(_x, _y, _color, _win));
    }

    void reset(int x, int y, double vel, Dir dir);
    void setDir(Dir dir);
    void onTick();
    void update();
    void draw();
    void grow();
    void speedUp();
    bool isWallCollide();
    bool isSelfCollide();

private:
    void _moveBodies();

    double _vel_inc;
    std::vector<std::shared_ptr<Body>> _bodies;
};

#endif
