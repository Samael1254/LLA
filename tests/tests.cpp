#include "tests.hpp"
#include <exception>
#include <iostream>

int main()
{
	try
	{
		std::cout << "\e[34mTESTING LINEAR ALGEBRA LIBRARY\e[0m\n\n";
		testVector();
		std::cout << "\n";
		testMatrix();
		std::cout << "\n";
		test00();
		std::cout << "\n";
		test01();
		std::cout << "\n";
		test02();
		std::cout << "\n";
		test03();
		std::cout << "\n";
		test04();
		std::cout << "\n";
		test05();
		std::cout << "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
