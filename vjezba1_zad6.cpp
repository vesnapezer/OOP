#include <iostream>

using namespace std;

int nzd(int a, int b)
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0){
        const int ostatak{a % b};
        a = b;
        b = ostatak;
    }
    return a;
}

struct Fraction{
    int brojnik;
    int nazivnik;

    void reduce(){
        if (nazivnik == 0) 
            return;

        if (nazivnik < 0){
            brojnik = -brojnik;
            nazivnik = -nazivnik;
        }

        const int g{nzd(brojnik, nazivnik)};
        brojnik /= g;
        nazivnik /= g;
    }
    
    double value() const{
        return static_cast<double>(brojnik) / nazivnik;
    }

    void print() const{
        cout << brojnik << '/' << nazivnik;
    }
};

Fraction sum(const Fraction& a, const Fraction& b){
    Fraction rezultat{a.brojnik * b.nazivnik + b.brojnik * a.nazivnik,
                      a.nazivnik * b.nazivnik};
    rezultat.reduce();
    return rezultat;
}

int main()
{
    Fraction f{6, 8};
    cout << "razlomak prije reduce(): ";
    f.print();
    cout << endl;
    f.reduce();
    cout << "razlomak nakon reduce(): ";
    f.print();
    cout << "   value() = " << f.value() << endl;

    Fraction negativni{3, -6};
    negativni.reduce();
    cout << "3/-6 skraceno: ";
    negativni.print();
    cout << endl;

    Fraction nula{0, 5};
    nula.reduce();
    cout << "0/5 skraceno: ";
    nula.print();
    cout << endl;

    const Fraction a{1, 2};
    const Fraction b{1, 3};
    const Fraction c{1, 4};

    cout << "1/2 + 1/3 = ";
    sum(a, b).print();
    cout << endl;

    cout << "1/4 + 1/4 = ";
    sum(c, c).print();
    cout << endl;
}