#pragma once
#include <exception>
#include <iostream>

using namespace std;

class MyDerivedException : public exception
{
public:
	virtual const char* What() const throw();
};