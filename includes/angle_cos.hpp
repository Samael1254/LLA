#include "Vector.hpp"

template <unsigned int N, class T = float>
float angle_cos(const Vector<N, T> &u, const Vector<N, T> &v)
{
	return u.dot(v) / (u.norm() * v.norm());
}
