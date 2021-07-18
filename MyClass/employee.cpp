#include <iostream>
#include <string>
using namespace std;
class Date
{
    unsigned year{2021}, month{1}, day{1};

public:
    Date() = default;
    Date(unsigned y, unsigned m, unsigned d) : year(y), month(m), day(d) {}
    unsigned getYear() const { return year; }
    unsigned getMonth() const { return month; }
    unsigned getDay() const { return day; }
    void setYear(unsigned year) { this->year = year; }
    void setMonth(unsigned month) { this->year = month; }
    void setDay(unsigned day) { this->day = day; }
    string toString()
    {
        return to_string(year) + '-' + to_string(month) + '-' + to_string(day);
    }
    void show(){
        cout<<this->toString()<<endl;
    }
    friend class Kid; //friend declaration
    friend void print(const Date &d);
};
void print(const Date &d)
{ // defination
    cout << d.year << '-' << d.month << '-' << d.day << endl;
}
class Kid
{
    Date birthday;

public:
    Kid()
    {
        cout << "I was born in "
             << birthday.toString() << endl;
    }
};
enum class Gender
{
    male,
    female,
};
class Employee
{
private:
    string name;
    Gender gender;
    Date *birthday;
    static int cnt; //declaration

public:
    Employee()
    {
        ++cnt;
    };
    Employee(string name, Gender gender, Date *birthday) : name{name}, gender{gender}, birthday{birthday}
    {
        ++cnt;
    }
    // Employee(const Employee &e) = default; //浅拷贝ctor
    // Employee(const Employee &e)
    // { //深拷贝ctor
    //     birthday = new Date{e.birthday};
    // }
    const Employee &operator=(const Employee &e)
    {
        name = e.name;
        gender = e.gender;
        *birthday = *e.birthday; //复制内容而不是地址
        return (*this);
    }
    void setName(string name) { this->name = name; }
    void setGender(Gender gender) { this->gender = gender; }
    void setBirthday(Date birthday) { this->birthday = &birthday; }
    string getName() { return name; }
    Gender getGender() { return gender; }
    Date *getBirthday() { return birthday; } //! pointer to class Date
    string toString()
    {
        return (name + (gender == Gender::male ? string("male") : string("female")) + birthday->toString());
    }
    void showCnt()
    {
        cout << "cnt = " << cnt << endl;
    }
};

int Employee::cnt; //! defination

int main()
{
    Employee e1;
    e1.setBirthday(Date(2002, 10, 9));
    Employee e2{e1};  //!copy constructor
    Employee e3 = e1; //! obj1=obj2  assignment instead of copy
    cout << e1.toString() << endl;
    e1.getBirthday()->setYear(1998);
    cout << e1.toString() << endl;
    cout << "----------------------" << endl;

    cout << e2.toString() << endl;
    e2.getBirthday()->setYear(2003);
    cout << e2.toString() << endl;
    cout << e1.toString() << endl;
    cout << "----------------------" << endl;

    cout << e3.toString() << endl;
    e3.getBirthday()->setYear(2004);
    cout << e3.toString() << endl;
    cout << e1.toString() << endl;
    cout << "----------------------" << endl;

    e3.showCnt();
    print(Date(2002, 10, 9));
    // Kid k;
    Date d1(2000, 11, 8),d2(1999, 5, 3);
    Employee e4{"Jack", Gender::male, &d1}, e5{"Anna", Gender::female, &d2};
    cout << e4.toString() << endl;
    cout << e5.toString() << endl;
    e4 = e5;
    cout << e4.toString() << endl;

    return 0;
}