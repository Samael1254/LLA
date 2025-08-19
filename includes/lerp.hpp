template <class V, class T = float>
V lerp(const V &u, const V &v, T t)
{
	return (1 - t) * u + t * v;
}
