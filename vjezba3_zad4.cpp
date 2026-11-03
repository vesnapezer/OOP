#include <iostream>
#include <string>

using namespace std;

bool split_email(const string& email, string& user, string& domain) {
    size_t pos = email.find('@');

    if (pos == string::npos) {
        return false;
    }

    if (pos != email.rfind('@')) {
        return false;
    }

    if (pos == 0 || pos == email.size() - 1) {
        return false;
    }

    user = email.substr(0, pos);
    domain = email.substr(pos + 1);

    if (domain.find('.') == string::npos) {
        return false;
    }

    return true;
}

int main() {
    string email, user, domain;

    cout << "Unesite email adresu: ";
    getline(cin, email);

    if (split_email(email, user, domain)) {
        cout << "Korisnik: " << user << endl;
        cout << "Domena: " << domain << endl;
    }
    else {
        cout << "Neispravna adresa!" << endl;
    }

}