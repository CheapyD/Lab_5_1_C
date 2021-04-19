#include "MyException.h"

MyException::MyException() throw()
	: message()
{}

MyException::MyException(const string& m) throw()
	: message(m)
{}