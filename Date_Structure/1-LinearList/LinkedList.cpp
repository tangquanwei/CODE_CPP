#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;
int main(int argc, char const* argv[]) {
	LinkedList<string>* ll = new LinkedList<string>();
	ll->insertHead("Hi");
	ll->insertHead("Tang");
	ll->insertHead("Quanwei");
	ll->insertTail("Hello");
	ll->insertTail("Linked");
	ll->insertTail("List");
	ll->insertTail("Node");
	cout << *ll << '\n';
	ll->removeHead();
	cout << *ll << '\n';
	ll->removeTail();
	cout << *ll << '\n';
	cout << ll->remove("Tang") << '\n';
	cout << *ll << '\n';
	cout << ll->remove("List") << '\n';
	cout << *ll << '\n';
	cout << ll->remove("ist") << '\n';
	cout << *ll << '\n';
	ll->reverse();
	cout << *ll << '\n';
	cout << *ll << '\n';

	return 0;
}
