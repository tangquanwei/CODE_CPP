#ifndef __COMPLEX_HPP__
#define __COMPLEX_HPP__
#include <iostream>
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
        Complex(Complex&& c){
            this->re=c.re;
            this->im=c.im;
        }
		void operator=(const Complex& c) {
			this->re = c.re;
			this->im = c.im;
		}
		void operator=(const Complex* c) {
			this->re = c->re;
			this->im = c->im;
		}
        void operator=(Complex&& c) {
			this->re = c.re;
			this->im = c.im;
		}
		double getReal() { return re; }
		double getImag() { return im; }
		void setReal(double r) { re = r; }
		void setImag(double i) { im = i; }
		double real() const { return re; }
		double imag() const { return im; }

		Complex operator-();//negtive
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
#endif // !__COMPLEX_HPP__