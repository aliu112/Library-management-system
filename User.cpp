#include "User.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

User::User(){
    isAdmin = false;
    isLoggedIn = false;
}

bool User::isValidLogin(string username, string password){
    ifstream userFile;
    ifstream passFile;
    userFile.open("usernameList.txt");
    passFile.open("passwordList.txt");

    string tempUser;
    string tempPass;

    while(!userFile.eof())
    {
       // cout << "ENTER WHILE LOOP \n";
        userFile >> tempUser;
        passFile >> tempPass;
        //cout << "tempUser: " << tempUser << endl;
        //cout << "passUser: " << tempPass << endl;
        if(tempUser ==username && tempPass ==  password)
        {
           // cout << "IT WORKED\n";
            userFile.close();
            passFile.close();
            return true;
        }
    }

    userFile.close();
    passFile.close();
    cout << "No such login found\n";
    return false;
}

void User::addAccount(string username, string password){
    ofstream userFile;
    ofstream passFile;
    userFile.open("usernameList.txt",std::ofstream::app);
    passFile.open("passwordList.txt",std::ofstream::app);

    if(userFile.is_open())
    {
        userFile << username << endl;
    }
    if(passFile .is_open())
    {
        passFile << password << endl;
    }
    
    userFile.close();
    passFile.close();
    
    cout << "Account has successfully created and you have been logged in\n";
}

void User::removeAccount(string username, string password){
   /* int flag=0;
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
    */
}

bool User::getIsLoggedIn()
{
    return isLoggedIn;
}

bool User::getIsAdmin()
{
    return isAdmin;
}