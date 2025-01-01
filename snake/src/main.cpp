#include "game.h"

int main() {
    Game game;
    game.initialize();
    game.run();
    game.cleanup();
    return 0;
}
