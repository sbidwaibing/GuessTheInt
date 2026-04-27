#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils {
    public:
        static int generateRandomNumber(int min, int max);
        static void printHeader(const std::string& title);
        static void printDivider();
};

#endif // UTILS_H
