#include <iostream>

using namespace std;

class Fraction
{
private:
    int num, den;

public:
    explicit Fraction(int num, int den = 1) : num(num), den(den) {}
    /* 只能显式地调用 */
    operator double() const
    {
        return static_cast<double>(num) / den;
    }
    Fraction operator+(const Fraction &f)
    {
        return Fraction(this->num * f.den + this->den * f.num, this->den * f.den);
    }
    int getNum() const { return num; }
    int getDen() const { return den; }
};
ostream &operator<<(ostream &os, const Fraction &f)
{
    os << static_cast<double>(f.getNum()) / f.getDen();
}
int main()
{
    Fraction f(1, 3);
    // Fraction d = f + 4;
    double d = f + 4;
    cout << d << endl;
    return 0;
}
