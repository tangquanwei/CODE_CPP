#include "double_linked_list.h"
#include <iostream>
using namespace std;

class Person {
public:
	int id;
	int age;
	Person(int a, int b) : id(a), age(b) {}
};

int main() {
	DNode<int> head(10);
	head.insert_right(new DNode<int>(100));
	cout << head.data << endl;
	cout << head.next_right()->data << endl;


	return 0;
}