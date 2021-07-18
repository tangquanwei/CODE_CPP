#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton &rhs) {}

public:
    static Singleton &getInstance()
    {
        static Singleton s;
        return s;
    }
    Singleton &setup() {}
};