#ifndef GAME_H
#define GAME_H

#include "Difficulty.h"
#include "Player.h"

class Game {
public:
    void start();

private:
    void userGuessMode(Difficulty difficulty);
    void computerGuessMode();
    Difficulty selectDifficulty();
    int selectMode();
};

#endif // GAME_H
