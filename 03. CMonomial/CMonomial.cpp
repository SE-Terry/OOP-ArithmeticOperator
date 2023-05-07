#include <iostream>
using namespace std;

class CMonomial
{
private:
	float Coefficient;
	int Exponent;
public:
	CMonomial operator*(const CMonomial&);
	CMonomial operator/(const CMonomial&);
	CMonomial operator*=(const CMonomial&);
	CMonomial operator/=(const CMonomial&);
};

int main()
{
	cout << "Problem 03 - 22521474 - BT_OOP_W6." << endl;
	return 1;
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