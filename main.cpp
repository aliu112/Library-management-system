#include <iostream>
#include "LibraryFacade.h"
#include "User.h"
#include <string>

using namespace std;
int main()
{
    LibraryFacade test;
    int userInput=0;
    bool loggedIn= false;
    cout << "Welcome to the Library Management Sysytem\n";
    while(1)
     {
        while (cout << "Press enter one of the following\n1. Login\n2. Create an account\n" && !(std::cin >> userInput)) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(); //discard input
        std::cout << "Invalid input; please re-enter.\n";
    }
        //cout << "Press enter one of the following\n";
        //cout << "1. Login\n";
        //cout << "2. Create an account\n";
        //cin >> userInput;
        if (userInput == 1)
        {
            while(userInput ==1)
            {
                string temp1;
                string temp2;
                cout << "Please enter your username: ";
                cin >> temp1;
                cout << "Please enter your password: ";
                cin >> temp2;
                loggedIn = test.login(temp1, temp2);
                if(loggedIn == true)
                {
                    break;
                }
                
            }
        }
        else if (userInput == 2)
        {
            cout << "Please enter a username: "; //takes userInputs for user and password
            string temp1 ="";                   // then uses LibraryFacade to create account
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
  //  cout << "Successfully exited\n";

    

}