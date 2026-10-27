// Vježba 2, zadatak 2: sortiranje s function pointerom kao komparatorom.
//
// Prevođenje i pokretanje:
//   g++ -std=c++17 -Wall -Wextra -pedantic vjezba2_zad2.cpp -o zad2 && ./zad2
//
// cmp(a, b) odgovara na pitanje "treba li a ići prije b". Mora biti strog (cmp(x, x) je laž),
// zato koristimo < i >, a ne <= i >=.

#include <iostream>
#include <utility>   // std::swap

using namespace std;

inline bool ascending(int a, int b)
{
    return a < b;
}

inline bool descending(int a, int b)
{
    return a > b;
}

// Selection sort: u svakom koraku nađi element koji po komparatoru ide prvi u neuređenom dijelu
// [i, n) i zamijeni ga s arr[i]. Usporedbi je (n-1) + (n-2) + ... + 1 = n(n-1)/2, a zamjena najviše n-1.
// Parametar arr[] je u funkciji pointer, pa se duljina n prenosi posebno.
void my_sort(int arr[], int n, bool (*cmp)(int, int))
{
    for (int i{0}; i < n - 1; ++i)
    {
        int prvi{i};
        for (int j{i + 1}; j < n; ++j)
            if (cmp(arr[j], arr[prvi]))
                prvi = j;
        swap(arr[i], arr[prvi]);
    }
}

void ispisi(const int arr[], int n)
{
    for (int i{0}; i < n; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    int arr[] = {5, 2, 8, 1, 9, 3, 2};
    const int n{sizeof(arr) / sizeof(arr[0])};   // radi jer je arr ovdje pravi niz

    cout << "Pocetni niz: ";
    ispisi(arr, n);

    // Ime funkcije bez zagrada je njezina adresa. ascending() bi bio POZIV funkcije.
    my_sort(arr, n, ascending);
    cout << "Uzlazno:     ";
    ispisi(arr, n);

    my_sort(arr, n, descending);
    cout << "Silazno:     ";
    ispisi(arr, n);
}

// Primjer izlaza:
//   Pocetni niz: 5 2 8 1 9 3 2
//   Uzlazno:     1 2 2 3 5 8 9
//   Silazno:     9 8 5 3 2 2 1
