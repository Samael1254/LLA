#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>

void testVector()
{
	std::cout << "\e[35mTEST VECTOR\e[0m\n";

	std::cout << "\n\e[36mCREATION, SIZE AND PRINT\e[0m\n";
	Vector<3> a = {1, 4, 5};
	Vector<5> b{3, 3, 3, 3, 3};
	Vector<3> c = {0, -4, 20};
	std::cout << "Vector a of size " << a.size() << ": " << a << "\n";
	std::cout << "Vector b of size " << b.size() << ": " << b << "\n";
	std::cout << "Vector c of size " << c.size() << ": " << c << "\n";

	std::cout << "\n\e[36mACCESS AND MODIFICATION\e[0m\n";
	std::cout << "Third element of a: " << a[2] << "\n";
	a[2] = 8;
	std::cout << "Vector a after setting it to 8: " << a << "\n";

	std::cout << "\n\e[36mCONVERSION TO MATRIX\e[0m\n";
	std::cout << "Vector a as column matrix:" << a.columnMatrix();
	std::cout << "\nVector a as row matrix:" << a.rowMatrix();
}
