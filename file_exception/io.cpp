#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define D(a)         \
    T << #a << endl; \
    a
ofstream T("output.txt");

int main()
{
    D(int i = 23;)

    int n{25};
    cout << "dec: " << dec << n << endl;
    cout << "oct: " << oct << n <<  endl;
    cout << "hex: " << hex << n <<  endl;

    double d{12.4};
    cout.setf(ios_base::left, ios_base::adjustfield);//左对齐
    cout.width(10);//宽度
    cout.precision(10);
    cout<<d<<endl;


    // cin.tie( &cout);
    // cerr<<"Quanwei\n";
    // cout<<"Quan\n";
    // cout<<"HI\n"<<flush;
    // cout<<"HI\n"<<ends;
    // cout<<"HI\n"<<endl;

    return 0;
}
