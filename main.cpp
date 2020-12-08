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
    //hard code books into the system
    LibraryFacade test = LibraryFacade();

    // Create sample books and put them in categories
	Book* book1 = new Book("To Kill a Mockingbird", "Harper Lee", "07-11-1960", 281, 9780446310789);
	Book* book2 = new Book("The Great Gatsby", "F. Scott Fitzgerald", "04-10-1925", 218, 9780743273565);
	Book* book3 = new Book("The Catcher in the Rye", "J.D. Salinger", "07-16-1951", 234, 9780316769488);
	Book* book4 = new Book("The Immortal Life of Henrietta Lacks", "Rebecca Skloot", "02-02-2010", 381, 9781400052172);
	Book* book5 = new Book("Educated", "Tara Westover", "02-20-2018", 352, 9780399590504);
	Book* book6 = new Book("How to Win Friends and Influence People", "Dale Carnegie", "00-10-1936", 270, 9780671027032);
	Book* book7 = new Book("A Promised Land", "Barack Obama", "11-17-2020", 768, 9781524763169);
	Book* book8 = new Book("Becoming", "Michelle Obama", "11-13-2018", 448, 9781524763138);
	Book* book9 = new Book("Greenlights", "Matthew McConaughey", "10-20-2020", 304, 9780593139134);
	Book* book10 = new Book("HumanKind", "Yuval Noah Harari", "00-00-2011", 443, 9780062316097);
	Book* book11 = new Book("A People's History of the Unites States", "Howard Zim", "00-00-1980", 729, 9780060838652);
	Book* book12 = new Book("Guns, Germs, and Steel", "Jared Diamond", "00-03-1997", 480, 9780393317558);


	Category* category1 = new Category("Fiction");
	category1->add(book1);
    category1->add(book2);
    category1->add(book3);

	Category* category2 = new Category("Non-fiction");
	category2->add(book4);
    category2->add(book5);
    category2->add(book6);

	Category* category3 = new Category("Biographies");
	category3->add(book7);
    category3->add(book8);
    category3->add(book9);

    Category* category4 = new Category("History");
	category4->add(book10);
    category4->add(book11);
    category4->add(book12);

	// Add another layer to the composition
	//BookManager mange = BookManager();
	test.addCategory(category1);
	test.addCategory(category2);
	test.addCategory(category3);
    test.addCategory(category4); 
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
    //User Interface, User will use this code to interact w/ the library system
    while(loggedIn){
        cout << "Please select the following options\n";
        cout << "0. Quit\n";
        cout << "1. Borrow a book\n";
        cout << "2. Display a book's information\n";
        cout << "3. Show debt\n";
        cout << "4. Display all books w/ info\n";
        cout << "5. Display all book categories\n";
        cout << "6. Add book\n";
        cout << "7. Remove book\n";
        cout << "8. Add Category\n";
        cout << "9. Remove Category\n";
        cout << "10. Delete account\n";
        
        cin >> userInput2;

        //exits loop
        if(userInput2 == "0")
        {
            loggedIn= false;
        }
        //User inputs a title that they wish to checkout
        //If the book is availiable then it'll be checked out
        //if not system will let them know it's not available
        else if(userInput2 =="1")
        {
            string bookName ="";
            cout << "Enter the book's name (Caps sensitive): ";
            cin.ignore();
            getline(cin,bookName);
            test.borrowBook(bookName);
        }
        //Displays a book's information
        //Initiated by userInput
        else if(userInput2 =="2")
        {
            string bookName="";
            cout << "Enter the book's name (Caps sensitive): ";
            cin.ignore();
            getline(cin,bookName);
            test.searchBook(bookName);   
        }
        //Checks user's account and displays if they owe any money
        else if(userInput2 =="3")
        {
           int amount = test.payDebt();
           cout << "You owe $" << amount << endl;
        }
        //displays all books in the system
        else if(userInput2 =="4")
        {
            test.displayBooks();
        }
        //displays all categories of books the library has
        else if(userInput2 =="5")
        {
            test.showCategories();
        }
        //adds book
        else if(userInput2 =="6")
        {
           int isFound = -1;
            while(isFound == -1)
            {
                string CategoryName="";
                cout << "Enter the name of the category you wish to put the book under: ";
                cin >> CategoryName;
                isFound = test.findCategory(CategoryName);
                if(isFound != -1)
                {
                    cout << "Category found\n";
                }
                else
                {
                    cout << "Category not found\nPlease";
                }
            }
            string title;
            string author;
            string publishDate;
            int numPages= 0;
            uint64_t numIsbn13;

            cout << "Enter title: ";
            cin.ignore();
            getline(cin,title);
            cout << "Enter author name: ";
            cin.ignore();
            getline(cin,author);
            cout << "Enter publish date (dd-mm-year): ";
            cin >> publishDate;
            cout << "Enter the number of pages: ";
            cin >> numPages;
            cout << "Enter the 13 number long isbn13: ";
            cin >> numIsbn13;
            Book* tempBook = new Book(title,author,publishDate,numPages,numIsbn13);

            test.addBook(tempBook, isFound);
            cout << "Book successfully added\n";
         }
        //removes book
        else if(userInput2 =="7")
        {
           int isFound = -1;
            while(isFound == -1)
            {
                string CategoryName="";
                cout << "Enter the name of the category the book is under: ";
                cin >> CategoryName;
                isFound = test.findCategory(CategoryName);
                if(isFound != -1)
                {
                    cout << "Category found\n";
                }
                else
                {
                    cout << "Category not found\nPlease";
                }
            }
            string title;
            cout << "Enter book title: ";
            cin >> title;
            test.removeBook(title,isFound);
        }
        //adds category
        else if(userInput2 =="8")
        {
           string categoryName="";
           cout << "Please enter a Category name: ";
           cin >> categoryName;
           Category* tempCategory = new Category(categoryName);
           test.addCategory(tempCategory);
        }
        //removes category only if found
        else if(userInput2 =="9")
        {
            string categoryName="";
           cout << "Please enter a Category name for removal: ";
           cin >> categoryName;
           bool wasRemoved = test.removeCategory(categoryName);
           if (wasRemoved)
           {
               cout << "Successfully removed\n";
           }
           else 
           {
               cout << "Could not find category\n";
           }
           
        }
        //removes an account from the system and logs them out 
        else if(userInput2 =="10")
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
    cout << "Successfully exited\nThank you for using Library Management System\n";

    

}