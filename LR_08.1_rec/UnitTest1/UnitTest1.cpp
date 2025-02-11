#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_08.1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{
    TEST_CLASS(CountTests)
    {
    public:
        TEST_METHOD(TestCountWithNoMatches)
        {
            char str[] = "Hello world!";
            int result = Count(str, 1);
            Assert::AreEqual(0, result, L"Expected 0 groups of ', -'");
        }

        TEST_METHOD(TestCountWithOneMatch)
        {
            char str[] = "Hello, - world!";
            int result = Count(str, 1);
            Assert::AreEqual(1, result, L"Expected 1 group of ', -'");
        }

        TEST_METHOD(TestCountWithMultipleMatches)
        {
            char str[] = "Hello, - world, - test, - end";
            int result = Count(str, 1);
            Assert::AreEqual(3, result, L"Expected 3 groups of ', -'");
        }

        TEST_METHOD(TestCountWithEdgeCase)
        {
            char str[] = ", -";
            int result = Count(str, 1);
            Assert::AreEqual(1, result, L"Expected 1 group of ', -'");
        }
    };

    TEST_CLASS(ChangeTests)
    {
    public:
        TEST_METHOD(TestChangeWithNoMatches)
        {
            char str[] = "Hello world!";
            char dest[50] = "";
            Change(dest, str, dest, 0);
            Assert::AreEqual("Hello world!", dest, L"Expected no changes");
        }

        TEST_METHOD(TestChangeWithOneMatch)
        {
            char str[] = "Hello, - world!";
            char dest[50] = "";
            Change(dest, str, dest, 0);
            Assert::AreEqual("Hello** world!", dest, L"Expected ', -' to be replaced with '**'");
        }

        TEST_METHOD(TestChangeWithMultipleMatches)
        {
            char str[] = "Hello, - world, - test, - end";
            char dest[100] = "";
            Change(dest, str, dest, 0);
            Assert::AreEqual("Hello** world** test** end", dest, L"Expected multiple ', -' patterns to be replaced with '**'");
        }

        TEST_METHOD(TestChangeWithEdgeCase)
        {
            char str[] = ", -";
            char dest[10] = "";
            Change(dest, str, dest, 0);
            Assert::AreEqual("**", dest, L"Expected single ', -' pattern to be replaced with '**'");
        }
    };
}
