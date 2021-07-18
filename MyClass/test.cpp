// 动态多态
// 继承
//继承虚函数
#include <iostream>
using namespace std;
class Animal
{
private:

public:
    int date{0};
    Animal(int d) : date(d) {}
    virtual void speak()
    {
        cout << "Animal" << endl;
    }
};
class Cat : public Animal
{
public:
    using Animal::Animal;
    virtual void speak()
    {
        cout << "Cat" << endl;
        cout << this->date << endl;
    }
};
class Dog : public Animal
{
public:
    virtual void speak()
    {
        cout << "Dog" << endl;
    }
};
void doSpeak(Animal &a)
{
    a.speak();
}
int main()
{
    Cat c(10);
    c.speak();
    

    return 0;
}