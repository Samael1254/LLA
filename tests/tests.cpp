#include "tests.hpp"
#include <array>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

int main(int argc, char **argv)
{
	std::array<void (*)(), NB_TESTS> tests{testVector, testMatrix, test00, test01, test02, test03, test04, test05,
	                                       test06,     test07,     test08, test09, test10, test11, test12, test13};

	try
	{
		if (argc == 1)
		{
			std::cout << "\e[32mTESTING LINEAR ALGEBRA LIBRARY\e[0m\n\n";
			for (std::array<void (*)(), NB_TESTS>::iterator it = tests.begin(); it != tests.end(); ++it)
				(*it)();
		}
		else
		{
			if (std::string(argv[1]) == "vec")
				testVector();
			else if (std::string(argv[1]) == "mat")
				testMatrix();
			else
			{
				unsigned int nb = std::atoi(argv[1]);
				if (nb > NB_TESTS - 3)
					throw std::invalid_argument("There is no test number " + std::string(argv[1]));
				tests[nb + 2]();
			}
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "\e[31mError:\e[0m " << e.what() << std::endl;
	}
}
