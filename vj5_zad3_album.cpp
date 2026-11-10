#include <iostream>
#include <string>
#include <vector>

struct Song {
    std::string title;
    std::string artist;
    int seconds;
};

class Album {
private:
    std::string title;
    int year;
    std::vector<Song> songs;

public:
    //prva pjesma osigurava invarijantu - album nikad nije prazan
    Album(const std::string& t, int y, const Song& first)
        : title(t), year(y), songs{first} {
    }

    // Dodaje pjesmu samo ako naslov već ne postoji.
    bool add(const Song& s) {
        for (const Song& existing : songs) {
            if (existing.title == s.title) {
                return false;
            }
        }

        songs.push_back(s);
        return true;
    }

    int duration() const {
        int total = 0;
        for (const Song& s : songs) {
            total += s.seconds;
        }
        return total;
    }

    void print() const {
        const int total = duration();
        const int minutes = total / 60;
        const int seconds = total % 60;

        std::cout << title << " (" << year << "), "
                  << songs.size() << " pjesme, "
                  << minutes << ':';

        if (seconds < 10) std::cout << '0';
        std::cout << seconds << '\n';

        for (std::size_t i = 0; i < songs.size(); ++i) {
            std::cout << "  " << i + 1 << ". " << songs[i].title << '\n';
        }
    }
};

int main() {
    Album a("Sol Invictus", 2015, {"Sol Invictus", "Faith No More", 156});
    a.add({"Superhero", "Faith No More", 315});
    a.add({"Matador", "Faith No More", 368});
    std::cout << a.add({"Superhero", "Faith No More", 315}) << '\n';
    a.print();
    return 0;
}
