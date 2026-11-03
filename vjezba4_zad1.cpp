#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>
#include <cstdlib>

using namespace std;

void input_vector(vector<int>& v) {
	int broj;
	cout << "Unosi brojeve (0 za kraj): ";
	do {
		cin >> broj;
		if (broj != 0) {
			v.push_back(broj);
		}
	} while (broj != 0);
}

bool je_li_negativan(int x) {
	return x < 0;

}

int main() {
	vector<int> v;
	input_vector(v);
	int k;
	cout << "k: ";
	cin >> k;
	if (k <= 0) {
		cout << "k mora biti veci od 0!" << endl;
		return 0;
	}
	if (v.empty()) {
		cout << "Vektor je prazan!" << endl;
		return 0;
	}

	//brojanje negativnih:	
	int br_neg = count_if(v.begin(), v.end(), [](int x) { return x < 0; });
	cout << "Negativnih ima: " << br_neg << endl;

	//prvi visekratnik broja:
	auto it = find_if(v.begin(), v.end(), [k](int x) {return x % k == 0; });
	if (it != v.end()) {
		cout << "Prvi visekratnik je od " << k << "je: " << *it << "na poziciji: " << it - v.begin() << endl;
	}
	else {
		cout << "Nema višekratnika broja " << k << endl;
	}

	//najmanji i najveci
	auto min = min_element(v.begin(), v.end());
	auto max = max_element(v.begin(), v.end());
	cout << "Najmanji: " << *min << " na poziciji: " << min - v.begin() << endl;
	cout << "Najveci: " << *max << " na poziciji: " << max - v.begin() << endl;

	//uklanjanje visekratnika:
	v.erase(remove_if(v.begin(), v.end(), [k](int x) { return x % k == 0; }), v.end());
	cout << "Bez visekratnika: " << endl;
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	cin.ignore(1000, '\n');
	cin.get();

}