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

	std::cout << "\n\e[36mComplex LINEAR INTERPOLATION\e[0m\n";
	std::cout << "lerp(a, b, 0): " << lerp(a, b, 0) << "\n";
	std::cout << "lerp(a, b, 0.5): " << lerp(a, b, 0.5) << "\n";
	std::cout << "lerp(a, b, 1): " << lerp(a, b, 1) << "\n";

	std::cout << "\n\e[36mVECTORS\e[0m\n";
	Vector<3, Complex> u = {a, b, c};
	Vector<3, Complex> v = {b, d, a};
	std::cout << "u = " << u << "\n";
	std::cout << "v = " << v << "\n";

	std::cout << "\n\e[36mLINEAR COMBINATION\e[0m\n";
	std::array<Complex, 2> coeffs = {1, 2};
	std::cout << "Coeffs: " << coeffs[0] << ", " << coeffs[1] << "\n";
	std::cout << linear_combination<3, 2, Complex>({u, v}, coeffs) << "\n";

	std::cout << "\n\e[36mMATRIX\e[0m\n";
	Matrix<2, 4, Complex> m = {{a, b, c, d}, {c, d, b, a}};
	std::cout << "m = " << m << "\n";
	Matrix<2, 2, Complex> n = {{a, b}, {c, d}};
	std::cout << "n = " << n << "\n";
	Matrix<4, 4, Complex> o = {{a, b, a, b}, {c, d, c, d}, {a, c, b, c}, {c, a, b, d}};
	std::cout << "o = " << o << "\n";

	std::cout << "\n\e[36mMATRIX TRACE\e[0m\n";
	std::cout << "trace of n = " << n.trace() << "\n";

	std::cout << "\n\e[36mMATRIX TRACE\e[0m\n";
	std::cout << "transpose of n = " << n.transpose() << "\n";

	std::cout << "\n\e[36mMATRIX ROW ECHELON\e[0m\n";
	std::cout << "row echelon m = " << m.row_echelon().rounded(1e-5) << "\n";

	std::cout << "\n\e[36mMATRIX DETERMINANT\e[0m\n";
	std::cout << "rank of o = " << o.determinant() << "\n";

	std::cout << "\n\e[36mMATRIX INVERSE\e[0m\n";
	Matrix<2, 2, Complex> invN = n.inverse();
	std::cout << "inverse n = " << invN.rounded(1e-5) << "\n";
	std::cout << "n * inv(n) = " << (n * invN).rounded(1e-5) << "\n";
	Matrix<4, 4, Complex> invo = o.inverse();
	std::cout << "inverse o = " << invo.rounded(1e-5) << "\n";
	std::cout << "o * inv(o) = " << (o * invo).rounded(1e-5) << "\n";

	std::cout << "\n\e[36mMATRIX RANK\e[0m\n";
	std::cout << "rank of o = " << o.rank() << "\n";
}
