#include "Counters.h"

// Inicijalizacija statičkih varijabli - u cpp
int Ticket::next_id = 1;
int Coin::active_count = 0;

Ticket::Ticket() : id{ next_id++ } {}

int Ticket::get_id() const {
    return id;
}

int Ticket::total_issued() {
    return next_id - 1;
}

Coin::Coin() {
    ++active_count;
}

Coin::~Coin() {
    --active_count;
}

int Coin::current_active() {
    return active_count;
}