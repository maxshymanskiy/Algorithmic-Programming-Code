#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <sstream>
#include <string>
#include "../LR_11.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForTransfers
{
	TEST_CLASS(UnitTestForTransfers)
	{
	public:

		TEST_METHOD(TestCreateList)
		{
			std::string testFile = "testfile.txt";
			createList(testFile);

			std::ifstream file(testFile);
			Assert::IsTrue(file.good());

			file.close();
			remove(testFile.c_str());
		}

		TEST_METHOD(TestAddTransfer)
		{
			std::string testFile = "testfile.txt";
			createList(testFile);

			std::istringstream input("12345\n67890\n100.50\n");
			std::streambuf* cinBackup = std::cin.rdbuf(input.rdbuf());

			addTransfer(testFile);

			std::cin.rdbuf(cinBackup);

			std::ifstream file(testFile);
			Assert::IsTrue(file.good());

			std::string line;
			std::getline(file, line);
			Assert::AreEqual(std::string("12345 67890 100.5"), line);

			file.close();
			remove(testFile.c_str());
		}

		TEST_METHOD(TestGetTotalAmountByPayer)
		{
			std::string testFile = "testfile.txt";
			createList(testFile);

			std::ofstream file(testFile);
			file << "12345 67890 100.5\n";
			file << "12345 67891 200.75\n";
			file << "67890 12345 50.0\n";
			file.close();
			std::ostringstream output;
			std::streambuf* coutBackup = std::cout.rdbuf(output.rdbuf());

			getTotalAmountByPayer(testFile, "12345");

			std::cout.rdbuf(coutBackup);

			std::string expectedOutput = "Сума, знята з рахунку 12345: 301.25 грн.\n";
			Assert::AreEqual(expectedOutput, output.str());

			remove(testFile.c_str());
		}

		TEST_METHOD(TestViewList)
		{
			std::string testFile = "testfile.txt";
			createList(testFile);

			std::ofstream file(testFile);
			file << "12345 67890 100.5\n";
			file << "67890 12345 50.0\n";
			file.close();

			std::ostringstream output;
			std::streambuf* coutBackup = std::cout.rdbuf(output.rdbuf());

			viewList(testFile);

			std::cout.rdbuf(coutBackup);

			std::string expectedOutput = "\nСписок переказів:\n12345 67890 100.5\n67890 12345 50.0\n";
			Assert::AreEqual(expectedOutput, output.str());

			remove(testFile.c_str());
		}
	};
}
