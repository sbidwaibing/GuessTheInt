#ifndef COMPUTER_GUESSER_H
#define COMPUTER_GUESSER_H

class ComputerGuesser {
private:
    int low, high, mid;

public:
    ComputerGuesser(int min, int max);

    int makeGuess();
    void updateRange(bool isHigher);
};

#endif // COMPUTER_GUESSER_H
