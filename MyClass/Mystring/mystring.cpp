#include "mystring.hpp"
#include <iostream>
#include <cstring> //strlen
using std::cout;
using std::endl;
using std::ostream;

size_t strLen(const char *s)
{
    size_t i = 0;
    for (; s[i] != '\0'; ++i)
        ;
    return i;
}
char *strCpy(char *s, char *t)
{
    size_t i = 0;
    for (; s[i] != '\0'; ++i)
        ;
    for (size_t j = 0; t[j] != '\0'; ++j, ++i)
    {
        s[i] = t[j];
    }
    return s;
}
bool strCompare(const char *s1, const char *s2)
{
    while (*s1 == *s2 && *s1 != '\0')
    {
        ++s1;
        ++s2;
    }
    return *s1 - *s2;
}
char *lstrip(char *s)
{
    size_t cnt;
    for (size_t i = 0; s[i] != '\0'; ++i)
        if (s[i] == ' ' || s[i] == '\t')
        {
            for (size_t j = i; s[j] != '\0'; ++j)
                s[j] = s[j + 1];
            ++cnt;
            --i;
        }
    s[strLen(s) - cnt] = '\0';
    return s;
}
char *rstrip(char *s)
{
    if (*s == '\0')
        return s;
    char *p = s;
    while (*p != '\0')
        ++p;
    --p;
    while (*p == ' ' || *p == '\t')
    {
        *p = '\0';
        --p;
    }

    return s;
}
char *strip(char *s)
{
    return lstrip(rstrip(s));
}

inline String::String(const char *cstr) //重新定义函数实现中的默认参数。它只应该在函数声明中定义(头文件)
{
    if (cstr)
    {
        m_data = new char[strLen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }
}
inline String::~String()
{
    if (m_data)
    {
        delete[] m_data;
        m_data = nullptr;
    }
}
inline String::String(const String &str)
{
    m_data = new char[strLen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}
inline String &String::operator=(const String &str)
{
    if (this == &str)
        return *this; //检测自我赋值，必要
    delete[] m_data;
    m_data = new char[strLen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
} //拷贝赋值

ostream &operator<<(ostream &os, const String &str)
{
    return os << str.getCStr() << ' ';
}

int main()
{
    // String s1{"Hell"}, s2{"World"};
    char s[50] = "      hello ";
    char t[10] = "Word";
    // cout << s1 << s2;
    // cout << strLen(s1.getCStr()) << endl;
    // cout << strCompare(s1.getCStr(), s2.getCStr()) << endl;
    // cout << rstrip(s) << endl;
    // cout << lstrip(s) << endl;

    cout << strCpy(s, t) << endl;

    return 0;
}
