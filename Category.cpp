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