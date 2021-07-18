#include <iostream>
#include <string>
#include <vector>
/* 
append() (追加字符串)
assign() (为字符串赋值)
at(index):  返回当前字符串中index位置的字符
clear(): 清空字符串
erase(index, n):  删除字符串从index开始的n个字符
empty(): 检测字符串是否为空
compare() (比较字符串)
at() 函数用于获取一个单独的字符；
substr() 函数则可以获取一个子串
find() 函数可以在一个字符串中搜索一个子串或者一个字符
insert() : 将某个字符/字符串插入到当前字符串的某个位置
replace() 将本字串从某个位置开始的一些字符替换为其它内容

[ ]
用数组下标运算符访问字符串中的字符
=
将一个字符串的内容复制到另一个字符串
+
连接两个字符串得到一个新串
+=
将一个字符串追加到另一个字符串末尾
<< 
将一个字符串插入一个流
>> 
从一个流提取一个字符串，分界符为空格或者空结束符
==, !=, <,   <=, >, >=
用于字符串比较
 */

using namespace std;

int main()
{
    vector<string> str_vec;
    vector<string> v1{"qwer", "asdf", "zxcv", "rtyu"};
    string temp;
    // while (cin >> temp)
    // {
    //     if (temp[0]=='1')
    //     {
    //         break;
    //     }
    //     str_vec.push_back(temp);
    //     cout << temp << endl;
    // }
    // for (auto &&i : str_vec)
    // {
    //     cout << i << ' ';
    // }


    return 0;
}
