// Vježba 2, zadatak 6: struct Student i filter_students (function pointer za akciju, lambda za uvjet).
//
// Prevođenje i pokretanje:
//   g++ -std=c++17 -Wall -Wextra -pedantic vjezba2_zad6.cpp -o zad6 && ./zad6

#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string ime;
    string jmbag;   // string, a ne broj: identifikator s 10 znamenki (ne staje u int) i vodećim nulama
    int godina;          // godina studija
    int ects;            // položeni ECTS bodovi u godini
    double prosjek;
};

// Akciju izvrši nad svakim studentom koji zadovoljava uvjet.
// Potpisi function pointera moraju točno odgovarati: akcija prima Student& (smije mijenjati),
// a uvjet const Student& (ne smije). Niz Student s[] je u funkciji pointer, pa se n prenosi posebno.
void filter_students(Student s[], int n, void (*action)(Student&), bool (*cond)(const Student&))
{
    for (int i{0}; i < n; ++i)
        if (cond(s[i]))
            action(s[i]);
}

// Akcije su funkcije. Ispis mora imati Student& (a ne const Student&), iako ne mijenja studenta:
// void(*)(const Student&) je drugi tip od void(*)(Student&) i ne bi se mogao predati kao action.
void ispisi(Student& s)
{
    cout << "  " << s.ime << ", JMBAG " << s.jmbag << ", " << s.godina << ". godina, "
              << s.ects << " ECTS, prosjek " << s.prosjek << endl;
}

void sljedeca_godina(Student& s)
{
    ++s.godina;
}

int main()
{
    Student studenti[] = {
        {"Ana Horvat",  "0036501234", 1, 30, 4.2},
        {"Marko Maric", "0036505678", 1,  0, 3.1},
        {"Ivana Kovac", "0036509012", 2, 48, 3.8},
        {"Petar Peric", "0036503456", 3, 45, 3.4},
        {"Maja Juric",  "0036507890", 1, 12, 3.6},
        {"Luka Babic",  "0036502345", 2, 20, 2.9}
    };
    const int n{sizeof(studenti) / sizeof(studenti[0])};

    // Uvjeti su lambde bez capturea (pretvaraju se u function pointer), pa pragovi idu kao literali.
    // "Barem jedan ispit": struktura ne pamti ispite, nego ECTS bodove, pa to tumačimo kao ects > 0.
    cout << "Studenti prve godine koji su polozili barem jedan ispit:" << endl;
    filter_students(studenti, n, ispisi,
                    [](const Student& s) { return s.godina == 1 && s.ects > 0; });

    cout << "Studenti s prosjekom vecim od 3.5:" << endl;
    filter_students(studenti, n, ispisi,
                    [](const Student& s) { return s.prosjek > 3.5; });

    cout << "Povecavam godinu studentima s najmanje 45 ECTS bodova." << endl;
    filter_students(studenti, n, sljedeca_godina,
                    [](const Student& s) { return s.ects >= 45; });

    cout << "Svi studenti nakon toga (uvjet je uvijek istinit):" << endl;
    filter_students(studenti, n, ispisi,
                    [](const Student&) { return true; });
}

// Primjer izlaza:
//   Studenti prve godine koji su polozili barem jedan ispit:
//     Ana Horvat, JMBAG 0036501234, 1. godina, 30 ECTS, prosjek 4.2
//     Maja Juric, JMBAG 0036507890, 1. godina, 12 ECTS, prosjek 3.6
//   Studenti s prosjekom vecim od 3.5:
//     Ana Horvat, JMBAG 0036501234, 1. godina, 30 ECTS, prosjek 4.2
//     Ivana Kovac, JMBAG 0036509012, 2. godina, 48 ECTS, prosjek 3.8
//     Maja Juric, JMBAG 0036507890, 1. godina, 12 ECTS, prosjek 3.6
//   Povecavam godinu studentima s najmanje 45 ECTS bodova.
//   Svi studenti nakon toga (uvjet je uvijek istinit):
//     Ana Horvat, JMBAG 0036501234, 1. godina, 30 ECTS, prosjek 4.2
//     Marko Maric, JMBAG 0036505678, 1. godina, 0 ECTS, prosjek 3.1
//     Ivana Kovac, JMBAG 0036509012, 3. godina, 48 ECTS, prosjek 3.8
//     Petar Peric, JMBAG 0036503456, 4. godina, 45 ECTS, prosjek 3.4
//     Maja Juric, JMBAG 0036507890, 1. godina, 12 ECTS, prosjek 3.6
//     Luka Babic, JMBAG 0036502345, 2. godina, 20 ECTS, prosjek 2.9
