#include "game.h"

#include <curses.h>
#include <ncurses.h>
#include <locale.h>
#include <chrono>
#include <thread>

#define WIDTH 60
#define HEIGHT 30
#define SPEED 0.1

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

    _game_win = newwin(HEIGHT, WIDTH, 0, 0);
    _snake = Snake(WIDTH / 2, HEIGHT / 2, SPEED, Snake::Dir::Right, COLOR_GREEN, _game_win);
    _snake.grow();

    _elements.push_back(&_snake);
    _isRunning = true;
}

void Game::run() {
    const std::chrono::milliseconds frameDuration(1000 / _fps);
    while (_isRunning) {
        auto startTime = std::chrono::steady_clock::now();

        _handleInput();
        _update();
        _draw();

        auto elapsedTime = std::chrono::steady_clock::now() - startTime;
        auto sleepDuration = frameDuration - std::chrono::duration_cast<std::chrono::milliseconds>(elapsedTime);
        if (sleepDuration > std::chrono::milliseconds(0)) {
            std::this_thread::sleep_for(sleepDuration);
        }
    }
}

void Game::cleanup() {
    delwin(_game_win);
    endwin();
}

void Game::_handleInput() {
    int ch = getch();
    if (ch != ERR) {
        if (ch == 'q') _isRunning = false;
        else if (ch == 'w') _snake.setDir(Snake::Dir::Up);
        else if (ch == 'a') _snake.setDir(Snake::Dir::Left);
        else if (ch == 's') _snake.setDir(Snake::Dir::Down);
        else if (ch == 'd') _snake.setDir(Snake::Dir::Right);
    }
}

void Game::_update() {
    for (auto& element : _elements) {
        element->update();
    }
}

void Game::_draw() {
    werase(_game_win);
    for (auto& element : _elements) {
        element->draw();
    }
    box(_game_win, 0, 0);
    wrefresh(_game_win);
}

