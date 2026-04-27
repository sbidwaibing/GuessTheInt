#include "Game.h"
#include "Utils.h"
#include "ComputerGuesser.h"
#include <iostream>
#include <cmath>

void Game::start() {
    Utils::printHeader("Number Guessing Game");

    int mode = selectMode();

    if (mode == 1) {
        Difficulty difficulty = selectDifficulty();
        userGuessMode(difficulty);
    } else {
        computerGuessMode();
    }
}

int Game::selectMode() {
    std::cout << "Select Mode:\n";
    std::cout << "1. You guess the number\n";
    std::cout << "2. Computer guesses your number\n";
    std::cout << "Choice: ";

    Player p;
    return p.getValidatedInput(1, 2);
}

Difficulty Game::selectDifficulty() {
    std::cout << "\nSelect Difficulty:\n";
    std::cout << "1. Easy\n2. Medium\n3. Hard\nChoice: ";

    Player p;
    int choice = p.getValidatedInput(1, 3);

    return static_cast<Difficulty>(choice);
}

void Game::userGuessMode(Difficulty difficulty) {
    int chances = getChances(difficulty);
    int target = Utils::generateRandomNumber(1, 100);

    Player player;

    Utils::printDivider();

    for (int i = 0; i < chances; i++) {
        std::cout << "Attempt " << (i + 1) << "/" << chances << "\n";
        std::cout << "Enter guess (1-100): ";

        int guess = player.getValidatedInput(1, 100);

        if (guess == target) {
            std::cout << "Correct!\n";
            return;
        } else if (guess < target) {
            std::cout << "Too low\n";
        } else {
            std::cout << "Too high\n";
        }
    }

    std::cout << "You lost. Number was: " << target << "\n";
}

void Game::computerGuessMode() {
    ComputerGuesser ai(1, 100);
    Player player;

    std::cout << "\nThink of a number between 1 and 100.\n";

    int attempts = 0;
    int maxAttempts = std::ceil(std::log2(100)); // optimal bound

    std::cout << "Max optimal attempts: " << maxAttempts << "\n";

    while (true) {
        attempts++;

        int guess = ai.makeGuess();

        std::cout << "\nAttempt " << attempts << "\n";
        std::cout << "Computer guesses: " << guess << "\n";
        std::cout << "1. Correct  2. Higher  3. Lower : ";

        int response = player.getValidatedInput(1, 3);

        if (response == 1) {
            std::cout << "\nComputer guessed correctly in "
                      << attempts << " attempts.\n";
            break;
        } else if (response == 2) {
            ai.updateRange(true);
        } else {
            ai.updateRange(false);
        }
    }
}