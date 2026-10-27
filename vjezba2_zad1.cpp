#include <iostream>
#include <string>

using namespace std;

#define MAX(a, b) a > b ? a : b
#define MAX_ZAGRADE(a, b) ((a) > (b) ? (a) : (b))

inline int my_max(int a, int b){
    return a > b ? a : b;
}

template<typename T> T my_max(T a, T b){
    return a > b ? a : b;
}

int main(){
    int a = MAX(3, 5);
    int b = 2 * MAX(3, 5);
    int c = MAX(3, 5) + 1;
    cout << "Izvorni makro: a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "MAX(7, 5) + 1 = " << (MAX(7, 5) + 1) << "   (ispravno bi bilo 8)" << endl;

    int a2 = MAX_ZAGRADE(3, 5);
    int b2 = 2 * MAX_ZAGRADE(3, 5);
    int c2 = MAX_ZAGRADE(3, 5) + 1;
    cout << "Popravljeni makro: a = " << a2 << ", b = " << b2 << ", c = " << c2 << endl;
    cout << "MAX_ZAGRADE(7, 5) + 1 = " << (MAX_ZAGRADE(7, 5) + 1) << endl;

    int i{3};
    const int r_makro{MAX_ZAGRADE(++i, 2)};
    cout << "MAX_ZAGRADE(++i, 2) = " << r_makro << ", i nakon poziva = " << i << endl;

    i = 3;
    const int r_funkcija{my_max(++i, 2)};
    cout << "my_max(++i, 2)      = " << r_funkcija << ", i nakon poziva = " << i << endl;

    cout << "my_max<int>(3, 5)    = " << my_max<int>(3, 5) << "   (eksplicitno: template)" << endl;
    cout << "my_max(2.5, 1.5)     = " << my_max(2.5, 1.5) << endl;
    cout << "my_max('a', 'b')     = " << my_max('a', 'b') << endl;
    cout << "my_max(string, string) = " << my_max(string{"abc"}, string{"abd"}) << endl;
}
