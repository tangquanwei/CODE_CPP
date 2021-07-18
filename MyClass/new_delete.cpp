#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
using namespace std;

class Foo
{
private:
    int id;
    long data;
    string str;

public:
    Foo() : id(0)
    {
        cout << "default ctor: this=" << this << "id=" << id << endl;
    }
    Foo(int id) : id(id)
    {
        cout << "ctor: this=" << this << "id=" << id << endl;
    }
    ~Foo()
    {
        cout << "dtor: this=" << this << "id=" << id << endl;
    }
    //* override menber
    static void *operator new(size_t size)
    {
        Foo *p = (Foo *)malloc(size);
        cout << "operator new" << endl;
        return p;
    }

    static void operator delete(void *pdead)
    {
        free(pdead);
        cout << "operator delete" << endl;
    }
    static void *operator new[](size_t size)
    {
        Foo *p = (Foo *)malloc(size);
        cout << "operator new[]" << endl;
        return p;
    }
    static void operator delete[](void *pdead)
    {
        free(pdead);
        cout << "operator delete[]" << endl;
    }
};
//*override global
inline void *operator new(size_t size)
{
    Foo *p = (Foo *)malloc(size);
    cout << "::operator new" << endl;
    return p;
}
inline void operator delete(void *pdead)
{
    free(pdead);
    cout << "::operator delete" << endl;
}
inline void *operator new[](size_t size)
{
    Foo *p = (Foo *)malloc(size);
    cout << "::operator new[]" << endl;
    return p;
}
inline void operator delete[](void *pdead)
{
    free(pdead);
    cout << "::operator delete[]" << endl;
}
//* override placement

void *operator new(size_t size,int id){
    Foo *p = (Foo *)malloc(size);
    cout << "placement new" << endl;
    return p;
}
void operator delete(void* pdead,int i){
    free(pdead);
    cout<<"placement delete"<<endl;
}

int main()
{


    return 0;
}