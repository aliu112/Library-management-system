#include <iostream>
#include <string>

#include "Media.h"
#include "Book.h"
#include "Category.h"

using namespace std;
int main()
{
	Book* book1 = new Book("Jacob's Big Adventure", "John Doe", "04-16-1989", 270, 4451952310892);
	Book* book2 = new Book("How to Program in C++", "John Doe", "04-16-1989", 270, 1732630091782);
	Book* book3 = new Book("Satistics for Dummies", "John Doe", "04-16-1989", 270, 7388419576579);

	Category* category1 = new Category();
	category1->add(book1);
	category1->add(book2);
	category1->add(book3);
	category1->printBooks();
	category1->remove(7388419576579);
	std::cout << std::endl << "----------------" << std::endl;
	category1->printBooks();
}