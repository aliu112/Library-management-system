#include "Category.h"
#include <iostream>

Category::Category() : Media() {}

Category::Category(string title) : Media(title) {}

void Category::print() {
	std::cout << "Category: " << std::endl;
}

void Category::setTitle(string title) {
	this->title = title;
}

string Category::getTitle() {
	return this->title;
}
