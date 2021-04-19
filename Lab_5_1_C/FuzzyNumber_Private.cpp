#include "FuzzyNumber_Private.h"

FuzzyNumber_Private::FuzzyNumber_Private()
	: FuzzyNumber()
{}

FuzzyNumber_Private::FuzzyNumber_Private(double X, double L, double R)
	: FuzzyNumber(X, L, R)
{}


FuzzyNumber_Private::FuzzyNumber_Private(const FuzzyNumber_Private& v)
	: FuzzyNumber(v)
{}


FuzzyNumber_Private& FuzzyNumber_Private::operator = (const FuzzyNumber_Private& n)
{
	FuzzyNumber::operator = (n);
	return *this;
}

FuzzyNumber_Private::operator string () const
{
	stringstream ss;
	ss << "(" << GetL() << "; " << GetX() << "; " << GetR() << ")" << endl;
	return ss.str();
}

FuzzyNumber_Private& FuzzyNumber_Private::operator --() throw(MyDerivedException)
{
	this->SetL(this->GetL() - 1);
	if (this->GetL() < 0)
		throw new MyDerivedException();
	return *this;
}

FuzzyNumber_Private& FuzzyNumber_Private::operator ++() throw(MyException)
{
	this->SetR(this->GetR() + 1);
	if (this->GetR() > 10)
		throw MyException("Right coordinate bigger than 10");
	return *this;
}

FuzzyNumber_Private FuzzyNumber_Private::operator --(int) throw(MyDerivedException)
{
	FuzzyNumber_Private a(*this);
	this->SetL(this->GetL() - 1);
	if (this->GetL() < 0)
		throw MyDerivedException();
	return a;
}

FuzzyNumber_Private FuzzyNumber_Private::operator ++(int) throw(logic_error)
{
	FuzzyNumber_Private a(*this);
	this->SetR(this->GetR() + 1);
	if (this->GetR() > 10)
		throw logic_error("Right coordinate bigger than 10");
	return a;
}

FuzzyNumber_Private operator + (const FuzzyNumber_Private a, const FuzzyNumber_Private b)
{
	FuzzyNumber_Private T;
	T.SetX(a.GetX() + b.GetX());
	T.SetL(a.GetX() + b.GetX() - a.GetL() - b.GetL());
	T.SetR(a.GetX() + b.GetX() + a.GetR() + b.GetR());
	return T;
}

FuzzyNumber_Private operator * (const FuzzyNumber_Private a, const FuzzyNumber_Private b)
{
	FuzzyNumber_Private N;
	N.SetX(a.GetX() * b.GetX());
	N.SetL(a.GetX() * b.GetX() - b.GetX() * a.GetL() - a.GetX() * b.GetL() - a.GetL() * b.GetL());
	N.SetR(a.GetX() * b.GetX() + b.GetX() * a.GetR() + a.GetX() * b.GetR() + a.GetR() * b.GetR());
	return N;
}

ostream& operator <<(ostream& out, const FuzzyNumber_Private& a)
{
	return out << string(a);
}

istream& operator >>(istream& in, FuzzyNumber_Private& a) throw(logic_error)
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