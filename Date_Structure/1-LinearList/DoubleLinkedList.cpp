#include <bits/stdc++.h>
#include "DoubleLinkedList.h"
using namespace std;
int main(int argc, char const* argv[]) {
	DoubleLinkedList<string>* sl = new DoubleLinkedList<string>();
	sl->insertHead("tang1");
	sl->insertHead("tang2");
	sl->insertHead("tang3");
	sl->insertTail("Qianwei1");
	sl->insertTail("Qianwei2");
	sl->insertTail("Qianwei3");
	cout << sl->removeHead() << "\n";
	cout << sl->removeHead() << "\n";
	cout << sl->removeHead() << "\n";
	cout << sl->removeHead() << "\n";
	cout << sl->removeHead() << "\n";
	cout << sl->removeHead() << "\n";
	
	cout << *sl << "\n";
	return 0;
}
