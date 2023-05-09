#include "CPolynomial.h"

int main()
{
	cout << "Problem 04 - 22521474 - BT_OOP_W6." << endl;
	CPolynomial a, b, s, d, m, q;
	cout << "\nEnter the first polynomial(a): " << endl;
	cin >> a;
	cout << "\nEnter the second polynomial(b): " << endl;
	cin >> b;
	cout << "\nThe summary of 2 polynomials is(s): ";
	s = a + b;
	cout << s << endl;
	cout << "\nThe subtraction of 2 polynomials is(d): ";
	d = a - b;
	cout << d << endl;
	cout << "\nThe multiplication of 2 polynomials is(m): ";
	m = a * b;
	cout << m << endl;
	cout << "\nThe quotation of 2 polynomials is(q): ";
	q = a / b;
	cout << q << endl;
	cout << "\na += a: ";
	a += a;
	cout << a << endl;
	cout << "\nb -= b: ";
	b -= b;
	cout << b << endl;
	cout << "\ns *= s: ";
	s *= s;
	cout << s << endl;
	cout << "\nq /= m: ";
	q /= m;
	cout << q << endl;
	return 1;
}