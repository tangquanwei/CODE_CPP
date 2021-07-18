#include <iostream>

using namespace std;

template <typename T>
class SharedPtr
{
private:
     T *px;
     long *pn;

public:
     SharedPtr(T *p) : px(p) {}
     T &operator*() const
     {
          return *px;
     }
     T *operator->() const
     {
          return px;
     }
};
struct Foo
{
     void method()
     {
          cout << "I have been ! Called ! " << endl;
     }
};

int main()
{
     SharedPtr<Foo> sf(new Foo);
     Foo f(*sf);
     sf->method(); //sf->==px-> ->可延续

     return 0;
}