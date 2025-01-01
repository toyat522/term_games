#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <string>
#include <ncurses.h>

class Element {
public:
    virtual void update();
    virtual void draw();
    void setX(double x);
    void setY(double y);
    void setVx(double vx);
    void setVy(double vy);
    int getX();
    int getY();

protected:
    double _x, _y, _vx, _vy;
    int _color;
    std::string _to_draw;
    WINDOW* _win;
};

#endif
