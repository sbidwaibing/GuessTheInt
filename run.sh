set -e

MODE=${1:-debug}   # debug | release | sanitize

echo "=============================="
echo " Build Mode: $MODE"
echo "=============================="

echo "Cleaning old artifacts..."
rm -rf build game
rm -rf build game game.dSYM

compile_with_gpp() {

    FLAGS="-std=c++17"

    if [ "$MODE" = "debug" ]; then
        FLAGS="$FLAGS -g -O0"
    fi

    if [ "$MODE" = "release" ]; then
        FLAGS="$FLAGS -O3"
    fi

    if [ "$MODE" = "sanitize" ]; then
        FLAGS="$FLAGS -g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer"
    fi

    echo "Compiling with g++..."
    
    g++ $FLAGS \
        src/main.cpp \
        src/Game.cpp \
        src/Player.cpp \
        src/Utils.cpp \
        src/ComputerGuesser.cpp \
        -Iinclude \
        -o game

    echo "Running..."
    ./game
}

if command -v cmake >/dev/null 2>&1; then

    echo "CMake detected"

    mkdir build
    cd build

    if [ "$MODE" = "debug" ]; then
        cmake -DCMAKE_BUILD_TYPE=Debug ..
    elif [ "$MODE" = "release" ]; then
        cmake -DCMAKE_BUILD_TYPE=Release ..
    elif [ "$MODE" = "sanitize" ]; then
        cmake -DCMAKE_BUILD_TYPE=Debug ..
    fi

    make

    echo "Running..."
    ./bin/game

else
    echo "CMake not found → using g++ fallback"
    compile_with_gpp
fi