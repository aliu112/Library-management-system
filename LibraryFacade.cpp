#include "LibraryFacade.h"
using namespace std;

//class User;
LibraryFacade::LibraryFacade(){
}

void LibraryFacade::borrowBook(string temp){
    Book* searchedBook = manager.findBook(temp);
    bool isAvaliable = searchedBook->isAvailable();
    if(isAvaliable)
    {
        searchedBook->setAvailable(false);
        cout << "Successfully checkouted\n";
    }
    else
    {
        cout << "Book is not availiable\n";
    }
    
    
}

bool LibraryFacade::login(string username, string password){
    bool temp = user.isValidLogin(username,password);
    /*
    if(temp == true)
    {
        cout << "temp is true\n";
    }
    */
    return temp;
}
void LibraryFacade::createAccount(string username, string password){
    user.addAccount(username,password);
//    cout << "In create account" << endl;
}
bool LibraryFacade::removeAccount(string username, string password){
    bool temp = user.removeAccount(username,password);
    return temp;
}
void LibraryFacade::displayBooks(){
    manager.printHierarchy();
}
void LibraryFacade::addCategory(Category* newCategory)
{
    manager.add(newCategory);
}
bool LibraryFacade::removeCategory(string name){
    bool temp = manager.remove(name);
    return temp;
}

void LibraryFacade::addBook(Book* temp,int numCategory){
    manager.addBook(temp, numCategory);
}
void LibraryFacade::removeBook(string title, int numCategory){
    manager.removeBook(title,numCategory);
}

void LibraryFacade::showCategories()
{
    manager.printCategories();
}
void LibraryFacade::searchBook(string temp){
    Book* searchedBook = manager.findBook(temp);
    searchedBook->print();
}
int LibraryFacade::payDebt()
{
    return payment.GetAmountOwed();
    
}
int LibraryFacade::findCategory(string name){
    int x = manager.findCategory(name);
    return x;
}