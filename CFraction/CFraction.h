#include <iostream>
using namespace std;

class CFraction
{
private:
	int Numerator;
	int Denominator;
public:
	friend istream& operator >> (istream&, CFraction&);
	friend ostream& operator << (ostream&, CFraction&);
	CFraction operator+(const CFraction&);
	CFraction operator-(const CFraction&);
	CFraction operator*(const CFraction&);
	CFraction operator/(const CFraction&);
	CFraction& operator+=(const CFraction&);
	CFraction& operator-=(const CFraction&);
	CFraction& operator*=(const CFraction&);
	CFraction& operator/=(const CFraction&);
};

istream& operator >> (istream& is, CFraction& ft)
{
	cout << "Enter fraction's numerator:	";
	is >> ft.Numerator;
	cout << "Enter fraction's denominator:	";
	is >> ft.Denominator;
	return is;
}

ostream& operator << (ostream& os, CFraction& ft)
{
	os << ft.Numerator << "/" << ft.Denominator << ".";
	return os;
}
CFraction CFraction::operator+(const CFraction& ft)
{
	CFraction s{};
	s.Numerator = ft.Numerator * Denominator + Numerator * ft.Denominator;
	s.Denominator = ft.Denominator * Denominator;
	return s;
}
CFraction CFraction::operator-(const CFraction& ft)
{
	CFraction d{};
	d.Numerator = ft.Numerator * Denominator - Numerator * ft.Denominator;
	d.Denominator = ft.Denominator * Denominator;
	return d;
}
CFraction CFraction::operator*(const CFraction& ft)
{
	CFraction m{};
	m.Numerator = ft.Numerator * Numerator;
	m.Denominator = ft.Denominator * Denominator;
	return m;
}
CFraction CFraction::operator/(const CFraction& ft)
{
	CFraction q{};
	q.Numerator = Numerator * ft.Denominator;
	q.Denominator = Denominator * ft.Numerator;
	return q;
}

CFraction& CFraction::operator+=(const CFraction& ft)
{
	Numerator = ft.Numerator * Denominator + Numerator * ft.Denominator;
	Denominator = ft.Denominator * Denominator;
	return *this;
}
CFraction& CFraction::operator-=(const CFraction& ft)
{
	Numerator = ft.Numerator * Denominator + Numerator * ft.Denominator;
	Denominator = ft.Denominator * Denominator;
	return *this;
}
CFraction& CFraction::operator*=(const CFraction& ft)
{
	Numerator = ft.Numerator * Numerator;
	Denominator = ft.Denominator * Denominator;
	return *this;
}
CFraction& CFraction::operator/=(const CFraction& ft)
{
	Numerator = Numerator * ft.Denominator;
	Denominator = Denominator * ft.Numerator;
	return *this;
}