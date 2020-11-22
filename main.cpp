#include <iostream>
#include "LibraryFacade.h"
#include "User.h"
#include <string>

using namespace std;
int main()
{
    LibraryFacade test;
    int userInput=0;
    cout << "Welcome to the Library Management Sysytem\n";
    while(1){
        cout << "Press enter one of the following\n";
        cout << "1. Login\n";
        cout << "2. Create an account\n";
        cin >> userInput;
        if (userInput == 1){

           break;
        }
        else if (userInput == 2)
        {
            cout << "Please enter a username: ";
            string temp1 ="";
            cin >> temp1;
            cout << "Please enter a password: ";
            string temp2;
            cin >>temp2;
            test.createAccount(temp1,temp2);
            break;
        }
        else
        {
            cout << "ERROR\n";
        }
        
    }
    

}