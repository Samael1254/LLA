#include "Complex.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

Complex::Complex(float real, float im) : _real(real), _im(im) {}

Complex Complex::operator-() const
{
	return Complex(-_real, -_im);
}

std::ostream &operator<<(std::ostream &os, const Complex &c)
{
	if (c._real == 0)
	{
		os << c.im();
		if (c.im() != 0)
			os << "i";
		return os;
	}
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

Complex &Complex::operator=(const Complex &rhs)
{
	if (this != &rhs)
	{
		_real = rhs._real;
		_im = rhs._im;
	}
	return *this;
}

bool Complex::operator==(const Complex &rhs) const
{
	return _real == rhs._real && _im == rhs._im;
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

	return Complex(a * c - b * d, a * d + b * c);
}

Complex Complex::operator/(const Complex &rhs) const
{
	float a = _real;
	float b = _im;
	float c = rhs._real;
	float d = rhs._im;
	float fact = 1 / (c * c + d * d);

	return Complex(fact * (a * c + b * d), fact * (b * c - a * d));
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

bool Complex::operator==(float rhs) const
{
	return _real == rhs && _im == 0;
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

bool operator==(float lhs, Complex rhs)
{
	return rhs.real() == lhs && rhs.im() == 0;
}

Complex operator+(float lhs, Complex rhs)
{
	return Complex(rhs.real() + lhs, rhs.im());
}

Complex operator-(float lhs, Complex rhs)
{
	return Complex(lhs - rhs.real(), rhs.im());
}

Complex operator*(float lhs, Complex rhs)
{
	return Complex(rhs.real() * lhs, rhs.im() * lhs);
}

Complex operator/(float lhs, Complex rhs)
{
	return lhs * rhs.reciprocal();
}

/**
 * @brief Get the real part of the complex number
 *
 * @return Real part
 */
float Complex::real() const
{
	return _real;
}

/**
 * @brief Get the imaginary part of the complex number
 *
 * @return Imaginary part
 */
float Complex::im() const
{
	return _im;
}

/**
 * @brief Get the module of the complex number
 *
 * @return Module
 */
float Complex::mod() const
{
	return static_cast<float>(std::pow((_real * _real) + (_im * _im), 0.5));
}

/**
 * @brief Get the conjugate of the complex number
 *
 * @return Conjugate
 */
Complex Complex::conjugate() const
{
	return Complex(_real, -_im);
}

/**
 * @brief Get the reciprocal of the complex number
 *
 * @return Reciprocal
 */
Complex Complex::reciprocal() const
{
	float module = mod();
	return conjugate() / (module * module);
}

/**
 * @brief Fast multiply-add three complex numbers
 *
 * @param x
 * @param y
 * @param z
 * @return x * y + z
 */
Complex fma(Complex x, Complex y, Complex z)
{
	return x * y + z;
}

/**
 * @brief Round complex number (its real part and imaginary part)
 *
 * @param c Number to round
 * @return The rounded number
 */
Complex round(Complex c)
{
	return Complex(std::round(c.real()), std::round(c.im()));
}
