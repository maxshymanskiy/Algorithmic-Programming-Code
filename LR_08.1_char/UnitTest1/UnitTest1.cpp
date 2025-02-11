#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_08.1_char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(CountTests)
    {
    public:
        TEST_METHOD(TestCountWithNoMatches)
        {
            char str[] = "Hello world!";
            int result = Count(str);
            Assert::AreEqual(0, result, L"Expected 0 groups of ', -'");
        }

        TEST_METHOD(TestCountWithOneMatch)
        {
            char str[] = "Hello, - world!";
            int result = Count(str);
            Assert::AreEqual(1, result, L"Expected 1 group of ', -'");
        }

        TEST_METHOD(TestCountWithMultipleMatches)
        {
            char str[] = "Hello, - world, - test, - end";
            int result = Count(str);
            Assert::AreEqual(3, result, L"Expected 3 groups of ', -'");
        }

        TEST_METHOD(TestCountWithEdgeCase)
        {
            char str[] = ", -";
            int result = Count(str);
            Assert::AreEqual(1, result, L"Expected 1 group of ', -'");
        }
    };

    TEST_CLASS(ChangeTests)
    {
    public:
        TEST_METHOD(TestChangeWithNoMatches)
        {
            char str[] = "Hello world!";
            char expected[] = "Hello world!";
            char* result = Change(str);
            Assert::AreEqual(expected, result, L"Expected no changes");
            delete[] result;
        }

        TEST_METHOD(TestChangeWithOneMatch)
        {
            char str[] = "Hello, - world!";
            char expected[] = "Hello** world!";
            char* result = Change(str);
            Assert::AreEqual(expected, result, L"Expected ', -' to be replaced with '**'");
            delete[] result;
        }

        TEST_METHOD(TestChangeWithMultipleMatches)
        {
            char str[] = "Hello, - world, - test, - end";
            char expected[] = "Hello** world** test** end";
            char* result = Change(str);
            Assert::AreEqual(expected, result, L"Expected multiple ', -' patterns to be replaced with '**'");
            delete[] result;
        }

        TEST_METHOD(TestChangeWithEdgeCase)
        {
            char str[] = ", -";
            char expected[] = "**";
            char* result = Change(str);
            Assert::AreEqual(expected, result, L"Expected single ', -' pattern to be replaced with '**'");
            delete[] result;
        }
    };
}
