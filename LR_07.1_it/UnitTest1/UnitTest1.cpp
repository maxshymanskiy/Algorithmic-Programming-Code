#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_07.1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestCreate)
		{
			int rowCount = 3;
			int colCount = 3;
			int Low = 11;
			int High = 74;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			Create(a, rowCount, colCount, Low, High);

			for (int i = 0; i < rowCount; i++)
				for (int j = 0; j < colCount; j++)
				{
					Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
				}

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSort)
		{
			int rowCount = 3;
			int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 30; a[0][1] = 10; a[0][2] = 20;
			a[1][0] = 20; a[1][1] = 30; a[1][2] = 10;
			a[2][0] = 10; a[2][1] = 20; a[2][2] = 30;

			Sort(a, rowCount, colCount);

			Assert::IsTrue(a[0][0] <= a[1][0] && a[1][0] <= a[2][0]);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
