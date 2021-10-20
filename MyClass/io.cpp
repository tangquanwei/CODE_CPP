#include <iostream>
namespace IO {
	inline char nc() {
		static char buf[100000], *p1 = buf, *p2 = buf;
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
	}
	template <typename T>
	inline T read() {
		char ch = nc();
		T sum = 0;
		while (!(ch >= '0' && ch <= '9')) {
			ch = nc();
			if (ch == EOF)
				return EOF;
		}
		while (ch >= '0' && ch <= '9') {
			sum = sum * 10 + ch - 48;
			ch = nc();
			if (ch == EOF)
				return EOF;
		}
		return sum;
	}
}
using namespace IO;

int main() {
	long long tmp = read<long long>(); //输入方式
	std::cout << tmp << std::endl;

	while (tmp = read<long long>() != EOF) {} //循环判断EOF的方式
	return 0;
}