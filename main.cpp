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
        while (cout << "Press enter one of the following\n1. Login\n2. Create an account\n" && !(std::cin >> userInput)) 
        {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(); //discard input
        std::cout << "Invalid input; please re-enter.\n";
        }
 
        if (userInput == 1)
        {
            //Asks user for login
            //if login is invalid user is asked if they would like to try again
            //or if they would like to create an account
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
                   // cout << "correctly entered break if statement\n";
                    break;
                }
                while (cout << "Press 1 to retry\nPress 2 to create a new account\n" && !(std::cin >> userInput)) 
                {
                std::cin.clear(); //clear bad input flag
                std::cin.ignore(); //discard input
                std::cout << "Invalid input; please re-enter.\n";
                }
            }
            if(loggedIn == true)
            {
              break;
            }
        }
        
        if (userInput == 2)
        {
            cout << "Please enter a username: "; //takes userInputs for user and password
            string temp1 ="";                   // then uses LibraryFacade to create account
            cin >> temp1;
            cout << "Please enter a password: ";
            string temp2;
            cin >>temp2;
            test.createAccount(temp1,temp2);
            loggedIn = true;
            break;
        }
        
        if(userInput != 1 && userInput != 2)
        {
            cout << "ERROR\n";
        }
        
    }

    cout << "Welcome back\n";
    string userInput2;
    while(loggedIn){
        cout << "Please select the following options\n";
        cout << "0. Quit\n";
        cout << "1. \n";
        cin >> userInput2;
        // TODO Implement interface that prompts user to choose from adding
        //books, displaying books, borrowing books, etc...
        if(userInput2 == "0")
        {
            loggedIn= false;
        }
        
    }
    cout << "Successfully exited\n";

    

}