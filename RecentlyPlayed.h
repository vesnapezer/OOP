#pragma once
#include <string>

class RecentlyPlayed {
private:
    std::string* titles;
    int cap;
    int count;
    int next_idx;

public:
    RecentlyPlayed(int capacity = 3);
    ~RecentlyPlayed();                                        // Destruktor
    RecentlyPlayed(const RecentlyPlayed& other);             // Copy konstruktor
    RecentlyPlayed& operator=(const RecentlyPlayed& other);  // Copy operator=

    void play(const std::string& title);
    const std::string& get(int i) const;
    int size() const;
    int capacity() const;
    void print() const;
};
