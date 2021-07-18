#include <iostream>
using namespace std;

int main()
{
    string str("Tang Quanwei");
    for (auto &&i : str)
    {
        cout << i+1 << endl;
        
    }
}