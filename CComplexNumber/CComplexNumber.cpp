#include "CComplexNumber.h"

int main()
{
	cout << "Project 002 - 22521474 - BT_OOP_W6." << endl;
	CComplexNumber a, b, s, d, m, q;
	cout << "\nEnter the first complex number: " << endl;
	cin >> a;
	cout << "\nEnter the second complex number: " << endl;
	cin >> b;
	cout << "\nThe summary of 2 complex numbers is:		";
	s = a + b;
	cout << s << endl;
	cout << "\nThe subtraction of 2 complex numbers is:	";
	d = a - b;
	cout << d << endl;
	cout << "\nThe multiplication of 2 complex numbers is:	";
	m = a * b;
	cout << m << endl;
	cout << "\nThe quotation of 2 complex numbers is:		";
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