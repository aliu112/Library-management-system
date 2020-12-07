#include "User.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

User::User(){
    isAdmin = false;
    isLoggedIn = false;
    numInList=0;
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
        numInList++;
        //cout << "tempUser: " << tempUser << endl;
        //cout << "passUser: " << tempPass << endl;
        if(tempUser ==username && tempPass ==  password)
        {
           // cout << "IT WORKED\n";
           int random = GetNumInList();
            userFile.close();
            passFile.close();
            return true;
        }
    }

    userFile.close();
    passFile.close();
    cout << "No such login found\n";
    numInList=0;
    return false;
}

void User::addAccount(string username, string password){
    // check to see if the passed in username and password already exist
    //if it does not skip writing to file
    int flag =0;
    string tempUser;
    string tempPass;

    ifstream userFile2;
    ifstream passFile2;
    userFile2.open("usernameList.txt");
    passFile2.open("passwordList.txt");
    while(!userFile2.eof())
    {
        userFile2 >> tempUser;
        passFile2 >> tempPass;
        if(tempUser == username && tempPass == password)
        {
            flag =1;
            cout << "Account already exists\n Logging you in now\n\n";
        }
    
    }
    userFile2.close();
    passFile2.close();

    if(flag ==0){
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
        
        cout << "Account has successfully created\n\n";
    }
}

bool User::removeAccount(string username, string password){
    int flag=0;
    string tempUser;
    string tempPass;
    ifstream userFile;
    ifstream passFile;
    userFile.open("usernameList.txt");
    passFile.open("passwordList.txt");

    ofstream userFile2;
    ofstream passFile2;
    userFile2.open("usernameListTemp.txt",std::ofstream::app);
    passFile2.open("passwordListTemp.txt",std::ofstream::app);

    while(!userFile.eof())
    {
        userFile >> tempUser;
        passFile >> tempPass;
        if(tempUser == username && tempPass == password)
        {
            flag =1;
            
        }
        if(tempUser != username && tempPass != password)
        {
            userFile2 << tempUser << endl;
            passFile2 << tempPass << endl;
        }
    
    }

    if(flag ==1)
    {
        cout << "Account found and removed\n";
    }
    if(flag == 0)
    {
        cout << "Account not found\n";
    }

    userFile.close();
    passFile.close();
    userFile2.close();
    passFile2.close();

    int temp10=0;
    remove( "usernameList.txt" );
    remove( "passwordList.txt" );

    char userOldName[] ="usernameListTemp.txt";
    char userNewName[] ="usernameList.txt";

    char passOldName[] ="passwordListTemp.txt";
    char passNewName[] ="passwordList.txt";

    rename(userOldName,userNewName);
    rename(passOldName,passNewName );
    
    if(flag == 0)
    {
        return 0;
    }
    else 
    {
        return 1;
    }


}

bool User::getIsLoggedIn()
{
    return isLoggedIn;
}

bool User::getIsAdmin()
{
    return isAdmin;
}

int User::GetNumInList(){
    int temp2 = numInList;
    ofstream temp;
    temp.open("NumInList.txt");
    temp << numInList;
    temp.close();
    numInList =0;
    
    ifstream temp1;
    temp1.open("NumInList.txt");
    temp1 >> temp2;
    temp1.close();
    return temp2;
}