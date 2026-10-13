#include <cstdlib>   // std::abs
#include <iostream>

using namespace std;

int& find_max(int arr[], int n)
{
    int indeks_max{0};
    for (int i{1}; i < n; ++i)
        if (arr[i] > arr[indeks_max])
            indeks_max = i;
    return arr[indeks_max];
}

int main(){
    int numbers[] = {4, -7, 12, 0, 9, -3};

    const int n{sizeof(numbers) / sizeof(numbers[0])};

    cout << "Pocetni niz:      ";
    for (const int x : numbers)
        cout << x << ' ';
    cout << endl;

    for (int& x : numbers)
        if (x < 0)
            x = abs(x);

    cout << "Nakon std::abs:   ";
    for (const int x : numbers)
        cout << x << ' ';
    cout << endl;

    find_max(numbers, n) = 0;

    cout << "Nakon find_max=0: ";
    for (const int x : numbers)
        cout << x << ' ';
    cout << endl;

}

