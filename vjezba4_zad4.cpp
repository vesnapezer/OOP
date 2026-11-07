#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

struct PasswordInfo {
    int length;
    int digits;
    int uppercase;
    int special;
};

PasswordInfo analyze(const string& password) {
    PasswordInfo info;
    info.length = password.size();
    info.digits = count_if(password.begin(), password.end(), [](char c) {
            return isdigit(static_cast<unsigned char>(c));
        });
    info.uppercase = count_if(password.begin(), password.end(),[](char c) {
            return isupper(static_cast<unsigned char>(c));
        });
    info.special = count_if(password.begin(), password.end(), [](char c) {
            return ispunct(static_cast<unsigned char>(c));
        });
    return info;
}

bool is_strong(const PasswordInfo& info) {
    return info.length >= 10 &&
           info.digits >= 1 &&
           info.uppercase >= 1 &&
           info.special >= 1;
}

int main() {
    string password;
    cout << "Unesi lozinku: ";
    getline(cin, password);
    PasswordInfo info = analyze(password);

    cout << "Duljina: " << info.length << endl;
    cout << "Znamenke: " << info.digits << endl;
    cout << "Velika slova: " << info.uppercase << endl;
    cout << "Posebni znakovi: " << info.special << endl;

    if (is_strong(info)) {
        cout << "Lozinka je jaka." << endl;
    }
    else {
        cout << "Lozinka je slaba." << endl;
    }
}