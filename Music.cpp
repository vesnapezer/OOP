#include "Music.h"
#include <iostream>

Album::Album(const std::string& t, const Song& initial_song) : title{ t } {
    songs.push_back(initial_song);
}

void Album::add_song(const Song& s) {
    songs.push_back(s);
}

const std::vector<Song>& Album::get_songs() const {
    return songs;
}

const std::string& Album::get_title() const {
    return title;
}

Player::Player() : current_album{ nullptr } {}

void Player::load(const Album& alb) {
    current_album = &alb;
}

void Player::play() const {
    if (!current_album) {
        std::cout << "Player je prazan.\n";
        return;
    }

    std::cout << "Svira album: " << current_album->get_title() << '\n';
    for (const auto& s : current_album->get_songs()) {
        std::cout << "  -> " << s.artist << " - " << s.title << '\n';
    }
}