#include "pch.h"
#include "../LR_06_3_rec.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMax)
		{
			int a[] = { -5, 0, 15, 34, -10 };
			const int size = sizeof(a) / sizeof(a[0]);
			int expected_max = 34;
			int max_value = Max(a, size, 1, a[0]);

			Assert::AreEqual(expected_max, max_value, L"Max value is incorrect");
		}

		TEST_METHOD(TestMaxAllNegative)
		{
			int a[] = { -20, -15, -30, -5, -10 };
			const int size = sizeof(a) / sizeof(a[0]);
			int expected_max = -5;
			int max_value = Max(a, size, 1, a[0]);

			Assert::AreEqual(expected_max, max_value, L"Max value with all negatives is incorrect");
		}
	};
}
