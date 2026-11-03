#include <iostream>
#include <string>

using namespace std;

string with_separators(string digits) {
    int start = 0;

    if (digits[0] == '-') {
        start = 1;
    }

    size_t i = digits.size();

    while (i > start + 3) {
        i -= 3;
        digits.insert(i, ".");
    }

    return digits;
}

string without_separators(string text) {

    size_t pos = text.find('.');

    while (pos != string::npos) {
        text.erase(pos, 1);
        pos = text.find('.');
    }

    return text;
}

int main() {
    string broj;
    cout << "Unesi broj: ";
    cin >> broj;

    cout << "S tockama: " << with_separators(broj) << endl;

    string tekst;

    cout << "Unesi broj s tockama: ";
    cin >> tekst;

    cout << "Bez tocaka: " << without_separators(tekst) << endl;
}