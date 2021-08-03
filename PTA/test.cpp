#include <bits/stdc++.h>
using namespace std;

typedef struct Node* List;
struct Node {
	int data;
	struct Node* next;
};
int main() {
	char s[] = "hello qafa ufafa afaf nafaf wei";
	int cnt = 0;
	string str;
	for_each(begin(s), end(s), [&](auto x) {
		str[cnt++]=x;
	});
	s[8] = 0;
	cout << str;
	return 0;
}