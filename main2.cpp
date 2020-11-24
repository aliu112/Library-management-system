#include <iostream>
#include <string>

#include "Media.h"
#include "Book.h"
#include "Category.h"

using namespace std;
int main()
{
	Book* book1 = new Book("Hello World");
	Book* book2 = new Book("Test");
	Book* book3 = new Book("Jacob's Big Adventure");

	Category* category1 = new Category();
	category1->add(book1);
	category1->add(book2);
	category1->add(book3);
	category1->print();
	category1->printBooks();

	std::cout << "----------------" << std::endl << std::endl;

	category1->remove("Test");
	category1->printBooks();
}