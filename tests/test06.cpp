#include "cross_product.hpp"
#include "Vector.hpp"
#include <iostream>

void test06()
{
	std::cout << "\e[35mTEST EX06\e[0m\n";

	std::cout << "\n\e[36mVECTORS\e[0m\n";
	Vector<3> a = {1, 2, 3};
	Vector<3> b = {4, 5, 6};
	std::cout << "Vector a: " << a << "\n";
	std::cout << "Vector b: " << b << "\n";

	std::cout << "\n\e[36mCROSS PRODUCT\e[0m\n";
	std::cout << "a ^ b = " << cross_prouct(a, b) << "\n";
	std::cout << "b ^ a = " << cross_prouct(b, a) << "\n";
	std::cout << "a ^ a = " << cross_prouct(a, a) << "\n";
}
