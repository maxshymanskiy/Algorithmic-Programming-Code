#include "pch.h"
#include "../LR_06_4_rec.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMultipOfPositiveElements)
		{
			double arr1[] = { 1.5, 2.0, 3.0 };
			Assert::AreEqual(9.0, MultipOfPositiveElements(arr1, 3));

			double arr2[] = { -2.0, 4.0, -1.0, 3.0 };
			Assert::AreEqual(12.0, MultipOfPositiveElements(arr2, 4));

			double arr3[] = { -1.0, -2.0, -3.0 };
			Assert::AreEqual(0.0, MultipOfPositiveElements(arr3, 3));
		}

		TEST_METHOD(TestFindMinIndex)
		{
			double arr1[] = { -2.0, 3.0, 4.0 };
			Assert::AreEqual(0, FindMinIndex(arr1, 0, 3, 0));

			double arr2[] = { 4.0, -1.0, 3.0, 2.0 };
			Assert::AreEqual(1, FindMinIndex(arr2, 0, 4, 0));

			double arr3[] = { 3.0, 2.0, -5.0 };
			Assert::AreEqual(2, FindMinIndex(arr3, 0, 3, 0));
		}

		TEST_METHOD(TestSumBeforeMinElement)
		{
			double arr1[] = { -2.0, 3.0, 4.0 };
			Assert::AreEqual(0.0, SumBeforeMinElement(arr1, 0, 0));

			double arr2[] = { 4.0, -1.0, 3.0, 2.0 };
			Assert::AreEqual(4.0, SumBeforeMinElement(arr2, 1, 0));

			double arr3[] = { 3.0, 2.0, -5.0 };
			Assert::AreEqual(5.0, SumBeforeMinElement(arr3, 2, 0));
		}

	};
}
