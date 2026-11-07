#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string jmbag;
    string surname;
    int points;
};

int main() {

    vector<Student> registered{
        {"0302", "Kovac", 78},
        {"0117", "Babic", 45},
        {"0255", "Maric", 91},
        {"0117", "Babic", 45},
        {"0410", "Novak", 78},
        {"0089", "Juric", 62},
        {"0255", "Maric", 91},
        {"0520", "Maric", 55},
        {"0333", "Peric", 30}
    };

    // Prvo sortiramo po jmbag jer unique() uklanja samo uzastopne duplikate. 
    // Za ukloniti sve duplikate, prvo ih moramo postaviti jedan do drugoga

    sort(registered.begin(), registered.end(), [](const Student& a, const Student& b) {
            return a.jmbag < b.jmbag;
        });

    auto kraj = unique(registered.begin(), registered.end(), [](const Student& a, const Student& b) {
            return a.jmbag == b.jmbag;
        });

    registered.erase(kraj, registered.end());
    cout << "Prijavljenih: " << registered.size() << endl;

    // Uklanjanje studenata ispod praga
    int prag;
    cout << "Prag: ";
    cin >> prag;

    registered.erase(remove_if(registered.begin(), registered.end(), [prag](const Student& s) {
            return s.points < prag;
        }), registered.end());

    // Sortiranje rang-liste
    sort(registered.begin(), registered.end(), [](const Student& a, const Student& b) {
            if (a.points != b.points) {
                return a.points > b.points;
            }
            return a.surname < b.surname;
        });

    // Ispis rang-liste
    for (int i = 0; i < registered.size(); i++) {
        cout << i + 1 << ". " << registered[i].surname << " (" << registered[i].jmbag << ") " << registered[i].points << endl;
    }
}