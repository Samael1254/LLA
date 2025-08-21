#include "Complex.hpp"
#include <cmath>
#include <ostream>

Complex::Complex() : _real(0), _im(0) {}

Complex::Complex(float real) : _real(real), _im(0) {}

Complex::Complex(float real, float im) : _real(real), _im(im) {}

Complex &Complex::operator=(const Complex &rhs)
{
	if (this != &rhs)
	{
		_real = rhs._real;
		_im = rhs._im;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Complex &c)
{
	os << c.real();
	if (c.im() == 0)
		return os;
	if (c.im() < 0)
		os << " - " << -c.im();
	else
		os << " + " << c.im();
	os << "i";
	return os;
}

Complex Complex::operator+(const Complex &rhs) const
{
	return Complex(_real + rhs._real, _im + rhs._im);
}

Complex Complex::operator-(const Complex &rhs) const
{
	return Complex(_real - rhs._real, _im - rhs._im);
}

Complex Complex::operator*(const Complex &rhs) const
{
	float a = _real;
	float b = _im;
	float c = rhs._real;
	float d = rhs._im;

	return Complex((a * c) - (b * d), (a * d) - (b * c));
}

Complex Complex::operator/(const Complex &rhs) const
{
	float a = _real;
	float b = _im;
	float c = rhs._real;
	float d = rhs._im;
	float fact = 1 / (c * c + d * d);

	return Complex(fact * (a * c + b * d), fact * (a * d - b * c));
}

Complex Complex::operator+=(const Complex &rhs)
{
	*this = *this + rhs;
	return *this;
}

Complex Complex::operator-=(const Complex &rhs)
{
	*this = *this - rhs;
	return *this;
}

Complex Complex::operator*=(const Complex &rhs)
{
	*this = *this * rhs;
	return *this;
}

Complex Complex::operator/=(const Complex &rhs)
{
	*this = *this / rhs;
	return *this;
}

Complex &Complex::operator=(float rhs)
{
	_real = rhs;
	_im = 0;
	return *this;
}

Complex Complex::operator+(float rhs) const
{
	return Complex(_real + rhs, _im);
}
Complex Complex::operator-(float rhs) const
{
	return Complex(_real - rhs, _im);
}
Complex Complex::operator*(float rhs) const
{
	return Complex(_real * rhs, _im * rhs);
}
Complex Complex::operator/(float rhs) const
{
	return Complex(_real / rhs, _im / rhs);
}

Complex Complex::operator+=(float rhs)
{
	*this = *this + rhs;
	return *this;
}
Complex Complex::operator-=(float rhs)
{
	*this = *this - rhs;
	return *this;
}
Complex Complex::operator*=(float rhs)
{
	*this = *this * rhs;
	return *this;
}
Complex Complex::operator/=(float rhs)
{
	*this = *this / rhs;
	return *this;
}

Complex operator+(float lhs, Complex rhs)
{
	return Complex(rhs.real() + lhs, rhs.im());
}
Complex operator-(float lhs, Complex rhs)
{
	return Complex(rhs.real() - lhs, rhs.im());
}
Complex operator*(float lhs, Complex rhs)
{
	return Complex(rhs.real() * lhs, rhs.im() * lhs);
}
Complex operator/(float lhs, Complex rhs)
{
	return Complex(rhs.real() / lhs, rhs.im() / lhs);
}

float Complex::real() const
{
	return _real;
}

float Complex::im() const
{
	return _im;
}

float Complex::module() const
{
	return static_cast<float>(std::pow((_real * _real) + (_im * _im), 0.5));
}
