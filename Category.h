#pragma once
#include "Media.h"
#include "Book.h"
#include <vector>

using std::vector;

class Category : public Media {
private:
	vector<Book*> list;

public:
	// Constructors
	Category();
	Category(string title);

	// Populate virtual function
	void print();

	// Functions for vector manipulation
	void printBooks();

	Book* findBook(string title);
	Book* findBook(int isbn13);
	void add(Book*);
	void remove(Book*);
	void remove(string title);
	void remove(int isbn13);
};