// Vježba 2, zadatak 5: niz function pointera (kalkulator).
//
// Prevođenje i pokretanje:
//   g++ -std=c++17 -Wall -Wextra -pedantic vjezba2_zad5.cpp -o zad5 && ./zad5

#include <iostream>

using namespace std;

inline double add(double a, double b)
{
    return a + b;
}

inline double subtract(double a, double b)
{
    return a - b;
}

inline double multiply(double a, double b)
{
    return a * b;
}

inline double divide(double a, double b)
{
    return a / b;
}

// Alias čini tip čitljivijim od double (*operacije[])(double, double).
using Operacija = double (*)(double, double);

int main()
{
    // Adrese funkcija u nizu; indeks odgovara rednom broju operacije (0 do 3).
    // add i &add su isto: ime funkcije se pretvara u njezinu adresu. Adresa inline funkcije je dopuštena.
    const Operacija operacije[]{add, subtract, multiply, divide};
    const char simboli[]{'+', '-', '*', '/'};
    const int broj_operacija{sizeof(operacije) / sizeof(operacije[0])};   // 4

    double a{};
    double b{};
    int k{};

    cout << "Unesite dva broja: ";
    if (!(cin >> a >> b))
    {
        cout << "Neispravan unos." << endl;
        return 1;
    }

    cout << "Operacija (0 = +, 1 = -, 2 = *, 3 = /): ";
    if (!(cin >> k))
    {
        cout << "Neispravan unos." << endl;
        return 1;
    }

    // Indeks izvan niza je nedefinirano ponašanje, pa se raspon provjerava prije poziva.
    if (k < 0 || k >= broj_operacija)
    {
        cout << "Nepoznata operacija: " << k << endl;
        return 1;
    }

    // Dijeljenje double nulom ne ruši program, nego daje inf (ili nan), pa provjera mora biti izričita.
    // Usporedba s točno 0 je ovdje ispravna: samo je točna nula problem, vrlo mali b daje velik, ali konačan rezultat.
    if (k == 3 && b == 0)
        cout << "Dijeljenje nulom nije definirano." << endl;
    else
        cout << a << ' ' << simboli[k] << ' ' << b << " = " << operacije[k](a, b) << endl;
}

// Primjeri izlaza:
//   Unesite dva broja: 6 3
//   Operacija (0 = +, 1 = -, 2 = *, 3 = /): 0
//   6 + 3 = 9
//
//   Unesite dva broja: 5 0
//   Operacija (0 = +, 1 = -, 2 = *, 3 = /): 3
//   Dijeljenje nulom nije definirano.
