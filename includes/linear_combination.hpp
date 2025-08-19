#include "Vector.hpp"
#include <array>

template <unsigned int N, unsigned int L, class T = float>
Vector<N, T> linear_combination(std::array<Vector<N, T>, L> u, std::array<T, L> coeffs)
{
	Vector<N, T> comb;

	for (unsigned int i = 0; i < L; ++i)
		comb += u[i] * coeffs[i];
	return comb;
}
