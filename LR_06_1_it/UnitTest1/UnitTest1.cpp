#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_06_1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCountElements)
        {
            int x[] = { -1, -2, -3, -4, -5, -6, 3, 6, 9 };
            const int size = sizeof(x) / sizeof(x[0]);
            int count = CountElements(x, size);
            Assert::AreEqual(4, count);
        }

        TEST_METHOD(TestSum)
        {
            int x[] = { -1, -2, -3, -4, -5, -6, 3, 6, 9 };
            const int size = sizeof(x) / sizeof(x[0]);
            int count_element = 0;
            int sum = Sum(x, size, count_element);

            Assert::AreEqual(-12, sum);         // Sum of -1, -2, -4, -5
            Assert::AreEqual(4, count_element); // Count of elements summed

            int expected_x[] = { 0, 0, -3, 0, 0, -6, 3, 6, 9 };
            for (int i = 0; i < size; ++i)
            {
                Assert::AreEqual(expected_x[i], x[i]);
            }
        }
	};
}
