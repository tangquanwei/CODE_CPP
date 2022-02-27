#include <iostream>

using namespace std;

unsigned int RGB(unsigned char r, unsigned char g, unsigned char b, unsigned char alph);


int main()
{
	unsigned musk = 1u << 31;

	float x(0);
	cin >> x;
	if (x > -5 && x < 0) {
		cout << x - 1 << endl;
	}
	else if (x == 0) {
		cout << x << endl;
	}
	else if (x > 0 && x < 8) {
		cout << x + 1 << endl;
	}
	else
	{
		cout << "10" << endl;
	}

}

unsigned int RGB(unsigned char r, unsigned char g, unsigned char b, unsigned char alph) {
	unsigned x = (r << 24);
	x += (g << 16);
	x += (b << 8);
	x += alph;
	return x;
}

unsigned char GetRed(unsigned char color) {
	return color >> 24;
}
unsigned int SetBit(unsigned int x, int position) {
	unsigned y = 1u << (position - 1);
	return x | y;//置一
}

unsigned int ResetBit(unsigned int x, int position) {
	unsigned y = 1u << (position - 1);
	return x & (~y);//置零
}
