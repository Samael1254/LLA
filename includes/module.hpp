#include <string>
#include <typeinfo>

template <class T>
float module(T nb)
{
	if (std::string(typeid(nb).name()) == "float")
	{
		if (nb < 0)
			return static_cast<float>(-nb);
		return static_cast<float>(nb);
	}
	if (std::string(typeid(nb).name()) == "Complex")
		return nb.module();
}
