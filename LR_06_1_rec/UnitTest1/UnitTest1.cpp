#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_06_1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCountElements)
        {
            // Arrange
            int x[] = { -1, -2, -3, -4, -5, -6, 3, 6, 9 };
            const int size = sizeof(x) / sizeof(x[0]);
            int count_element = 0;

            // Act
            CountElements(x, size, 0, count_element);

            // Assert
            Assert::AreEqual(4, count_element); // -1, -2, -4, -5 are < 0 and not divisible by 3
        }

        TEST_METHOD(TestSumElements)
        {
            // Arrange
            int x[] = { -1, -2, -3, -4, -5, -6, 3, 6, 9 };
            const int size = sizeof(x) / sizeof(x[0]);

            // Act
            int sum = SumElements(x, size, 0);

            // Assert
            Assert::AreEqual(-12, sum); // Sum of -1, -2, -4, -5
        }
	};
}
