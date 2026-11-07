#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input_vector(vector<int>& v) {
    int broj;
    cout << "Unesi brojeve (0 za kraj): ";
    do {
        cin >> broj;
        if (broj != 0) {
            v.push_back(broj);
        }
    } while (broj != 0);
}

int main() {
    vector<int> v;
    input_vector(v);

    int k;
    cout << "k: ";
    cin >> k;

    if (k <= 0) {
        cout << "k mora biti veci od 0." << endl;
        return 0;
    }

    if (v.empty()) {
        cout << "Vektor je prazan." << endl;
        return 0;
    }

    //Brojanje negativnih brojeva
    int negativnih = count_if(v.begin(), v.end(), [](int x) { return x < 0; });
    cout << "Negativnih: " << negativnih << endl;

    //Prvi visekratnik broja k
    auto it = find_if(v.begin(), v.end(), [k](int x) { return x % k == 0; });
    if (it != v.end()) {
        cout << "Prvi visekratnik od " << k << ": " << *it << " (pozicija " << it - v.begin() << ")" << endl;
    }
    else {
        cout << "Nema visekratnika broja " << k << endl;
    }

    // Najmanji i najveci broj
    auto min = min_element(v.begin(), v.end());
    auto max = max_element(v.begin(), v.end());
    cout << "Min: " << *min << " (pozicija " << min - v.begin() << ")";
    cout << ", Max: " << *max << " (pozicija " << max - v.begin() << ")" << endl;

    // Uklanjanje visekratnika broja k
    v.erase(remove_if(v.begin(), v.end(), [k](int x) { return x % k == 0; }), v.end());

    cout << "Bez visekratnika: ";
    for (int x : v) {
        cout << x << " ";
    }
	cout << endl;
	cin.ignore(1000, '\n');
	cin.get() //nezatvaranje konzolnog prozora
}

// da se unese odmah 0 vektor bi bio prazan jer bi min_element i max_element vratili v.end()
