#include <iostream>
using namespace std;

class CMonomial
{
private:
	float Coefficient;
	int Exponent;
public:
	friend istream& operator >> (istream&, CMonomial&);
	friend ostream& operator << (ostream&, CMonomial&);
	CMonomial operator*(const CMonomial&);
	CMonomial operator/(const CMonomial&);
	CMonomial operator*=(const CMonomial&);
	CMonomial operator/=(const CMonomial&);
};

int main()
{
	cout << "Problem 03 - 22521474 - BT_OOP_W6." << endl;
	CMonomial a, b, m, q;
	cout << "\nEnter the first monomial(a):" << endl;
	cin >> a;
	cout << "\nEnter the second monomial(b):" << endl;
	cin >> b;
	cout << "\nThe multiplication of 2 monomials is(m): ";
	m = a * b;
	cout << m << endl;
	cout << "\nThe quotation of 2 monomials is(q): ";
	q = a / b;
	cout << q << endl;
	cout << "\nm *= a: ";
	m *= a;
	cout << m << endl;
	cout << "\nq /= b: ";
	q /= b;
	cout << q << endl;
	return 1;
}

istream& operator >> (istream& is, CMonomial& mn)
{
	cout << "Enter the coefficient:			";
	is >> mn.Coefficient;
	cout << "Enter the exponent:			";
	is >> mn.Exponent;
	return is;
}

CMonomial CMonomial::operator*(const CMonomial& mn)
{
	CMonomial m;
	m.Coefficient = Coefficient * mn.Coefficient;
	m.Exponent = Exponent + mn.Exponent;
	return m;
}

CMonomial CMonomial::operator/(const CMonomial& mn)
{
	CMonomial q;
	q.Coefficient = Coefficient / mn.Coefficient;
	q.Exponent = Exponent - mn.Exponent;
	return q;
}

CMonomial CMonomial::operator*=(const CMonomial& mn)
{
	Coefficient *= mn.Coefficient;
	Exponent += mn.Exponent;
	return *this;
}

CMonomial CMonomial::operator/=(const CMonomial& mn)
{
	Coefficient /= mn.Coefficient;
	Exponent -= mn.Exponent;
	return *this;
}

ostream& operator << (ostream& os, CMonomial& mn)
{
	os << mn.Coefficient << "x^" << mn.Exponent;
	return os;
}