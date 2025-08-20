#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>

void test08()
{
	try
	{
		std::cout << "\e[35mTEST EX08\e[0m\n";

		std::cout << "\n\e[36mMATRIXES\e[0m\n";
		Matrix<3, 3> ma{{2, -5, 0}, {4, 3, 7}, {-2, 3, 4}};
		Matrix<3, 3> mb{{-2, -8, 4}, {1, -23, 4}, {0, 6, 4}};
		Matrix<2, 3> mc{{-2, -8, 4}, {1, -23, 4}};
		std::cout << "Matrix A: " << ma << "\n";
		std::cout << "Matrix B: " << mb << "\n";
		std::cout << "Matrix C: " << mc << "\n";

		std::cout << "\e[36mTRACE\e[0m\n";
		std::cout << "Trace of A: " << ma.trace() << "\n";
		std::cout << "Trace of B: " << mb.trace() << "\n";
		std::cout << "Trace of C: " << mc.trace() << "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << "\e[31mError:\e[0m " << e.what() << std::endl;
	}
}
