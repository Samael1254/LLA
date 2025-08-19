#include "Vector.hpp"
#include <iostream>

void test03()
{
	std::cout << "\e[35mTEST EX03\e[0m\n";

	std::cout << "\n\e[36mVECTORS\e[0m\n";
	Vector<3> a = {1, 2, 3};
	Vector<3> b = {4, 5, 6};
	std::cout << "Vector a: " << a << "\n";
	std::cout << "Vector b: " << b << "\n";

	std::cout << "\n\e[36mDOT PRODUCT\e[0m\n";
	std::cout << "a.b = " << a.dot(b) << "\n";
}
