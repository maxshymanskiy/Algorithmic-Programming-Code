#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_08.1_str.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(CountTests)
    {
    public:
        TEST_METHOD(TestCountWithNoMatches)
        {
            string str = "Hello world!";
            int result = Count(str);
            Assert::AreEqual(0, result, L"Expected 0 groups of ', -'");
        }

        TEST_METHOD(TestCountWithOneMatch)
        {
            string str = "Hello, - world!";
            int result = Count(str);
            Assert::AreEqual(1, result, L"Expected 1 group of ', -'");
        }

        TEST_METHOD(TestCountWithMultipleMatches)
        {
            string str = "Hello, - world, - test, - end";
            int result = Count(str);
            Assert::AreEqual(3, result, L"Expected 3 groups of ', -'");
        }

        TEST_METHOD(TestCountWithEdgeCase)
        {
            string str = ", -";
            int result = Count(str);
            Assert::AreEqual(1, result, L"Expected 1 group of ', -'");
        }
    };

    TEST_CLASS(ChangeTests)
    {
    public:
        TEST_METHOD(TestChangeWithNoMatches)
        {
            string str = "Hello world!";
            string result = Change(str);
            Assert::AreEqual("Hello world!", result.c_str(), L"Expected no changes");
        }

        TEST_METHOD(TestChangeWithOneMatch)
        {
            string str = "Hello, - world!";
            string result = Change(str);
            Assert::AreEqual("Hello** world!", result.c_str(), L"Expected ', -' to be replaced with '**'");
        }

        TEST_METHOD(TestChangeWithMultipleMatches)
        {
            string str = "Hello, - world, - test, - end";
            string result = Change(str);
            Assert::AreEqual("Hello** world** test** end", result.c_str(), L"Expected multiple ', -' patterns to be replaced with '**'");
        }

        TEST_METHOD(TestChangeWithEdgeCase)
        {
            string str = ", -";
            string result = Change(str);
            Assert::AreEqual("**", result.c_str(), L"Expected single ', -' pattern to be replaced with '**'");
        }
    };
}
