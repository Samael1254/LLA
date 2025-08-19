#include "Vector.hpp"
#include <iostream>

void test04()
{
	std::cout << "\e[35mTEST EX04\e[0m\n";

	std::cout << "\n\e[36mVECTORS\e[0m\n";
	Vector<3> a = {1, 2, 3};
	std::cout << "Vector a: " << a << "\n";

	std::cout << "\n\e[36mNORM 1\e[0m\n";
	std::cout << "a.b = " << a.norm_1() << "\n";
	std::cout << "\n\e[36mEUCLIDEAN NORM\e[0m\n";
	std::cout << "a.b = " << a.norm() << "\n";
	std::cout << "\n\e[36mNORM INFINITY\e[0m\n";
	std::cout << "a.b = " << a.norm_inf() << "\n";
}
