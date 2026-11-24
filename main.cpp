#include <iostream>
#include "Volume.h"
#include "Clip.h"
#include "Music.h"
#include "Counters.h"

int main() {
    // Volume
    Volume v(80);
    v.up(); // korak 10 -> 90
    std::cout << "Volume: " << v.get() << "%\n";

    // Clip
    Clip c("Intro", 5, 25);
    c.print();

    // Album i Player
    Album alb("Greatest Hits", { "Song 1", "Artist A", 2020 });
    alb.add_song({ "Song 2", "Artist A", 2021 });
    Player p;
    p.load(alb);
    p.play();

    // Ticket i Coin
    Ticket t1, t2;
    std::cout << "Zadnji izdani ticket ID: " << Ticket::total_issued() << '\n';

    std::cout << "Aktivnih novcica: " << Coin::current_active() << '\n';
    {
        Coin c1, c2;
        std::cout << "U bloku novcica: " << Coin::current_active() << '\n';
    }
    std::cout << "Nakon bloka novcica: " << Coin::current_active() << '\n';

    return 0;
}