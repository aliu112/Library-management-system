#include "LibraryFacade.h"
using namespace std;

class User;
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
    return temp;
}
void LibraryFacade::createAccount(string username, string password){
    user.addAccount(username,password);
//    cout << "In create account" << endl;
}
void LibraryFacade::removeAccount(string username, string password){
    user.removeAccount(username,password);
}
void LibraryFacade::removeBook(){
//TODO
}
void LibraryFacade::reserveBook(){
//TODO
}
void LibraryFacade::payDebt(){
//TODO
}