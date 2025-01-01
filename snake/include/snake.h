#ifndef SNAKE_H_
#define SNAKE_H_

#include "body.h"
#include "element.h"

#include <memory>
#include <vector>

class Snake : public Element {
public:
    enum Dir { Up = 0, Left, Down, Right };

    Snake(WINDOW* win) {
        Snake(0, 0, 0, Right, COLOR_GREEN, win);
    }

    Snake(double x, double y, double vel, Dir dir, int color, WINDOW* win) {
        _x = x;
        _y = y;
        _vel = vel;
        _dir = dir;
        _color = color;
        _win = win;
        _bodies.push_back(std::make_shared<Body>(x, y, color, win));
    }

    void setDir(Dir dir);
    void update();
    void draw();
    void grow();

private:
    Dir _dir;
    double _vel;
    std::vector<std::shared_ptr<Body>> _bodies;
};

#endif
