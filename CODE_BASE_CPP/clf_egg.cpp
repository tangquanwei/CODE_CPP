#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <conio.h>
// #include <format> c++20

using namespace std;

void copyRight()
{
    ifstream in(R"(D:\workspaceFolder\CODE_C++\txt\Copyright.txt)", ios::in);
    char buf[256];
    while (in.getline(buf, sizeof(buf)))
    {
        cout << buf << endl;
        Sleep(100);
    }
}

void showName_v2()
{
    system("cls");
    ifstream ifs(R"(D:\workspaceFolder\CODE_C++\txt\name.txt)", ios::in);
    char buf[256];
    for (int i = 1; ifs.getline(buf, sizeof(buf)); ++i)
    {
        cout << buf << endl;
        if (i % 11 == 0)
        {
            Sleep(500);
            system("cls");
        }
    }
}
void showQuote()
{
    system("cls");
    ifstream in(R"(D:\workspaceFolder\CODE_C++\txt\quote.txt)", ios::in);
    char buf[256];
    int cnt = 0;
    while (in.getline(buf, sizeof(buf)))
    {
        cout << buf << endl;
        if (cnt > 25)
            Sleep(300);
        ++cnt;
    }
    in.close();
    system("pause");
    system("cls");
}
//    ________________________________________________________
// 　|　Window                                    [－][口][×]| |
// 　|________________________________________________________|
// 　|                   Are you sure quit?                   |
// 　|                                                        |
// 　|                                                        |
// 　|       ----------       ----------       ----------     |
// 　|      |    Yes   |     |    NO    |     |   Close  |    |
// 　|       ----------       ----------       ----------     |
// 　|________________________________________________________|
//
int binary_search(vector<int> v, int k)
{
    int h = 0;
    int l = v.size();
    int mid = l / 2;
    while (h <= l)
    {
        if (v[mid] == k)
            return mid;
        else if (v[mid] < k)
        {
            h = mid + 1;
            mid = (h + l) / 2;
        }
        else if (v[mid] > k)
        {
            l = mid - 1;
            mid = (h + l) / 2;
        }
    }
    return -1;
}
void ProgressBar()
{
    const int len = 100;
    for (int i = 0; i <= len; i++)
    {
        system("cls");
        cout << "\n正在加载数据...... \n";
        cout << '[';
        for (int j = 0; j <= i; ++j)
            cout << (j == i ? '>' : '=');
        for (int j = 0; j < len - i; ++j)
            cout << ' ';
        cout << ']';
        cout.width(3);
        cout << i << "%";
        Sleep((len - 4 * i) > 0 ? len - 4 * i : 10);
    }
}

int ShowMenu_GetChoice()
{
    int cnt{0}, c1, c2;
    while (1)
    {
        cout << R"( ________________________________________________________ )" << endl;
        cout << R"(|　By_Quanwei                               [－][口][×]| |)" << endl;
        cout << R"(|________________________________________________________|)" << endl;
        cout << R"(|               _欢迎使用间谍管理系统_                   |)" << endl;
        if (cnt == 0)
            cout << R"(|            ==> 0. 退出系统                             |)" << endl;
        else
            cout << R"(|                0. 退出系统                             |)" << endl;
        if (cnt == 1)
            cout << R"(|            ==> 1. 添加间谍信息                         |)" << endl;
        else
            cout << R"(|                1. 添加间谍信息                         |)" << endl;
        if (cnt == 2)
            cout << R"(|            ==> 2. 显示间谍信息                         |)" << endl;
        else
            cout << R"(|                2. 显示间谍信息                         |)" << endl;
        if (cnt == 3)
            cout << R"(|            ==> 3. 删除间谍信息                         |)" << endl;
        else
            cout << R"(|                3. 删除间谍信息                         |)" << endl;
        if (cnt == 4)
            cout << R"(|            ==> 4. 修改间谍信息                         |)" << endl;
        else
            cout << R"(|                4. 修改间谍信息                         |)" << endl;
        if (cnt == 5)
            cout << R"(|            ==> 5. 查找间谍信息                         |)" << endl;
        else
            cout << R"(|                5. 查找间谍信息                         |)" << endl;
        if (cnt == 6)
            cout << R"(|            ==> 6. 按编号排序	                         |)" << endl;
        else
            cout << R"(|                6. 按编号排序	                         |)" << endl;
        if (cnt == 7)
            cout << R"(|            ==> 7. 清空所有文档                         |)" << endl;
        else
            cout << R"(|                7. 清空所有文档                         |)" << endl;
        cout << R"(|                                                        |)" << endl;
        cout << R"(|                请输入选项:)" << cnt << R"(                            |)" << endl;
        cout << R"(|________________________________________________________|)" << endl;
        c1 = _getch();
        cout<<c1<<endl;
        if (c1 == 13) // enter
            return cnt;
        if (c1 >= 49 && c1 < 56) //1 - 8
            return c1-48;
        c2 = _getch();
        switch (c2)
        {
        case 72: // up
            --cnt;
            break;
        case 80: // down
            ++cnt;
            break;
        case 75: // left
        case 77: // right
            return cnt;
        default:
            continue;
        }
        system("cls");
    }
}
int main()
{
    // ProgressBar();
    cout<<ShowMenu_GetChoice();

    return 0;
}
