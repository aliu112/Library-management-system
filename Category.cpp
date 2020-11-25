#include "Category.h"
#include <iostream>

Category::Category() : Media() {}

Category::Category(string title) : Media(title) {}

void Category::print() {
	std::cout << "Category: " << std::endl;
}

void Category::printBooks() {
	for (Book* book : this->list)
		book->print();
}

int Category::bookCount() {
	return this->list.size();
}

Book* Category::findBook(string title) {
	for (Book* book : this->list)
		if (title == book->getTitle())
			return book;

	// If no book is found, return an empty one
	Book* noneFound = new Book("BookNotFound");
	return noneFound;
}

Book* Category::findBook(int isbn13) {
	for (Book* book : this->list)
		if (isbn13 == book->getISBN13())
			return book;

	// If no book is found, return an empty one
	Book* noneFound = new Book("BookNotFound");
	return noneFound;
}

void Category::add(Book* book) {
	this->list.push_back(book);
}

void Category::remove(Book* book) {
	for (int i = 0; i < this->list.size(); i++)
		if (this->list.at(i)->compare(book))
		{
			this->list.erase(this->list.begin() + i);
			break;
		}
}

void Category::remove(string title) {
	for (int i = 0; i < this->list.size(); i++)
		if (title == this->list.at(i)->getTitle())
		{
			this->list.erase(this->list.begin() + i);
			break;
		}
}

void Category::remove(long int isbn13) {
	for (int i = 0; i < this->list.size(); i++)
		if (isbn13 == this->list.at(i)->getISBN13())
		{
			this->list.erase(this->list.begin() + i);
			break;
		}
}