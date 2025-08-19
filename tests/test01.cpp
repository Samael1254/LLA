#include "linear_combination.hpp"
#include "Vector.hpp"
#include <array>
#include <iostream>

void test01()
{
	std::cout << "\e[35mTEST EX01\e[0m\n";

	std::cout << "\n\e[36mVECTORS\e[0m\n";
	Vector<3> a = {1, 2, 3};
	Vector<3> b = {4, 5, 6};
	Vector<3> c = {7, 8, 9};
	Vector<3> d = {10, 11, 12};
	std::cout << "Vector a: " << a << "\n";
	std::cout << "Vector b: " << b << "\n";
	std::cout << "Vector c: " << c << "\n";
	std::cout << "Vector d: " << d << "\n";

	std::cout << "\n\e[36mCOEFFS\e[0m\n";
	std::array<float, 4> coeffs = {1, 2, 3, 4};
	std::cout << coeffs[0] << ", " << coeffs[1] << ", " << coeffs[2] << ", " << coeffs[3] << "\n";

	std::cout << "\n\e[36mLINEAR COMBINATION\e[0m\n";
	std::cout << linear_combination<3, 4>({a, b, c, d}, coeffs);
}
