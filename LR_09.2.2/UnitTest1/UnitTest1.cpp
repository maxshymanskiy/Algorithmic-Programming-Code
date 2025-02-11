#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <sstream>
#include <string>
#include "../LR_09.2.2.cpp"
#define _CRT_SECURE_NO_WARNINGS

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
#ifdef USE_NUM_ARRAY
            int testArray[SIZE];
            Assert::IsTrue(typeid(testArray[0]) == typeid(int), L"Масив повинен бути типу int.");
#else
            char testArray[SIZE];
            Assert::IsTrue(typeid(testArray[0]) == typeid(char), L"Масив повинен бути типу char.");
#endif
        }
    };
}