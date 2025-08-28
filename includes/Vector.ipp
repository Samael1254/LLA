#pragma once

#include "liblinal.hpp"
#include <cmath>
#include <initializer_list>
#include <iostream>

// Constructors and destructor

template <unsigned int N, class T>
Vector<N, T>::Vector(std::initializer_list<T> init)
{
	if (init.size() != N)
		throw std::runtime_error("Invalid Vector elements number");

	unsigned int i = 0;
	for (auto it = init.begin(); it != init.end(); ++it)
		this->_values[i++] = *it;
}

template <unsigned int N, class T>
Vector<N, T>::Vector(const Vector<N, T> &other) : _values(other._values)
{
}

// Operator overloads

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

// Operations

template <unsigned int N, class T>
void Vector<N, T>::add(const Vector<N, T> &rhs)
{
	for (unsigned int i = 0; i < N; ++i)
		(*this)[i] += rhs[i];
}

template <unsigned int N, class T>
void Vector<N, T>::sub(const Vector<N, T> &rhs)
{
	for (unsigned int i = 0; i < N; ++i)
		(*this)[i] -= rhs[i];
}

template <unsigned int N, class T>
void Vector<N, T>::scale(T lambda)
{
	for (unsigned int i = 0; i < N; ++i)
		(*this)[i] *= lambda;
}

template <unsigned int N, class T>
T Vector<N, T>::dot(const Vector<N, T> &rhs) const
{
	T res = 0;

	for (unsigned int i = 0; i < N; ++i)
		res = std::fma((*this)[i], rhs[i], res);
	return res;
}

// Informations

template <unsigned int N, class T>
unsigned int Vector<N, T>::size() const
{
	return N;
}

template <unsigned int N, class T>
float Vector<N, T>::norm_1() const
{
	float res = 0;

	for (unsigned int i = 0; i < N; ++i)
		res += module((*this)[i]);
	return res;
}

template <unsigned int N, class T>
float Vector<N, T>::norm() const
{
	float res = 0;

	for (unsigned int i = 0; i < N; ++i)
	{
		float mod = module((*this)[i]);
		res = std::fma(mod, mod, res);
	}
	return static_cast<float>(std::pow(res, 0.5));
}

template <unsigned int N, class T>
float Vector<N, T>::norm_inf() const
{
	float res = 0;

	for (unsigned int i = 0; i < N; ++i)
	{
		float mod = module((*this)[i]);
		if (res < mod)
			res = mod;
	}
	return res;
}

// Conversions

template <unsigned int N, class T>
Matrix<1, N, T> Vector<N, T>::rowMatrix() const
{
	Matrix<1, N, T> row;
	for (unsigned int j = 0; j < N; j++)
		row[0][j] = this->_values[j];
	return row;
}

template <unsigned int N, class T>
Matrix<N, 1, T> Vector<N, T>::columnMatrix() const
{
	Matrix<N, 1, T> column;
	for (unsigned int i = 0; i < N; i++)
		column[i][0] = this->_values[i];
	return column;
}
