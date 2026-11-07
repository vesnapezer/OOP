#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Song {
    string title;
    string artist;
    int year;
    int plays;
};

void print_song(const Song& s) {
    cout << s.title << " - " << s.artist << " (" << s.year << "), slusanja: " << s.plays << endl;
}

int main() {
    vector<Song> songs{
        {"Blinding Lights", "The Weeknd", 2019, 4100},
        {"Despacito", "Luis Fonsi ft. Daddy Yankee", 2017, 3200},
        {"Uptown Funk", "Mark Ronson ft. Bruno Mars", 2014, 1800},
		{"Counting Stars", "OneRepublic", 2013, 2100},
        {"Closer", "The Chainsmokers ft. Halsey", 2016, 2800},
        {"Wake Me Up", "Avicii", 2013, 2200},
        {"Bad Guy", "Billie Eilish", 2019, 2500},
        {"Radioactive", "Imagine Dragons", 2012, 1700}		
    };

    // Sortiranje po godini, a zatim po naslovu
    sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
            if (a.year != b.year) {
                return a.year < b.year;
            }
            return a.title < b.title;
        });

    cout << "Sortirane pjesme:\n";
    for (const Song& s : songs) {
        print_song(s);
    }

    // Unos izvodjaca
    string artist;
    cout << "\nUnesite izvodjaca: ";
    getline(cin, artist);

    // Brojanje pjesama izvodjaca
    int broj = count_if(songs.begin(), songs.end(), [artist](const Song& s) {
            return s.artist == artist;
        });
		cout << "Broj pjesama: " << broj << endl;

    // Najstarija pjesma izvodjaca
    auto it = find_if(songs.begin(), songs.end(), [artist](const Song& s) {
            return s.artist == artist;
        });
	//prethodno smo sortirali pjesme po godini uzlazno, prva pjesma pronadjena za tog izvodjaca je njegova najstarija pjesma

    if (it != songs.end()) {
        cout << "Najstarija pjesma: ";
        print_song(*it);
    }
    else {
        cout << "Izvodjac nije pronadjen." << endl;
    }

    // Najslusanija pjesma
    auto naj = max_element(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
            return a.plays < b.plays;
        });

    cout << "\nNajslusanija pjesma: ";
    print_song(*naj);
}
