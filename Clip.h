#pragma once
#include <string>

class Clip {
private:
    std::string name;
    int start;
    int end;
    int length;
    const int max_length;

public:
    Clip(const std::string& name, int s, int e);
    void print() const;
};