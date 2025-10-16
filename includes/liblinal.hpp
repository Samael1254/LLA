#pragma once

#include "Complex.hpp"
#include "Vector.hpp"
#include <array>
#include <cstdint>
#include <type_traits>

/**
 * @enum EAxis
 * @brief Three dimensional basis axes
 */
enum EAxis : std::uint8_t
{
	XAxis,
	YAxis,
	ZAxis,
};

/**
 * @brief Compute the cosine of the angle between two Vectors
 *
 * @param u First vector
 * @param v Second vector
 * @return Cosine of the angle
 */
template <unsigned int N, class T = float>
float angle_cos(const Vector<N, T> &u, const Vector<N, T> &v)
{
	return u.dot(v) / (u.norm() * v.norm());
}

/**
 * @brief Compute the cross product of two 3D Vectors
 *
 * @param u First 3D vector
 * @param v Second 3D vector
 * @return Cross product
 */
template <class T = float>
Vector<3, T> cross_product(const Vector<3, T> &u, const Vector<3, T> &v)
{
	Vector<3, T> res;

	for (unsigned int i = 0; i < 3; ++i)
		res[i] = u[(i + 1) % 3] * v[(i + 2) % 3] - u[(i + 2) % 3] * v[(i + 1) % 3];
	return res;
}

/**
 * @brief Linear interpolation between two objects
 *
 * @tparam V Object like a scalar, a vector or a matrix
 * @param u Start value (for t = 0)
 * @param v End value (for t = 1)
 * @param t Interpolation factor
 * @return Object interpolated linearily
 */
template <class V, class T = float>
V lerp(const V &u, const V &v, T t)
{
	return (1 - t) * u + t * v;
}

/**
 * @brief Computes the linear combination of an array of vectors by an array of coefficients
 *
 * @tparam N Vectors size
 * @tparam L Number of vectors
 * @param u Vectors
 * @param coeffs Coefficients
 * @return Linear combination
 */
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

/**
 * @brief Computes the module of an arithmetic number as its absolute value
 * @details Use this for compatibility purposes if you plan to use modules in templates with custom classes
 *
 * @tparam T Type
 * @param nb Number
 * @return Module
 */
template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
float mod(T nb)
{
	return std::abs(nb);
}

float mod(const Complex &c);

Matrix<4, 4, float> projection(float fov, float ratio, float near, float far);

Matrix<4, 4, float> orthographic(float width, float height, float near, float far);
