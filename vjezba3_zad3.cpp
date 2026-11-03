#include <iostream>
#include <array>

using namespace std;

constexpr int DAYS = 7;

double total(const array<double, DAYS>& hours) {
    double suma = 0;
    for (int i = 0; i < DAYS; i++) {
        suma += hours[i];
    }
    return suma;
}

int best_day(const array<double, DAYS>& hours) {
    int najbolji = 0;
    for (int i = 1; i < DAYS; i++) {
        if (hours[i] > hours[najbolji]) {
            najbolji = i;
        }
    }
    return najbolji + 1;
}

int main() {
    array<double, DAYS> week1;
    array<double, DAYS> week2;

    cout << "Unesite sate ucenja za svaki dan:\n";
    for (int i = 0; i < DAYS; i++) {
        cin >> week1[i];
    }

    cout << "Ukupno sati: " << total(week1) << endl;
    cout << "Najvise se ucilo " << best_day(week1) << ". dan." << endl;

    week2.fill(1.5);

    cout << "\nDrugi tjedan:\n";
    for (double x : week2) {
        cout << x << " ";
    }

    cout << "\n\nUsporedba tjedana:\n";
    cout << boolalpha;
    cout << "week1 == week2: " << (week1 == week2) << endl;
    cout << "week1 < week2: " << (week1 < week2) << endl;

    week1.swap(week2);

    cout << "\nNakon zamjene:\n";
    cout << "Ukupno sati prvi tjedan: " << total(week1) << endl;
    cout << "Ukupno sati drugi tjedan: " << total(week2) << endl;

}