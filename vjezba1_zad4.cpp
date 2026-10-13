#include <iostream>
#include <string>

using namespace std;

namespace geo{
    const double PI{3.14159265358979323846};
}

double area(double r){
    return geo::PI * r * r;
}

double area(double a, double b){
    return a * b;
}

int area(int a){
    return a * a;
}

void print_line(char c = '-', int length = 30){
    if (length > 0)
        cout << string(length, c);
    cout << endl;
}

int main(){
    print_line('=');

    cout << "area(5)    = " << area(5)    << "   (int: kvadrat)" << endl;
    cout << "area(5.0)  = " << area(5.0)  << "   (double: krug)" << endl;
    cout << "area(2, 3) = " << area(2, 3) << "   (double, double: pravokutnik)" << endl;
    cout << "area('A')  = " << area('A')  << "   (char -> int: kvadrat stranice 65)" << endl;

    print_line();          
    print_line('*');       
    print_line('#', 10); 
}