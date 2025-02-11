#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../LR_11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForCommaDash
{
    TEST_CLASS(UnitTestForCommaDash)
    {
    public:
        TEST_METHOD(TestCountCommaDash)
        {
            const char* line1 = "abc, -def";
            const char* line2 = "abc, def";
            const char* line3 = ", - , - , -";
            const char* line4 = "no matches here";

            Assert::AreEqual(1, countCommaDash(line1), L"Помилка у підрахунку для рядка 1");
            Assert::AreEqual(0, countCommaDash(line2), L"Помилка у підрахунку для рядка 2");
            Assert::AreEqual(3, countCommaDash(line3), L"Помилка у підрахунку для рядка 3");
            Assert::AreEqual(0, countCommaDash(line4), L"Помилка у підрахунку для рядка 4");
        }

        TEST_METHOD(TestCountCommaDashInFile)
        {
            const char* testFile = "test.txt";

            std::ofstream outFile(testFile);
            outFile << "abc, -def\n";
            outFile << "abc, def\n";
            outFile << ", - , - , -\n";
            outFile << "no matches here\n";
            outFile.close();

            int result = countCommaDashInFile(testFile);
            Assert::AreEqual(4, result, L"Помилка у підрахунку груп ', -' у файлі");

            remove(testFile);
        }

        TEST_METHOD(TestFileNotFound)
        {
            const char* testFile = "nonexistent.txt";
            int result = countCommaDashInFile(testFile);
            Assert::AreEqual(0, result, L"Помилка обробки файлу, якого не існує");
        }
    };
}
