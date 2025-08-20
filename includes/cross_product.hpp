#include "Vector.hpp"
template <class T = float>
Vector<3, T> cross_prouct(const Vector<3, T> &u, const Vector<3, T> &v)
{
	Vector<3, T> res;

	for (unsigned int i = 0; i < 3; ++i)
		res[i] = u[(i + 1) % 3] * v[(i + 2) % 3] - u[(i + 2) % 3] * v[(i + 1) % 3];
	return res;
}
