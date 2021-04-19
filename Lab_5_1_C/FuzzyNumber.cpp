#include "FuzzyNumber.h"

FuzzyNumber::FuzzyNumber()
	: x(0), l(0), r(0)
{}

FuzzyNumber::FuzzyNumber(double X, double L, double R) throw(logic_error)
{
	if (!(X > (X - L) && (X + R) > X))
		throw logic_error("Condition is not met");

	this->SetX(X);
	this->SetL(X - L);
	this->SetR(X + R);
}

FuzzyNumber::FuzzyNumber(const FuzzyNumber& v)
{
	x = v.x;
	l = v.l;
	r = v.r;
}

FuzzyNumber& FuzzyNumber::operator = (const FuzzyNumber& n)
{
	x = n.x;
	l = n.l;
	r = n.r;
	return *this;
}

FuzzyNumber::operator string () const
{
	stringstream ss;
	ss << "(" << this->l << "; " << this->x << "; " << this->r << ")" << endl;
	return ss.str();
}

FuzzyNumber& FuzzyNumber::operator --() throw(MyDerivedException)
{
	--l;
	if (l < 0)
		throw new MyDerivedException();
	return *this;
}

FuzzyNumber& FuzzyNumber::operator ++() throw(MyException)
{
	++r;
	if (r > 10)
		throw logic_error("Right coordinate bigger than 10");
	return *this;
}

FuzzyNumber FuzzyNumber::operator --(int) throw(MyDerivedException)
{
	FuzzyNumber a(*this);
	l--;
	if (l < 0)
		throw MyDerivedException();
	return a;
}

FuzzyNumber FuzzyNumber::operator ++(int) throw(logic_error)
{
	FuzzyNumber a(*this);
	r++;
	if (r > 10)
		throw logic_error("Right coordinate bigger than 10");
	return a;
}

FuzzyNumber operator + (const FuzzyNumber a, const FuzzyNumber b)
{
	FuzzyNumber T;
	T.x = a.x + b.x;
	T.l = a.x + b.x - a.l - b.l;
	T.r = a.x + b.x + a.r + b.r;
	return T;
}

FuzzyNumber operator * (const FuzzyNumber a, const FuzzyNumber b)
{
	FuzzyNumber N;
	N.x = a.x * b.x;
	N.l = (a.x * b.x) - (b.x * a.l) - (a.x * b.l) - (a.l * b.l);
	N.r = (a.x * b.x) + (b.x * a.r) + (a.x * b.r) + (a.r * b.r);
	return N;
}

ostream& operator <<(ostream& out, const FuzzyNumber& a)
{
	return out << string(a);
}

istream& operator >>(istream& in, FuzzyNumber& a) throw(logic_error)
{
	double x, l, r;
	cout << "x = "; in >> x;
	cout << "l = "; in >> l;
	cout << "r = "; in >> r;

	if (!(x > (x - l) && (x + r) > x))
		throw logic_error("Condition is not met");

	a.SetX(x); a.SetL(x - l); a.SetR(x + r);
	return in;
}