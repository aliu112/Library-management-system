#ifndef __library_facade_h__
#define __library_facade_h__
#include "OwedDebts.h"
#include "User.h"
#include <string>

using namespace std;

class LibraryFacade{
    protected:
        User user;
        OwedDebts payment;      
        
    public:
        LibraryFacade();
        void borrowBook();
        void displayBookInfo();
        void addBook();
        bool login(string,string);
        void createAccount(string,string);
        void removeAccount(string,string);
        void removeBook();
        void reserveBook();
        void payDebt();

};

#endif //