/**************************************************************
检测内存泄漏
在申请内存时记录下该内存的地址和在代码中申请内存的位置，
在内存销毁时删除该地址对应的记录，程序最后统计下还有哪条记录没有被删除，
如果还有没被删除的记录就代表有内存泄漏。
*/

#include <cstdlib>
#include <iostream>
#include <vector>
#define new new (__FILE__, __LINE__) //new A的时候底层就会自动调用operator new(std::size_t size, const char* file, int line)函数

using namespace std;

vector<char*> g_v_file;
vector<int> g_v_line;

void* operator new(std::size_t size, const char* file, int line) {
	g_v_file.push_back(file);
	g_v_line.push_back(line);
	return malloc(size);
}
void* operator new[](std::size_t size, const char* file, int line);

void show() {
	for (auto&& i : g_v_line) {
		cout << i << endl;
	}
}

int main() {
	int* p = new int;
    int a=100;
    p=&a;
	cout << *p << endl;
	show();

	return 0;
}