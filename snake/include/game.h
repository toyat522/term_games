#ifndef GAME_H_
#define GAME_H_

#include "element.h"
#include "apple.h"
#include "snake.h"

#include <memory>
#include <vector>

class Game {
public:
    Game() : _isRunning(true), _isGameOver(false), _fps(60),
        _snake(_game_win), _apple(_game_win) {}
    void initialize();
    void start();
    void run();
    void cleanup();

private:
    std::vector<Element*> _elements;
    WINDOW* _game_win;
    WINDOW* _text_win;

    int _score;
    bool _isGameOver;
    bool _isRunning;
    int _fps;
    void _handleInput();
    void _update();
    void _draw();

    Snake _snake;
    Apple _apple;
};

#endif
