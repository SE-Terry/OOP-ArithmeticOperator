#include <iostream>
using namespace std;
#include "CMonomial.h"

int main()
{
	cout << "Problem 03 - 22521474 - BT_OOP_W6." << endl;
	CMonomial a, b, m, q;
	cout << "\nEnter the first monomial(a):" << endl;
	cin >> a;
	cout << "\nEnter the second monomial(b):" << endl;
	cin >> b;
	cout << "\nThe multiplication of 2 monomials is(m):		";
	m = a * b;
	cout << m << "." << endl;
	cout << "\nThe quotation of 2 monomials is(q):			";
	q = a / b;
	cout << q << "." << endl;
	cout << "\nm *= a: ";
	m *= a;
	cout << m << "." << endl;
	cout << "\nq /= b: ";
	q /= b;
	cout << q << "." << endl;
	return 1;
}