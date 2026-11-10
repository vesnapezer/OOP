#include <iostream>
#include <string>

class Ticket {
private:
    std::string concert;
    int id;
    static int next_id;

public:
    explicit Ticket(const std::string& concert)
        : concert(concert), id(next_id++) {
    }

    int get_id() const {
        return id;
    }

    static int issued() {
        return next_id - 1;
    }
};

//definicija statičkog člana izvan klase
int Ticket::next_id = 1;

int main() {
    std::cout << Ticket::issued() << '\n';
    Ticket t1("Shame, Zagreb");
    Ticket t2("Shame, Zagreb");
    Ticket t3("Viagra Boys, Ljubljana");
    std::cout << t1.get_id() << ' ' << t2.get_id() << ' ' << t3.get_id() << '\n';
    std::cout << Ticket::issued() << '\n';
    return 0;
}
