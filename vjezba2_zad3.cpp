// Vježba 2, zadatak 3: my_sort, ascending i descending kao function templatei.
//
// Prevođenje i pokretanje:
//   g++ -std=c++17 -Wall -Wextra -pedantic vjezba2_zad3.cpp -o zad3 && ./zad3
//
// Zašto se poziv s ascending iz zadatka 2 ne prevodi za niz tipa double?
//   double ad[] = {3.5, 1.5, 2.5};
//   my_sort(ad, 3, ascending_int);        // ascending_int je tipa bool(int, int)
// 1) T se zaključuje iz DVA argumenta i ne slažu se: iz niza slijedi T = double, a iz komparatora
//    bool(*)(int, int) slijedi T = int. Pri zaključivanju tipa pretvorbe se ne provode.
//    (g++: "deduced conflicting types for parameter 'T' ('double' and 'int')")
// 2) Ni my_sort<double>(ad, 3, ascending_int) ne prolazi: function pointer mora točno odgovarati
//    potpisu, a bool(*)(int, int) se ne pretvara u bool(*)(double, double).
//    (g++: "invalid conversion from 'bool (*)(int, int)' to 'bool (*)(double, double)'")
// Probaj: odkomentiraj redak označen s "GRESKA" u main i pročitaj poruku prevoditelja.

#include <iostream>
#include <utility>   // std::swap

using namespace std;

// ascending iz zadatka 2 (preimenovan da ne smeta predlošku istog imena); radi samo za int.
inline bool ascending_int(int a, int b)
{
    return a < b;
}

template<typename T>
inline bool ascending(T a, T b)
{
    return a < b;
}

template<typename T>
inline bool descending(T a, T b)
{
    return a > b;
}

// T se pojavljuje na dva mjesta (niz i komparator) i na oba mora dati isti tip.
template<typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T))
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

template<typename T>
void ispisi(const T arr[], int n)
{
    for (int i{0}; i < n; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    int ai[] = {5, 2, 8, 1, 9};
    double ad[] = {3.5, -1.25, 2.0, 0.5};
    char ac[] = {'d', 'a', 'c', 'b'};   // ne "dacb": literal ima i '\0', pa bi niz imao 5 elemenata

    const int ni{sizeof(ai) / sizeof(ai[0])};
    const int nd{sizeof(ad) / sizeof(ad[0])};
    const int nc{sizeof(ac) / sizeof(ac[0])};

    // Stari komparator i dalje radi za int, jer se T slaže (int i int).
    my_sort(ai, ni, ascending_int);
    cout << "int, ascending_int:  ";
    ispisi(ai, ni);

    // GRESKA: my_sort(ad, nd, ascending_int);

    my_sort(ai, ni, descending<int>);
    cout << "int, silazno:        ";
    ispisi(ai, ni);

    // Ime predloška bez <> prolazi kad se T može zaključiti iz niza (ovdje T = double).
    // Ako ga tvoj prevoditelj ne prihvati, napiši ascending<double>.
    my_sort(ad, nd, ascending);
    cout << "double, uzlazno:     ";
    ispisi(ad, nd);

    my_sort(ad, nd, descending<double>);
    cout << "double, silazno:     ";
    ispisi(ad, nd);

    my_sort(ac, nc, ascending<char>);
    cout << "char, uzlazno:       ";
    ispisi(ac, nc);

    my_sort(ac, nc, descending<char>);
    cout << "char, silazno:       ";
    ispisi(ac, nc);
}

// Primjer izlaza:
//   int, ascending_int:  1 2 5 8 9
//   int, silazno:        9 8 5 2 1
//   double, uzlazno:     -1.25 0.5 2 3.5
//   double, silazno:     3.5 2 0.5 -1.25
//   char, uzlazno:       a b c d
//   char, silazno:       d c b a
