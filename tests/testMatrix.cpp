#include "Matrix.hpp"
#include <iostream>

void testMatrix()
{
	std::cout << "\e[35mTEST MATRIX\e[0m\n";

	std::cout << "\n\e[36mCREATION, SIZE AND PRINT\e[0m\n";
	Matrix<3, 2> a{{1, 1}, {1, 1}, {2, 2}};
	Matrix<1, 3> b{{2, 5, 0}};
	Matrix<2, 2> c{{2, 5}, {1, 0}};
	std::cout << "Matrix A of size (" << a.size().first << "," << a.size().second << "): " << a << "\n";
	std::cout << "Matrix B of size (" << b.size().first << "," << b.size().second << "): " << b << "\n";

	std::cout << "\e[36mACCESS AND MODIFICATION\e[0m\n";
	a[2][1] = 8;
	a[0][0] = 177;
	std::cout << "Matrix A after change:" << a << "\n";

	std::cout << "\e[36mSQUARENESS\e[0m\n";
	std::cout << "Matrix C of size (" << c.size().first << "," << c.size().second << "): " << c << "\n";
	std::cout << "Matrix A is square: " << a.isSquare() << "\n";
	std::cout << "Matrix B is square: " << b.isSquare() << "\n";
	std::cout << "Matrix C is square: " << c.isSquare() << "\n";

	std::cout << "\n\e[36mEXTRACT VECTORS\e[0m\n";
	std::cout << "Second column of A: " << a.columnVector(1) << "\n";
	std::cout << "First row of A: " << a.rowVector(0) << "\n";
}
