#ifndef __owed_debts_h__
#define __owed_debts_h__

#include <iostream>
using namespace std;


class OwedDebts{
    private:
        int amount;
    public:
        OwedDebts();
        void addPayment(int num);
        void removePayment();
        int GetAmountOwed();
};

#endif