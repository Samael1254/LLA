#include "Matrix.hpp"
#include <iostream>

void test13()
{
	std::cout << "\e[35mTEST EX13\e[0m\n";

	std::cout << "\n\e[36mMATRIXES\e[0m\n";
	Matrix<3, 3> ma{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	Matrix<3, 4> mb{{1, 2, 0, 0}, {2, 4, 0, 0}, {-1, 2, 1, 1}};
	Matrix<4, 3> mc{{8, 5, -2}, {4, 7, 20}, {7, 6, 1}, {21, 18, 7}};
	std::cout << "Matrix A: " << ma << "\n";
	std::cout << "Matrix B: " << mb << "\n";
	std::cout << "Matrix C: " << mc << "\n";

	std::cout << "\e[36mRANK\e[0m\n";
	std::cout << "rank A: " << ma.rank() << "\n";
	std::cout << "rank B: " << mb.rank() << "\n";
	std::cout << "rank C: " << mc.rank() << "\n";
}
