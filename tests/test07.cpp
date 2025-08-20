#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>

void test07()
{
	std::cout << "\e[35mTEST EX07\e[0m\n";

	std::cout << "\n\e[36mVECTORS\e[0m\n";
	Vector<3> a = {1, 2, 3};
	Vector<3> b = {4, 5, 6};
	std::cout << "Vector a: " << a << "\n";
	std::cout << "Vector b: " << b << "\n";

	std::cout << "\n\e[36mMATRIXES\e[0m\n";
	Matrix<2, 3> ma{{1, 1, 1}, {1, 2, 2}};
	Matrix<3, 2> mb{{0, -1}, {1, -3}, {4, 0}};
	std::cout << "Matrix A: " << ma << "\n";
	std::cout << "Matrix B: " << mb << "\n";

	std::cout << "\e[36mVECTOR MATRIX PRODUCT\e[0m\n";
	std::cout << "A * a = " << ma * a << "\n";
	std::cout << "b * B = " << b * mb << "\n";

	std::cout << "\n\e[36mMATRIX PRODUCT\e[0m\n";
	std::cout << "A * B =" << ma * mb << "\n";
}
