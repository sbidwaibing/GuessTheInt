#include "Utils.h"
#include <iostream>
#include <random>

int Utils::generateRandomNumber(int min, int max){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

void Utils::printHeader(const std::string& title){
    std::cout << "\n====================================\n";
    std::cout << "   " << title << "\n";
    std::cout << "====================================\n";
}

void Utils::printDivider(){
    std::cout << "------------------------------------\n";
}