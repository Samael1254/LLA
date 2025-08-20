#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>

void test10()
{
	std::cout << "\e[35mTEST EX10\e[0m\n";

	std::cout << "\n\e[36mMATRIXES\e[0m\n";
	Matrix<3, 3> ma{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	Matrix<2, 2> mb{{1, 2}, {3, 4}};
	Matrix<2, 2> mc{{1, 2}, {2, 4}};
	Matrix<3, 5> md{{8, 5, -2, 4, 28}, {4, 2.5, 20, 4, -4}, {8, 5, 1, 4, 17}};
	std::cout << "Matrix A: " << ma << "\n";
	std::cout << "Matrix B: " << mb << "\n";
	std::cout << "Matrix C: " << mc << "\n";
	std::cout << "Matrix D: " << md << "\n";

	std::cout << "\e[36mSWAP ROWS\e[0m\n";
	ma.swapRows(0, 2);
	std::cout << "swap line 1 and 3 of A: " << ma << "\n";
	ma.swapRows(0, 2);

	std::cout << "\e[36mSCALE ROW\e[0m\n";
	ma.scaleRow(1, 4);
	std::cout << "scale line 2 of A by 4: " << ma << "\n";
	ma.scaleRow(1, 0.25);

	std::cout << "\e[36mADD SCALED ROW\e[0m\n";
	ma.fmaRows(1, 0, 4);
	std::cout << "add line 2 of A by 4 times line 1: " << ma << "\n";
	ma.fmaRows(1, 0, -4);

	std::cout << "\e[36mROW ECHELON FORM\e[0m\n";
	std::cout << "A: " << ma.row_echelon() << "\n";
	std::cout << "B: " << mb.row_echelon() << "\n";
	std::cout << "C: " << mc.row_echelon() << "\n";
	std::cout << "D: " << md.row_echelon();
}
