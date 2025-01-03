#include "apple.h"

void Apple::move() {
    int width, height;
    getmaxyx(_win, height, width);

    std::uniform_int_distribution<> x_dist(1, width - 2);
    std::uniform_int_distribution<> y_dist(1, height - 2);
    _x = x_dist(_gen);
    _y = y_dist(_gen);
}
