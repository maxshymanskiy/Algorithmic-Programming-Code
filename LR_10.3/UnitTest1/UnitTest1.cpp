#include "pch.h"
#include "CppUnitTest.h"
#include "../LR_10.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestSortBills)
        {
            // Тестуємо сортування платежів
            int N = 3;
            Bill* bills = new Bill[N];

            bills[0].payer_account = "UA5555555555";
            bills[0].recipient_account = "UA9988776655";
            bills[0].amount = 3000.0;

            bills[1].payer_account = "UA1234567890";
            bills[1].recipient_account = "UA0987654321";
            bills[1].amount = 2500.0;

            bills[2].payer_account = "UA1234567890";
            bills[2].recipient_account = "UA1122334455";
            bills[2].amount = 1500.0;

            SortBills(bills, N);

            // Після сортування перші два елементи повинні мати рахунок "UA1234567890"
            Assert::AreEqual(std::string("UA1234567890"), bills[0].payer_account);
            Assert::AreEqual(std::string("UA1234567890"), bills[1].payer_account);
            Assert::AreEqual(std::string("UA5555555555"), bills[2].payer_account);

            delete[] bills;
        }
        TEST_METHOD(TestGetAmountByPayer)
        {
            // Тестуємо отримання суми за платником
            int N = 3;
            Bill* bills = new Bill[N];

            bills[0].payer_account = "UA1234567890";
            bills[0].recipient_account = "UA0987654321";
            bills[0].amount = 2500.0;

            bills[1].payer_account = "UA1234567890";
            bills[1].recipient_account = "UA1122334455";
            bills[1].amount = 1500.0;

            bills[2].payer_account = "UA5555555555";
            bills[2].recipient_account = "UA9988776655";
            bills[2].amount = 3000.0;

            double amount = GetAmountByPayer(bills, N, "UA1234567890");
            Assert::AreEqual(4000.0, amount);

            amount = GetAmountByPayer(bills, N, "UA0000000000");
            Assert::AreEqual(-1.0, amount);

            delete[] bills;
        }
	};
}
