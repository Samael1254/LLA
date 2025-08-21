#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>

void test12()
{
	std::cout << "\e[35mTEST EX12\e[0m\n";

	std::cout << "\n\e[36mMATRIXES\e[0m\n";
	Matrix<2, 2> ma{{1, 0}, {-1, 1}};
	Matrix<3, 3> mb{{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
	Matrix<3, 3> mc{{8, 5, -2}, {4, 7, 20}, {7, 6, 1}};
	Matrix<4, 4> md{{8, 5, -2, 4}, {4, 2.5, 20, 4}, {8, 5, 1, 4}, {28, -4, 17, 1}};
	std::cout << "Matrix A: " << ma << "\n";
	std::cout << "Matrix B: " << mb << "\n";
	std::cout << "Matrix C: " << mc << "\n";
	std::cout << "Matrix D: " << md << "\n";

	std::cout << "\e[36mINVERSES\e[0m\n";
	std::cout << "inv A: " << ma.inverse() << "\n";
	std::cout << "A * inv A: " << ma.inverse().mul_mat(ma) << "\n";
	std::cout << "inv B: " << mb.inverse() << "\n";
	std::cout << "B * inv B: " << mb.inverse().mul_mat(mb) << "\n";
	std::cout << "inv C: " << mc.inverse() << "\n";
	std::cout << "C * inv C: " << mc.inverse().mul_mat(mc) << "\n";
	std::cout << "inv D: " << md.inverse() << "\n";
	std::cout << "D * inv D: " << md.inverse().mul_mat(md) << "\n";
}
