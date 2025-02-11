#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_06_2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestingZero)
        {
            const int size = 3;
            int arr[size] = { 1, 3, 5 }; 
            int result = avgSum(arr, size, 0, 0, 0);
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(avgSum_Testing)
        {
            const int size = 5;
            int arr[size] = { 2, 3, 4, 5, 6 }; 
            int result = avgSum(arr, size, 0, 0, 0);
            Assert::AreEqual(2, result);
        }
	};
}
