#pragma once
#include <string>
#include <sstream>

using namespace std;

class MyException
{
private:
	string message;

public:
	MyException() throw();
	MyException(const string& m) throw();
	string What() const throw() { return message; }
	virtual ~MyException() {};
};