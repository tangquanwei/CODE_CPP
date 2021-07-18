#include <iostream>
using namespace std;

// 函数声明
int func();
// 变量声明
extern int a, b;
extern int c;
extern float f;

int main()
{
    // 变量定义
    int a, b;
    int c;
    float f;

    // 实际初始化
    a = 10;
    b = 20;
    c = a + b;
    // 函数调用
    int i = func();

} // namespace std;
// 函数定义
int func()
{
    return 0;
}
/* 左值（lvalue）：指向内存位置的表达式被称为左值（lvalue）表达式。
左值可以出现在赋值号的左边或右边。
右值（rvalue）：术语右值（rvalue）指的是存储在内存中某些地址的数值。
右值是不能对其进行赋值的表达式，
也就是说，右值可以出现在赋值号的右边，但不能出现在赋值号的左边。

变量是左值，因此可以出现在赋值号的左边。
数值型的字面值是右值，因此不能被赋值，不能出现在赋值号的左边。 */