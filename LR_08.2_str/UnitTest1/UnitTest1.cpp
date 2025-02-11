#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_08.2_str.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(RemovesLeadingZeros)
        {
            Assert::AreEqual(string("123"), processString("00123"), L"Expected to remove leading zeros");
            Assert::AreEqual(string("1"), processString("00001"), L"Expected to reduce to a single 1");
            Assert::AreEqual(string("0"), processString("00000"), L"Expected to reduce multiple zeros to a single 0");
        }

        // Test for handling fractional parts by limiting to two digits
        TEST_METHOD(LimitsFractionalDigits)
        {
            Assert::AreEqual(string("123.45"), processString("123.456"), L"Expected to limit to two fractional digits");
            Assert::AreEqual(string("0.00"), processString("0.00123"), L"Expected to round to two fractional digits");
            Assert::AreEqual(string("12.34"), processString("12.345678"), L"Expected to truncate to two fractional digits");
        }

        // Test for handling both integer and fractional parts in mixed format
        TEST_METHOD(HandlesMixedIntegerAndFractionalParts)
        {
            Assert::AreEqual(string("123.45"), processString("000123.4500"), L"Expected correct handling of leading zeros and fractional digits");
            Assert::AreEqual(string("456.78"), processString("00456.7800"), L"Expected correct leading zero removal and fractional truncation");
            Assert::AreEqual(string("0.12"), processString("0.123"), L"Expected fractional digits to be limited");
        }

        // Test for input with no spaces, expecting the entire string to be processed
        TEST_METHOD(ProcessesUntilSpace)
        {
            Assert::AreEqual(string("123"), processString("123 hello world"), L"Expected processing only until the first space");
            Assert::AreEqual(string("1.23"), processString("01.23456 remaining text"), L"Expected to handle fractional part before space");
        }

        // Test for empty input
        TEST_METHOD(HandlesEmptyInput)
        {
            Assert::AreEqual(string(""), processString(""), L"Expected empty input to return an empty string");
        }

        // Test for input without any digits (should be unaffected)
        TEST_METHOD(NoDigitHandling)
        {
            Assert::AreEqual(string("abc.def"), processString("abc.def"), L"Expected non-digit input to remain unchanged");
        }
	};
}
