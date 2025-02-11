#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <string>
#include <sstream>
#include "../LR_11.4.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCreateFileF)
        {
            std::string testFile = "testFileF.txt";

            std::istringstream input("Hello World\nTest String\nEND\n");
            std::streambuf* cinBackup = std::cin.rdbuf(input.rdbuf());

            createFileF(testFile);

            std::cin.rdbuf(cinBackup);

            std::ifstream file(testFile);
            Assert::IsTrue(file.good());

            std::string line;
            std::getline(file, line);
            Assert::AreEqual(std::string("Hello World"), line);

            std::getline(file, line);
            Assert::AreEqual(std::string("Test String"), line);

            file.close();
            remove(testFile.c_str());
        }

        TEST_METHOD(TestCopyFileWithModification)
        {
            std::string inputFile = "testFileF.txt";
            std::string outputFile = "testFileH.txt";

            std::ofstream inFile(inputFile);
            inFile << "Hello World\n";
            inFile << "Test String\n";
            inFile.close();

            copyFileWithModification(inputFile, outputFile);

            std::ifstream outFile(outputFile);
            Assert::IsTrue(outFile.good());

            std::string line;
            std::getline(outFile, line);
            Assert::AreEqual(std::string("1 Hello World 11"), line);

            std::getline(outFile, line);
            Assert::AreEqual(std::string("2 Test String 11"), line);

            outFile.close();
            remove(inputFile.c_str());
            remove(outputFile.c_str());
        }
	};
}
