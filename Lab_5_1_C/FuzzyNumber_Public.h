#pragma once
#include "FuzzyNumber.h"

class FuzzyNumber_Public : public FuzzyNumber
{
public:
	FuzzyNumber_Public();
	FuzzyNumber_Public(double x, double l, double r);
	FuzzyNumber_Public(const FuzzyNumber_Public& v);

	FuzzyNumber_Public& operator =(const FuzzyNumber_Public& n);

	FuzzyNumber_Public& operator --() throw(MyDerivedException);
	FuzzyNumber_Public& operator ++() throw(MyException);
	FuzzyNumber_Public operator --(int) throw(MyDerivedException);
	FuzzyNumber_Public operator ++(int) throw(logic_error);

	friend FuzzyNumber_Public operator + (const FuzzyNumber_Public a, const FuzzyNumber_Public b);
	friend FuzzyNumber_Public operator * (const FuzzyNumber_Public a, const FuzzyNumber_Public b);
};