#pragma once

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

	Complex &operator=(const Complex &rhs);

	Complex operator+(const Complex &rhs) const;
	Complex operator-(const Complex &rhs) const;
	Complex operator*(const Complex &rhs) const;
	Complex operator/(const Complex &rhs) const;

	Complex operator+=(const Complex &rhs);
	Complex operator-=(const Complex &rhs);
	Complex operator*=(const Complex &rhs);
	Complex operator/=(const Complex &rhs);

	Complex &operator=(float rhs);

	Complex operator+(float rhs) const;
	Complex operator-(float rhs) const;
	Complex operator*(float rhs) const;
	Complex operator/(float rhs) const;

	Complex operator+=(float rhs);
	Complex operator-=(float rhs);
	Complex operator*=(float rhs);
	Complex operator/=(float rhs);

	float real() const;
	float im() const;
	float module() const;
};
