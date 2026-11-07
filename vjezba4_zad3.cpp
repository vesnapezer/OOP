#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool starts_with(const string& s, const string& prefix) {
    if (prefix.size() > s.size()) {
        return false;
    }
    return equal(prefix.begin(), prefix.end(), s.begin());
}

bool ends_with(const string& s, const string& suffix) {
    if (suffix.size() > s.size()) {
        return false;
    }
    return equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main() {
    vector<string> files{
        "vjezba04.cpp",
        "slajdovi.pdf",
        "main.cpp",
        "README.md",
        "vjezba04.h",
        "notes.txt",
        "vjezba03.cpp"
    };

    // Brojanje .cpp datoteka
    int broj = count_if(files.begin(), files.end(), [](const string& s) {
            return ends_with(s, ".cpp");
        });

    cout << ".cpp datoteka: " << broj << endl;

    // Uklanjanje datoteka koje pocinju s vjezba
    files.erase(remove_if(files.begin(), files.end(), [](const string& s) {
            return starts_with(s, "vjezba");
        }), files.end());

    for (const string& s : files) {
        cout << s << " ";
    }
}

//equal() ne provjerava duljinu drugog raspona. Ako je prefiks dulji od stringa, čitali bi izvan dopuštenog raspona, nedefinirano ponašanje