#include <iostream>

using namespace std;

int val = 23; //* 拥有全局作用域

int main()
{
    int a = 10;
    {
        int a = 5;
        int val = 34;//* 新建局部变量，拥有块作用域
        cout << "a=" << a << "\nval=" << val << endl;
    }
    cout << "a=" << a << "\nval=" << ::val << endl; //! 显示访问全局变量 val
    return 0;
}