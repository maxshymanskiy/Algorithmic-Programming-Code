#include "pch.h"
#include "CppUnitTest.h"
#include "../var.cpp"
#include "../dod.cpp"

using namespace nsDod;
using namespace nsVar;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			a = 1.0;
			R = 2.0;

			double expected_a = a * R;

			dod();

			Assert::AreEqual(expected_a, a, 0.001, L"Correct dod() of not?");
		}
	};
}
