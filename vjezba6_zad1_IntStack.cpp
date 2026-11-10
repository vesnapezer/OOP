/*Napomena za sve zadatke: data memberi su private. -> enkapsulacija 
Osim navedenih metoda, klase smiju imati i dodatne: get metode za čitanje članova, pomoćne privatne metode i set metode koje
čuvaju invarijantu klase (npr. provjerom ili ograničavanjem vrijednosti).
1. Napišite klasu IntStack: stog cijelih brojeva koji elemente čuva u nizu na heapu.
◦ Članovi: pointer na niz, broj elemenata i veličina niza (kapacitet). Konstruktor
prima početni kapacitet (zadano 2) i zauzima niz s new[]; destruktor ga oslobađa.
◦ push(int x): ako je niz pun, zauzmite novi niz dvostruke veličine, prepišite elemente,
oslobodite stari niz i tek onda dodajte x.
◦ pop(), top(), empty(), size() i capacity(). capacity() vraća veličinu niza
◦ Napišite copy konstruktor (deep copy).
Program za testiranje je u datoteci intstack_main.cpp.
Što bi se ispisalo bez vlastitog copy konstruktora?*/

//konstruktor ima isto ime kao i klasa, može primati parametre, nema povratni tip, služi za inicijalizaciju
//copy konstruktor stvara novi objekt na temelju postojećeg iste klase
//Klasa(const Klasa& other);
/*
class Student {
private:
string name;
int points;

public: 
void print() const {cout << name << " " << points; 
}
};

*/
//pr: Student a;
// Student b = a;

//deep copy:
/*
Array(const Array& other)
: data(new int[other.size]) {
for (int i = 0; i < other.size; ++i){
data[i] = other.data; //odvojene mem lokacije
}
}
*/

//delete je zabrana kopiranja
//Ticket(const Ticket&) = delete;
//Ticket t2 = t1; - error

//stack LIFO

#include <iostream>
#include <cassert>
using namespace std;

class IntStack {
private: 
	int* data;
	int count;
	int cap;

public:
	IntStack(int capacity = 2) {
		count = 0;

		if (capacity > 0)
			cap = capacity;
		else
			cap = 1;

		data = new int[cap];
	}

	~IntStack() {
		delete data[];
	}

	void push(int x) {
		if (count == cap) {
			int new_cap = cap * 2;
			int* new_data = new int[new_cap];
			for (int i = 0; i < count; ++i) {
				new_data[i] = data[i];
				delete[] data;
				data = new_data;
				cap = new_cap;
			}
			data[count] = x;
			++count;
		}	
	}

	void pop(int x) {
		if (count > 0)
			--count;
	}

	int top() const {
		return data[count - 1];
	}

	bool empty() const {
		return count == 0;
	}

	int size() const {
		return count;
	}

	int capacity() const {
		return cap;
	}

	IntStack(const IntStack& other) {
		count = other.count;
		cap = other.cap;
		data = new int[cap];
		for (int i = 0; i < 0; ++i) {
			data[i] = other.data[i];
		}
	}
};
int main() {
	IntStack s;
	for (int i = 0; )

}