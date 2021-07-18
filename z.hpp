#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
int convert2(char *s)
{
    int x = 0;
    while (*s != '\0')
    {
        x = *s == '1' ? (x << 1) + 1 : (x << 1);
        ++s;
    }
    return x;
}
int convert8(char *s)
{
    int x = 0;
    while (*s != '\0')
    {
        x = (x << 3) + *s - '0';
        ++s;
    }
    return x;
}
int convert16(char *s)
{
    int x = 0;
    while (*s != '\0')
    {
        if ('0' <= *s && *s <= '9')
            x = (x << 4) + *s - '0';
        else if ('A' <= *s && *s <= 'F')
            x = (x << 4) + *s - 'A' + 10;
        else if ('a' <= *s && *s <= 'f')
            x = (x << 4) + *s - 'a' + 10;
        ++s;
    }
    return x;
}
double ArcTan(double x, double e = 0.000001)
{
    double y{x}, z{x};
    for (int i = 3; abs(y / i) > e; i += 2)
    {
        y = -y * x * x;
        z = z + y / i;
    }
    return z; //rad
}
bool Sym(int n)
{
    int x{n}, y{0};
    while (x != 0)
    {
        y = y * 10 + x % 10;
        x = x / 10;
    }
    return n == y;
} //回文
int f(int x)
{
    return x <= 0 ? 1 : f(x - 1) * x;
} //递归

void Horn(char a, char b, char c, int n)
{
    if (n == 1)
    {
        cout << "Move " << n << " from " << a << " to " << c << endl;
        return;
    }
    Horn(a, c, b, n - 1);
    cout << "Move " << n << " from " << a << " to " << c << endl;
    Horn(b, a, c, n - 1);
}
void Hanoi(char a, char b, char c, int n)
{
    if (n == 1)
        cout << a << "->" << c << endl; //a->c
    else
    {
        Hanoi(a, c, b, n - 1); // n-1个 a->b
        cout << a << "->" << c << endl; //第n个 a -> c
        Hanoi(b, a, c, n - 1); // n-1个 b->c
    }
}
void Swap(int a, int b)
{
    int c = a;
    a = b;
    b = c;
    cout << "a=" << a << ",b=" << b << endl;
}
void sWap(int *a, int *b)
{
    int *c = a;
    a = b;
    b = c;
    cout << "a=" << *a << ",b=" << *b << endl;
}
void swAp(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
    cout << "a=" << *a << ",b=" << *b << endl;
}
void swaP(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
    cout << "a=" << a << ",b=" << b << endl;
}
inline int add(int a, int b = 0)
{
    return a + b;
}
int add(int a, int b, int c)
{
    return a + b + c;
}
double add(double a, double b)
{
    return a + b;
}
class Point
{
private:
    int x, y;

public:
    static int CountP;
    Point(int a, int b); //这里不加const居然没报错
    Point()
    {
        x = 0;
        y = 0;
        ++CountP;
    }
    ~Point();
    Point(const Point &p);
    void Display() const;
    void Display();
    void Move(int deltX = 1, int deltY = 1);
    void Move(int deltX, int deltY, int scale);
    int GetX() const { return x; }
    int GetY() const { return y; }
    static void Fun() { cout << CountP << endl; }
    friend double Distance(Point &a, Point &b);
    friend class Line;
    friend ostream&  operator<<(ostream& os,Point* p);
    
};
ostream& operator<<(ostream& os,Point *p)
{
    p->Display();
    return os;
}
double Distance(Point &a, Point &b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
int Point::CountP;
Point::Point(const Point &p) //这里必须是const Fun才能返回临时对象
{
    x = p.x;
    y = p.y;
    cout << "Ctor 0 " << endl;
    ++CountP;
}
Point::Point(const int x, const int y) : x(x), y(y)
{
    cout << "Ctor 1 "
         << "x=" << x << ",y=" << y << endl;
    ++CountP;
}

Point::~Point()
{
    cout << "Dtor "
         << "x=" << x << ",y=" << y << endl;
    --CountP;
}
void Point::Move(int deltX, int deltY)
{
    x += deltX;
    y += deltY;
}
void Point::Move(int deltX, int deltY, int scale)
{
    x += deltX;
    y += deltY;
    x *= scale;
    y *= scale;
}
void Point::Display() const
{
    cout << "x=" << x << ",y=" << y << endl;
    cout << "const" << endl;
}
void Point::Display()
{
    cout << "x=" << x << ",y=" << y << endl;
}
Point Fun() { return Point(); } //called copy Ctor
class Sector
{
private:
    Point cental; //composition
    double r, start, end;

public:
    Sector()
    {
        r = 10;
        start = 0;
        end = 3.14 / 2;
    }
    Sector(int x, int y, double r1, double s, double e);
    Sector(Sector &s);
    ~Sector() { cout << "Dtor has been called " << endl; }
    void Move(int deltX, int deltY) { cental.Move(deltX, deltY); }
    void Display();
    double Length() { return 2 * r + (end - start) * r; }
    double Area() { return r * r * (end - start) / 2; }
};
Sector::Sector(int x, int y, double r_, double s, double e) : cental(x, y)
{
    r = r_;
    start = s;
    end = e;
}
Sector::Sector(Sector &s)
{
    cental = s.cental;
    r = s.r;
    start = s.start;
    end = s.end;
}
void Sector::Display()
{
    cental.Display();
    cout << r << "," << start << "," << end << endl;
}
class Line
{
private:
    Point p1, p2;

public:
    Line(int a1, int b1, int a2, int b2);
    Line(Point t1, Point t2);
    Line();
    double Length();
    void Display();
    void Move(int deltX, int deltY);
};
Line::Line(Point t1, Point t2) : p1(t1), p2(t2) {}
Line::Line(int a1, int b1, int a2, int b2) : p2(a2, b2), p1(a1, b1) {}
Line::Line() {}
void Line::Move(int deltX, int deltY) { p1.Move(deltX, deltY); }
void Line::Display()
{
    p1.Display();
    p2.Display();
}
double Line::Length()
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

class Circle
{
private:
    int x, y, r;

public:
    Circle(int a1, int b1, int R);
    Circle()
    {
        x = y = 0;
        r = 10;
    }
    double Length();
    void Display();
    void Move(int deltX, int deltY);
    double Area();
};
double Circle::Area()
{
    return 3.14 * r * r;
}
void Circle::Move(int deltX, int deltY)
{
    x += deltX;
    y += deltY;
}
void Circle::Display()
{
    cout << "x=" << x << ",y=" << y << ",r=" << r << endl;
}
double Circle::Length()
{
    return 2 * 3.14 * r;
}
Circle::Circle(int a1, int b1, int R)
{
    x = a1;
    y = b1;
    r = R;
}
class Rectangle
{
private:
    int x1, y1, x2, y2;

public:
    Rectangle(int a1, int b1, int a2, int b2);
    Rectangle() { x1 = x2 = y1 = y2 = 0; }
    double Length();
    void Display();
    void Move(int deltX, int deltY);
    double Area();
    ~Rectangle() {}
};
double Rectangle::Area()
{
    return abs((x2 - x1) * (y2 - y1));
}
void Rectangle::Move(int deltX, int deltY)
{
    x1 += deltX;
    y1 += deltY;
    x2 += deltX;
    y2 += deltY;
}
void Rectangle::Display()
{
    cout << "x1=" << x1 << ",y1=" << y1 << ",x2=" << x2 << ",y2=" << y2 << endl;
}
double Rectangle::Length()
{
    return 2 * (abs(x2 - x1) + abs(y2 - y1));
}
Rectangle::Rectangle(int a1, int b1, int a2, int b2)
{
    x1 = a1;
    y1 = b1;
    x2 = a2;
    y2 = b2;
}
class Student
{
private:
    char *name;
    int math;
    int english;

public:
    Student(char *n, int m, int e);
    Student(Student &s);
    void Display();
    int Sum() { return math + english; }
    ~Student();
};
Student::Student(char *n, int m, int e) : math(m), english(e)
{
    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
}
Student::Student(Student &s)
{
    name = new char[strlen(s.name) + 1];
    strncpy(name, s.name, strlen(s.name) + 1);
    math = s.math;
    english = s.english;
}
Student::~Student()
{
    delete name;
    cout << "~student run" << endl;
}
void Student::Display()
{
    cout << name << "," << math << "," << english << endl;
}
#define HEADA
// #undef HEADA
#ifdef HEADA
int xxx = 100;
#else
int xxx = -99;
#endif
class TV;
class Remote
{
public:
    void volume_to(TV &tv, int x);
    static void channel_to(TV &tv, int x);
};
class TV
{
private:
    int channel;
    int volume;
    int state;
    static int price;

public:
    enum
    {
        off = 0,
        on = 1
    };
    friend void Remote::volume_to(TV &tv, int x);
    friend void Remote::channel_to(TV &tv, int x);
    TV(int st = on, int c = 10) : volume(20), state(st), channel(c) {}
    void onOff()
    {
        state ^= 1;
        cout << "now state is " << (state ? "on" : "off") << endl;
    }
    void chan_next() { cout << "now channel is " << ++channel << endl; }
    void chan_pre() { cout << "now channel is " << --channel << endl; }
    void vol_larger() { cout << "now volume is " << ++volume << endl; }
    void vol_smaller() { cout << "now volume is " << --volume << endl; }
    void Display() const
    {
        cout << "now state is " << (state ? "on" : "off") << endl;
        cout << "now channel is " << channel << endl;
        cout << "now volume is " << volume << endl;
    }
};
int TV::price = 99;
void Remote::volume_to(TV &tv, int x)
{
    tv.volume = x;
    cout << "now volume is " << tv.volume << endl;
}
void Remote::channel_to(TV &tv, int x)
{
    tv.channel = x;
    cout << "now channel is " << tv.channel << endl;
}

char *StringCopy(char *source, char *target)
{
    char *p = target;
    while (*source != '\0')
    {
        *p = *source;
        p++;
        source++;
    }
    *p = '\0';
    return target;
}
int StringLength(char *t)
{
    int c = 0;
    while (*t != '\0')
    {
        t++;
        c++;
    }
    return c;
}
char *StringConcat(char *source, char *target)
{
    char *p = target;
    while (*p != '\0')
        p++;
    while (*source != '\0')
    {
        *p = *source;
        p++;
        source++;
    }
    *p = '\0';
    return target;
}
int StringCompare(char *s, char *t)
{
    while (*s == *t && *s != '\0')
        s++, t++;
    return *s - *t;
}
char *StringLeftTrim(char *s)
{
    int c = 0;
    char *p = s;
    while (*p == ' ' || *p == '\t')
        c++, p++;
    while (*p != '\0')
    {
        *(p - c) = *p;
        p++;
    }
    *(p - c) = '\0';
    return s;
}
char *StringRightTrim(char *s)
{
    char *p = s;
    while (*p != '\0')
        p++;
    if (p == s)
        return s; // void str
    p--;
    while (*p == ' ' || *p == '\t')
        *(p--) = '\0';
    return s;
}
char *StringTrim(char *s)
{
    return StringLeftTrim(StringRightTrim(s));
}

class Bird
{
protected:
    string name;

public:
    Bird(string n) { name = n; }
    void fly() { cout << name << " bird fly" << endl; }
    void run() { cout << name << " bird run" << endl; }
    void shout() { cout << name << "bird shout" << endl; }
};
class Duck : public Bird
{
public:
    Duck(string n) : Bird(n) {}
    void fly() { cout << name << " Duck fly" << endl; }
    void run() { cout << name << " Duck run" << endl; }
    void shout() { cout << name << "Duck shout" << endl; }
};
class Cock : public Bird
{
public:
    // Cock(string n) : Bird(n) {}  
    using Bird::Bird;
    void fly() { cout << name << " Cock fly" << endl; }
    void run() { cout << name << " Cock run" << endl; }
    void shout() { cout << name << "Cock shout" << endl; }
};
