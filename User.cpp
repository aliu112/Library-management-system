#include "User.h"
#include <string>
#include <iostream>
using namespace std;

User::User(){
    isAdmin = false;
    isLoggedIn = false;
}

bool User::isValidLogin(string username, string password){
    for(unsigned int i=0; i< userNameList.size(); i++)
    {
        if(userNameList.at(i)==username && passwordList.at(i) == password)
        {
            cout << "Login Successful\n";
            return true;
        }
    }
    cout << "No such login found\n";
    return false;
}

void User::addAccount(string username, string password){
    userNameList.push_back(username);
    passwordList.push_back(password);
    cout << "Account has successfully created and you have been logged in\n";
}

void User::removeAccount(string username, string password){
    int flag=0;
     for(unsigned int i=0; i< userNameList.size(); i++)
    {
        if(userNameList.at(i)==username && passwordList.at(i) == password)
        {
            userNameList.erase(userNameList.begin()+i);
            passwordList.erase(passwordList.begin()+i);
            flag=1;
        }
    }
    
    if(flag ==0){
        cout << "Error no account with such credentials found\n";
    }
}

bool User::getIsLoggedIn()
{
    return isLoggedIn;
}