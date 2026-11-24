#include "Board.h"
#include <iostream>

Board::Board(int w, int h, char init_char)
    : width{ w }, height{ h }, grid(static_cast<std::size_t>(w* h), init_char) {
}

char Board::at(int x, int y) const {
    return grid[y * width + x];
}

void Board::set(int x, int y, char c) {
    grid[y * width + x] = c;
}

void Board::print() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << at(x, y) << ' ';
        }
        std::cout << '\n';
    }
}