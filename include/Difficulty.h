#ifndef DIFFICULTY_H
#define DIFFICULTY_H

enum class Difficulty
{
    Easy = 1,
    Medium = 2,
    Hard = 3
};

inline int getChances(Difficulty d){
    switch(d){
        case Difficulty::Easy:
            return 10;
        case Difficulty::Medium:
            return 7;
        case Difficulty::Hard:
            return 5;
        default:
            return 0;
    }
}

#endif // DIFFICULTY_H