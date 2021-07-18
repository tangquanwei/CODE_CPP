#include <iostream>
using std::cout;
using std::endl;
double devide(double x, double y)
{

    if (y == 0)
        throw "被除数不能为0"; //* 1.显示地抛出异常
    return x / y;              //*异常之后的代码不执行
}
void exception()
{
    try
    {
        cout << devide(2, 0); //* 2.执行可能出现异常的代码
    }
    catch (const char *error) //* 3.根据类型捕获异常
    {
        cout << error << endl;
    }
    catch (...) //* 所有异常
    {
    }
    cout << "over" << endl;
}
int main()
{
    return 0;
}