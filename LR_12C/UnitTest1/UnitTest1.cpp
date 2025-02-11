#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../LR_12C.cpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

        TEST_METHOD(TestProcessBIN)
        {
            const char* inputFile = "test1.bin";
            const char* outputFile = "test2.bin";

            std::ofstream file(inputFile, std::ios::binary);
            int nums[] = { 1, 2, 3 };
            file.write(reinterpret_cast<const char*>(nums), sizeof(nums));
            file.close();

            ProcessBIN(inputFile, outputFile);

            std::ifstream output(outputFile, std::ios::binary);
            Assert::IsTrue(output.is_open());

            std::vector<int> data;
            int num;
            while (output.read(reinterpret_cast<char*>(&num), sizeof(int))) {
                data.push_back(num);
            }
            output.close();

            Assert::AreEqual(1, data[0]);
            Assert::AreEqual(3, data[1]);
            Assert::AreEqual(6, data[2]);
        }
	};
}
