#include "BookManager.h"
#include <iostream>

BookManager::BookManager() {
}

BookManager::~BookManager() {
	for (int i = 0; i < this->categories.size(); i++)
		delete this->categories[i];
}

void BookManager::print() {
	std::cout << "Book Manager" << std::endl;
}

void BookManager::printCategories() {
	for (int i = 0; i < this->categories.size(); i++)
		this->categories[i]->print();
}

void BookManager::printHierarchy() {
	this->print();
	for (int i = 0; i < this->categories.size(); i++) {
		this->categories[i]->print();
		this->categories[i]->printBooks();
	}
}

void BookManager::add(Category* category) {
	this->categories.push_back(category);
}

void BookManager::remove(Category* category) {
	this->remove(category->getTitle());
}

void BookManager::remove(string title) {
	for (int i = 0; i < this->categories.size(); i++)
		if (title == this->categories[i]->getTitle())
		{
			this->categories.erase(this->categories.begin() + i);
			break;
		}
}

int BookManager::categoryCount() {
	return this->categories.size();
}

void BookManager::editCategory(string current, string change) {
	for (int i = 0; i < this->categories.size(); i++)
		if (current == this->categories[i]->getTitle())
			this->categories[i]->setTitle(change);
}

void BookManager::changeBookCategory(string book, string currentCategory, string changeCategory) {
	for (int i = 0; i < this->categories.size(); i++)
	{
		if (this->categories[i]->getTitle() == currentCategory)
		{
			// Get the book
			Book* temp = this->categories[i]->findBook(book);
			if (temp->getTitle() != "BookNotFound")
			{
				// Remove the book from the old list
				Book* found = new Book(temp);
				this->categories[i]->remove(temp);
				
				// Add it to the new list
				for (int i = 0; i < this->categories.size(); i++)
					if (this->categories[i]->getTitle() == changeCategory)
					{
						this->categories[i]->add(found);
						break;
					}

				break;
			}
		}
	}
}

Book* BookManager::findBook(string title) {
	Book* temp = new Book();
	for (int i = 0; i < this->categories.size(); i++)
	{
		delete temp;
		temp = this->categories[i]->findBook(title);
		if (temp->getTitle() != "BookNotFound")
			return temp;
	}
	// Returns "None" if nothing is found
	return temp;
}

Book* BookManager::findBook(uint64_t isbn13) {
	Book* temp = new Book();
	for (int i = 0; i < this->categories.size(); i++)
	{
		delete temp;
		temp = this->categories[i]->findBook(isbn13);
		if (temp->getTitle() != "BookNotFound")
			return temp;
	}
	// Returns "None" if nothing is found
	return temp;
}

void BookManager::exportData() {
	// TODO
}