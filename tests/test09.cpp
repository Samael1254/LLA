#include "Matrix.hpp"
#include <iostream>

void test09()
{
	std::cout << "\e[35mTEST EX09\e[0m\n";

	std::cout << "\n\e[36mMATRIXES\e[0m\n";
	Matrix<2, 3> ma{{1, 1, 1}, {1, 2, 2}};
	Matrix<3, 2> mb{{0, -1}, {1, -3}, {4, 0}};
	std::cout << "Matrix A: " << ma << "\n";
	std::cout << "Matrix B: " << mb << "\n";

	std::cout << "\n\e[36mMATRIX TRANSPOSE\e[0m\n";
	std::cout << "Transpose of A:" << ma.transpose() << "\n";
	std::cout << "Transpose of B:" << mb.transpose() << "\n";
}
