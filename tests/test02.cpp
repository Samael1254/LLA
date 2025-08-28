#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>

void test02()
{
	std::cout << "\e[35mTEST EX02\e[0m\n";

	std::cout << "\n\e[36mVECTORS\e[0m\n";
	Vector<3> a = {1, 2, 3};
	Vector<3> b = {4, 5, 6};
	std::cout << "Vector a: " << a << "\n";
	std::cout << "Vector b: " << b << "\n";

	std::cout << "\n\e[36mVECTOR LINEAR INTERPOLATION\e[0m\n";
	std::cout << "lerp(a, b, 0): " << lerp(a, b, 0) << "\n";
	std::cout << "lerp(a, b, 0.5): " << lerp(a, b, 0.5) << "\n";
	std::cout << "lerp(a, b, 1): " << lerp(a, b, 1) << "\n";

	std::cout << "\n\e[36mMATRIXES\e[0m\n";
	Matrix<2, 3> ma{{1, 1, 1}, {1, 2, 2}};
	Matrix<2, 3> mb{{0, -1, 1}, {-3, 4, 0}};
	std::cout << "Matrix A: " << ma << "\n";
	std::cout << "Matrix B: " << mb << "\n";

	std::cout << "\e[36mMATRIX LINEAR INTERPOLATION\e[0m\n";
	std::cout << "lerp(A, B, 0): " << lerp(ma, mb, 0) << "\n";
	std::cout << "lerp(A, B, 0.5): " << lerp(ma, mb, 0.5) << "\n";
	std::cout << "lerp(A, B, 1): " << lerp(ma, mb, 1);
}
