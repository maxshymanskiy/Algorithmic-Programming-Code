#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_10.2.a.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestFindStudentWithMinAverage)
        {
            int N = 3;
            Student* s = new Student[N];

            s[0] = { "Ivanenko", 2, RI, 3, 4, 5 };
            s[1] = { "Petrenko", 3, IK, 2, 3, 4 };
            s[2] = { "Sydorenko", 1, SSHI, 5, 5, 5 };

            int minIndex = FindStudentWithMinAverage(s, N);
            Assert::AreEqual(1, minIndex); 

            delete[] s;
        }

        TEST_METHOD(TestSortPhysical)
        {
            int N = 3;
            Student* s = new Student[N];

            s[0] = { "Ivanenko", 2, RI, 3, 4, 5 }; // avg = 4.0
            s[1] = { "Petrenko", 3, IK, 2, 3, 4 }; // avg = 3.0
            s[2] = { "Sydorenko", 1, SSHI, 5, 5, 5 }; // avg = 5.0

            SortPhysical(s, N);

            Assert::AreEqual(std::string("Petrenko"), s[0].prizv);
            Assert::AreEqual(std::string("Ivanenko"), s[1].prizv);
            Assert::AreEqual(std::string("Sydorenko"), s[2].prizv);

            delete[] s;
        }
	};
}
