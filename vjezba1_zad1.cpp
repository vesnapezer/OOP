#include <iostream>

using namespace std;

int main(){
    int a{};
    int b{};

    cout << "Unesite dva cijela broja: ";
    cin >> a >> b;

    const int zbroj{a + b};

    const double sredina{(a + b) / 2.0};

    const bool a_manji{a < b};

    cout << "Zbroj: " << zbroj << endl;
    cout << "Aritmeticka sredina: " << sredina << endl;
    cout << "a < b: " << boolalpha << a_manji << endl;
}