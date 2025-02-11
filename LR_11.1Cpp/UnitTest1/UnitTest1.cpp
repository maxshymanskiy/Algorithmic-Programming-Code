#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <string>
#include "../LR_11.1Cpp.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTestForCommaDash)
    {
    public:

        TEST_METHOD(TestCountCommaDash)
        {
            string line1 = "abc, -def";
            string line2 = "abc, def";
            string line3 = ", - , - , -";
            string line4 = "no matches here";

            Assert::AreEqual(1, countCommaDash(line1), L"Помилка у підрахунку для рядка 1");
            Assert::AreEqual(0, countCommaDash(line2), L"Помилка у підрахунку для рядка 2");
            Assert::AreEqual(3, countCommaDash(line3), L"Помилка у підрахунку для рядка 3");
            Assert::AreEqual(0, countCommaDash(line4), L"Помилка у підрахунку для рядка 4");
        }

        TEST_METHOD(TestCountCommaDashInFile)
        {
            string testFile = "testFile.txt";

            ofstream outFile(testFile);
            outFile << "abc, -def\n";
            outFile << "abc, def\n";
            outFile << ", - , - , -\n";
            outFile << "no matches here\n";
            outFile.close();

            int result = countCommaDashInFile(testFile);
            Assert::AreEqual(4, result, L"Помилка у підрахунку груп ', -' у файлі");

            remove(testFile.c_str());
        }

        TEST_METHOD(TestFileNotFound)
        {
            string testFile = "nonexistent.txt";
            int result = countCommaDashInFile(testFile);
            Assert::AreEqual(0, result, L"Помилка обробки файлу, якого не існує");
        }
    };
}
