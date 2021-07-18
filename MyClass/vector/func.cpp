#include"main.hpp"

int my() {
	cout << "hello";
	return 0;
}

unsigned fact(unsigned n) { //copy
	if (n == 1)
		return 1;
	else
		return fact(n - 1) * n;
}

size_t count_calls() {
	static size_t ctr = 0;
	return ++ctr;
}

int reset(int& i) {   //alias
	cout << i << endl;
	return i = 100;
}

string::size_type find_char(const string& s, char c, string::size_type& occurs) {
	auto location = s.size();
	occurs = 0;
	for (decltype(location) i = 0; i != s.size(); ++i) {
		if (s[i] == c) {
			if (location == s.size())
				location = i;
			++occurs;
		}
	}
	return location + 1;
}

void hanoi(char a, char b, char c, int n) {
	if (n == 1)
	{
		cout << a << "->" << c << endl;
		return;
	}

	else {
		hanoi(a, c, b, n - 1);
		cout << n << ':' << a << "->" << c << '\t';
		hanoi(b, a, c, n - 1);
	}
}



void output(const int& n) {
	cout << "\t" << n;
}
void output(const double& d) {
	cout << "\t" << d;
}

int add(int a = 10, int b = 10, int c = 10) {
	return a + b + c;
}