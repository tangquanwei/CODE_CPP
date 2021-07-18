#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int main()
{
    vector<string> v1{"a", "an", "the"};
    vector<int> ivec(10, -1);
    vector<string> svec(10, "a");

    vector<int> v2;
    // for (int i = 0; i != 100; ++i)
    // {
    //     v2.push_back(i);
    // }
    // for (auto &&i : v2)
    // {
    //     cout << i << endl;
    // }

    string s;
    vector<string> text;
    while (getline(cin, s))
    {
        if (!s.empty())
        {
            text.push_back(s);
            cout << s;
        }
        else
            break;
    }

    return 0;
}
