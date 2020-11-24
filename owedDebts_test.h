#include "gtest/gtest.h"
#include "User.h"
#include "owedDebts.h"

TEST(owedDebtsTests, addpayment)
{
    User temp;
    temp.addAccount("hello","world");
    EXPECT_EQ(temp.isValidLogin("hello","world"), true);
    OwedDebts temp2;
    temp2.addPayment(3);
    EXPECT_EQ(temp2.GetAmountOwed(),3);
    temp.addAccount("hello2","world2");
    EXPECT_EQ(temp.isValidLogin("hello2","world2"), true);
    temp2.addPayment(5);
    EXPECT_EQ(temp2.GetAmountOwed(),5);
    temp.addAccount("hello3","world3");
    EXPECT_EQ(temp.isValidLogin("hello3","world3"), true);
    temp2.addPayment(10);
    EXPECT_EQ(temp2.GetAmountOwed(),10);
}

TEST(owedDebtsTests, addpayment2)
{
    User temp;
    temp.isValidLogin("aliu112", "password");
    OwedDebts temp2;
    temp2.addPayment(88);
    EXPECT_EQ(temp2.GetAmountOwed(),88);
}

