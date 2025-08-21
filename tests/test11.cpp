#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>

void test11()
{
	std::cout << "\e[35mTEST EX11\e[0m\n";

	std::cout << "\n\e[36mMATRIXES\e[0m\n";
	Matrix<3, 3> ma{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	Matrix<3, 3> mb{{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
	Matrix<3, 3> mc{{8, 5, -2}, {4, 7, 20}, {7, 6, 1}};
	Matrix<4, 4> md{{8, 5, -2, 4}, {4, 2.5, 20, 4}, {8, 5, 1, 4}, {28, -4, 17, 1}};
	std::cout << "Matrix A: " << ma << "\n";
	std::cout << "Matrix B: " << mb << "\n";
	std::cout << "Matrix C: " << mc << "\n";
	std::cout << "Matrix D: " << md << "\n";

	std::cout << "\e[36mDETERMINANT\e[0m\n";
	std::cout << "det A: " << ma.determinant() << "\n";
	std::cout << "det B: " << mb.determinant() << "\n";
	std::cout << "det C: " << mc.determinant() << "\n";
	std::cout << "det D: " << md.determinant() << "\n";
}
