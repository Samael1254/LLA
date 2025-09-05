#pragma once

#include "Complex.hpp"
#include "Vector.hpp"
#include <array>
#include <cstdint>
#include <type_traits>

enum EAxis : std::uint8_t
{
	XAxis,
	YAxis,
	ZAxis,
};

template <unsigned int N, class T = float>
float angle_cos(const Vector<N, T> &u, const Vector<N, T> &v)
{
	return u.dot(v) / (u.norm() * v.norm());
}

template <class T = float>
Vector<3, T> cross_product(const Vector<3, T> &u, const Vector<3, T> &v)
{
	Vector<3, T> res;

	for (unsigned int i = 0; i < 3; ++i)
		res[i] = u[(i + 1) % 3] * v[(i + 2) % 3] - u[(i + 2) % 3] * v[(i + 1) % 3];
	return res;
}

template <class V, class T = float>
V lerp(const V &u, const V &v, T t)
{
	return (1 - t) * u + t * v;
}

template <unsigned int N, unsigned int L, class T = float>
Vector<N, T> linear_combination(std::array<Vector<N, T>, L> u, std::array<T, L> coeffs)
{
	Vector<N, T> comb;

	for (unsigned int i = 0; i < L; ++i)
		comb += u[i] * coeffs[i];
	return comb;
}

// template <class V, unsigned int L, class T = float>
// V linear_combination(std::array<V, L> u, std::array<T, L> coeffs)
// {
// 	V comb;
//
// 	for (unsigned int i = 0; i < L; ++i)
// 		comb += u[i] * coeffs[i];
// 	return comb;
// }

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
T module(T nb)
{
	return std::abs(nb);
}

float module(const Complex &c);

Matrix<4, 4, float> projection(float fov, float ratio, float near, float far);
