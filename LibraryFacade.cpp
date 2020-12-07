#include "LibraryFacade.h"
using namespace std;

//class User;
LibraryFacade::LibraryFacade(){
}

void LibraryFacade::borrowBook(){
//TODO
}
void LibraryFacade::displayBookInfo(){

}
void LibraryFacade::addBook(){
//TODO
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
void LibraryFacade::removeBook(){
//TODO
}
void LibraryFacade::reserveBook(){
//TODO
}
void LibraryFacade::payDebt(){
    
}