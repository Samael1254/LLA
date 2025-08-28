#include "Vector.hpp"
#include <iostream>

void test05()
{
	std::cout << "\e[35mTEST EX05\e[0m\n";

	std::cout << "\n\e[36mVECTORS\e[0m\n";
	Vector<2> a = {1, 0};
	Vector<2> b = {1, 1};
	Vector<2> c = {0, 1};
	std::cout << "Vector a: " << a << "\n";
	std::cout << "Vector b: " << b << "\n";
	std::cout << "Vector c: " << c << "\n";

	std::cout << "\n\e[36mCOSINES\e[0m\n";
	std::cout << "cos(a, b) = " << angle_cos(a, b) << "\n";
	std::cout << "cos(a, c) = " << angle_cos(a, c) << "\n";
	std::cout << "cos(a, a) = " << angle_cos(a, a) << "\n";
}
