#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"
#include <array>
#include <cmath>
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>

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
			for (unsigned short k = 0; k < widths[j] - width + (j < N - 1); ++k)
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

template <unsigned int M, unsigned int N, class T>
Vector<M, T> Matrix<M, N, T>::operator*(const Vector<N, T> &rhs)
{
	return mul_vec(rhs);
}

template <unsigned int M, unsigned int N, class T>
template <unsigned int O>
Matrix<M, O, T> Matrix<M, N, T>::operator*(const Matrix<N, O, T> &rhs)
{
	return mul_mat(rhs);
}

template <unsigned int M, unsigned int N, class T>
Vector<N, T> operator*(const Vector<M, T> &lhs, const Matrix<M, N, T> &rhs)
{
	Vector<N, T> res;

	for (unsigned int i = 0; i < N; ++i)
		for (unsigned int k = 0; k < M; ++k)
			res[i] = std::fma(rhs[k][i], lhs[k], res[i]);
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

template <unsigned int M, unsigned int N, class T>
Vector<M, T> Matrix<M, N, T>::mul_vec(const Vector<N, T> &rhs) const
{
	Vector<M, T> res;

	for (unsigned int i = 0; i < M; ++i)
		for (unsigned int k = 0; k < N; ++k)
			res[i] = std::fma((*this)[i][k], rhs[k], res[i]);
	return res;
}

template <unsigned int M, unsigned int N, class T>
template <unsigned int O>
Matrix<M, O, T> Matrix<M, N, T>::mul_mat(const Matrix<N, O, T> &rhs) const
{
	Matrix<M, O, T> res;

	for (unsigned int i = 0; i < M; ++i)
		for (unsigned int j = 0; j < O; ++j)
			for (unsigned int k = 0; k < N; ++k)
				res[i][j] = std::fma((*this)[i][k], rhs[k][j], res[i][j]);
	return res;
}

template <unsigned int M, unsigned int N, class T>
void Matrix<M, N, T>::swapRows(unsigned int r1, unsigned int r2)
{
	std::swap(this->_values[r1], this->_values[r2]);
}

template <unsigned int M, unsigned int N, class T>
void Matrix<M, N, T>::scaleRow(unsigned int r1, T lambda)
{
	std::array<T, N> &row = this->_values[r1];
	for (unsigned int j = 0; j < N; ++j)
		row[j] *= lambda;
}

template <unsigned int M, unsigned int N, class T>
void Matrix<M, N, T>::fmaRows(unsigned int r1, unsigned int r2, T lambda)
{
	std::array<T, N> &row1 = this->_values[r1];
	std::array<T, N> &row2 = this->_values[r2];
	for (unsigned int j = 0; j < N; ++j)
		row1[j] = std::fma(lambda, row2[j], row1[j]);
}

// Transformations

template <unsigned int M, unsigned int N, class T>
Matrix<N, M, T> Matrix<M, N, T>::transpose() const
{
	Matrix<N, M, T> res;

	for (unsigned int i = 0; i < M; ++i)
		for (unsigned int j = 0; j < N; ++j)
			res[i][j] = (*this)[j][i];
	return res;
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T> Matrix<M, N, T>::row_echelon() const
{
	Matrix<M, N, T> res(*this);

	unsigned int r = 0;
	for (unsigned int j = 0; j < N; ++j)
	{
		T            pivot = 0;
		unsigned int k;

		for (unsigned int i = r; i < M; ++i)
		{
			T value = module(res[i][j]);
			if (value > pivot)
			{
				pivot = value;
				k = i;
			}
		}
		if (pivot == 0)
			continue;
		r += 1;
		res.scaleRow(k, 1 / pivot);
		if (k != r - 1)
			res.swapRows(k, r - 1);
		for (unsigned int i = 0; i < M; ++i)
			if (i != r - 1)
				res.fmaRows(i, r - 1, -res[i][j]);
	}

	return res;
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T> Matrix<M, N, T>::inverse() const
{
	if (!isSquare())
		throw std::runtime_error("A non square matrix cannot be inverted");
	if (determinant() == 0)
		throw std::runtime_error("The matrix is not invertible");

	switch (M)
	{
	case 2:
		return _inverse2D();
	case 3:
		return _inverse3D();
	default:
		return _inverseND();
	}
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T> Matrix<M, N, T>::_inverse2D() const
{
	Matrix<M, N, T> m = (*this);
	Matrix<M, N, T> inv = {{m[1][1], -m[0][1]}, {-m[1][0], m[0][0]}};
	inv *= 1 / (m[0][0] * m[1][1] - m[1][0] * m[0][1]);
	return inv;
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T> Matrix<M, N, T>::_inverse3D() const
{
	Matrix<M, N, T> m = (*this);
	T               a = m[1][1] * m[2][2] - m[2][1] * m[1][2];
	T               b = -(m[1][0] * m[2][2] - m[1][2] * m[2][0]);
	T               c = m[1][0] * m[2][1] - m[1][1] * m[2][0];
	T               d = -(m[0][1] * m[2][2] - m[0][2] * m[2][1]);
	T               e = m[0][0] * m[2][2] - m[0][2] * m[2][0];
	T               f = -(m[0][0] * m[2][1] - m[0][1] * m[2][0]);
	T               g = m[0][1] * m[1][2] - m[0][2] * m[1][1];
	T               h = -(m[0][0] * m[1][2] - m[0][2] * m[1][0]);
	T               i = m[0][0] * m[1][1] - m[0][1] * m[1][0];

	Matrix<M, N, T> inv{{a, d, g}, {b, e, h}, {c, f, i}};
	inv *= 1 / (m[0][0] * a + m[0][1] * b + m[0][2] * c); // divide by det(m)
	return inv;
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, N, T> Matrix<M, N, T>::_inverseND() const
{
	Matrix<M, N, T>     m = (*this);
	Matrix<M, 2 * N, T> aug = m.augmentMatrix(Matrix<M, M, T>::createIdentityMatrix()).row_echelon();
	Matrix<M, M, T>     res;
	for (unsigned int i = 0; i < M; ++i)
		for (unsigned int j = 0; j < M; ++j)
			res[i][j] = aug[i][j + N];
	return res;
}

// Information

template <unsigned int M, unsigned int N, class T>
std::pair<unsigned int, unsigned int> Matrix<M, N, T>::size() const
{
	return {M, N};
}

template <unsigned int M, unsigned int N, class T>
bool Matrix<M, N, T>::isSquare() const
{
	return M == N;
}

template <unsigned int M, unsigned int N, class T>
T Matrix<M, N, T>::trace() const
{
	if (!this->isSquare())
		throw std::runtime_error("The trace of a non square matrix does not exist");

	T res = 0;

	for (unsigned int i = 0; i < M; ++i)
		res += (*this)[i][i];
	return res;
}

template <unsigned int M, unsigned int N, class T>
T Matrix<M, N, T>::determinant() const
{
	if (!this->isSquare())
		throw std::runtime_error("The determinant of a non square matrix does not exist");

	switch (M)
	{
	case 2:
		return _determinant2D();
	case 3:
		return _determinant3D();
	default:
		return _determinantND();
	}
}

template <unsigned int M, unsigned int N, class T>
T Matrix<M, N, T>::_determinant2D() const
{
	Matrix<M, N, T> mat = (*this);
	return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
}

template <unsigned int M, unsigned int N, class T>
T Matrix<M, N, T>::_determinant3D() const
{
	Matrix<M, N, T> mat = (*this);
	return mat[0][0] * mat[1][1] * mat[2][2] + mat[0][1] * mat[1][2] * mat[2][0] + mat[0][2] * mat[1][0] * mat[2][1] -
	       mat[2][0] * mat[1][1] * mat[0][2] - mat[0][0] * mat[2][1] * mat[1][2] - mat[1][0] * mat[0][1] * mat[2][2];
}

template <unsigned int M, unsigned int N, class T>
T Matrix<M, N, T>::_determinantND() const
{
	Matrix<M, N, T> mat(*this);
	T               det = 1;

	unsigned int r = 0;
	for (unsigned int j = 0; j < N; ++j)
	{
		T            pivot = 0;
		unsigned int k;

		for (unsigned int i = r; i < M; ++i)
		{
			T value = module(mat[i][j]);
			if (value > pivot)
			{
				pivot = value;
				k = i;
			}
		}
		det *= pivot;
		if (pivot == 0)
			continue;
		r += 1;
		mat.scaleRow(k, 1 / pivot);
		if (k != r - 1)
		{
			mat.swapRows(k, r - 1);
			det *= -1;
		}
		for (unsigned int i = 0; i < M; ++i)
			if (i != r - 1)
				mat.fmaRows(i, r - 1, -mat[i][j]);
	}

	return det;
}

template <unsigned int M, unsigned int N, class T>
unsigned int Matrix<M, N, T>::rank() const
{
	Matrix<M, N, T> re = row_echelon();

	unsigned int rank = M;
	for (unsigned int i = 0; i < M; ++i)
	{
		bool nullLine = true;
		for (unsigned int j = 0; j < N; ++j)
			if (re[i][j] != 0)
				nullLine = false;
		if (nullLine)
			rank--;
	}
	return rank;
}

// Extract Vectors

template <unsigned int M, unsigned int N, class T>
Vector<N, T> Matrix<M, N, T>::rowVector(unsigned int idx) const
{
	Vector<N, T> row;

	for (unsigned int j = 0; j < N; ++j)
		row[j] = (*this)[idx][j];
	return row;
}

template <unsigned int M, unsigned int N, class T>
Vector<M, T> Matrix<M, N, T>::columnVector(unsigned int idx) const
{
	Vector<M, T> column;

	for (unsigned int i = 0; i < M; ++i)
		column[i] = (*this)[i][idx];
	return column;
}

// Generators

template <unsigned int M, unsigned int N, class T>
Matrix<M, M, T> Matrix<M, N, T>::createIdentityMatrix()
{
	if (M != N)
		throw std::runtime_error("Identity matrix has to be square");

	Matrix<M, M, T> identity;
	for (unsigned int i = 0; i < M; ++i)
		identity[i][i] = 1;
	return identity;
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, M, T> Matrix<M, N, T>::createRotationMatrix(float angle, EAxis axis)
{
	if (M < 3 || M > 4)
		throw std::runtime_error("cannot create rotation matrix of given size");

	Matrix<M, M, T> m = createIdentityMatrix();
	float           cos = std::cos(angle);
	float           sin = std::sin(angle);

	m[(axis + 1) % 3][(axis + 1) % 3] = cos;
	m[(axis + 2) % 3][(axis + 2) % 3] = cos;
	m[(axis + 1) % 3][(axis + 2) % 3] = -sin;
	m[(axis + 2) % 3][(axis + 1) % 3] = sin;

	return m;
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, M, T> Matrix<M, N, T>::createTranslationMatrix(const Vector<M - 1> &translator)
{
	Matrix<4, 4> mat = createIdentityMatrix();

	for (int i = 0; i < M - 1; ++i)
		mat[i][M - 1] = translator[i];

	return mat;
}

template <unsigned int M, unsigned int N, class T>
Matrix<M, M, T> Matrix<M, N, T>::createScalingMatrix(const Vector<M> &scale)
{
	Matrix<4, 4> mat;

	for (int i = 0; i < M; ++i)
		mat[i][i] = scale[i];

	return mat;
}

template <unsigned int M, unsigned int N, class T>
template <unsigned int O>
Matrix<M, N + O, T> Matrix<M, N, T>::augmentMatrix(const Matrix<M, O, T> &rightMat)
{
	Matrix<M, N + O, T> aug;
	for (unsigned int i = 0; i < M; ++i)
	{
		for (unsigned int j = 0; j < N + O; ++j)
		{
			if (j < N)
				aug[i][j] = (*this)[i][j];
			else
				aug[i][j] = rightMat[i][j - N];
		}
	}
	return aug;
}

template <unsigned int M, unsigned int N, class T>
void Matrix<M, N, T>::arrayRMO(T array[M * N]) const
{
	for (unsigned int i = 0; i < M; ++i)
		for (unsigned int j = 0; j < N; ++j)
			array[(i * M) + j] = (*this)[i][j];
}

template <unsigned int M, unsigned int N, class T>
void Matrix<M, N, T>::arrayCMO(T array[M * N]) const
{
	for (unsigned int j = 0; j < N; ++j)
		for (unsigned int i = 0; i < N; ++i)
			array[(j * N) + i] = (*this)[i][j];
}
