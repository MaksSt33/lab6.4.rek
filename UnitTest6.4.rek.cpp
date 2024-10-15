#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.4.rek/lab6.4.rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64rek
{
	TEST_CLASS(UnitTest64rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 5;
			double a[n] = { -1.5, 0.5, 3.0, -2.0, 4.5 };
			double C = 1.0;

			int result = CountGreaterThanC(a, n, C);

			Assert::AreEqual(2, result);

		}
	};
}
