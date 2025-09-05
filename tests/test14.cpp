#include "Matrix.hpp"
#include "liblinal.hpp"
#include <iostream>

void test14()
{
	std::cout << "\e[35mTEST EX14\e[0m\n";

	std::cout << "\n\e[36mPARAMETERS\e[0m\n";
	float fov = 75 * M_PI / 180;
	float ratio = 1;
	float near = 1;
	float far = 100;
	std::cout << "FOV: " << fov << "\n";
	std::cout << "Ratio: " << ratio << "\n";
	std::cout << "Near: " << near << "\n";
	std::cout << "Far: " << far << "\n";

	std::cout << "\n\e[36mPROJECTION MATRIX\e[0m\n";
	std::cout << projection(fov, ratio, near, far) << "\n";
}
