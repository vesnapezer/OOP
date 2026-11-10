#include <cassert>
#include <iostream>

class Volume {
private:
    int level;
    int previous_level;
    bool muted;

    //ograničava vrijednost na interval [0, 100].
    static int clamp(int value) {
        if (value < 0) return 0;
        if (value > 100) return 100;
        return value;
    }

    //glasnoća uvijek mora biti u rasponu 0–100
    bool valid() const {
        return level >= 0 && level <= 100;
    }

public:
    //konstruktor s argumentom
    explicit Volume(int l)
        : level(clamp(l)), previous_level(clamp(l)), muted(false) {
        assert(valid());
    }

    //default konstruktor delegira na konstruktor s argumentom
    Volume() : Volume(50) {}

    int get() const {
        return level;
    }

    void up(int step = 10) {
        level = clamp(level + step);
        if (!muted) previous_level = level;
        assert(valid());
    }

    void down(int step = 10) {
        level = clamp(level - step);
        if (!muted) previous_level = level;
        assert(valid());
    }

    void mute() {
        if (!muted) {
            previous_level = level;
            level = 0;
            muted = true;
        }
        assert(valid());
    }

    void unmute() {
        if (muted) {
            level = clamp(previous_level);
            muted = false;
        }
        assert(valid());
    }
};

int main() {
    Volume v;
    std::cout << v.get() << '\n';
    v.up();
    v.up(60);
    std::cout << v.get() << '\n';
    v.mute();
    std::cout << v.get() << '\n';
    v.unmute();
    std::cout << v.get() << '\n';
    Volume w(-20);
    w.down();
    std::cout << w.get() << '\n';
    return 0;
}
