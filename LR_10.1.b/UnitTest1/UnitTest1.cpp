#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_10.1.b.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            Student students[3] = {
                { "Ivanenko", 2, KN, 3, 4, 5 },
                { "Petrenko", 3, INF, 2, 3, 4 },
                { "Sydorenko", 1, ME, 5, 5, 5 }
            };
            int N = sizeof(students) / sizeof(Student);

            int expectedIndex = 1;
            int actualIndex = FindStudentWithMinAverage(students, N);

            Assert::AreEqual(expectedIndex, actualIndex);
        }
    };
}
