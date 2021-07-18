#include <cmath>
#include <iostream>

using namespace std;

class Vec3D {
private:
	double x, y, z;

public:
	//big 8
	Vec3D() : Vec3D(0, 0, 0) {}										   //default ctor
	explicit Vec3D(double x, double y, double z) : x(x), y(y), z(z) {} //ctor
	explicit Vec3D(Vec3D&& v) noexcept : x(v.x), y(v.y), z(v.z) {}	   //move ctor
	explicit Vec3D(const Vec3D& v) : x(v.x), y(v.y), z(v.z) {}		   //copy ctor
	explicit Vec3D(const Vec3D* vp) : x(vp->x), y(vp->y), z(vp->z) {}  //copy ctor pass by pointer
	Vec3D& operator=(Vec3D&& v) noexcept {							   //move assign
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}
	Vec3D& operator=(const Vec3D& v) { //copy assign
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}
	~Vec3D() = default;
	//function
	//getor
	decltype(x) getX() { return x; }
	decltype(y) getY() { return y; }
	decltype(z) getZ() { return z; }
	double getLength() { return sqrt(x * x + y * y + z * z); }
	//setor
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
	void setZ(double z) { this->z = z; }
	void show() { cout << *this; }
	friend ostream& operator<<(ostream& os, const Vec3D& v) {
		os << '(' << v.x << ',' << v.y << ',' << v.z << ',' << endl;
		return os;
	}
	friend istream& operator>>(istream& is, Vec3D& v) {
		is >> v.x >> v.y >> v.z;
		return is;
	}
	friend Vec3D operator+(const Vec3D& v, const Vec3D& s) {}
	friend Vec3D operator-(const Vec3D& v, const Vec3D& s) {}
	friend Vec3D operator*(const Vec3D& v, const Vec3D& s) {}
	friend Vec3D operator/(const Vec3D& v, const Vec3D& s) {}

	Vec3D& operator-() { //negative
		this->x = -x;
		this->y = -y;
		this->z = -z;
		return *this;
	}
	Vec3D& operator+=(const Vec3D& v) {}
	Vec3D& operator-=(const Vec3D& v) {}
	Vec3D& operator*=(const Vec3D& v) {}
	Vec3D& operator/=(const Vec3D& v) {}
	Vec3D& operator*=(const double k) {}
	Vec3D& operator/=(const double k) {}

	double operator[](int i) { return i == 0 ? x : (i == 1 ? y : z); }
};

int main() {
	Vec3D v(1, 2, 5);
	cout << v[3] << endl;
	cout << v.getLength() << endl;

	return 0;
}