#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5_1_C/FuzzyNumber_Public.cpp"
#include "../Lab_5_1_C/FuzzyNumber_Private.cpp"
#include "../Lab_5_1_C/FuzzyNumber.cpp"
#include "../Lab_5_1_C/MyDerivedException.cpp"
#include "../Lab_5_1_C/MyException.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Labtest51C
{
	TEST_CLASS(Labtest51C)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			FuzzyNumber_Private A1(4, 1, 7), B1(6, 3, 9);
			FuzzyNumber_Private Sum = A1 + B1;
			Assert::AreEqual(Sum.GetX(), 10.0);
		}

		TEST_METHOD(TestMethod2)
		{
			FuzzyNumber_Public A2(6, 3, 2);
			A2++;
			Assert::AreEqual(A2.GetX(), 6.0);
		}
	};
}
