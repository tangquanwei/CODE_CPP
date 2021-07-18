#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Transform {
public:
	template <typename T>
	T& operator()(T& t) {
		return t;
	}
};

template <typename T>
T& my_transform(T& t) {
	return t;
}

template <typename T>
void do_func(T func) {
	func();
}

int main() {
	vector<int> vi1{ 1, 2, 3, 4, 5, 6 };
	list<int> li1;
	vector<int> vi2{ 1, 2, 3, 4, 5, 6 };
	list<int> li2;
	li1.resize(vi1.size()); //设置大小
	li2.resize(vi1.size());


	// transform(vi1.begin(), vi1.end(), li1.begin(), Transform());
	copy(vi2.begin(), vi2.end(), li2.begin());


	// for (auto&& i : li1) {
	// 	cout << i << ' ';
	// }
	// cout << endl;
	// for (auto&& i : vi1) {
	// 	cout << i << ' ';
	// }
	// cout << endl;
	// for (auto&& i : li2) {
	// 	cout << i << ' ';
	// }
	// cout << endl;

	// do_func([]() { cout << "do_func"; });

	char* a = new char[10];
	a = "quanwei";
	char* b = nullptr;
	b = a;
	a="quan";

	cout << a << endl;
	cout << b << endl;
	printf("%d\n%d", a, b);

	return 0;
}