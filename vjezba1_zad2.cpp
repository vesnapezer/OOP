#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int trenutna_godina(){
    const time_t sada{time(nullptr)};
    return localtime(&sada)->tm_year + 1900;
}

string inicijali(const string& ime_prezime)
{
    string rezultat;
    bool start{true};

    for (const char znak : ime_prezime)    {
        if (znak == ' '){
            start = true;
        } else {
            if (start)            {
                rezultat += znak;
                rezultat += '.';
            }
            start = false;
        }
    }
    return rezultat;
}

int broj_znakova_bez_razmaka(const string& tekst)
{
    int broj{0};
    for (const char znak : tekst)
        if (znak != ' ')
            ++broj;
    return broj;
}

int main()
{
    int godina_rodenja{};
    cout << "Unesite godinu rodenja: ";
    cin >> godina_rodenja;
    if (!(cin))
    {
        cout << "Neispravan unos." << endl;
        return 1;
    }

    cin.ignore(1000, '\n');

    string ime_prezime;
    cout << "Unesite ime i prezime: ";
    getline(cin, ime_prezime);

    cout << "Inicijali: " << inicijali(ime_prezime) << endl;
    cout << "Broj znakova bez razmaka: " << broj_znakova_bez_razmaka(ime_prezime) << endl;
    cout << "Ove godine osoba navrsava: " << trenutna_godina() - godina_rodenja << endl;
}
