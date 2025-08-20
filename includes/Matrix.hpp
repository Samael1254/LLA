#pragma once

#include "Vector.hpp"
#include <array>
#include <ostream>
#include <utility>

template <unsigned int M, unsigned int N, class T = float>
class Matrix
{
  private:
	std::array<std::array<T, N>, M> _values{0};

  public:
	Matrix();
	Matrix(const Matrix<M, N, T> &other);
	Matrix(std::initializer_list<std::initializer_list<T>> init);
	~Matrix();

	// Overloads

	Matrix<M, N, T> &operator=(const Matrix<M, N, T> &other);
	template <unsigned int I, unsigned int J, class U>
	friend std::ostream &operator<<(std::ostream &os, const Matrix<I, J, U> &mat);
	T                   *operator[](unsigned int i);
	const T             *operator[](unsigned int i) const;

	Matrix<M, N, T> operator+(const Matrix<M, N, T> &rhs);
	Matrix<M, N, T> operator-(const Matrix<M, N, T> &rhs);
	Matrix<M, N, T> operator*(T lambda);
	Vector<M, T>    operator*(const Vector<N, T> &rhs);
	template <unsigned int O>
	Matrix<M, O, T> operator*(const Matrix<N, O, T> &rhs);
	Matrix<M, N, T> operator+=(const Matrix<M, N, T> &rhs);
	Matrix<M, N, T> operator-=(const Matrix<M, N, T> &rhs);
	Matrix<M, N, T> operator*=(T lambda);

	// Operations
	void add(const Matrix<M, N, T> &rhs);
	void sub(const Matrix<M, N, T> &rhs);
	void scale(T lambda);

	Vector<M, T> mul_vec(const Vector<N, T> &rhs) const;
	template <unsigned int O>
	Matrix<M, O, T> mul_mat(const Matrix<N, O, T> &rhs) const;
	Matrix<N, M, T> transpose() const;

	// Information

	std::pair<unsigned int, unsigned int> size() const;
	bool                                  isSquare() const;
	T                                     trace() const;

	// Extract Vectors

	Vector<N, T> rowVector(unsigned int idx) const;
	Vector<M, T> columnVector(unsigned int idx) const;
};

#include "Matrix.ipp"
