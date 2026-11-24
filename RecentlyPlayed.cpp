#include "RecentlyPlayed.h"
#include <iostream>
#include <cassert>

RecentlyPlayed::RecentlyPlayed(int capacity)
    : cap{ capacity }, count{ 0 }, next_idx{ 0 } {
    assert(cap > 0);
    titles = new std::string[cap];
}

RecentlyPlayed::~RecentlyPlayed() {
    delete[] titles;
}

RecentlyPlayed::RecentlyPlayed(const RecentlyPlayed& other)
    : cap{ other.cap }, count{ other.count }, next_idx{ other.next_idx } {
    titles = new std::string[cap];
    for (int i = 0; i < cap; ++i) {
        titles[i] = other.titles[i];
    }
}

RecentlyPlayed& RecentlyPlayed::operator=(const RecentlyPlayed& other) {
    if (this == &other) {
        return *this;
    }

    std::string* fresh = new std::string[other.cap];
    for (int i = 0; i < other.cap; ++i) {
        fresh[i] = other.titles[i];
    }

    delete[] titles;

    titles = fresh;
    cap = other.cap;
    count = other.count;
    next_idx = other.next_idx;

    return *this;
}

void RecentlyPlayed::play(const std::string& title) {
    titles[next_idx] = title;
    next_idx = (next_idx + 1) % cap;
    if (count < cap) {
        ++count;
    }
}

const std::string& RecentlyPlayed::get(int i) const {
    assert(i >= 0 && i < count);
    int idx = (next_idx - 1 - i + cap) % cap;
    return titles[idx];
}

int RecentlyPlayed::size() const {
    return count;
}

int RecentlyPlayed::capacity() const {
    return cap;
}

void RecentlyPlayed::print() const {
    std::cout << "Nedavno slusano (" << count << "/" << cap << "): ";
    for (int i = 0; i < count; ++i) {
        std::cout << get(i) << (i + 1 < count ? ", " : "");
    }
    std::cout << '\n';
}