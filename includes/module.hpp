template <class T>
float module(T nb)
{
	if (nb < 0)
		return static_cast<float>(-nb);
	return static_cast<float>(nb);
}
