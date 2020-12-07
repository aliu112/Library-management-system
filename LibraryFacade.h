#ifndef __library_facade_h__
#define __library_facade_h__
#include "OwedDebts.h"
#include "BookManager.h"
#include "Book.h"
#include "User.h"
#include <string>

using namespace std;

class LibraryFacade{
    protected:
        User user;
        OwedDebts payment;
        BookManager manager;      
        
    public:
        LibraryFacade();
        void borrowBook(string);
        void addBook(Book*,int );
        bool login(string,string);
        void createAccount(string,string);
        bool removeAccount(string,string);
        void displayBooks();
        void showCategories();
        void addCategory(Category*);
        bool removeCategory(string);
        void removeBook(string);
        void searchBook(string);
        int payDebt();
        int findCategory(string);
};

#endif //