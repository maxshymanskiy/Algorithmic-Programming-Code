#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_07.2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
	public:

        TEST_METHOD(TestSearchMinInRowRecursive_Simple)
        {
            const int N = 5;
            int row[N] = { 3, 10, 5, 2, 8 };

            int result = SearchMinInRowRecursive(row, N, 0, 0);
            Assert::AreEqual(3, result);  
        }
        TEST_METHOD(TestCreateRows)
        {
            const int N = 3;
            const int Low = 1;
            const int High = 10;
            int** matrix = new int* [N];
            for (int i = 0; i < N; i++) {
                matrix[i] = new int[N];
            }

            CreateRows(matrix, N, Low, High, 0);

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    Assert::IsTrue(matrix[i][j] >= Low && matrix[i][j] <= High);
                }
            }

            for (int i = 0; i < N; i++)
                delete[] matrix[i];
            delete[] matrix;
        }

        TEST_METHOD(TestPrintRows)
        {
            const int N = 3;
            int** matrix = new int* [N];
            for (int i = 0; i < N; i++) {
                matrix[i] = new int[N];
            }

            // [ 1, 2, 3 ]
            // [ 4, 5, 6 ]
            // [ 7, 8, 9 ]
            matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
            matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;
            matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9;

            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

            PrintRows(matrix, N, 0);

            std::cout.rdbuf(old);

            std::string expectedOutput = "   1   2   3\n   4   5   6\n   7   8   9\n\n";
            Assert::AreEqual(expectedOutput, buffer.str());

            for (int i = 0; i < N; i++)
                delete[] matrix[i];
            delete[] matrix;
        }

	};
}
