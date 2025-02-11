#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_08.1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCount_NoPattern)
        {
            char str[] = "Hello, world!";
            Assert::AreEqual(0, Count(str), L"Expected count to be 0 as no pattern ', -' exists");
        }

        TEST_METHOD(TestCount_MultiplePatterns)
        {
            char str[] = "Hello,- world,b- test,n- end";
            Assert::AreEqual(2, Count(str), L"Expected count to be 3 as there are three ', -' patterns");
        }

        TEST_METHOD(TestChange_NoPattern)
        {
            char str[] = "Hello, world!";
            char* result = Change(str);
            Assert::AreEqual("Hello, world!", result, L"Expected no change as no ', -' pattern exists");
            delete[] result;
        }

        TEST_METHOD(TestChange_MultiplePatterns)
        {
            char str[] = "Hello, ,- world, - test, - end";
            char* result = Change(str);
            Assert::AreEqual("Hello, ,- world** test** end", result, L"Expected all ', -' patterns to be replaced with '**'");
            delete[] result;
        }
	};
}
