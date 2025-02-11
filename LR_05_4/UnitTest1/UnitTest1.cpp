#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_05_4.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Arrange
			int K = 1;
			int N = 5;
			double expected = S0(K, N);

			// Act & Assert for each function
			Assert::AreEqual(expected, S0(K, N), 0.00001, L"S0 failed.");
			Assert::AreEqual(expected, S1(K, N, K), 0.00001, L"S1 failed.");
			Assert::AreEqual(expected, S2(K, N, N), 0.00001, L"S2 failed.");
			Assert::AreEqual(expected, S3(K, N, K, 0), 0.00001, L"S3 failed.");
			Assert::AreEqual(expected, S4(K, N, N, 0), 0.00001, L"S4 failed.");
		}
	};
}
