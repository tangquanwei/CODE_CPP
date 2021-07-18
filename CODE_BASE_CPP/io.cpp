#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <conio.h>

using namespace std;

void cin_() {
	char c = cin.get(); //
	char buf[64];
	char ch_end = '#';
	cin.getline(buf, sizeof(buf), ch_end); //读入一个字符串到ch_end结束
	int len = 10;
	cin.ignore(len, ch_end);
}
void cout_() {
	cout.put('a'); //输出一个字符
	/* 整型 */
	int n{ 27 };
	cout << dec << n << endl
		 << oct << n << endl
		 << hex << n << endl;
	/* 浮点型 */
	double d1 = 12.3456789, d2 = 12;
	int i1 = 12;
	cout << setprecision(6)
		 << d1 << endl
		 << d2 << endl
		 << i1 << endl;
}

int main() {
	cout_();

	return 0;
}