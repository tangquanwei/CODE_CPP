#include<iostream>
#include<math.h>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<string>
#include<sstream>
using namespace std;
/*class Scale
{
private:
	int x1, y1, x2, y2;
public:
	Scale(int a, int b, int c, int d);
	{
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}
	double Length();
	void Display();
	void Move(int deltX, int deltY);
	double Area();
};
Scale::Scale(int a,int b,int c,int d)
{
	x1 = a;
	y1 = b;
	x2 = c;
	y2 = d;
}
void Scale::Move(int deltX, int deltY)
{
	x1 += deltX;
	x2 += deltX;
	y1 += deltY;
	y2 += deltY;
}
double Scale::Length()
{
	return 2 * (abs(x2 - x1) + abs(y2 - y1));
}
double Scale::Area()
{
	return abs((x1 - x2) * (y1 - y2));
}
void Scale::Display()
{
	cout << "x1=" << x1 << ",y1=" << y1 << " x2=" << x2 << ",y2=" << y2 << endl;
}
class Student
{
private:
	char* name;
	int math;
	int english;
public:
	Student(const char* n, int m, int e);
	Student(Student& s);
	void Display();
	int Sum() { return math + english; }
	"Student();"
};
class Donut
{
private:
	double r1, r2;
	double price1, price2;
public:
	Donut(double r, double p1, double p2);
	double Getsum();
};
Donut::Donut(double r, double p1, double p2) {
	r1 = r;
	r2 = p1;
	p = p2;
}
class Point
{
private:
	int x, y;
public:
	Point(int a, int b);
	Point() { x = 0; y = 0; }
	~Point();
	Point(Point& p);
	void Display();
	void Move(int deltx = 1,int delty = 1);
	void Move(int deltx, int delty,int scale);
	int Getx() { return x; }
	int Gety() { return y; }
};

class Sector
{
private:
	double start, end, r;
	Point cental;
public:
	Sector() { r = 10, start = 0, end = 3.14 / 2; }
	Sector(int x, int y, double r1, double s, double e);
	Sector(Sector& s);
	~Sector() { cout << 'xi' << endl; }
	double Length() { return 2 * r + (end - start); }
	double Area() { return r * r * (end - start) / 2; }
	void Display();
	void Move(int deltX, int deltY) { cental.Move(deltX, deltY); }
};
Sector::Sector(int x, int y, double r1, double s, double e) :cental(x, y)
{
	r = r1;
	start = s;
	end = e;
}
void Sector::Display()
{
	cental.Display();
	cout << r << start << end << endl;
}
Sector::Sector(Sector& s)
{
	cental = s.cental;
	r = s.r;
	start = s.start;
	end = s.end;
}
Point::Point(Point& p)
{
	x = p.x;
	y = p.y;
}
Point::Point(int a, int b)
{
	x = a;
	y = b;
	cout << "x=" << x << "y=" << y << endl;
}
Point::~Point()
{
	cout << "x1=" << x << "y1=" << y << endl;
}
void Point::Move(int deltx, int delty) 
{
	x += deltx;
	y += delty;
}
void Point::Move(int deltx, int delty, int scale)
{
	x += deltx;
	y += delty;
	x *= scale;
	y *= scale;
}
inline void Point::Display()
{
	cout << "x=" << x << "y=" << y << endl;
}
class Heima
{
private:
	int x, y;
public:
	Heima A() { x = 0, y = 0; }
	void toubu() { cout << "souye" << endl; }
	void zhuoce() { cout << "python,c++" << endl; }
	void weibu() { cout << "shiping,guanggao" << endl; }
	static void F() { cout << "ss" << endl; }
	friend double Distance(Heima& a, Heima& b);
};
double Distance(Heima& a, Heima& b)
{
	double dx = a.x - b.x;
	double dy = a.y = b.y;
	return sqrt(dx * dx + dy * dy);
}
#define HEADA
#undef HEADA
#ifdef HEADA
	int xxx = 1000;
#else
	int xxx = -99;
#endif

class TV;
class Remote
{
piblic:
	void volume_to(TV& tv, int x);
	static void channel_to(TV& tv, int x);
};
class TV
{
public:
	enum{off=0,on=1};
	friend void Remote::volume_to(TV& tv, int x);
	friend void Remote::channel_to(TV& tv, int x);
	TV(int st = on)::volume(20)
	{
		state = st; channel = 5;
	}
	void onff() { state = state ^ 1;cout<<"now state is"<<(state ? "on") }
	void chan_next() { cout << "now channel is" << ++channel << endl; }
	void chan_pre() { cout << "" << --channel << endl; }
	void
};
int main()
{
	int i,j,k,t[3][3];
	int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int b[3][3] = { {10, 11, 12}, { 15 }, { 20 } };
	for (i = 0; i < 3; i++) 
	{
		for (j = 0; j < 3; j++) 
		{
			t[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
			cout << t[i][j]<<" ";
		}
		cout << endl;
	}
	*/
char* StringCopy(char* source, char* target)
{
		char* p = target;
		while (*source != '\0')
		{
			*p = *source;
			p++;
			source++;
		}
		*p = '\0';
		return target;
}
int StringLength(char* t)
{
	int s = 0;
	while (*t != '\0')
	{
		t++;
		s += 1;
	}
	return s;
}
char* StringConcat(char* source, char* target)
{
	char* p = target;
	while (*p != '\0')p++;
	while (*source != '\0')
	{
		*p = *source;
		p++;
		source++;
	}
	*p = '\0';
	return target;
}
int StringCompare(char* s, char* t)
{
	while (*s != '\0'&&*s==*t)
	{
		s++;
		t++;
	}
	return *s - *t;
}
char* StringRightTrim(char* s)
{
	char* p=s;
	while (*p != '\0')
	{
		p++;
	}
	if (p == s) { return s; }
	p--;
	while (*p == ' ' || *p == '\t')
	{
		*(p--) = '\0';
	}
	return s;
}
char* StringLeftTrim(char* s)
{
	int c = 0;
	char* p = s;
	while (*p == ' ' || *p == '\t')
	{
		c++, p++;
	}
	while (*p != '\0')
	{
		*(p - c) = *p;
		p++;
	}
	*(p - c) = '\0';
	return s;
}
char* StringTrim(char* s)
{
	return StringLeftTrim(StringRightTrim(s));
}

class Bird
{
private:
	string c;
public:
	Bird() {};
	void fly() { cout << "A bird is flying" << endl; }
	void run() { cout << "A mouse is running" << endl; }
	void shout() { cout <<"A dog is shouting" << endl; }
	~Bird() { cout << "bird析构函数被调用" << endl; }
};
class Duck:public Bird
{
private:
	string d;
public:
	Duck(string d, string c) { this->d = d; cout << "构造对象d" << endl; }
	~Duck() { cout << "duck析构函数被调用" << endl; }
	void showDuck() { cout << "d=" << this->d << endl; }
	
	
};
class Cock :public Bird, public Duck
{
/*private:
	string e;
public:
	Cock(string c, string d, string e) { this->e = e; }
	~Cock() { cout << "" << endl; }*/
};
class Complex
{
private:
	double real, imag;
public:
	Complex(double r = 0, double i = 0) { real = r, imag = i; }
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& b);
	Complex operator++();/*前置运算*/
	Complex operator--();
	Complex operator++(int);/*后置运算*/
	Complex operator--(int);
	friend Complex operator--(Complex& c);
	friend Complex operator--(Complex& c, int);
	double& operator[](int index);
	double operator()(int index);
	friend Complex operator+(const Complex& c, double a);
	friend Complex operator*(const Complex& c1, const Complex& c2);
	friend ostream& operator<<(ostream& out, const Complex& c);
	friend istream& operator>>(istream& in, Complex& x);
	friend Complex operator/(const Complex& c1, const Complex& c2);
	
	void Display();
};
Complex operator--(Complex& c,int)
{
	Complex t = c;
	c.real -= 1;
	return t;
}
Complex operator--(Complex& c)
{
	c.real -= 1;
	return c;
}
Complex Complex::operator++(int)
{
	Complex c = *this;
	real += 1;
	return c;
}
Complex Complex::operator--(int)
{
	Complex c = *this;
	real -= 1;
	return c;
}
Complex Complex::operator++()
{
	real += 1;
	return *this;
}
Complex Complex::operator--()
{
	real -= 1;
	return *this;
}
double& Complex::operator[](int index)
{
	if (index == 0)
		return real;
	else
		return imag;
}
double Complex::operator()(int index)
{ 
	if (index == 0)
		return sqrt(real * real + imag * imag);
	else
		return atan(imag / real) / 3.14 * 180;
}
Complex operator/(const Complex& c1, const Complex& c2)
{
	Complex x;
	x.real=(c1.real * c2.real + c1.imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
	x.imag = (c1.imag * c2.real-c1.real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
	return x;
}
istream& operator>>(istream& in,Complex& x)
{
	int i = -1;
	char buffer[64];
	int sign = 1;
	do
	{
		i++;
		in.get(buffer[i]);
	} while (!(buffer[i] == '+' || buffer[i] == '-'));
	if(buffer[i]='-')
		sign=-1;
	buffer[i] = '\0';
	x.real = atof(buffer);
	i = -1;
	do
	{
		i++;
		in.get(buffer[i]);
	} while (buffer[i] != 'i');
	buffer[i] = '\0';
	x.imag = sign*atof(buffer);
	return in;
}
ostream& operator<<(ostream& out, const Complex& c)
{
	out << "(" << c.real << "," << c.imag << "i)" << endl;
	return out;
}
Complex operator*(const Complex& c1, const Complex& c2)
{
	double real = c1.real * c2.real - c1.imag * c2.imag;
	double imag = c1.real * c2.imag + c1.imag * c2.real;
	return Complex(real, imag);
}
Complex operator+ (const Complex & c, double a)
{
	return Complex(c.real + a, c.imag);/*普通类型的数据与虚数相加*/
}
Complex Complex::operator+(const Complex& c)
{
	return Complex(real + c.real, imag + c.imag);
}
Complex Complex::operator-(const Complex& b)
{
	return Complex(real - b.real, imag - b.imag);
}
void Complex::Display()
{
	cout <<"("<< real <<","<< imag <<"i)"<< endl;
}
class Matrix
{
private:
	double data[3][3];
public:
	Matrix();
	Matrix(double a, double b);
	Matrix(double d[], int n);
	friend ostream& operator<<(ostream& os, Matrix m);
	Matrix operator+(Matrix m);
	Matrix operator*(Matrix m);
	
	friend Matrix operator-(Matrix m1, Matrix m2);
};
Matrix operator-(Matrix m1, Matrix m2)
{
	Matrix t;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			t.data[i][j] = m1.data[i][j] - m2.data[i][j];
	return t;
}
ostream& operator<<(ostream& os, Matrix m)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << setw(8) << m.data[i][j];
		cout << endl;
	}
	return os;
}
Matrix Matrix::operator*(Matrix m)
{
	Matrix t;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			t.data[i][j] = data[i][0] * m.data[0][j] + data[i][1] * m.data[1][j] + data[i][2] * m.data[2][j];
		}
	}
	return t;
}
Matrix Matrix::operator+(Matrix m)
{
	Matrix t;
	for(int i=0;i<3;i++)
		for (int j = 0; j < 3; j++)
			t.data[i][j] = data[i][j] + m.data[i][j];
	return t;
}
Matrix::Matrix()
{
	int k = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			data[i][j] = k++;
}
Matrix::Matrix(double d[], int n)
{
	int k = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (k >= n)
				data[i][j] = 0;
			else
				data[i][j] = k++;

		}
}
Matrix::Matrix(double a, double b)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			data[i][j] = a+(b-a)*rand()/32767;/*映射*/ 
		}
}
class Vector3
{
private:
	double x, y, z;
public:
	Vector3() { x = y = z = 0; }
	Vector3(double x, double y, double z);
	friend ostream& operator<<(ostream& os, Vector3 v);
	Vector3 operator+(Vector3 v);
	Vector3 operator-(Vector3 v);
	double& operator[](int index);
	double operator()(int index);
	bool Normal();
};
bool Vector3::Normal()
{
	if (x == 0 && y == 0 && z == 0)
		return false;
	double R = sqrt(x * x + y * y + z * z);
	x /= R;
	y /= R;
	z /= R;
	return true;
}
double Vector3::operator()(int index)
{
	double r = sqrt(x * x + y * y );
	double R = sqrt(x * x + y * y + z * z);
	if (index == 0)
		return R;
	if (index == 1)
		return asin(r / R) * 180 / 3.14;
	else
		return atan(y / R) * 180 / 3.14;
}
double& Vector3::operator[](int index)
{
	if (index == 1)
		return x;
	if (index == 2)
		return y;
	if (index == 3)
		return z;
}
Vector3::Vector3(double x,double y,double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Vector3 Vector3::operator+(Vector3 v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
} 
Vector3 Vector3::operator-(Vector3 v) 
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}
ostream& operator<<(ostream& os, Vector3 v)
{
	os << "(" << v.x << "," << v.y << "," << v.z << ")" << endl;
	return os;
}
/*函数指针*/
void a()
{
	cout << "a function" << endl;
}
void b()
{
	cout << "b function" << endl;
}
void c()
{
	cout << "c function" << endl;
}
/*虚函数 关键字 virtual*/
class Shape
{
public:
	virtual double Area() { return 0; }
	virtual double Length() { return 0; }

};
class Circles :public Shape
{
private:
	double r;
public:
	Circles(double r = 0) { this->r = r; }
	double Area() { return 3.14 * r * r; }
	double Length() { return 2 * 3.14 * r; }
};
/*矩形*/
class Rectangles :public Shape
{
private:
	double width, high;
public:
	Rectangles(double width, double high) { this->width = width, this->high = high; }
	double Area() { return width * high; }
	double Length(){return 2 * (width + high);}
};
/*三角形*/
class Triangles :public Shape
{
private:
	double a, b, c;
public:
	Triangles(double a = 1, double b =1, double c = 1)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	double Area() 
	{ 
		double s = (a + b + c) / 2; 
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}
	double Length() { return a + b + c; }
};
/*游戏接口*/
/*课程设计*/
class object
{
public:
	virtual void Move() = 0;/*移动*/
	virtual void Fire() = 0;/*生火发射物体*/
	virtual void Collision() = 0;/*摩擦碰撞*/
	virtual void Display() = 0;/*显示图片*/
};
/*地图*/ 
class Map
{
public:
	int data[40][80];
	char screen[40][80];
	object* my[10];
	object* npc[10];
	object* enemy[10];
	Map() {};
	bool insertMy(object* ob) { return true; }
	bool insertEnemy(object* ob) { return true; }
	bool insertNpc(object* ob) { return true; }
	bool RemoveMy(object* ob) { return true; }
	bool RemoveEnemy(object* ob) { return true; }
	/*bool insertNpc(object* ob) { return true; }*/
};
/*坦克*/
class TankT80 :public object
{
private:
	Map* map;
	int x, y;
	int width, high;
	char imag[200][200];
	double defence;/*防御值*/
	double attack;/*攻击力*/
	double health;/*生命值*/
	double speed;/*速度值*/
	int direction;
	int owner;
	int time1;
	int time2;
public:
	virtual void Move() = 0;/*移动*/
	virtual void Fire() = 0;/*生火发射物体*/
	virtual void Collision() = 0;/*摩擦碰撞*/
	virtual void Display() = 0;/*显示图片*/
};
void TankT80::Move()
{
	int t = rand();//32767
	if (x < 12)
	{
		direction = (direction + x) % 4;
		return;
	}
	else if(x<30)
	{
		switch (direction)
		{
		case 0:
			x += speed;
			return;
		case 1:
			y += speed;
			return;
		case 2:
			x -= speed;
			return;
		case 3:
			y-=speed;
			return;
		}
	}
}
void TankT80::Fire()
{
	/*if (owner == 0)
	{
		if (kbhit == 0)
		{

		}
	}
	int t = rand();//32767
	if (t < 12)
	{

	}
	else if (t < 30)
	{

	}*/
}
void TankT80::Collision()
{
	if (health > 100)
	{

	}
}
void TankT80::Display()
{

}

template<typename T>
void Sort(T a[], int n)
{
	int i, j;
	T x;
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
			if (a[j] < a[i])
			{
				x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
}
//保存一个数
template<class T>
class Store
{
private:
	T item;//用于存放任意类型的数据
	int haveValue;//用于标记item是否已被存入内容
public:
	Store(void);//默认形式(无形参)的构造函数
	T GetElem(void);
	void PutElem(T x);
};
template <class T>
Store<T>::Store(void) { haveValue = 0; }
template <class T>
T Store<T>::GetElem(void)
{
	if (haveValue == 0) 
	{
		cout << "No item present!" << endl;
		exit(1);
	}
	return item;
}
template <class T>
void Store<T>::PutElem(T x)
{
	haveValue++;
	item = x;
}

/*
int main()
{
	//读写文件文件操作大小写更改
	ifstream in;
	ofstream out;
	in.open("c:\\a.txt", ios::_Nocreate);
	out.open("c:\\b.txt", ios::trunc);
	char ch;
	while (in.good())
	{
		//ASC码读写 
		in>>ch;
		out << ch; 
	}
	in.close();
	out.close();
	
	Complex g(1000, 23);
	Store<int> S1, S2;
	Store<Complex> S3;
	Store<double> D;
	S1.PutElem(3);
	S2.PutElem(-7);
	cout << S1.GetElem() << " " 
		<< S2.GetElem() << endl;
	S3.PutElem(g);
	cout << "The student id is" 
		<< S3.GetElem()[0] << endl;
	cout << "Retrieving object D";
	cout << D.GetElem() << endl;//输出对象D的数据成员
	int a[] = { 54,43,76,25,97,13,53 };
	Sort(a, 7);
	for (int i = 0; i < 7; i++)
		cout << a[i] << " ";
}*/
	/*Map m;
	m.insertEnemy(new TankT80());
	while (true)
	{
		for (int i = 0; i < 10; i++)
		{
			if (m.enemy[i] != NULL)
				m.enemy[i]->Move();
				
		}
		for (int i = 0; i < 10; i++)
		{
			if (m.my[i] != NULL)
				m.my[i]->Move();
		}
		for (int i = 0; i < 10; i++)
		{
			if (m.enemy[i] != NULL)
				m.enemy[i]->Fire();
		}
		for (int i = 0; i < 10; i++)
		{
			if (m.my[i] != NULL)
				m.my[i]->Fire();
		}
		for (int i = 0; i < 10; i++)
		{
			if (m.enemy[i] != NULL)
				m.enemy[i]->Collision();
		}
		for (int i = 0; i < 10; i++)
		{
			if (m.my[i] != NULL)
				m.my[i]->Collision();
		}
		for (int i = 0; i < 10; i++)
		{
			if (m.enemy[i] != NULL)
				m.enemy[i]->Display();
		}
		for (int i = 0; i < 10; i++)
		{
			if (m.my[i] != NULL)
				m.my[i]->Display();
		}
		for (int i = 0; i < 40; i++)
			cout << m.screen[i] << endl;
		system("cls");*/
		//sleep(50);
	/*void (*ff)();
	int x1;
	cin >> x1;
	if (x1 < 0)
		ff = a;
	else if (x1 > 100)
		ff = b;
	else
		ff = c;
	ff();
	Shape* p[6];
	p[0] = new Circles(10);
	p[1] = new Rectangles(4, 5);
	p[2] = new Circles(20);
	p[3] = new Triangles(3,4,5);
	p[4] = new Shape();
	p[5] = new Rectangles(8, 8);
	for (int i = 0; i < 6; i++)
	{
		cout << "Length="<<p[i]->Length() << endl;
		cout <<"Area="<< p[i]->Area() << endl;
	}
	Duck d("ddd", "ccc");
	d.fly();
	d.shout();
	d.run();
	d.showDuck();
	int(*ptr)[10] = new int[3][10];
	ptr[1][5] = 100;
	cout << *(*(ptr + 1) + 5) << endl;
	string s = "wejioh";
	cout << s<< endl; 
	int k;
	char j[100] = "   1 2  34   56"; 
	
	cout << StringTrim(j) << endl;*/
	/*Complex c1(7, 6), c2(2, 3), c3, c,c4;
	c = c1 * c2;
	c3 = c / c2;
	c4 = c1 / c2;
	cout << c(0)<<c(3)<<c1;
	Matrix x(2.0, 3.0),a,b;

	cout << b * a;
	return 0;
} 
	/*Scale x(1, 2, 5, 6);
	cout << "c=" << x.Length() << endl;
	cout << "s=" << x.Area() << endl;
	x.Display();
	x.Move(2, 3);
	x.Display();
	Heima p,q;
	p.toubu();
	p.weibu();
	p.zhuoce();
	Distance(p, q);
	Heima::F();
	return 0;
}*/

//教室信息管理系统
#include<iostream>
#include<fstream>
#include<list>
using namespace std;
class Classroom
{
public:
	string num;//教室编号
	string name;//教室所在教学楼名字
	string desk_number;//教室中课桌数量
	string user;//教室使用情况
	friend istream& operator>>(istream& in, Classroom& c);
	friend ostream& operator<<(ostream& out, const Classroom& c);
	Classroom(){}
};
istream& operator>>(istream& in, Classroom& c)//重载运算符
{
	in >> c.num;
	in >> c.name;
	in >> c.desk_number;
	in >> c.user;
	return in;
}
ostream& operator<<(ostream& out, const Classroom& c)
{
	out << "教室编号为:" << c.num << endl;
	out << "教室所在教学楼为：" << c.name << endl;
	out << "教室中课桌数量：" << c.desk_number << endl;
	out << "教室使用情况：" << c.user << "\n";
	return out;
}
class Classmessage:public Classroom
{
private:
	list<Classroom> classroomlist;//存储所有教室信息的容器
	string path;//文件路径

	// 将容器中所有信息写入文件函数
	void ofsallMess()
	{
		path = "D:\\student\\classroom.txt";
		ofstream ofst;//以清空源文件内容方式打开文件
		ofst.open(path, ios::trunc);
		if (!ofst.is_open())//判断文件是否打开成功
		{
			cout << "文件打开失败" << endl;
			return;
		}
		//将容器中所有信息写入文件中功能实现部分
		for (list<Classroom>::const_iterator it = classroomlist.begin(); it != classroomlist.end(); it++)
			ofst << endl << it->num << endl << it->name << endl << it->desk_number << endl << it->user << endl;
			ofst.close();//关闭文件
	}
public:
	Classmessage();//构造函数
	void Menu();//功能菜单
	void Add();//添加新的教室
	void Display();//显示所有教室信息
	void Search();//查询教室信息
	void Delete();//删除教室信息
	void Modify();//修改教室信息
};
Classmessage::Classmessage()//用于将文件中的内容按格式读取到list<Classroom>中去
{
	path = "D:\\student\\classroom.txt";
	ifstream ifstr;
	ifstr.open(path, ios::in);//打开文件路径中的文件，如果打开失败则创建文件
	if (!ifstr.is_open())
	{
		ofstream temp(path);//创建文件
		temp.open(path, ios::out);
		if (!temp.is_open())//检测是否创建成功
		{
			cout << "创建文件失败，退出程序" << endl;
			exit(-1);
		}
		temp.close();//文件创建成功则关闭文件
	}
	system("cls");//清屏
	ifstream ifst;//将文件中所有内容读取到list容器中
	ifst.open(path, ios::in);
	char line[14];//字符数组，用于存储教室属性信息
	Classroom temp;
	ifst.getline(line, sizeof(line));
	//按行读取文件中的内容
	//循环读取信息，并将信息插入到list容器中
	while (!ifst.eof())//ifstream.eof()判断文件是否为空
	{
		//保存信息到临时教室temp中
		ifst.getline(line, sizeof(line));
		temp.num = line;
		ifst.getline(line, sizeof(line));
		temp.name = line;
		ifst.getline(line, sizeof(line));
		temp.desk_number = line;
		ifst.getline(line, sizeof(line));
		temp.user = line;

		classroomlist.push_back(temp);//将temp插入到教室容器中
	}
}
void Classmessage::Menu()
{
	for (int i = 0; i < 10; i++)
	{
		cout << "*";
	}
	cout << "教室信息管理系统";
	for (int i = 0; i < 10; i++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "*1.显示" << "\t\t" << "2.录入*" << endl;
	cout << "*3.查询" << "\t\t" << "4.修改*" << endl;
	cout << "*5.删除" << "\t\t" << "6.退出*" << endl;
	for (int i = 0; i < 32; i++)
	{
		cout << "*";
	}
	cout << endl;
}

void Classmessage::Add()
{
	path = "D:\\student\\classroom.txt";
	Classroom c;//创建一个教室结构体
	A:
	cout << "编号：";
	cin >> c.num;
	//查重，读入编号时，遍历所有的教室编号信息，如果编号相同则输出并提示重新输入
	for(list<Classroom>::const_iterator it =classroomlist.begin();it!=classroomlist.end();it++)
		if (it->num == c.num)
		{
			cout << "教室信息重复，请重新输入：" << endl << endl;
			goto A;
		}
	cout << "请输入该教室的信息：" << endl;
	cout << "教室所在教学楼名：";
	cin >> c.name;
	cout << "教室中课桌数量：";
	cin >> c.desk_number;
	cout << "教室使用情况(占用或空)：";
	cin >> c.user;
	classroomlist.push_back(c);//将新添加的教室信息尾插到容器中
	ofstream ofst;//创建写入流对象
	ofst.open(path, ios::app);//在文件路径中以追加方式打开文件
	//将教室信息按顺序写入到文件中
	ofst << endl << c.num << endl << c.name << endl << c.desk_number << endl << c.user << endl;
	ofst.close();
}
void Classmessage::Display()
{
	cout << endl;
	for (list<Classroom>::const_iterator it = classroomlist.begin(); it != classroomlist.end(); it++)
	{
		cout << "编号为" << it->num << "教室的基本信息如下：" << endl;
		cout << "\t教室所在教学楼为     " << it->name<< endl;
		cout << "\t教室中课桌数量     " << it->desk_number << endl;
		cout << "\t教室使用情况 " << it->user << "\n";
	}
}
void Classmessage::Search()
{
	string find_num;
	cout << "请输入需要查找的教室的编号：";
	cin >> find_num;
	for (list<Classroom>::const_iterator it =classroomlist.begin(); it !=classroomlist.end(); it++)
		if (it->num == find_num)
		{
			cout << "教室编号为:" << it->num << endl;
			cout << "教室所在教学楼为：" << it->name << endl;
			cout << "教室中课桌数量：" << it->desk_number << endl;
			cout << "教室使用情况：" << it->user << "\n";
			return;
		}
	cout << "没有找到编号为：" << find_num << "的教室" << endl;
}
void Classmessage::Delete()
{
	//从容器中查找和需要删除教室的编号一样的编号，找到则删除，并刷新文件内容
	string delete_num;
	cout << "请输入需要删除的教室的编号：";
	cin >> delete_num;
	list<Classroom>::const_iterator it;//const_iterator用于读取容器内的元素
	for (list<Classroom>::const_iterator it = classroomlist.begin(); it != classroomlist.end(); it++)
		if (it->num == delete_num)
		{
			classroomlist.erase(it);
			ofsallMess();//将容器中内容写入文件中 
			cout << "已删除" << endl;
			return;
		}
	cout << "没有找到该编号的教室..." << endl;
}
void Classmessage::Modify()
{
	string modify_num;
	A:
	cout << "请输入需要修改的教室的编号：";
	cin >> modify_num;
	//接受编号后，先遍历一遍容器查看是否有该编号，如果没有则重新输入
	list<Classroom>::const_iterator it;
	for (it = classroomlist.begin(); it != classroomlist.end(); it++)
		if (it->num == modify_num)break;
	if (it == classroomlist.end())
	{
		cout << "没有找到该编号...";
		goto A;
	}
	//修改教室信息
	for (list<Classroom>::iterator it = classroomlist.begin(); it != classroomlist.end(); it++)
		if (it->num == modify_num)
		{
			//先输出原信息
			cout << "该教室原来信息：" << endl;
			cout << "教室编号为:" << it->num << endl;
			cout << "教室所在教学楼为：" << it->name << endl;
			cout << "教室中课桌数量：" << it->desk_number << endl;
			cout << "教室使用情况：" << it->user << "\n";
			//再修改
			cout << "请输入修改后的学生信息：" << endl << endl;;
			cout << "教室编号为:"; cin >> it->num;
			cout << "教室所在教学楼为：";cin>> it->name;
			cout << "教室中课桌数量：";cin>> it->desk_number;
			cout << "教室使用情况："; cin >> it->user;
			break;
		}
	ofsallMess();//刷新文件中的信息
	cout << endl << "修改成功" << endl;
}
int main()
{
	Classmessage s;//创建管理系统对象
	char key;//key接收一个值，根据key值的不同执行不同的功能
	while (true)
	{
		s.Menu();//显示功能菜单
		cout << endl << "请输入需要执行的功能" << endl;
		cin >> key;
		cout << endl;

		switch (key) 
		{
		case '1':
			s.Display();
			break;
		case '2':
			s.Add();
			break;
		case '3':
			s.Search();
			break;
		case '4':
			s.Modify();
			break;
		case '5':
			s.Delete();
			break;
		case '6':
			return 0;
		}
		system("pause");//暂停中止
		system("cls");//每次执行完毕，清屏
	}
	return 0;
}