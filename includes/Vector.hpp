#pragma once

#include "Complex.hpp"
#include <array>
#include <ostream>

template <typename T, typename>
float mod(T nb);

float mod(const Complex &c);

template <unsigned int M, unsigned int N, class T>
class Matrix;

/**
 * @class Vector
 * @brief Vector class for linear algebra and rendering purposes
 *
 * @tparam N Size
 * @tparam T Type of the Vector elements
 */
template <unsigned int N, class T = float>
class Vector
{
  private:
	std::array<T, N> _values{0};

  public:
	Vector() = default;
	Vector(const Vector<N, T> &other);
	Vector(const std::array<T, N> &array);
	Vector(std::initializer_list<T> init);
	~Vector() = default;

	T &x() requires(N >= 1 && N <= 4);
	T &y() requires(N >= 2 && N <= 4);
	T &z() requires(N >= 3 && N <= 4);
	T &w() requires(N == 4);
	T &r() requires(N >= 1 && N <= 4);
	T &g() requires(N >= 2 && N <= 4);
	T &b() requires(N >= 3 && N <= 4);
	T &a() requires(N == 4);
	T &u() requires(N == 2);
	T &v() requires(N == 2);

	const T &x() const requires(N >= 1 && N <= 4);
	const T &y() const requires(N >= 2 && N <= 4);
	const T &z() const requires(N >= 3 && N <= 4);
	const T &w() const requires(N == 4);
	const T &r() const requires(N >= 1 && N <= 4);
	const T &g() const requires(N >= 2 && N <= 4);
	const T &b() const requires(N >= 3 && N <= 4);
	const T &a() const requires(N == 4);
	const T &u() const requires(N == 2);
	const T &v() const requires(N == 2);

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
	Vector<N, T> operator-() const;

	void add(const Vector<N, T> &rhs);
	void sub(const Vector<N, T> &rhs);
	void scale(T lambda);

	T dot(const Vector<N, T> &rhs) const;

	void         normalize();
	Vector<N, T> normalized() const;
	unsigned int size() const;
	float        norm_1() const;
	float        norm() const;
	float        norm_inf() const;

	Matrix<1, N, T> rowMatrix() const;
	Matrix<N, 1, T> columnMatrix() const;
	void            array(T array[N]) const;
	template <unsigned int M>
	Vector<M, T> resize(bool isHomogenous) const;
};

#include "Vector.ipp"
