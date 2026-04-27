#include "ComputerGuesser.h"

ComputerGuesser::ComputerGuesser(int min, int max)
    : low(min), high(max) {}

int ComputerGuesser::makeGuess() {
    mid = low + (high - low) / 2;
    return mid;
}

void ComputerGuesser::updateRange(bool isHigher) {
    if (isHigher) {
        low = mid + 1;
    } else {
        high = mid - 1;
    }
}