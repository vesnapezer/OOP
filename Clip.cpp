#include "Clip.h"
#include <iostream>

Clip::Clip(const std::string& name, int s, int e)
    : name{ name }, start{ s }, end{ e }, length{ e - s }, max_length{ 300 } {
}

void Clip::print() const {
    std::cout << "Klip '" << name << "': " << start << "s - " << end
        << "s (trajanje: " << length << "s, max: " << max_length << "s)\n";
}