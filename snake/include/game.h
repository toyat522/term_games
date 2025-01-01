#ifndef GAME_H_
#define GAME_H_

#include "element.h"
#include "snake.h"

#include <vector>

class Game {
public:
    Game() : _isRunning(false), _fps(60), _snake(_game_win) {}
    void initialize();
    void run();
    void cleanup();

private:
    std::vector<Element*> _elements;
    WINDOW* _game_win;

    bool _isRunning;
    int _fps;
    void _handleInput();
    void _update();
    void _draw();

    Snake _snake;
};

#endif
