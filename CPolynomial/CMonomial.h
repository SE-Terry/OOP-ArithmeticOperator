#include <iostream>
using namespace std;

class CMonomial
{
private:
	float Coefficient;
	int Exponent;
public:
	CMonomial();
	CMonomial(float, int);
	friend istream& operator>>(istream&, CMonomial&);
	friend ostream& operator<<(ostream&, CMonomial&);
	void setCoef(float);
	void setExpo(int);
	float getCoef();
	int getExpo();
	CMonomial operator+(const CMonomial&);
	CMonomial operator-(const CMonomial&);
	CMonomial operator*(const CMonomial&);
	CMonomial operator/(const CMonomial&);
};

CMonomial::CMonomial()
{
	Coefficient = 0;
	Exponent = 0;
}

CMonomial::CMonomial(float Coef, int Expo)
{
	Coefficient = Coef;
	Exponent = Expo;
}

istream& operator>>(istream& is, CMonomial& mono)
{
	cout << "Enter the coefficient:		";
	is >> mono.Coefficient;
	cout << "Enter the exponent:		";
	is >> mono.Exponent;
	return is;
}

void CMonomial::setCoef(float Coef)
{
	Coefficient = Coef;
}

void CMonomial::setExpo(int Expo)
{
	Exponent = Expo;
}

float CMonomial::getCoef()
{
	return Coefficient;
}

int CMonomial::getExpo()
{
	return Exponent;
}

CMonomial CMonomial::operator+(const CMonomial& mono)
{
	CMonomial s;
	if (Exponent == mono.Exponent)
	{
		s.Coefficient = Coefficient + mono.Coefficient;
		s.Exponent = Exponent;
	}
	return s;
}

CMonomial CMonomial::operator-(const CMonomial& mono)
{
	CMonomial d;
	if (Exponent == mono.Exponent)
	{
		d.Coefficient = Coefficient - mono.Coefficient;
		d.Exponent = Exponent;
	}
	return d;
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

ostream& operator<<(ostream& os, CMonomial& mono)
{
	if (mono.Exponent == 0 || mono.Coefficient == 0)
		os << mono.Coefficient;
	else
	{
		if (mono.Coefficient == -1)
			os << " - ";
		else if (mono.Coefficient != 1)
			os << mono.Coefficient;
		if (mono.Exponent == 1)
			os << 'x';
		else
			os << "x^" << mono.Exponent;
	}
	return os;
}