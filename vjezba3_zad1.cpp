#include <iostream>
#include <vector>

using namespace std;

void input_vector(vector<int>& v) {
    int broj;
    cout << "Unosi brojeve (0 za kraj): ";
    do {
        cin >> broj;
        if (broj != 0) {
            v.push_back(broj);
        }
    } while (broj != 0);
}

void print_vector(const vector<int>& v) {
    for (int broj : v) {
        cout << broj << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v;
    input_vector(v);

    cout << "Vektor: ";
    print_vector(v);

    cout << "Obrnuto ispisano: ";
    for (auto i = v.rbegin(); i != v.rend(); ++i) {
        cout << *i << " ";
    }
    cout << endl;


    vector<int> a;

    cout << "\nBez reserve:\n";

    for (int i = 1; i <= 20; i++) {
        a.push_back(i);
        cout << "Size: " << a.size() << " Capacity: " << a.capacity() << endl;
    }

    vector<int> b;

    b.reserve(100);

    cout << "\nS reserve(100):\n";

    for (int i = 1; i <= 20; i++) {
        b.push_back(i);
        cout << "Size: " << b.size() << " Capacity: " << b.capacity() << endl;
    }

    b.shrink_to_fit();

    cout << "Capacity nakon shrink_to_fit: "
         << b.capacity() << endl;
         
}