#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_06_3_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

        TEST_METHOD(TestMax)
        {
            int a[] = { -5, 0, 15, 34, -10, 22, 5, 34, 7, -3 };
            const int size = sizeof(a) / sizeof(a[0]);
            int max_value = Max(a, size);

            Assert::AreEqual(34, max_value);
        }

        TEST_METHOD(TestMaxWithNegativeNumbers)
        {
            int a[] = { -20, -15, -30, -5, -10 };
            const int size = sizeof(a) / sizeof(a[0]);
            int max_value = Max(a, size);
            
            Assert::AreEqual(-5, max_value);

        }


	};
}
