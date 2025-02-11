#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_06_2_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestGenArray)
        {
            const int size = 10;
            int arr[size];
            genArray(arr, size);
            int result = avgSum(arr, size);
            int expected = 5;
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestOwnNubmers)
        {
            const int size = 5;
            int arr[size] = { 2, 4, 6, 8, 10 };
            int result = avgSum(arr, size);
            int expected = 2;
            Assert::AreEqual(expected, result);
        }

	};
}
