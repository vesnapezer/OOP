// Vježba 2, zadatak 4: my_transform, lambde bez konteksta i s kontekstom.
//
// Prevođenje i pokretanje:
//   g++ -std=c++17 -Wall -Wextra -pedantic vjezba2_zad4.cpp -o zad4 && ./zad4

#include <iostream>

using namespace std;

// Svaki element zamijeni s f(element). Parametar int (*f)(int) je function pointer.
void my_transform(int arr[], int n, int (*f)(int))
{
    for (int i{0}; i < n; ++i)
        arr[i] = f(arr[i]);
}

int twice(int x)
{
    return 2 * x;
}

// Dodatak (izvan slajdova): predložak prima bilo što što se može pozvati,
// pa prima i lambde s capturom. Vidi odgovor na pitanje na kraju datoteke.
template<typename F>
void my_transform_t(int arr[], int n, F f)
{
    for (int i{0}; i < n; ++i)
        arr[i] = f(arr[i]);
}

void ispisi(const int arr[], int n)
{
    for (int i{0}; i < n; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    // 1) twice kao function pointer (ime funkcije bez zagrada je njezina adresa)
    int a1[] = {1, 2, 3, 4, 5, 6};
    const int n1{sizeof(a1) / sizeof(a1[0])};
    my_transform(a1, n1, twice);
    cout << "twice:                    ";
    ispisi(a1, n1);

    // 2) Lambda bez konteksta ([] je prazan) pretvara se u function pointer.
    //    Parnost se provjerava s % 2 == 0 (radi i za negativne brojeve; x % 2 == 1 ne bi, jer je -3 % 2 == -1).
    int a2[] = {1, 2, 3, 4, 5, 6, -3, -4};
    const int n2{sizeof(a2) / sizeof(a2[0])};
    my_transform(a2, n2, [](int x) { return x % 2 == 0 ? x / 2 : x * 2; });
    cout << "parni /2, neparni *2:     ";
    ispisi(a2, n2);

    // 3) Lambde s kontekstom, bez my_transform: petlja u main-u poziva lambdu za svaki element.
    int brojevi[] = {3, 7, 2, 9, 5, 4};

    // [&] hvata sve što lambda koristi po referenci. Početne vrijednosti su neutralni elementi:
    // 0 za zbrajanje i 1 za množenje. Produkt je long long jer int preljeva već kod 13!.
    int suma{0};
    long long produkt{1};
    auto zbroji_i_pomnozi = [&](int x)
    {
        suma += x;
        produkt *= x;
    };
    for (const int x : brojevi)
        zbroji_i_pomnozi(x);
    cout << "suma = " << suma << ", produkt = " << produkt << endl;

    // [prag, &s]: prag je kopija (unutar lambde samo za čitanje), a s je referenca pa se mijenja original.
    const int prag{4};
    int s{0};
    auto zbroji_vece = [prag, &s](int x)
    {
        if (x > prag)
            s += x;
    };
    for (const int x : brojevi)
        zbroji_vece(x);
    cout << "suma clanova vecih od " << prag << " = " << s << endl;

    // Dodatak: predložak prima i lambdu s capturom.
    int a3[] = {1, 2, 3};
    const int n3{sizeof(a3) / sizeof(a3[0])};
    const int faktor{10};
    my_transform_t(a3, n3, [faktor](int x) { return x * faktor; });
    cout << "my_transform_t, *faktor:  ";
    ispisi(a3, n3);
}

// Može li se lambda s kontekstom predati funkciji my_transform? NE.
//   my_transform(a3, n3, [faktor](int x) { return x * faktor; });   // GRESKA: cannot convert ... to 'int (*)(int)'
// Razlog: int (*f)(int) je function pointer, a on čuva samo ADRESU koda. Lambda s capturom je objekt
// koji uz kod nosi i podatke (uhvaćeni faktor), a to se ne može spremiti u običan pointer.
// Pretvorba lambde u function pointer postoji samo kad je lista capturea prazna: ni [&] ne prolazi,
// čak ni kad lambda ništa ne hvata.
// Rješenje: parametar koji prima bilo što što se može pozvati (predložak kao gore ili std::function<int(int)>).

// Primjer izlaza:
//   twice:                    2 4 6 8 10 12
//   parni /2, neparni *2:     2 1 6 2 10 3 -6 -2
//   suma = 30, produkt = 7560
//   suma clanova vecih od 4 = 21
//   my_transform_t, *faktor:  10 20 30
