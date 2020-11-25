#include <iostream>
#include <string>

#include "Media.h"
#include "Book.h"
#include "Category.h"
#include "BookManager.h"

using namespace std;
int main()
{
	Book* book1 = new Book("Jacob's Big Adventure", "John Doe", "04-16-1989", 270, 4451952310892);

	Category* category1 = new Category("Cool");
	Category* category2 = new Category("Rad");
	category1->add(book1);

	category1->print();
	category1->printBooks();
	category2->print();
	category2->printBooks();
	std::cout << std::endl << "----------------" << std::endl;
	BookManager bookManager = BookManager();
	bookManager.add(category1);
	bookManager.add(category2);

	bookManager.changeBookCategory("Jacob's Big Adventure", "Cool", "Rad");

	category1->print();
	category1->printBooks();
	category2->print();
	category2->printBooks();

	bookManager.editCategory("Cool", "Super Cool");
	bookManager.printCategories();

	bookManager.print();
}