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

	int bookCount();

	Book* findBook(string title);
	Book* findBook(__int64 isbn13);
	void add(Book*);
	void remove(Book*);
	void remove(string title);
	void remove(__int64 isbn13);
};