#pragma once
#pragma pack(1)
#include "MyException.h"
#include "MyDerivedException.h"

class FuzzyNumber
{
private:
	double x, l, r;

public:
	FuzzyNumber();
	FuzzyNumber(double x, double l, double r) throw(logic_error);
	FuzzyNumber(const FuzzyNumber& v);

	double GetX() const { return x; }
	double GetL() const { return l; }
	double GetR() const { return r; }

	void SetX(double value) { x = value; }
	void SetL(double value) { l = value; }
	void SetR(double value) { r = value; }

	FuzzyNumber& operator = (const FuzzyNumber& n);
	operator string() const;

	FuzzyNumber& operator --() throw(MyDerivedException);
	FuzzyNumber& operator ++() throw(MyException);
	FuzzyNumber operator --(int) throw(MyDerivedException);
	FuzzyNumber operator ++(int) throw(logic_error);

	friend FuzzyNumber operator + (const FuzzyNumber a, const FuzzyNumber b);
	friend FuzzyNumber operator * (const FuzzyNumber a, const FuzzyNumber b);

	friend ostream& operator <<(ostream& out, const FuzzyNumber& a);
	friend istream& operator >>(istream& in, FuzzyNumber& a) throw(logic_error);
};