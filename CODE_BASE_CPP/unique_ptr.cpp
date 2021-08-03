#include <iostream>
#include <memory>
#include <vector>
using namespace std;

unique_ptr<int> getRet()
{
    unique_ptr<int> up_i1{new int{100}};
    unique_ptr<int> up_i2 = make_unique<int>();
    return up_i1;
} //* 像声明函数的局部变量那样去声明智能指针

//返回指向动态分配资源的独占指针
unique_ptr<int> makeResource()
{
    unique_ptr<int> uptrResult(new int);
    *uptrResult = 55;
    return uptrResult;
}

int main()
{
    // unique_ptr<int> uptr;
    // uptr = makeResource(); // 自动移动
    // cout << *uptr << endl;
    // cout << *getRet() << endl;
    // cout << *makeResource() << endl;

    string s{"this is astring!"};
    unique_ptr<string> up_str(new string);
    *up_str = move(s);
    cout << *up_str << endl;
    cout << s << endl; //! cout nothing

    unique_ptr<vector<int>> up_vec_int = make_unique<vector<int>>();
    for (int i = 0; i < 10; ++i)
    {
        up_vec_int->push_back(i + 1);
    }
    for (auto &&i : *up_vec_int)
    {
        cout << i << "  ";
    }

    return 0;
}