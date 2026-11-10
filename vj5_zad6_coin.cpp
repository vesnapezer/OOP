#include <iostream>

class Coin {
private:
    int value;
    static int count;

public:
    explicit Coin(int value)
        : value(value) {
        ++count;
    }

    //kopiranje je zabranjeno jer bi implicitno kopiranje stvorilo dodatni objekt bez povećanja brojača
    Coin(const Coin&) = delete;
    Coin& operator=(const Coin&) = delete;

    ~Coin() {
        --count;
    }

    int get_value() const {
        return value;
    }

    static int remaining() {
        return count;
    }
};

int Coin::count = 0;

void bonus() {
    Coin c1(5);
    Coin c2(5);
    Coin c3(10);
    std::cout << Coin::remaining() << '\n';
}

int main() {
    std::cout << Coin::remaining() << '\n';
    Coin gold(50);
    {
        Coin a(1);
        Coin b(1);
        std::cout << Coin::remaining() << '\n';
    }
    std::cout << Coin::remaining() << '\n';
    bonus();
    std::cout << Coin::remaining() << '\n';
    return 0;
}
