#include "Category.h"
#include <iostream>

Category::Category() : Media() {}

Category::Category(string title) : Media(title) {}

Category::~Category() {
	for (int i = 0; i < this->list.size(); i++)
		delete this->list[i];
}

void Category::print() {
	std::cout << "Category: " << this->getTitle() << std::endl;
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

Book* Category::findBook(uint64_t isbn13) {
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
			delete this->list[i];
			this->list.erase(this->list.begin() + i);
			break;
		}
}

void Category::remove(string title) {
	for (int i = 0; i < this->list.size(); i++)
		if (title == this->list.at(i)->getTitle())
		{
			delete this->list[i];
			this->list.erase(this->list.begin() + i);
			break;
		}
}

void Category::remove(int index) {
	delete this->list[index];
	this->list.erase(this->list.begin() + index);
}

void Category::remove(uint64_t isbn13) {
	for (int i = 0; i < this->list.size(); i++)
		if (isbn13 == this->list.at(i)->getISBN13())
		{
			this->list.erase(this->list.begin() + i);
			break;
		}
}