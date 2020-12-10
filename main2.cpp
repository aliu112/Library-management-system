#include <iostream>
#include <string>

#include "Media.h"
#include "Book.h"
#include "Category.h"
#include "BookManager.h"

using namespace std;
int main()
{
	// Create sample books and put them in categories
	Book* book1 = new Book("Jacob's Big Adventure", "John Doe", "2-12-2000", 270, 4451952310892);
	Book* book2 = new Book("How to Program in C++", "John Doe", "04-16-1989", 270, 1732630091782);
	Book* book3 = new Book("Satistics for Dummies", "John Doe", "04-16-1989", 270, 7388419576579);

	Category* category1 = new Category("Cool");
	category1->add(book1);

	Category* category2 = new Category("Rad");
	category2->add(book2);

	Category* category3 = new Category("Boring");
	category3->add(book3);

	// Display the hierarchy
	category1->print();
	category1->printBooks();
	category2->print();
	category2->printBooks();
	category3->print();
	category3->printBooks();
	std::cout << std::endl << "----------------" << std::endl;

	// Add another layer to the composition
	BookManager bookManager = BookManager();
	bookManager.add(category1);
	bookManager.add(category2);
	bookManager.add(category3);

	// Put the book into a different category
	bookManager.changeBookCategory("Jacob's Big Adventure", "Cool", "Rad");

	// Display the changed hierarchy
	category1->print();
	category1->printBooks();
	category2->print();
	category2->printBooks();
	category3->print();
	category3->printBooks();
	std::cout << std::endl << "----------------" << std::endl;

	std::cout << "Before: " << category1->getTitle() << std::endl;
	bookManager.editCategory("Cool", "Super Cool");
	std::cout << "After: " << category1->getTitle() << std::endl;
	bookManager.printCategories();

	// Print out the book manager
	bookManager.print();
	std::cout << std::endl << "0----------------0" << std::endl;
	bookManager.printHierarchy();

	bookManager.exportData("database.txt");

	// Showcase the data import function
	BookManager copiedManager = BookManager();
	copiedManager.importData("database.txt");
	std::cout << std::endl << "1----------------1" << std::endl;
	copiedManager.printHierarchy();
}