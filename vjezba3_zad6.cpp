#include <iostream>
#include <string>
#include <vector>

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
    string text;
    cout << "Unesi recenicu: ";
    getline(cin, text);

    vector<string> words = split_words(text);

    cout << "Broj rijeci: " << words.size() << endl;

    if (words.empty()) {
        cout << "Nije unesena nijedna rijec." << endl;
        return 0;
    }

    string longest = words[0];

    for (int i = 1; i < words.size(); i++) {
        if (words[i].size() > longest.size()) {
            longest = words[i];
        }
    }

    cout << "Najdulja: " << longest << endl;

    string reversed;

    for (int i = words.size() - 1; i >= 0; i--) {
        reversed += words[i];

        if (i > 0) {
            reversed += "-";
        }
    }

    cout << reversed << endl;

    string first = words[0];

    for (int i = 1; i < words.size(); i++) {
        if (words[i] < first) {
            first = words[i];
        }
    }

    cout << "Prva po abecedi: " << first << endl;
}