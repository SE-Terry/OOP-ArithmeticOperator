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
class CPolynomial
{
private:
	int sz;
	CMonomial PolyArr[1000];
public:
	friend istream& operator>>(istream&, CPolynomial&);
	friend ostream& operator<<(ostream&, CPolynomial&);
	CPolynomial& operator=(const CPolynomial&);
	CPolynomial operator+(const CPolynomial&);
	CPolynomial operator-(CPolynomial);
	CPolynomial operator*(CMonomial);
	CPolynomial operator*(const CPolynomial&);
	CPolynomial operator/(CPolynomial);
	CPolynomial& operator+=(const CPolynomial&);
	CPolynomial& operator-=(CPolynomial);
	CPolynomial& operator*=(const CPolynomial&);
	CPolynomial& operator/=(CPolynomial);
};

int main()
{
	cout << "Problem 04 - 22521474 - BT_OOP_W6." << endl;
	CPolynomial a, b, s, d, m, q;
	cin >> a;
	cin >> b;
	s = a + b;
	cout << s << endl;
	d = a - b;
	cout << d << endl;
	m = a * b;
	cout << m << endl;
	q = a / b;
	cout << q << endl;
	a += a;
	cout << a << endl;
	b -= b;
	cout << b << endl;
	s *= s;
	cout << s << endl;
	q *= q;
	cout << q << endl;
	return 1;
}

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
	Coefficient = Coef                                                                                                                                                                                                                                                                                                                                         ;
}

void CMonomial::setExpo(int Expo)
{
	Exponent=Expo;
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

CPolynomial Remainder;

istream& operator>>(istream& is, CPolynomial& Poly)
{
	cout << "Enter the polynomial's level:		";
	is >> Poly.sz;
	for (int i = Poly.sz; i >= 0; i--)
	{
		if (i != 0)
			cout << "Enter the coefficient of x^" << i << ":	";
		else
			cout << "Enter the free coefficient:			";
		float a;
		is >> a;
		Poly.PolyArr[i].setCoef(a);
		Poly.PolyArr[i].setExpo(i);
	}
	return is;
}

ostream& operator<<(ostream& os, CPolynomial& Poly)
{
	os << "\nf(x) = ";
	os << Poly.PolyArr[Poly.sz];
	for (int i = Poly.sz - 1; i >= 0; i--)
		if (Poly.PolyArr[i].getCoef() != 0)
		{
			if (Poly.PolyArr[i].getCoef() > 0)
				os << " + ";
			else
				os << " - ";
			if (abs(Poly.PolyArr[i].getCoef()) != 1 || Poly.PolyArr[i].getExpo() == 0)
				os << abs(Poly.PolyArr[i].getCoef());
			if (Poly.PolyArr[i].getExpo() == 1)
				os << 'x';
			else
				if (Poly.PolyArr[i].getExpo() != 0)
					os << "x^" << Poly.PolyArr[i].getExpo();
		}
	return os;
}

CPolynomial& CPolynomial::operator=(const CPolynomial& Poly)
{
	sz = Poly.sz;
	for (int i = 0; i <= Poly.sz; i++)
		PolyArr[i] = Poly.PolyArr[i];
	return *this;
}

CPolynomial CPolynomial::operator+(const CPolynomial& Poly)
{
	CPolynomial s;
	if (sz > Poly.sz)
	{
		s = *this;
		for (int i = 0; i <= Poly.sz; i++)
			s.PolyArr[i] = s.PolyArr[i] + Poly.PolyArr[i];
	}
	else
	{
		s = Poly;
		for (int i = 0; i <= sz; i++)
			s.PolyArr[i] = s.PolyArr[i] + PolyArr[i];
	}
	while (s.PolyArr[s.sz].getCoef() == 0 && s.sz != 0)
		s.sz--;
	return s;
}

CPolynomial CPolynomial::operator-(CPolynomial Poly)
{
	CMonomial temp{-1,0};
	for (int i = 0; i <= Poly.sz; i++)
		Poly.PolyArr[i] = Poly.PolyArr[i] * temp;
	CPolynomial d = (*this) + Poly;
	while (d.PolyArr[d.sz].getCoef() == 0 && d.sz != 0)
		d.sz--;
	return d;
}

CPolynomial CPolynomial::operator*(CMonomial Mono)
{
	CPolynomial m;
	if (Mono.getCoef() == 0)
	{
		m.sz = 0;
		return m;
	}
	int t = Mono.getExpo();
	m.sz = (sz + t);
	for (int i = 0; i <= m.sz; i++)
		m.PolyArr[i].setExpo(i);
	for (int i = 0; i <= sz; i++)
	{
		int z = PolyArr[i].getExpo();
		m.PolyArr[z + t] = PolyArr[i] * Mono;
	}
	return m;
}

CPolynomial CPolynomial::operator*(const CPolynomial& Poly)
{
	CPolynomial m = (*this) * Poly.PolyArr[0];
	for (int i = 1; i <= Poly.sz; i++)
	{
		CPolynomial temp = (*this) * Poly.PolyArr[i];
		m = m + temp;
	}
	return m;
}

CPolynomial CPolynomial::operator/(CPolynomial Poly)
{
	Remainder = (*this);
	CPolynomial r;
	if (sz < Poly.sz)
		return r;
	int t = sz - Poly.sz;
	r.sz = t;
	for (int i = 0; i <= t; i++)
		r.PolyArr[i].setExpo(i);
	while (Remainder.sz >= Poly.sz)
	{
		r.PolyArr[Remainder.sz - Poly.sz] = Remainder.PolyArr[Remainder.sz] / Poly.PolyArr[Poly.sz];
		CPolynomial temp = Poly * r.PolyArr[Remainder.sz - Poly.sz];
		Remainder -= temp;
	}
	return r;
}

CPolynomial& CPolynomial::operator+=(const CPolynomial& Poly)
{
	CPolynomial s;
	if (sz > Poly.sz)
	{
		s = *this;
		for (int i = 0; i <= Poly.sz; i++)
			s.PolyArr[i] = s.PolyArr[i] + Poly.PolyArr[i];
	}
	else
	{
		s = Poly;
		for (int i = 0; i <= sz; i++)
			s.PolyArr[i] = s.PolyArr[i] + PolyArr[i];
	}
	while (s.PolyArr[s.sz].getCoef() == 0 && s.sz != 0)
		s.sz--;
	(*this) = s;
	return *this;
}

CPolynomial& CPolynomial::operator-=(CPolynomial Poly)
{
	CMonomial temp(-1, 0);
	for (int i = 0; i <= Poly.sz; i++)
		Poly.PolyArr[i] = Poly.PolyArr[i] * temp;
	CPolynomial d = (*this) + Poly;
	while (d.PolyArr[d.sz].getCoef() == 0 && d.sz != 0)
		d.sz--;
	(*this) = d;
	return *this;
}

CPolynomial& CPolynomial::operator*=(const CPolynomial& Poly)
{
	CPolynomial m = (*this) * Poly.PolyArr[0];
	for (int i = 1; i <= Poly.sz; i++)
	{
		CPolynomial temp = (*this) * Poly.PolyArr[i];
		m = m + temp;
	}
	(*this) = m;
	return *this;
}

CPolynomial& CPolynomial::operator/=(CPolynomial Poly)
{
	Remainder = (*this);
	CPolynomial r;
	if (sz < Poly.sz)
		return r;
	int t = sz - Poly.sz;
	r.sz = t;
	for (int i = 0; i <= t; i++)
		r.PolyArr[i].setExpo(i);
	while (Remainder.sz >= Poly.sz)
	{
		r.PolyArr[Remainder.sz - Poly.sz] = Remainder.PolyArr[Remainder.sz] / Poly.PolyArr[Poly.sz];
		CPolynomial temp = Poly * r.PolyArr[Remainder.sz - Poly.sz];
		Remainder -= temp;
	}
	(*this) = r;
	return *this;
}