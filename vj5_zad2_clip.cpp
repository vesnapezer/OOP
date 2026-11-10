#include <iostream>
#include <string>

class Clip {
    int length;
    int start;
    int end;
    std::string name;
    const int max_length;

public:
    Clip(const std::string& name, int s, int e)
        // članovi se inicijaliziraju redoslijedom deklaracije u klasi pa length ide prije start i end
        : length(e - s),
          start(s),
          end(e),
          name(name),
          max_length(600) {
    }

    void print() const {
        std::cout << name << ": " << length << " s\n";
    }
};

int main() {
    Clip c("Concrete (Shame)", 10, 190);
    c.print();
    return 0;
}
