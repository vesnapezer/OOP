#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Broj dana: ";
    cin >> n;
    if (n <= 0) {
        cout << "Broj dana mora biti veci od 0." << endl;
        return 0;
    }

    vector<double> temperature(n);
    cout << "Unesite temperature po danima: ";
    for (int i = 0; i < n; i++) {
        cin >> temperature[i];
    }


    vector<double> promjene;
    promjene.reserve(n - 1);

    for (auto it = temperature.begin(); it != temperature.end() - 1; it++) {
        promjene.push_back(*(it + 1) - *it);
    }

    cout << "Promjene: ";
    for (double x : promjene) {
        cout << x << " ";
    }
    cout << endl;

    temperature.resize(7, temperature.back());

    cout << "Izvjestaj: ";
    for (double x : temperature) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> a(5); //5 el, svi 0
    vector<int> b{5}; //1 el

    cout << "\nBroj elemenata vektora a: " << a.size() << endl;
    cout << "Broj elemenata vektora b: " << b.size() << endl;

}