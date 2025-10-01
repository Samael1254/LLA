#pragma once

#include <ostream>
class Complex
{
  private:
	float _real;
	float _im;

  public:
	Complex();
	Complex(float real);
	Complex(float real, float im);
	Complex(const Complex &other) = default;
	~Complex() = default;

	Complex              operator-() const;
	friend std::ostream &operator<<(std::ostream &os, const Complex &c);

	Complex &operator=(const Complex &rhs);

	bool operator==(const Complex &rhs) const;

	Complex operator+(const Complex &rhs) const;
	Complex operator-(const Complex &rhs) const;
	Complex operator*(const Complex &rhs) const;
	Complex operator/(const Complex &rhs) const;

	Complex operator+=(const Complex &rhs);
	Complex operator-=(const Complex &rhs);
	Complex operator*=(const Complex &rhs);
	Complex operator/=(const Complex &rhs);

	Complex &operator=(float rhs);

	bool operator==(float rhs) const;

	Complex operator+(float rhs) const;
	Complex operator-(float rhs) const;
	Complex operator*(float rhs) const;
	Complex operator/(float rhs) const;

	Complex operator+=(float rhs);
	Complex operator-=(float rhs);
	Complex operator*=(float rhs);
	Complex operator/=(float rhs);

	friend Complex operator+(float lhs, Complex rhs);
	friend Complex operator-(float lhs, Complex rhs);
	friend Complex operator*(float lhs, Complex rhs);
	friend Complex operator/(float lhs, Complex rhs);

	float   real() const;
	float   im() const;
	float   mod() const;
	Complex conjugate() const;
	Complex reciprocal() const;

	friend Complex fma(Complex x, Complex y, Complex z);
};
