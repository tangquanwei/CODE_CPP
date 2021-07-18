#ifndef _MAIN_HPP_
#define _MAIN_HPP_

#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#define _USE_MATH_DEFINES // before #include <cmath>
#include <cmath>
// 二维矢量、三维矢量、矩阵(V)
// 运算符重载、函数重载
namespace Shape {
	// class SolidSphere;//! 前向引用声明
	class Shape //抽象类，不能实例化对象
	{
	public:
		virtual double getArea() = 0; //虚函数
	};

	class Circle : public Shape {
	private:
		mutable double radius{ 0 }; //就地初始化
	public:
		static const double pi;
		// const double pi{acos(-1)};
		// Circle(){};
		// Circle() = default;
		// Circle(double radius){
		//     this->radius=radius;
		// }
		// The two are the same for the Base type
		// Circle(double radius) : radius(radius) //Constructor Initializer List
		// {
		//     cout << "The Circle Object Has been Created!\nAnd the Radius is: " <<
		//     radius << endl;
		// }
		Circle(double radius = 1) { this->radius = radius; }
		// 若类的成员函数参数与私有成员变量名相同，那么参数名应加下划线后缀
		Circle& setRadius(double radius) {
			this->radius = radius;
			return (*this);
			// return Object
		}

		Circle& movRadius(double radius) {
			this->radius += radius;
			return (*this);
		}
		Circle& operator=(const Circle& p) { this->radius = p.radius; }
		double getRadius() { return radius; }
		double getRadius() const //! 重载getRadius函数
		{
			// radius++;//! raidus is mutable
			return radius;
		}
		double getLength() const {
			double a = 2 * pi * radius;
			return a;
		}
		double getArea() override {
			double a = pi * radius * radius;
			return a;
		}
		~Circle() {
			// execute when program is over
			// cout << "The " << typeid(*this).name() << " Object Has been Destroyed!"
			// << endl;
		}
		friend class Student;
	};
	const double Circle::pi{ M_PI };

	class SolidSphere : public Circle //! 默认的继承方式是私有继承
	{
		double radius{ 0 };

	public:
		using Circle::Circle; //? 继承基类所有构造函数（除了子类定义的同类的）
		SolidSphere(double radius)
			: radius{ radius }, Circle(radius) {} //*基类初始化，先基类，再子类；与次序无关
		using Circle::getArea;					  //*继承子类同名函数
		double getArea(int i) const {
			double ret = 4 * pi * radius * radius;
			return ret;
		}
		double getVolume() const {
			double ret = 4.0 / 3 * pi * radius * radius * radius;
			return ret;
		}
		~SolidSphere() {
			// execute when program is over
			// cout << "The " << typeid(*this).name() << " Object Has been Destroyed!"
			// << endl;
		}
	};

	class Point : public Shape { //能在类中初始化的成员只有一种，那就是静态常量成员
		static size_t cnt;		 //! 不能初始化，static const 可以
		double x, y;

	public:
		Point() : Point(0, 0) {}
		Point(double x, double y) : x{ x }, y{ y } { ++cnt; }
		Point(Point& p) : x{ p.x }, y{ p.y } { ++cnt; }
		Point(Point* p) : x{ p->x }, y{ p->y } { ++cnt; }
		~Point() {}
		double getX() { return x; }
		double getY() { return y; }
		double getArea() { return 0; }
		static size_t getCnt() { return cnt; }
	};
	size_t Point::cnt{ 0 };

	class Line : public Shape {
		Point d1, d2;

	public:
		Line() : Line(0, 0, 1, 1) {}
		Line(double a, double b) : Line(0, 0, a, b) {}
		Line(double a, double b, double c, double d) : d1{ a, b }, d2{ c, d } {}
		double getArea() { return 0; }
		double getLength() {
			return sqrt(pow(d1.getX() - d2.getX(), 2) + pow(d1.getY() - d2.getY(), 2));
		}
	};
	class Rectangle : public Shape, Line {
	private:
		Point d1, d2;

	public:
		// Rectangle() : Rectangle(0, 0, 1, 1) {}
		// Rectangle(double x, double y) : Rectangle(0, 0, x, y) {}
		// Rectangle(double a, double b, double c, double d) : d1{a, b}, d2{c, d} {}
		using Line::Line;
		double getLength() //! no const
		{
			return (fabs(d1.getX() - d2.getX()) + fabs(d1.getY() - d2.getY())) * 2;
		}
		double getArea() {
			return fabs(d1.getX() - d2.getX()) * fabs(d1.getY() - d2.getY());
		}
		~Rectangle() {}
	};
}

namespace SalesDate {
	class SalesDate {
	private:
		std::string bookNo{ "" };
		unsigned unitsSold{ 0 };
		double revenue{ 0 };

	public:														// *delegating constructor
		SalesDate() : SalesDate("Unknown") {}					// *constructor initialize list
		SalesDate(const std::string& s) : SalesDate(s, 0, 0) {} // also{}
		SalesDate(const std::string& s, unsigned n, double p)
			: bookNo(s), unitsSold(n), revenue(p * n) {}
		void show();
	};
}

namespace student {

	class Student {
		std::string fname{ "Unknown" };
		std::string lname{ "Unknown" };
		std::string* name_ps = &lname;
		unsigned num{ 0 };
		unsigned age{ 0 };
		int i;
		int j;

	public:
		Student() = default;
		Student(int v) : j(v), i(j) {} //! 安定义顺序赋值
		Student(std::string s, std::string c, unsigned n, unsigned a)
			: fname(s), lname(c), num(n), age(a) {}
		Student(const Student& p) {
			//* name_c = new char[strlen(p.name_c) + 1];
			name_ps = new std::string(*p.name_ps);
		}
		void ResetName(std::string fname) { this->fname = fname; }
		void show() {
		}
		void CalcCircleArea(double radius) {
		}

		~Student() {
			if (!name_ps) {
				delete name_ps;
				name_ps = nullptr;
			}
		}
	};
}
namespace vprt_vtable {
	class A {
	private:
		int m_data1, m_data2; //*  2*4个字节

	public:
		A(int v1 = 0, int v2 = 0) : m_data1(v1), m_data2(v2) {}
		~A() {}
		//@ 定义了2个虚函数 类中会有一个指向vtbl的指针 8个字节
		virtual void vfunc1() {}
		virtual void vfunc2() {}
		void func1() {}
		void func2() {}
	};
	class B : public A {
	private:
		int m_data3;

	public:
		B(int value = 0) : m_data3(value) {}
		~B() {}
		virtual void vfunc1(){};
		void func2() {}
	};

	class C : public B {
	private:
		int m_data4;

	public:
		C(int v = 0) : m_data4(v) {}
		~C() {}
		virtual void vfunc1(){};
		void func2() {}
	};

} // namespace Vptr_Vtbl

namespace Function_like_Class { // function-like class 仿函数

	template <class T>
	struct Identity {
		const T& operator()(const T& x) const { return x; }
	};
	template <class Pair>
	struct Select1st {
		const typename Pair::first_type&
		operator()(const Pair& x) const { return x.first; }
	};
	template <class Pair>
	struct Select2nd {
		const typename Pair::second_type&
		operator()(const Pair& x) const { return x.second; }
	};

	template <class T1, class T2> // member template
	struct Pair {
		T1 first;
		T2 second;
		Pair() : first(T1()), second(T2()) {}
		Pair(const T1& a, const T2& b) : first(a), second(b) {}
		template <class U1, class U2>
		Pair(const Pair<U1, U2>& p) : first(p.first), second(p.second) {}
	};
} // namespace Function_like_Class

namespace Pointer_like_Class {
	template <typename T>
	class SharedPtr {
	private:
		T* px;
		long* pn;

	public:
		SharedPtr(T* p) : px(p) {}
		T& operator*() const {
			return *px;
		}
		T* operator->() const {
			return px; //!
		}
	};
	struct Foo {
		std::string method() {
			return "I have been !Called! ";
		}
	};
} // namespace Pointer_like_Class

namespace Virtual {
	class Virtual {
	public:
		virtual void print() = 0;
	};
	class MyClass

	{
	public:
		MyClass() = default;

		MyClass(MyClass&&) = default;
		MyClass(const MyClass&) = default;
		MyClass& operator=(MyClass&&) = default;
		MyClass& operator=(const MyClass&) = default;
		~MyClass() = default;

	private:
	};
} // namespace Virtual
namespace complex {
	class Complex {
	private:
		mutable double re, im;

	public:
		Complex(double r = 0, double i = 0) : re(r), im(i) {}
		Complex(const Complex& c) {
			this->re = c.re;
			this->im = c.im;
		}
		Complex(const Complex* c) {
			this->re = c->re;
			this->im = c->im;
		}
		void operator=(const Complex& c) {
			this->re = c.re;
			this->im = c.im;
		}
		void operator=(const Complex* c) {
			this->re = c->re;
			this->im = c->im;
		}
		double getReal() { return re; }
		double getImag() { return im; }
		void setReal(double r) { re = r; }
		void setImag(double i) { im = i; }
		double real() const { return re; }
		double imag() const { return im; }

		Complex operator-();
		Complex& operator+=(const Complex&);
		Complex& operator-=(const Complex&);
		Complex& operator*=(const Complex&);
		Complex& operator*=(const double&);
		Complex& operator/=(const Complex&);
		Complex& operator/=(const double);
		Complex operator!();
		Complex& operator++();
		Complex operator++(int);
		Complex& operator--();
		Complex operator--(int);
		bool operator==(const Complex&);

		friend Complex& __doapl(Complex*, const Complex&);
		friend std::istream& operator>>(std::istream& in, Complex& c) {
			in >> c.re >> c.im;
			return in;
		}
		friend std::ostream& operator<<(std::ostream& os, const Complex& c) { // ostream 的状态在改变
			return os << '(' << c.real() << ", " << c.imag() << ')' << '\n';
		}
	};

	Complex Complex::operator-() {
		return Complex(-this->re, -this->im);
	}
	Complex& Complex::operator+=(const Complex& c) {
		return __doapl(this, c);
	}
	Complex& Complex::operator-=(const Complex& c) {
		return __doapl(this, Complex(-c.re, -c.im));
	}
	Complex& Complex::operator*=(const Complex& c) {
		this->re = this->re * c.re - this->im * c.im;
		this->im = this->re * c.im + this->im * c.re;
		return *this;
	}
	Complex& Complex::operator*=(const double& k) {
		re *= k;
		im *= k;
		return *this;
	}
	bool Complex::operator==(const Complex& c) {
		if (this->re == c.re && this->im == c.im)
			return true;
		else
			return false;
	}

	Complex& __doapl(Complex* ths, const Complex& r) {
		ths->re += r.re;
		ths->im += r.im;
		return *ths;
	}
	Complex operator+(const Complex& x, const Complex& y) { //返回临时对象，不可返回reference
		return Complex(x.real() + y.real(), x.imag() + y.imag());
		//typename(); 临时对象
	}
	Complex operator-(const Complex& x, const Complex& y) { //返回临时对象，不可返回reference
		return Complex(x.real() - y.real(), x.imag() - y.imag());
		//typename(); 临时对象
	}
	Complex conj(const Complex& c) {
		return Complex(c.real(), -c.imag());
	}

	Complex& Complex::operator/=(const Complex& c) {
		this->re = (re * c.real() + im * c.imag()) / (c.real() * c.real() + c.imag() * c.imag());
		this->im = (im * c.real() - re * c.imag()) / (c.real() * c.real() + c.imag() * c.imag());
		return *this;
	}
	Complex& Complex::operator/=(const double k) {
		this->re /= k;
		this->im /= k;
		return *this;
	}
	Complex Complex::operator!() {
		return Complex(this->re, -this->im);
	}
	Complex& Complex::operator++() {
		++re;
		++im;
		return *this;
	}
	Complex Complex::operator++(int) {
		Complex c = *this;
		++c;
		return c;
	}
	Complex& Complex::operator--() {
		--this->re;
		--this->im;
		return *this;
	}
	Complex Complex::operator--(int) {
		return Complex(re - 1, im - 1);
	}
}
namespace vec2d {
	class Vec2D {
	private:
		double x, y;

	public:
		Vec2D() : Vec2D(0, 0) {}
		Vec2D(double x, double y) : x{ x }, y{ y } {}
		Vec2D(const Vec2D& vct) // 必须是const
		{
			this->x = vct.x;
			this->y = vct.y;
		}
		Vec2D(const Vec2D* vct) {
			this->x = vct->x;
			this->y = vct->y;
		}
		const Vec2D& operator=(const Vec2D& vct) {
			this->x = vct.x;
			this->y = vct.y;
			return (*this);
		}
		const Vec2D& operator=(const Vec2D* vct) {
			this->x = vct->x;
			this->y = vct->y;
			return (*this);
		}

		~Vec2D() {}
		Vec2D operator+(const Vec2D& vct) {
			return add(vct);
		}
		Vec2D operator+=(const Vec2D& vct) {
			*this = this->add(vct);
			return *this;
		}

		Vec2D operator-(Vec2D& vct) {
			return subtract(vct);
		}
		double operator*(Vec2D& vct) {
			return dot(vct);
		}
		Vec2D operator*(double k) {
			return multiply(k);
		}

		bool operator==(Vec2D& vct) {
			return equals(vct);
		}

		bool operator!=(Vec2D& vct) {
			return !equals(vct);
		}

		bool operator>(Vec2D& vct) {
			return (compareTo(vct) > 0);
		}
		bool operator<(Vec2D& vct) {
			return (compareTo(vct) < 0);
		}
		double& operator[](const unsigned int& index) { //不能重载为友元函数，只能重载为成员函数
			if (index == 0)
				return x;
			else if (index == 1)
				return y;
			else {
				std::cout << "index out of bound" << '\n';
				exit(0);
			}
		}
		const double& operator[](const unsigned int& index) const { //不能重载为友元函数，只能重载为成员函数
			if (index == 0)
				return x;
			else if (index == 1)
				return y;
			else {
				std::cout << "index out of bound" << '\n';
				exit(0);
			}
		}
		Vec2D operator-()						//作为对象成员的一元运算符无参数
		{										//unary operator '-'
			return Vec2D(-(this->x), -this->y); // 返回匿名临时对象
		}
		Vec2D operator++() // prefix
		{
			x += 1;
			y += 1;
			return *this;
		}

		Vec2D operator++(int dummy) // postfix dummy占位符
		{
			Vec2D temp(this->x, this->y);
			x += 1;
			y += 1;
			return temp;
		}
		Vec2D operator--() // prefix
		{
			x -= 1;
			y -= 1;
			return *this;
		}

		Vec2D operator--(int dummy) // postfix dummy占位符
		{
			Vec2D temp(this->x, this->y);
			x -= 1;
			y -= 1;
			return temp;
		}
		// std::ostream &operator<<(std::ostream &stream);
		// std::istream &operator>>(std::istream &stream);//和习惯不一样
		friend std::ostream& operator<<(std::ostream& stream, Vec2D& vct) { //cout << v1;
			stream << "(" << vct[0] << ", " << vct[1] << ")" << '\n';
			return stream;
		}

		friend std::istream& operator>>(std::istream& stream, Vec2D& vct) {
			stream >> vct.x >> vct.y;
			return stream;
		}

		operator double() //重载对象转换运算符，没有返回类型
		{
			return magnitude();
		}
		Vec2D add(const Vec2D& vct) {
			x += vct.x;
			y += vct.y;
			return (*this);
		}

		double compareTo(Vec2D& vct) {
			return (magnitude() - vct.magnitude());
		}

		Vec2D decrease() {
			--x;
			--y;
			return (*this);
		}
		double drection() {
			return std::atan(y / x);
		}
		double dot(Vec2D& vct) {
			return x * vct.x + y * vct.y;
		}
		bool equals(Vec2D& vct) {
			if (vct.x == x && vct.y == y)
				return true;
			else
				return false;
		}

		Vec2D increase() {
			++x;
			++y;
			return (*this);
		}
		double magnitude() {
			return sqrt(x * x + y * y);
		}
		Vec2D multiply(double k) {
			x *= k;
			y *= k;
			return (*this);
		}
		Vec2D negative() {
			x = -x;
			y = -y;
			return (*this);
		}
		Vec2D subtract(Vec2D& vct) {
			x -= vct.x;
			y -= vct.y;
			return (*this);
		}
		std::string toString() {
			return "\nx = " + std::to_string(this->x) + "\ny = " + std::to_string(this->y);
		}
		void show() {
			std::cout << "(" << (*this)[0] << ", " << (*this)[1] << ")" << '\n';
		}
	};

	class PrintStr {
	private:
		std::ostream& os;
		char sep;

	public:
		PrintStr(std::ostream& os = std::cout, char sep = '\n') : os(os), sep(sep) {}
		void operator()(const std::string& s) const { os << s << sep; }
		/* 重载函数调用运算符 */
	};
	class Vec3D {
	private:
		double x, y, z;

	public:
		Vec3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
		Vec3D(const Vec3D& v) {
			x = v.x;
			y = v.y;
			z = v.z;
		}
		~Vec3D() {}

		Vec3D& operator=(const Vec3D& v);
		Vec3D& operator+=(const Vec3D& v);
		Vec3D& operator-=(const Vec3D& v);
		Vec3D& operator*=(const Vec3D& v);
		Vec3D& operator/=(const Vec3D& v);
		Vec3D& operator++();
		Vec3D& operator--();
		Vec3D operator++(int);
		Vec3D operator--(int);
		Vec3D operator+(const Vec3D& v);
		Vec3D operator-(const Vec3D& v);
		Vec3D operator*(const Vec3D& v);
		Vec3D operator/(const Vec3D& v);

		double operator[](unsigned x);
		double operator*(double x);
		double operator()(unsigned x);
		bool operator==(const Vec3D& v);
		bool normalize() {
			if (x == 0 && y == 0 && z == 0)
				return false;
			else {
				double r = sqrt(x * x + y * y + z * z);
				x /= r;
				y /= r;
				z /= r;
				return true;
			}
		}
		bool isNormalized() {
			return x * x + y * y + z * z == 1 ? true : false;
		}

		friend std::ostream& operator<<(std::ostream& os, const Vec3D& v);
		friend std::istream& operator>>(std::istream& is, const Vec3D& v);
	};
}
namespace virt {
	class Shape // 考立体的,表面积,体积,正四面体
	{
	private:
	public:
		Shape() = default;
		~Shape() {}
		virtual double area() = 0;
		virtual double length() = 0;
	};
	class Circle : public Shape {
	private:
		double r;

	public:
		Circle(double r = 1) : r(r) {}
		~Circle() {}
		double area() override {
			return 3.14 * r * r;
		}
		double length() override {
			return 2 * 3.14 * r;
		}
	};
	class Rectangle : public Shape {
	private:
		double a, b;

	public:
		Rectangle(double a = 2, double b = 1) : a(a), b(b) {}
		~Rectangle() {}
		double area() override {
			return a * b;
		}
		double length() override {
			return 2 * (a + b);
		}
	};
	class Triangle : public Shape {
	private:
		double a, b, c;

	public:
		Triangle(double a = 1, double b = 1, double c = 1) : a(a), b(b), c(c) {}
		~Triangle() {}
		double area() override {
			double p = (a + b + c) / 2.0;
			return sqrt(p * (p - a) * (p - b) * (p - c));
		}
		double length() override { return a + b + c; }
	};
	class Body {

	public:
		Body() {}
		~Body() {}
		virtual double surarea() = 0;
		virtual double volume() = 0;
	};
	class Sphere : public Body {
	private:
		double radius;
		const double pi{ 3.14 };

	public:
		Sphere(double r = 1) : radius(r) {}
		~Sphere() {}
		double surarea() override { return 4 * pi * radius * radius; }
		double volume() override { return 4 * pi * radius * radius * radius / 3; }
	};
	class Tetrahedron : public Body //四面体
	{
	private:
		double l;

	public:
		Tetrahedron(double l = 1) : l(l) {}
		~Tetrahedron() {}
		double surarea() override { return sqrt(3) * l * l; }
		double volume() override { return sqrt(2) * l * l * l / 12; }
	};

} // namespace virt

#endif