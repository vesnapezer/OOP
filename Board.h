#pragma once
#include <vector>

class Board {
private:
    int width;
    int height;
    std::vector<char> grid;

public:
    Board(int w, int h, char init_char = '.');

    // Rule of Zero: ne pišemo destruktor, copy konstruktor niti operator=
    char at(int x, int y) const;
    void set(int x, int y, char c);
    void print() const;
};
