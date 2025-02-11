#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_05_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double eps = 0.000001;
			int n = 1;
			double result = S(0.5, eps, n, 0);
			Assert::IsTrue(result > 0);
		}
		TEST_METHOD(TestMethod2)
		{
			double result = A(0.5, 2, 0.1);
			Assert::IsTrue(result > 0);
		}

	};
}
