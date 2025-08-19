#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>

void test00()
{
	std::cout << "\e[35mTEST EX00\e[0m\n";

	std::cout << "\n\e[36mVECTORS\e[0m\n";
	Vector<3> a = {1, 4, 5};
	Vector<5> b{3, 3, 3, 3, 3};
	Vector<3> c = {0, -4, 20};
	std::cout << "Vector a: " << a << "\n";
	std::cout << "Vector b: " << b << "\n";
	std::cout << "Vector c: " << c << "\n";

	std::cout << "\n\e[36mVECTOR OPERATIONS\e[0m\n";
	std::cout << "a + c = " << a + c << "\n";
	std::cout << "a - c = " << a - c << "\n";
	std::cout << "a * 4 = " << a * 4 << "\n";
	std::cout << "4 * a = " << 4 * a << "\n";

	std::cout << "\n\e[36mVECTOR IN PLACE OPERATIONS\e[0m\n";
	b += Vector<5>{5, 5, 5, 5, 5};
	std::cout << "b += [5 5 5 5 5]: " << b << "\n";
	b -= Vector<5>{2, 2, 2, 2, 2};
	std::cout << "b -= [2 2 2 2 2]: = " << b << "\n";
	b *= -2;
	std::cout << "b *= -2 = " << b << "\n";

	std::cout << "\n\e[36mMatrixes\e[0m\n";
	Matrix<2, 3> ma{{1, 1, 1}, {1, 2, 2}};
	Matrix<2, 3> mb{{0, -1, 1}, {-3, 4, 0}};

	std::cout << "Matrix A: " << ma << "\n";
	std::cout << "Matrix B: " << mb << "\n";

	std::cout << "\e[36mMATRIX OPERATIONS\e[0m\n";
	std::cout << "A + B = " << ma + mb << "\n";
	std::cout << "A - B = " << ma - mb << "\n";
	std::cout << "A * 4 = " << ma * 4 << "\n";
	std::cout << "4 * A = " << 4 * ma << "\n";

	std::cout << "\e[36mMATRIX IN PLACE OPERATIONS\e[0m\n";
	mb += ma;
	std::cout << "b += a: " << mb << "\n";
	mb *= -2;
	std::cout << "b *= -2 = " << mb;
}
