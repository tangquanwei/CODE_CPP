#include <iostream>
using namespace std;

void hanoi(unsigned n, unsigned char a, unsigned char b, unsigned char c)
{
    if (n == 1)
    {
        cout << a << " --> " << c << endl;
    }
    else
    {
        hanoi(n - 1, a, c, b);
        cout << a << " --> " << c << endl;
        hanoi(n - 1, b, a, c);
    }
}

int main()
{
    unsigned char a{'A'}, b{'B'}, c{'C'};
    unsigned n{2};
    hanoi(n, a, b, c);

    return 0;
}