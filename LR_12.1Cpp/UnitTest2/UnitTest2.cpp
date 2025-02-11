#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_12.1Cpp.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(PrintBIN_Test)
		{
			char testFileName[] = "test_file.dat";

			ofstream fout(testFileName, ios::binary);
			int testData[] = { 1, 2, 3, 4 };
			for (int num : testData) {
				fout.write((char*)&num, sizeof(num));
			}
			fout.close();

			stringstream buffer;
			streambuf* oldCout = cout.rdbuf(buffer.rdbuf()); 

			PrintBin(testFileName);

			cout.rdbuf(oldCout);

			string expectedOutput = "File content (test_file.dat):\n1 2 3 4 \n";

			Assert::AreEqual(expectedOutput, buffer.str(), L"Output does not match expected result.");

			remove(testFileName);
		}
	};
}
