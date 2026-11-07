#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> split_words(const string& text) {
    vector<string> words;
    size_t start = 0;

    while (start < text.size()) {
        while (start < text.size() && text[start] == ' ') {
            start++;
        }

        if (start == text.size()) {
            break;
        }

        size_t end = text.find(' ', start);

        if (end == string::npos) {
            words.push_back(text.substr(start));
            break;
        }

        words.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    return words;
}

int main() {

    vector<string> dictionary{
        "programski", "jezik", "c++", "je", "brz", "i", "mocan", "ali", "nije", "jednostavan", "za", "pocetnike"
    };

    // Sortiranje rjecnika
    sort(dictionary.begin(), dictionary.end());


    // Unos recenice
    string text;
    cout << "Recenica: ";
    getline(cin, text);

    // Razdvajanje na rijeci
    vector<string> words = split_words(text);
    vector<string> unknown;

    // Obrada svake rijeci
    for (string word : words) {
        // Uklanjanje zareza i tocaka
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
                return c == ',' || c == '.';
            }), word.end());

        // Pretvaranje u mala slova
        for (char& c : word) {
            c = tolower(static_cast<unsigned char>(c));
        }

        // Provjera u rjecniku
        if (!binary_search(dictionary.begin(), dictionary.end(), word)) {
            unknown.push_back(word);
        }
    }

    // Ispis nepoznatih rijeci
    cout << "Nepoznatih rijeci: " << unknown.size() << endl;
    for (string word : unknown) {
        cout << word << " ";
    }
}