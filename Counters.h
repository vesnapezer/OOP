#pragma once

class Ticket {
private:
    int id;
    static int next_id;

public:
    Ticket();
    int get_id() const;
    static int total_issued();
};

class Coin {
private:
    static int active_count;

public:
    Coin();
    ~Coin();
    static int current_active();
};
