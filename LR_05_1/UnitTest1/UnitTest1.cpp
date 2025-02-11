#include "pch.h"
#include "CppUnitTest.h"
#include ""


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            double t;
            t = h(3, 1);
            Assert::AreEqual(t, -0.21622776601683796);
        }
    };
}
