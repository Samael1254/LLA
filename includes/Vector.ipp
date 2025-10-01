#pragma once

#include "Vector.hpp"
#include "liblinal.hpp"
#include <cmath>
#include <initializer_list>
#include <iostream>
#include <stdexcept>

// CONSTRUCTORS AND DESTRUCTOR

/**
 * @brief Construct a Vector with an initializer list
 *
 * @tparam N Size of Vector
 * @tparam T Type of Vector
 * @param init List of vector elements
 * @return The newly initialized vector
 */
template <unsigned int N, class T>
Vector<N, T>::Vector(std::initializer_list<T> init)
{
	if (init.size() != N)
		throw std::runtime_error("Invalid Vector elements number");

	unsigned int i = 0;
	for (auto it = init.begin(); it != init.end(); ++it)
		this->_values[i++] = *it;
}

/**
 * @brief Vector copy constructor
 *
 * @tparam N Size of Vector
 * @tparam T Type of Vector
 * @param other Vector to copy
 * @return The new duplicate Vector
 */
template <unsigned int N, class T>
Vector<N, T>::Vector(const Vector<N, T> &other) : _values(other._values)
{
}

/**
 * @brief Construct a Vector from an array
 *
 * @tparam N Size of Vector
 * @tparam T Type of Vector
 * @param array Array to convert
 * @return The new Vector
 */
template <unsigned int N, class T>
Vector<N, T>::Vector(const std::array<T, N> &array) : _values(array)
{
}

// GETTERS

/**
 * @brief Get Vector first coordinate
 *
 * @return Vector first coordinate
 */
template <unsigned int N, class T>
T &Vector<N, T>::x() requires(N >= 1 && N <= 4)
{
	return _values[0];
}

/**
 * @brief Get Vector second coordinate
 *
 * @return Vector second coordinate
 */
template <unsigned int N, class T>
T &Vector<N, T>::y() requires(N >= 2 && N <= 4)
{
	return _values[1];
}

/**
 * @brief Get Vector third coordinate
 *
 * @return Vector third coordinate
 */
template <unsigned int N, class T>
T &Vector<N, T>::z() requires(N >= 3 && N <= 4)
{
	return _values[2];
}

/**
 * @brief Get Vector fourth coordinate
 *
 * @return Vector fourth coordinate
 */
template <unsigned int N, class T>
T &Vector<N, T>::w() requires(N == 4)
{
	return _values[3];
}

/**
 * @brief Get Vector first coordinate (interpreted as red channel)
 *
 * @return Vector first coordinate
 */
template <unsigned int N, class T>
T &Vector<N, T>::r() requires(N >= 1 && N <= 4)
{
	return _values[0];
}

/**
 * @brief Get Vector second coordinate (interpreted as blue channel)
 *
 * @return Vector second coordinate
 */
template <unsigned int N, class T>
T &Vector<N, T>::g() requires(N >= 2 && N <= 4)
{
	return _values[1];
}

/**
 * @brief Get Vector third coordinate (interpreted as green channel)
 *
 * @return Vector third coordinate
 */
template <unsigned int N, class T>
T &Vector<N, T>::b() requires(N >= 3 && N <= 4)
{
	return _values[2];
}

/**
 * @brief Get Vector fourth coordinate (interpreted as alpha channel)
 *
 * @return Vector fourth coordinate
 */
template <unsigned int N, class T>
T &Vector<N, T>::a() requires(N == 4)
{
	return _values[3];
}

/**
 * @brief Get 2D Vector first coordinate (interpreted as UV coordinate)
 *
 * @return Vector first coordinate
 */
template <unsigned int N, class T>
T &Vector<N, T>::u() requires(N == 2)
{
	return _values[0];
}

/**
 * @brief Get 2D Vector second coordinate (interpreted as UV coordinate)
 *
 * @return Vector second coordinate
 */
template <unsigned int N, class T>
T &Vector<N, T>::v() requires(N == 2)
{
	return _values[1];
}

/**
 * @brief Get Vector first coordinate
 *
 * @return Vector first coordinate
 */
template <unsigned int N, class T>
const T &Vector<N, T>::x() const requires(N >= 1 && N <= 4)
{
	return _values[0];
}

/**
 * @brief Get Vector second coordinate
 *
 * @return Vector second coordinate
 */
template <unsigned int N, class T>
const T &Vector<N, T>::y() const requires(N >= 2 && N <= 4)
{
	return _values[1];
}

/**
 * @brief Get Vector third coordinate
 *
 * @return Vector third coordinate
 */
template <unsigned int N, class T>
const T &Vector<N, T>::z() const requires(N >= 3 && N <= 4)
{
	return _values[2];
}

/**
 * @brief Get Vector fourth coordinate
 *
 * @return Vector fourth coordinate
 */
template <unsigned int N, class T>
const T &Vector<N, T>::w() const requires(N == 4)
{
	return _values[3];
}

/**
 * @brief Get Vector first coordinate (interpreted as red channel)
 *
 * @return Vector first coordinate
 */
template <unsigned int N, class T>
const T &Vector<N, T>::r() const requires(N >= 1 && N <= 4)
{
	return _values[0];
}

/**
 * @brief Get Vector second coordinate (interpreted as green channel)
 *
 * @return Vector second coordinate
 */
template <unsigned int N, class T>
const T &Vector<N, T>::g() const requires(N >= 2 && N <= 4)
{
	return _values[1];
}

/**
 * @brief Get Vector third coordinate (interpreted as blue channel)
 *
 * @return Vector third coordinate
 */
template <unsigned int N, class T>
const T &Vector<N, T>::b() const requires(N >= 3 && N <= 4)
{
	return _values[2];
}

/**
 * @brief Get Vector fourth coordinate (interpreted as alpha channel)
 *
 * @return Vector fourth coordinate
 */
template <unsigned int N, class T>
const T &Vector<N, T>::a() const requires(N == 4)
{
	return _values[3];
}

/**
 * @brief Get 2D Vector first coordinate (interpreted as UV coordinates)
 *
 * @return Vector first coordinate
 */
template <unsigned int N, class T>
const T &Vector<N, T>::u() const requires(N == 2)
{
	return _values[0];
}

/**
 * @brief Get 2D Vector first coordinate (interpreted as UV coordinates)
 *
 * @return Vector first coordinate
 */
template <unsigned int N, class T>
const T &Vector<N, T>::v() const requires(N == 2)
{
	return _values[1];
}

// OPERATOR OVERLOADS

template <unsigned int N, class T>
Vector<N, T> &Vector<N, T>::operator=(const Vector<N, T> &other)
{
	if (this != &other)
		this->_values = other._values;
	return *this;
}

template <unsigned int N, class T>
std::ostream &operator<<(std::ostream &os, const Vector<N, T> &vec)
{
	os << "[";
	for (unsigned int i = 0; i < N; i++)
	{
		os << vec._values[i];
		if (i < N - 1)
			os << " ";
	}
	os << "]";

	return os;
}

template <unsigned int N, class T>
T &Vector<N, T>::operator[](unsigned int i)
{
	return this->_values[i];
}

template <unsigned int N, class T>
T Vector<N, T>::operator[](unsigned int i) const
{
	return this->_values[i];
}

template <unsigned int N, class T>
Vector<N, T> Vector<N, T>::operator+(const Vector<N, T> &rhs) const
{
	Vector<N, T> res;
	for (unsigned int i = 0; i < N; ++i)
		res[i] = (*this)[i] + rhs[i];
	return res;
}

template <unsigned int N, class T>
Vector<N, T> Vector<N, T>::operator-(const Vector<N, T> &rhs) const
{
	Vector<N, T> res;
	for (unsigned int i = 0; i < N; ++i)
		res[i] = (*this)[i] - rhs[i];
	return res;
}

template <unsigned int N, class T>
Vector<N, T> Vector<N, T>::operator*(T lambda) const
{
	Vector<N, T> res;

	for (unsigned int i = 0; i < N; ++i)
		res[i] = (*this)[i] * lambda;
	return res;
}

template <unsigned int N, class T, class U>
Vector<N, T> operator*(U lambda, const Vector<N, T> &rhs)
{
	Vector<N, T> res;

	for (unsigned int i = 0; i < N; ++i)
		res[i] = rhs[i] * static_cast<T>(lambda);
	return res;
}

template <unsigned int N, class T>
Vector<N, T> Vector<N, T>::operator+=(const Vector<N, T> &rhs)
{
	this->add(rhs);
	return *this;
}

template <unsigned int N, class T>
Vector<N, T> Vector<N, T>::operator-=(const Vector<N, T> &rhs)
{
	this->sub(rhs);
	return *this;
}

template <unsigned int N, class T>
Vector<N, T> Vector<N, T>::operator*=(T lambda)
{
	this->scale(lambda);
	return *this;
}

// OPERATIONS

/**
 * @brief Add another Vector to Vector in place
 *
 * @param rhs Vector to add to this one
 */
template <unsigned int N, class T>
void Vector<N, T>::add(const Vector<N, T> &rhs)
{
	for (unsigned int i = 0; i < N; ++i)
		(*this)[i] += rhs[i];
}

/**
 * @brief Subtract another Vector to Vector in place
 *
 * @param rhs Vector to subtract to this one
 */
template <unsigned int N, class T>
void Vector<N, T>::sub(const Vector<N, T> &rhs)
{
	for (unsigned int i = 0; i < N; ++i)
		(*this)[i] -= rhs[i];
}

/**
 * @brief Scale Vector by a scalar
 *
 * @param lamda Scalar value
 */
template <unsigned int N, class T>
void Vector<N, T>::scale(T lambda)
{
	for (unsigned int i = 0; i < N; ++i)
		(*this)[i] *= lambda;
}

/**
 * @brief Compute the dot product of two Vectors
 *
 * @param rhs Second Vector in the product
 * @return Dot product
 */
template <unsigned int N, class T>
T Vector<N, T>::dot(const Vector<N, T> &rhs) const
{
	T res = 0;

	for (unsigned int i = 0; i < N; ++i)
		res = fma((*this)[i], rhs[i], res);
	return res;
}

/**
 * @brief Normalize Vector in place
 */
template <unsigned int N, class T>
void Vector<N, T>::normalize()
{
	*this = this->normalized();
}

/**
 * @brief Compute the normalized Vector
 *
 * @return Normalized Vector
 */
template <unsigned int N, class T>
Vector<N, T> Vector<N, T>::normalized() const
{
	return *this * (1 / this->norm());
}

// INFORMATIONS

/**
 * @brief Return Vector size (dimension)
 *
 * @return Vector size
 */
template <unsigned int N, class T>
unsigned int Vector<N, T>::size() const
{
	return N;
}

/**
 * @brief Compute the 1-norm of the Vector
 *
 * @return Vector 1-norm
 */
template <unsigned int N, class T>
float Vector<N, T>::norm_1() const
{
	float res = 0;

	for (unsigned int i = 0; i < N; ++i)
		res += mod((*this)[i]);
	return res;
}

/**
 * @brief Compute the euclidean norm (2-norm) of the Vector
 *
 * @return Vector euclidean norm
 */
template <unsigned int N, class T>
float Vector<N, T>::norm() const
{
	float res = 0;

	for (unsigned int i = 0; i < N; ++i)
	{
		float module = mod((*this)[i]);
		res = fma(module, module, res);
	}
	return static_cast<float>(std::pow(res, 0.5));
}

/**
 * @brief Compute the infinite norm of the Vector
 *
 * @return Infinite norm
 */
template <unsigned int N, class T>
float Vector<N, T>::norm_inf() const
{
	float res = 0;

	for (unsigned int i = 0; i < N; ++i)
	{
		float module = mod((*this)[i]);
		if (res < module)
			res = module;
	}
	return res;
}

// CONVERSIONS

/**
 * @brief Convert Vector to a single-row Matrix
 *
 * @return Row matrix
 */
template <unsigned int N, class T>
Matrix<1, N, T> Vector<N, T>::rowMatrix() const
{
	Matrix<1, N, T> row;
	for (unsigned int j = 0; j < N; j++)
		row[0][j] = this->_values[j];
	return row;
}

/**
 * @brief Convert Vector to a single-column Matrix
 *
 * @return Column matrix
 */
template <unsigned int N, class T>
Matrix<N, 1, T> Vector<N, T>::columnMatrix() const
{
	Matrix<N, 1, T> column;
	for (unsigned int i = 0; i < N; i++)
		column[i][0] = this->_values[i];
	return column;
}

/**
 * @brief Fill the values of a fixed-size array with the Vector elements
 *
 * @param array Array to fill
 */
template <unsigned int N, class T>
void Vector<N, T>::array(T array[N]) const
{
	for (unsigned int i = 0; i < N; i++)
		array[i] = this->_values[i];
}

template <unsigned int N, class T>
/**
 * @brief Resize Vector
 *
 * @param isHomogenous If true, fill additional elements with 1. If false, fill them with 0
 * @return The resized Vector
 */
template <unsigned int M>
Vector<M, T> Vector<N, T>::resize(bool isHomogenous) const
{
	Vector<M, T> resized;

	for (unsigned int i = 0; i < M; ++i)
	{
		if (i < N)
			resized[i] = _values[i];
		else
			resized[i] = isHomogenous;
	}
	return resized;
}
