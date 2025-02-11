#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_07.2_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestSearchMinInRow)
		{
			int row[] = { 5, 3, 7, 2, 6 };
			int n = 5;
			int minIndex = SearchMinInRow(row, n);
			Assert::AreEqual(minIndex, 3);
		}
        TEST_METHOD(TestPrintMatrix)
        {
            const int n = 3;
            int** matrix = new int* [n];
            for (int i = 0; i < n; i++) {
                matrix[i] = new int[n];
            }

            // [ 1, 2, 3 ]
            // [ 4, 5, 6 ]
            // [ 7, 8, 9 ]
            matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
            matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;
            matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9;
            
            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

            Print(matrix, n);

            std::cout.rdbuf(old);

            std::string output = buffer.str();
            std::string expectedOutput = "\n   1   2   3\n   4   5   6\n   7   8   9\n\n";
            Assert::AreEqual(expectedOutput, output);

            for (int i = 0; i < n; i++)
                delete[] matrix[i];
            delete[] matrix;
        }
		
	};
}
