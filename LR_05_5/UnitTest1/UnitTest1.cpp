#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_05_5.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Test case for base case n = 1
        TEST_METHOD(TestBaseCase)
        {
            int depth = 0;
            double result = a_n(1, 1, depth);

            Assert::AreEqual(1.0, result, L"Base case failed");
            Assert::AreEqual(1, depth, L"Depth for base case is incorrect");
        }

     
    };
}