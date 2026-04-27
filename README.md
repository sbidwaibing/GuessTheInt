# GuessInt

Terminal-based number guessing game in C++17. 
- Two modes: 
-    -- you guess a random number, or 
-    -- the computer guesses yours using binary search.

## Modes

**You Guess** — Computer picks a number (1–100). You guess within a limited number of attempts based on difficulty:

| Difficulty| Attempts |
|-----------|----------|
| Easy      | 10       |
| Medium    | 7        |
| Hard      | 5        |

**Computer Guesses** — You think of a number. Computer finds it using optimal binary search (≤7 attempts for 1–100).

## Build & Run

```bash
chmod +x run.sh
./run.sh           # debug (default)
./run.sh release   # optimized
./run.sh sanitize  # address + UB sanitizers
```

Uses CMake if available, falls back to g++/clang++.

## Project Structure
```
GuessInt/
│
├── src/
│   ├── main.cpp
│   ├── Game.cpp
│   ├── Player.cpp
│   ├── Utils.cpp
│   ├── ComputerGuesser.cpp
│
├── include/
│   ├── Game.h
│   ├── Player.h
│   ├── Utils.h
│   ├── ComputerGuesser.h
│   ├── Difficulty.h
│
├── build/
├── run.sh
├── CMakeLists.txt
├── test.sh
├── .gitignore
```
## Requirements

- C++17 compiler (g++ or clang++)
- CMake 3.10+ (optional)
