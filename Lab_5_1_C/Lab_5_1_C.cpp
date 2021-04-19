#include "FuzzyNumber_Private.h"
#include "FuzzyNumber_Public.h"

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

void Call_Bad() throw(int)
{
	throw 'x';
}

int main()
{
	set_unexpected(_unexpected_to_bad);

	try
	{
		FuzzyNumber_Private A1;
		cin >> A1;
		cout << A1;

		cout << "Size of private class: " << sizeof(A1) << endl;

		FuzzyNumber_Private B1(5, 1, 7);
		cout << B1 << endl;

		FuzzyNumber_Private C1 = A1 + B1;
		cout << "C1 = " << C1 << endl;

		FuzzyNumber_Private D1 = A1 * B1;
		cout << "D1 = " << D1 << endl;
		try
		{
			A1--;
		}
		catch (MyDerivedException a)
		{
			cerr << a.What() << endl << endl;
		}
		catch (MyDerivedException* a)
		{
			cerr << a->What() << endl << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	FuzzyNumber_Private N1;
	cin >> N1;
	cout << N1;

	try
	{
		N1++;
	}
	catch (MyException& a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		FuzzyNumber_Public A2;
		cin >> A2;
		cout << A2;

		cout << "Size of public class: " << sizeof(A2) << endl;

		FuzzyNumber_Public B2(4, 1, 5);
		cout << B2 << endl;

		FuzzyNumber_Public C2 = A2 + B2;
		cout << "C2 = " << C2 << endl;

		FuzzyNumber_Public D2 = A2 * B2;
		cout << "D2 = " << D2 << endl;
		try
		{
			A2--;
		}
		catch (MyDerivedException a)
		{
			cerr << a.What() << endl << endl;
		}
		catch (MyDerivedException* a)
		{
			cerr << a->What() << endl << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	FuzzyNumber_Public N2;
	cin >> N2;
	cout << N2;

	try
	{
		N2++;
	}
	catch (MyException& a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Call_Bad();
	}
	catch (bad_exception)
	{
		cerr << "catch (bad_exception)" << endl;
	}
}