#ifndef __library_facade_h__
#define __library_facade_h__
#include "User.h"
#include <string>

using namespace std;

class LibraryFacade{
    private:
        User user;

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