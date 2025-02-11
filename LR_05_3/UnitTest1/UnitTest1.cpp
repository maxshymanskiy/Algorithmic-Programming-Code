#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_05_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double x = 2.0;
			double result = p(x);
			double expected = (pow(cos(x), 2) - sin(x)) / exp(sin(x));
			Assert::AreEqual(expected, result);
		}
	};
}
