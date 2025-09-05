#pragma once

#include <array>
#include <ostream>

template <unsigned int M, unsigned int N, class T>
class Matrix;

template <unsigned int N, class T = float>
class Vector
{
  private:
	std::array<T, N> _values{0};

  public:
	Vector() = default;
	Vector(const Vector<N, T> &other);
	Vector(std::initializer_list<T> init);
	~Vector() = default;

	// Getters
	T x() const;
	T y() const;
	T z() const;
	T w() const;
	T r() const;
	T g() const;
	T b() const;
	T a() const;
	T u() const;
	T v() const;

	// Overloads
	Vector &operator=(const Vector<N, T> &other);
	template <unsigned int M, class U>
	friend std::ostream &operator<<(std::ostream &os, const Vector<M, U> &vec);
	T                   &operator[](unsigned int i);
	T                    operator[](unsigned int i) const;

	Vector<N, T> operator+(const Vector<N, T> &rhs) const;
	Vector<N, T> operator-(const Vector<N, T> &rhs) const;
	Vector<N, T> operator*(T lambda) const;
	Vector<N, T> operator+=(const Vector<N, T> &rhs);
	Vector<N, T> operator-=(const Vector<N, T> &rhs);
	Vector<N, T> operator*=(T lambda);

	// Operations

	void add(const Vector<N, T> &rhs);
	void sub(const Vector<N, T> &rhs);
	void scale(T lambda);

	T dot(const Vector<N, T> &rhs) const;

	void         normalize();
	Vector<N, T> normalized() const;

	// Information

	unsigned int size() const;

	float norm_1() const;
	float norm() const;
	float norm_inf() const;

	// Conversions

	Matrix<1, N, T> rowMatrix() const;
	Matrix<N, 1, T> columnMatrix() const;
	void            array(T array[N]) const;
};

#include "Vector.ipp"
