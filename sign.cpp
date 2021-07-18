#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
    int a, b;
    
    signed char c1 = 129;       //* 原码 1000 0001 补码 1(符号位)111 1111(127)
    unsigned char c2 = -1;      //* 原码 1000 0001 补码 1111 1111
    unsigned char c3 = 255;     //* 原码 1111 1111 
    printf("%d\n%d\n%d", c1, c2,c3);
    return 0;
}