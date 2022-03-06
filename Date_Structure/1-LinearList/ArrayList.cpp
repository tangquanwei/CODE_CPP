#include <bits/stdc++.h>
#include "ArrayList.h"
using namespace std;

int main() {
	ArrayList<string>* al = new ArrayList<string>();
	cout << al->empty() << "\n";
	al->add("Tang");
	al->add("Quanwei");
	al->add("Here");
	al->add("Tang");
	al->add("Quanwei");
	al->add("Here");
	al->add("Tang");
	al->add("Quanwei");
	al->add("Here");
	cout << al << "\n";
	al->insert(0, "Hi");
	cout << al << "\n";
	al->insert(al->size() - 1, "Hi");
	cout << al << "\n";
	al->insert(al->size(), "Hi");
	cout << al << "\n";
	cout << al->indexOf("Hi") << "\n";
	cout << al->indexOf("Quanwei") << "\n";
	cout << al->lastIndexOf("Quanwei") << "\n";
	cout << al->lastIndexOf("Quanwe") << "\n";
	cout << al << "\n";
	try {
		cout << al->at(3) << "\n";
		cout << al->at(100) << "\n";
	}
	catch (const char* e) {
		cerr << e << '\n';
	}
	try {
		cout << "remove: " << al->remove(1) << '\n';
		cout << "remove: " << al->remove(2) << '\n';
		cout << "remove: " << al->remove(3) << '\n';
		cout << "remove: " << al->remove(103) << '\n';
	}
	catch (const char* e) {
		cerr << e << '\n';
	}
	cout << al << "\n";
	al->~ArrayList();
	cout << al << "\n";



	// auto al1 = new ArrayList<int>();
	// cout << al1;
	// cout << "\n";

	return 0;
}
