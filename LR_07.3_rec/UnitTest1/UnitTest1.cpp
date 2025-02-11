#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_07.3_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestPart1_CountCols)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                matrix[i] = new int[colCount];
            
            // [ 1,  0,  -3 ]
            // [ 0, -5,   6 ]
            // [ 4,  5,   6 ]
            matrix[0][0] = 1;  matrix[0][1] = 0;  matrix[0][2] = -3;
            matrix[1][0] = 0;  matrix[1][1] = -5; matrix[1][2] = 6;
            matrix[2][0] = 4;  matrix[2][1] = 5;  matrix[2][2] = 6;

            int count = Part1_CountCols(matrix, rowCount, colCount, 0);

            Assert::AreEqual(2, count);

            for (int i = 0; i < rowCount; i++)
                delete[] matrix[i];
            delete[] matrix;
        }
        TEST_METHOD(TestPart2_SaddlePointRows_Simple)
        {
            // Define a 3x3 matrix
            const int rowCount = 3;
            const int colCount = 3;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                matrix[i] = new int[colCount];

           
            // [ 3,  8,  4 ]
            // [ 6,  7,  9 ]
            // [ 5,  2,  1 ]
            matrix[0][0] = 3;  matrix[0][1] = 8;  matrix[0][2] = 4;
            matrix[1][0] = 6;  matrix[1][1] = 7;  matrix[1][2] = 9;
            matrix[2][0] = 5;  matrix[2][1] = 2;  matrix[2][2] = 1;

            int No = 0;
            Part2_SaddlePointRows(matrix, rowCount, colCount, No, 0);

            Assert::AreEqual(1, No); 

            // Clean up memory
            for (int i = 0; i < rowCount; i++)
                delete[] matrix[i];
            delete[] matrix;
        }
	};
}
