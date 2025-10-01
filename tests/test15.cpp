#include "Complex.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>

void test15()
{
	std::cout << "\e[35mTEST EX15\e[0m\n";

	std::cout << "\n\e[36mCOMPLEX NUMBERS\e[0m\n";
	Complex a(3, 2);
	Complex b(3, -2);
	Complex c(3);
	Complex d(0, 2);
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "c = " << c << "\n";
	std::cout << "d = " << d << "\n";

	std::cout << "\n\e[36mOPERATIONS\e[0m\n";
	std::cout << "a + b = " << a + b << "\n";
	std::cout << "a - b = " << a - b << "\n";
	std::cout << "a * b = " << a * b << "\n";
	std::cout << "a * a = " << a * a << "\n";
	std::cout << "a / b = " << a / b << "\n";
	std::cout << "3a = " << a * 3 << " (right hand float)\n";
	std::cout << "3a = " << 3 * a << " (left hand float)\n";
	a += b;
	std::cout << "a after a+=b = " << a << "\n";
	a -= b;
	std::cout << "a after a-=b = " << a << "\n";

	std::cout << "\n\e[36mVECTORS\e[0m\n";
	Vector<3, Complex> u = {a, b, c};
	Vector<3, Complex> v = {b, d, a};
	std::cout << "u = " << u << "\n";
	std::cout << "v = " << v << "\n";

	std::cout << "\n\e[36mMATRIX\e[0m\n";
	Matrix<2, 4, Complex> m = {{a, b, c, d}, {c, d, b, a}};
	std::cout << "m = " << m << "\n";
	std::cout << "row echelon m = " << m.row_echelon() << "\n";
	Matrix<2, 2, Complex> n = {{a, b}, {c, d}};
	std::cout << "n = " << n << "\n";
	Matrix<2, 2, Complex> invN = n.inverse();
	std::cout << "inverse n = " << invN << "\n";
	std::cout << "n * inv(n) = " << n * invN << "\n";
	Matrix<4, 4, Complex> o = {{a, b, a, b}, {c, d, c, d}, {a, b, a, b}, {c, d, c, d}};
	std::cout << "o = " << o << "\n";
	Matrix<4, 4, Complex> invo = o.inverse();
	std::cout << "inverse o = " << invo << "\n";
	std::cout << "row echelon o = " << o.row_echelon() << "\n";
	std::cout << "o * inv(o) = " << o * invo << "\n";

	// std::cout << "\n\e[36mPROJECTION MATRIX\e[0m\n";
	// std::cout << projection(fov, ratio, near, far) << "\n";
}
