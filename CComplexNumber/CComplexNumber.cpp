#include <iostream>
using namespace std;

class CComplexNumber
{
private:
	float Real;
	float Imaginary;
public:
	void Input();
	CComplexNumber operator+(const CComplexNumber&);
	CComplexNumber operator-(const CComplexNumber&);
	CComplexNumber operator*(const CComplexNumber&);
	CComplexNumber operator/(const CComplexNumber&);
	CComplexNumber operator^(int);
	CComplexNumber operator+=(const CComplexNumber&);
	CComplexNumber operator-=(const CComplexNumber&);
	CComplexNumber operator*=(const CComplexNumber&);
	CComplexNumber operator/=(const CComplexNumber&);
	void Output();
};

int main()
{
	cout << "Project 002 - 22521474 - BT_OOP_W6." << endl;
	return 1;
}

CComplexNumber CComplexNumber::operator+(const CComplexNumber& cn)
{
	CComplexNumber s{};
	s.Real = Real + cn.Real;
	s.Imaginary = Imaginary + cn.Imaginary;
	return s;
}

CComplexNumber CComplexNumber::operator-(const CComplexNumber& cn)
{
	CComplexNumber d{};
	d.Real = Real - cn.Real;
	d.Imaginary = Imaginary - cn.Imaginary;
	return d;
}

CComplexNumber CComplexNumber::operator*(const CComplexNumber& cn)
{
	CComplexNumber m{};
	m.Real = Real * cn.Real - Imaginary * cn.Imaginary;
	m.Imaginary = Real * cn.Imaginary - Imaginary * cn.Real;
	return m;
}

CComplexNumber CComplexNumber::operator/(const CComplexNumber& cn)
{
	CComplexNumber q{};
	q.Real = (Real * cn.Real + Imaginary * cn.Imaginary) / (cn.Real * cn.Real + cn.Imaginary * cn.Imaginary);
	q.Imaginary = (Imaginary * cn.Real - cn.Imaginary * Real) / (cn.Real * cn.Real + cn.Imaginary * cn.Imaginary);
	return q;
}

CComplexNumber CComplexNumber::operator^(int n)
{
	CComplexNumber p = *this;
	for (int i = 1; i < n; i++)
	{
		p *= (*this);
	}
	return p;
}

CComplexNumber CComplexNumber::operator+=(const CComplexNumber& cn)
{
	Real += cn.Real;
	Imaginary += cn.Imaginary;
	return *this;
}

CComplexNumber CComplexNumber::operator-=(const CComplexNumber& cn)
{
	Real -= cn.Real;
	Imaginary -= cn.Imaginary;
	return *this;
}

CComplexNumber CComplexNumber::operator*=(const CComplexNumber& cn)
{
	Real = Real * cn.Real - Imaginary * cn.Imaginary;
	Imaginary = Real * cn.Imaginary - Imaginary * cn.Real;
	return *this;
}

CComplexNumber CComplexNumber::operator/=(const CComplexNumber& cn)
{
	Real = (Real * cn.Real + Imaginary * cn.Imaginary) / (cn.Real * cn.Real + cn.Imaginary * cn.Imaginary);
	Imaginary = (Imaginary * cn.Real - cn.Imaginary * Real) / (cn.Real * cn.Real + cn.Imaginary * cn.Imaginary);
	return *this;
}