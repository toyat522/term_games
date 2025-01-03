#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <string>
#include <ncurses.h>

class Element {
public:
    enum Dir { Up = 0, Left, Down, Right };

    Element();

    Element(int x, int y, int color, std::string to_draw, WINDOW* win) :
        _x(x), _y(y), _vel(0), _next_dir(Right), _dir(Right),
        _vel_counter(0), _color(color), _to_draw(to_draw), _win(win) {}

    Element(int x, int y, double vel, Dir dir, int color, WINDOW* win) :
        _x(x), _y(y), _vel(vel), _next_dir(dir), _dir(dir),
        _vel_counter(0), _color(color), _to_draw(""), _win(win) {}

    Element(int x, int y, double vel, Dir dir, int color, std::string to_draw, WINDOW* win) :
        _x(x), _y(y), _vel(vel), _next_dir(dir), _dir(dir),
        _color(color), _to_draw(to_draw), _win(win) {}

    virtual void update();
    virtual void onTick();
    virtual void draw();
    virtual void setDir(Dir dir);
    virtual void setX(double x);
    virtual void setY(double y);
    virtual Dir getDir();
    virtual int getX();
    virtual int getY();

protected:
    Dir _next_dir, _dir;
    int _x, _y;
    double _vel, _vel_counter;
    int _color;
    std::string _to_draw;
    WINDOW* _win;
};

#endif
