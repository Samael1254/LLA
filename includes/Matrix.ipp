#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"
#include <array>
#include <initializer_list>
#include <ostream>
#include <sstream>

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T>::Matrix()
{
	for (unsigned int i = 0; i < M; ++i)
		_values[i].fill(0);
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T>::Matrix(std::initializer_list<std::initializer_list<T>> init)
{
	if (init.size() != M)
		throw std::runtime_error("Invalid Matrix rows number");

	unsigned int i = 0;
	for (auto it = init.begin(); it != init.end(); ++it)
	{
		if (it->size() != N)
			throw std::runtime_error("Invalid Matrix column number");
		unsigned int j = 0;
		for (auto jt = it->begin(); jt != it->end(); ++jt)
			this->_values[i][j++] = *jt;
		i++;
	}
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T>::Matrix(const Matrix<M, N, T> &other)
{
	for (unsigned int i = 0; i < M; ++i)
		for (unsigned int j = 0; j < N; ++j)
			this->_values[i][j] = other._values[i][j];
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T>::~Matrix()
{
}

// Overloads

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T> &Matrix<M, N, T>::operator=(const Matrix<M, N, T> &other)
{
	if (this != &other)
		for (unsigned int i = 0; i < M; ++i)
			this->_values[i] = other._values[i];
	return *this;
}

template <unsigned int M, unsigned int N, class T>
std::ostream &operator<<(std::ostream &os, const Matrix<M, N, T> &mat)
{
	std::array<unsigned short, N> widths = {0};

	// Compute the width of every column
	for (unsigned int i = 0; i < M; ++i)
	{
		for (unsigned int j = 0; j < N; ++j)
		{
			std::stringstream ss;
			ss << mat._values[i][j];
			widths[j] = std::max(static_cast<unsigned short>(ss.str().length()), widths[j]);
		}
	}

	os << "\n";
	for (unsigned int i = 0; i < M; ++i)
	{
		os << "|";
		for (unsigned int j = 0; j < N; ++j)
		{
			std::stringstream ss;
			ss << mat._values[i][j];
			unsigned short width = ss.str().length();

			os << mat._values[i][j];
			for (unsigned int k = 0; k < widths[j] - width + (j < N - 1); ++k)
				os << " ";
		}
		os << "|\n";
	}
	return os;
}

template <unsigned int M, unsigned int N, class T>
T *Matrix<M, N, T>::operator[](unsigned int i)
{
	return this->_values[i].data();
}

template <unsigned int M, unsigned int N, class T>
const T *Matrix<M, N, T>::operator[](unsigned int i) const
{
	return this->_values[i].data();
}

template <unsigned int M, unsigned int N, class T>
std::pair<unsigned int, unsigned int> Matrix<M, N, T>::size() const
{
	return {M, N};
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T> Matrix<M, N, T>::operator+(const Matrix<M, N, T> &rhs)
{
	Matrix<M, N, T> res;
	for (unsigned int i = 0; i < M; ++i)
		for (unsigned int j = 0; j < N; ++j)
			res[i][j] = (*this)[i][j] + rhs[i][j];
	return res;
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T> Matrix<M, N, T>::operator-(const Matrix<M, N, T> &rhs)
{
	Matrix<M, N, T> res;
	for (unsigned int i = 0; i < M; ++i)
		for (unsigned int j = 0; j < N; ++j)
			res[i][j] = (*this)[i][j] - rhs[i][j];
	return res;
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T> Matrix<M, N, T>::operator*(T lambda)
{
	Matrix<M, N, T> res;
	for (unsigned int i = 0; i < M; ++i)
		for (unsigned int j = 0; j < N; ++j)
			res[i][j] = (*this)[i][j] * lambda;
	return res;
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T> Matrix<M, N, T>::operator+=(const Matrix<M, N, T> &rhs)
{
	this->add(rhs);
	return (*this);
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T> Matrix<M, N, T>::operator-=(const Matrix<M, N, T> &rhs)
{
	this->sub(rhs);
	return (*this);
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T> Matrix<M, N, T>::operator*=(T lambda)
{
	this->scale(lambda);
	return (*this);
}

template <unsigned int M, unsigned int N, class T, class U>
Matrix<M, N, T> operator*(U lambda, const Matrix<M, N, T> &rhs)
{
	Matrix<M, N, T> res;
	for (unsigned int i = 0; i < M; ++i)
		for (unsigned int j = 0; j < N; ++j)
			res[i][j] = rhs[i][j] * static_cast<T>(lambda);
	return res;
}

// Operations
template <unsigned int M, unsigned int N, class T>
void Matrix<M, N, T>::add(const Matrix<M, N, T> &rhs)
{
	for (unsigned int i = 0; i < M; ++i)
		for (unsigned int j = 0; j < N; ++j)
			(*this)[i][j] += rhs[i][j];
}

template <unsigned int M, unsigned int N, class T>
void Matrix<M, N, T>::sub(const Matrix<M, N, T> &rhs)
{
	for (unsigned int i = 0; i < M; ++i)
		for (unsigned int j = 0; j < N; ++j)
			(*this)[i][j] -= rhs[i][j];
}

template <unsigned int M, unsigned int N, class T>
void Matrix<M, N, T>::scale(T lambda)
{
	for (unsigned int i = 0; i < M; ++i)
		for (unsigned int j = 0; j < N; ++j)
			(*this)[i][j] *= lambda;
}

// Information

template <unsigned int M, unsigned int N, class T>
bool Matrix<M, N, T>::isSquare() const
{
	return M == N;
}

template <unsigned int M, unsigned int N, class T>
Vector<N, T> Matrix<M, N, T>::rowVector(unsigned int idx) const
{
	Vector<N, T> row;

	for (unsigned int j = 0; j < N; ++j)
		row[j] = (*this)[idx][j];
	return row;
}

// Extract Vectors

template <unsigned int M, unsigned int N, class T>
Vector<M, T> Matrix<M, N, T>::columnVector(unsigned int idx) const
{
	Vector<M, T> column;

	for (unsigned int i = 0; i < M; ++i)
		column[i] = (*this)[i][idx];
	return column;
}
