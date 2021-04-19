#include "FuzzyNumber_Public.h"

FuzzyNumber_Public::FuzzyNumber_Public()
	: FuzzyNumber()
{}

FuzzyNumber_Public::FuzzyNumber_Public(double X, double L, double R)
	: FuzzyNumber(X, L, R)
{}

FuzzyNumber_Public::FuzzyNumber_Public(const FuzzyNumber_Public& v)
	: FuzzyNumber(v)
{}

FuzzyNumber_Public& FuzzyNumber_Public::operator = (const FuzzyNumber_Public& n)
{
	FuzzyNumber::operator = (n);
	return *this;
}

FuzzyNumber_Public& FuzzyNumber_Public::operator --() throw(MyDerivedException)
{
	this->SetL(this->GetL() - 1);
	if (this->GetL() < 0)
		throw new MyDerivedException();
	return *this;
}

FuzzyNumber_Public& FuzzyNumber_Public::operator ++() throw(MyException)
{
	this->SetR(this->GetR() + 1);
	if (this->GetR() > 10)
		throw MyException("Right coordinate bigger than 10");
	return *this;
}

FuzzyNumber_Public FuzzyNumber_Public::operator --(int) throw(MyDerivedException)
{
	FuzzyNumber_Public a(*this);
	this->SetL(this->GetL() - 1);
	if (this->GetL() < 0)
		throw MyDerivedException();
	return a;
}

FuzzyNumber_Public FuzzyNumber_Public::operator ++(int) throw(logic_error)
{
	FuzzyNumber_Public a(*this);
	this->SetR(this->GetR() + 1);
	if (this->GetR() > 10)
		throw logic_error("Right coordinate bigger than 10");
	return a;
}

FuzzyNumber_Public operator + (const FuzzyNumber_Public a, const FuzzyNumber_Public b)
{
	FuzzyNumber_Public T;
	T.SetX(a.GetX() + b.GetX());
	T.SetL(a.GetX() + b.GetX() - a.GetL() - b.GetL());
	T.SetR(a.GetX() + b.GetX() + a.GetR() + b.GetR());
	return T;
}

FuzzyNumber_Public operator * (const FuzzyNumber_Public a, const FuzzyNumber_Public b)
{
	FuzzyNumber_Public N;
	N.SetX(a.GetX() * b.GetX());
	N.SetL(a.GetX() * b.GetX() - b.GetX() * a.GetL() - a.GetX() * b.GetL() - a.GetL() * b.GetL());
	N.SetR(a.GetX() * b.GetX() + b.GetX() * a.GetR() + a.GetX() * b.GetR() + a.GetR() * b.GetR());
	return N;
}