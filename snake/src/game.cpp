#include "game.h"

#include <iostream>
#include <ncurses.h>
#include <locale.h>
#include <chrono>
#include <thread>

#define WIDTH 40
#define HEIGHT 20
#define SPEED 0.1
#define SPEED_INC 0.015

void Game::initialize() {
    setlocale(LC_ALL, "en_US.UTF-8");
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);

    _text_win = newwin(1, WIDTH, 0, 0);
    _game_win = newwin(HEIGHT, WIDTH, 1, 0);
    _snake = Snake(WIDTH / 2, HEIGHT / 2, SPEED, SPEED_INC, _game_win);
    _apple = Apple(_game_win);

    _elements.push_back(&_apple);
    _elements.push_back(&_snake);

    start();
}

void Game::start() {
    _snake.reset(WIDTH / 2, HEIGHT / 2, SPEED, Element::Right);

    _isGameOver = false;
    _score = 0;
    _apple.move();
}

void Game::run() {
    const std::chrono::milliseconds frameDuration(1000 / _fps);
    while (_isRunning) {
        auto startTime = std::chrono::steady_clock::now();

        _handleInput();

        if (!_isGameOver) {
            _update();
            _draw();
        }

        auto elapsedTime = std::chrono::steady_clock::now() - startTime;
        auto sleepDuration = frameDuration - std::chrono::duration_cast<std::chrono::milliseconds>(elapsedTime);
        if (sleepDuration > std::chrono::milliseconds(0)) {
            std::this_thread::sleep_for(sleepDuration);
        }
    }
}

void Game::cleanup() {
    delwin(_text_win);
    delwin(_game_win);
    endwin();
}

void Game::_handleInput() {
    int ch = getch();
    if (ch != ERR) {
        switch (ch) {
        case 'q':
            _isRunning = false;
            break;
        case 'r':
            start();
            break;
        case KEY_UP:
            _snake.setDir(Snake::Dir::Up);
            break;
        case KEY_LEFT:
            _snake.setDir(Snake::Dir::Left);
            break;
        case KEY_DOWN:
            _snake.setDir(Snake::Dir::Down);
            break;
        case KEY_RIGHT:
            _snake.setDir(Snake::Dir::Right);
        }
    }
}

void Game::_update() {
    if (_snake.getX() == _apple.getX() && _snake.getY() == _apple.getY()) {
        _snake.grow();
        _snake.speedUp();
        _apple.move();
        _score++;
    }

    if (_snake.isWallCollide() || _snake.isSelfCollide()) {
        _isGameOver = true;
    }

    for (auto& element : _elements) {
        element->update();
    }
}

void Game::_draw() {
    werase(_text_win);
    werase(_game_win);
    mvwaddstr(_text_win, 0, 0, ("score: " + std::to_string(_score)).c_str());
    for (auto& element : _elements) {
        element->draw();
    }
    box(_game_win, 0, 0);
    wrefresh(_text_win);
    wrefresh(_game_win);
}

