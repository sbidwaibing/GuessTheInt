#include "Player.h"
#include <iostream>
#include <limits>
#include <stdexcept>

int Player::getValidatedInput(int min, int max) {
    int input;

    while (true) {
        try {
            std::cin >> input;

            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input type.");
            }

            if (input < min || input > max) {
                throw std::out_of_range("Input out of range.");
            }

            return input;

        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << " Try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}