#pragma once
#include <string>
#include <vector>

struct Song {
    std::string title;
    std::string artist;
    int year;
};

class Album {
private:
    std::string title;
    std::vector<Song> songs; // Kompozicija

public:
    Album(const std::string& t, const Song& initial_song);

    void add_song(const Song& s);
    const std::vector<Song>& get_songs() const;
    const std::string& get_title() const;
};

class Player {
private:
    const Album* current_album; // Asocijacija (pokazivač 0..1)

public:
    Player();

    void load(const Album& alb);
    void play() const;
};