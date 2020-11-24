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

void Category::setTitle(string title) {
	this->title = title;
}

string Category::getTitle() {
	return this->title;
}

void Category::add(Book* book) {
	this->list.push_back(book);
}

void Category::remove(Book* book) {
	for (int i = 0; i < this->list.size(); i++)
		if (book == this->list.at(i))
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

void Category::remove(int isbn13) {
	for (int i = 0; i < this->list.size(); i++)
		if (isbn13 == this->list.at(i)->getISBN13())
		{
			this->list.erase(this->list.begin() + i);
			break;
		}
}