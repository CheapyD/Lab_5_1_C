#include "MyDerivedException.h"

const char* MyDerivedException::What() const
{
	return "Exception: MyDerivedException: l < 0 ";
}