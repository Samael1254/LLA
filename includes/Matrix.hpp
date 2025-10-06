#pragma once

#include "Vector.hpp"
#include "liblinal.hpp"
#include <array>
#include <ostream>
#include <utility>

/**
 * @class Matrix
 * @brief Matrix class for linear algebra and rendering purposes
 *
 * @tparam M Number of rows
 * @tparam N Number of columns
 * @tparam T Type of the Matrix elements
 */
template <unsigned int M, unsigned int N, class T = float>
class Matrix
{
  private:
	std::array<std::array<T, N>, M> _values;

	T _determinantND() const;
	T _determinant2D() const;
	T _determinant3D() const;

	Matrix<M, N, T> _inverse2D() const;
	Matrix<M, N, T> _inverse3D() const;
	Matrix<M, N, T> _inverseND() const;

  public:
	Matrix();
	Matrix(const Matrix<M, N, T> &other);
	Matrix(std::initializer_list<std::initializer_list<T>> init);
	~Matrix() = default;

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

	void add(const Matrix<M, N, T> &rhs);
	void sub(const Matrix<M, N, T> &rhs);
	void scale(T lambda);

	Vector<M, T> mul_vec(const Vector<N, T> &rhs) const;
	template <unsigned int O>
	Matrix<M, O, T> mul_mat(const Matrix<N, O, T> &rhs) const;

	void swapRows(unsigned int r1, unsigned int r2);
	void scaleRow(unsigned int r1, T lambda);
	void fmaRows(unsigned int r1, unsigned int r2, T lambda);

	Matrix<N, M, T> transpose() const;
	Matrix<M, N, T> row_echelon() const;
	Matrix<M, N, T> inverse() const;

	std::pair<unsigned int, unsigned int> size() const;
	bool                                  isSquare() const;
	T                                     trace() const;
	T                                     determinant() const;
	unsigned int                          rank() const;

	Vector<N, T> rowVector(unsigned int idx) const;
	Vector<M, T> columnVector(unsigned int idx) const;

	template <unsigned int O, unsigned int P>
	Matrix<O, P, T> resize(bool isHomogenous) const;
	Matrix<M, N, T> rounded(float precision) const;

	static Matrix<M, M, T> createIdentityMatrix();
	static Matrix<M, M, T> createRotationMatrix(float angle, EAxis axis);
	static Matrix<M, M, T> createTranslationMatrix(const Vector<M - 1> &translator);
	static Matrix<M, M, T> createScalingMatrix(const Vector<M> &scale);

	template <unsigned int O>
	Matrix<M, N + O, T> augmentMatrix(const Matrix<M, O, T> &rightMat);

	void arrayRMO(T array[M * N]) const;
	void arrayCMO(T array[M * N]) const;
};

#include "Matrix.ipp"
