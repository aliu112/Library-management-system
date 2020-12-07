#include <iostream>
#include "LibraryFacade.h"
#include "User.h"
#include "owedDebts.h"
#include "Media.h"
#include "Book.h"
#include "Category.h"
#include "BookManager.h"

#include <string>

using namespace std;
int main()
{
    LibraryFacade test = LibraryFacade();

    // Create sample books and put them in categories
	Book* book1 = new Book("Jacob's Big Adventure", "John Doe", "04-16-1989", 270, 4451952310892);
	Book* book2 = new Book("How to Program in C++", "John Doe", "04-16-1989", 270, 1732630091782);
	Book* book3 = new Book("Satistics for Dummies", "John Doe", "04-16-1989", 270, 7388419576579);

	Category* category1 = new Category("Cool");
	category1->add(book1);

	Category* category2 = new Category("Rad");
	category2->add(book2);

	Category* category3 = new Category("Boring");
	category3->add(book3);

	// Add another layer to the composition
	//BookManager mange = BookManager();
	test.addCategory(category1);
	test.addCategory(category2);
	test.addCategory(category3);
    //mange.printHierarchy();
    



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
            cout << "Now please login\n";
            while(loggedIn != true)
            {
                cout << "Please enter your username: ";
                cin >> temp1;
                cout << "Please enter your password: ";
                cin >>temp2;
                loggedIn = test.login(temp1,temp2);
                if(loggedIn ==false)
                {
                    cout << "Invalid login, please use the login your just created\n";
                }
                
            }
            if(loggedIn == true)
            {
                break;
            }
            
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
        cout << "1. Borrow a book\n";
        cout << "2. Display a book's information\n";
        cout << "3. payDebt\n";
        cout << "4. Display all avaliable books\n";
        cout << "5. Delete account\n";
        
        cin >> userInput2;
        // TODO Implement interface that prompts user to choose from adding
        //books, displaying books, borrowing books, etc...
        if(userInput2 == "0")
        {
            loggedIn= false;
        }
        else if(userInput2 =="1")
        {

        }
        else if(userInput2 =="2")
        {
            
        }
        else if(userInput2 =="3")
        {
            
        }
        else if(userInput2 =="4")
        {
            test.displayBooks();
        }
        else if(userInput2 =="5")
        {
            cout << "Reenter credentials to confirm deletion\n";
            cout << "Enter username: ";
            string user;
            string pass;
            cin >> user;
            cout << "Enter password: ";
            cin >> pass;
            bool tempHolder = test.removeAccount(user,pass);
            if(tempHolder == 1)
            {
                break;
            }
            
        }
        else
        {
            cout << "Invalid input\n\n";
        }
        

        
    }
    cout << "Successfully exited\n";

    

}